import socket
import json
import random
from multiprocessing import Process


def check_guess(guess, secret_word):
    result = {'letters': [], 'won': False}
    for i in range(len(secret_word)):
        if guess[i] == secret_word[i]:
            result['letters'].append({'letter': guess[i], 'status': 'green'})
        elif guess[i] in secret_word:
            result['letters'].append({'letter': guess[i], 'status': 'yellow'})
        else:
            result['letters'].append({'letter': guess[i], 'status': 'gray'})
    result['won'] = (guess == secret_word)
    return result

def handle_client(client_socket, address):
    words = [
        'house', 'light', 'dream', 'plant', 'stone', 'brain', 'earth', 'score', 'field', 'music',
        'glass', 'peace', 'river', 'space', 'fruit', 'clean', 'water', 'heart', 'sharp', 'crown',
        'street', 'sweet', 'flame', 'flash', 'climb', 'brave', 'story', 'frame', 'cloud', 'night',
        'grace', 'beach', 'fresh', 'magic', 'power', 'toast', 'chase', 'block', 'smile', 'honey',
        'level', 'sleep', 'sheep', 'shine', 'march', 'trust', 'panic', 'flaws', 'taste', 'angel',
        'paris', 'thumb', 'email', 'thing', 'tight', 'blame', 'stars', 'young', 'right', 'white',
        'green', 'brown', 'alien', 'first', 'third', 'merry', 'smoke', 'round', 'apple', 'chess',
        'dance', 'eagle', 'latte'
    ]
    secret_word = random.choice(words)
    print(f"[{address}] Secret word: {secret_word}")
    max_attempts = 6
    attempts = 0
    try:
        while attempts < max_attempts:
            data = client_socket.recv(1024).decode('utf-8')
            if not data:
                break
            guess = data.strip().lower()
            attempts += 1
            result = check_guess(guess, secret_word)
            if attempts >= max_attempts and not result['won']:
                result['message'] = f"You've used all attempts. The word was: {secret_word}"
            client_socket.send(json.dumps(result).encode('utf-8'))
            if result['won']:
                break
    except Exception as e:
        print(f"[{address}] Error: {e}")
    finally:
        print(f"[{address}] Connection closed.")
        client_socket.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("localhost", 12345))
    server_socket.listen(5)
    print("Server is running and waiting for connections...")

    try:
        while True:
            client_socket, client_address = server_socket.accept()
            print(f"Connection from {client_address}")
            process = Process(target=handle_client, args=(client_socket, client_address))
            process.start()
    except KeyboardInterrupt:
        print("Shutting down server...")
    finally:
        server_socket.close()

if __name__ == "__main__":
    main()