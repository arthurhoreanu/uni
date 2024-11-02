import socket
import json
import random

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

def main():
    words = ['apple', 'batch', 'chess', 'dance', 'eagle']
    secret_word = random.choice(words)
    print(f"Cuvânt secret: {secret_word}")

    # Configurare socket server
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(("INSERT_IP", INSERT_PORT))
    s.listen(1)

    # Acceptă conexiune client
    cs, addr = s.accept()

    max_attempts = 6
    attempts = 0

    while attempts < max_attempts:
        # Primește guess-ul de la client
        data = cs.recv(1024).decode('utf-8')
        
        if not data:
            break

        guess = data.strip().lower()
        attempts += 1

        # Verifică guess-ul
        result = check_guess(guess, secret_word)
        
        # Adaugă informații suplimentare în rezultat
        if attempts >= max_attempts and not result['won']:
            result['message'] = f"Ai epuizat încercările. Cuvântul era: {secret_word}"
        
        # Trimite răspuns înapoi la client
        cs.send(json.dumps(result).encode('utf-8'))

        # Verifică dacă jocul s-a încheiat
        if result['won']:
            break

    # Încheie conexiunile
    cs.close()
    s.close()

main()