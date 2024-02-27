def erscheinungen(text_input):
    file = open('meine_datei.txt', 'r')
    data = file.read()
    counter = data.count(text_input)
    return counter

def ersetzen():
    text_input = str(input("Welches Wort möchten Sie ersetzen? "))
    text_output = str(input(f"Womit soll {text_input} ersetzt werden? "))
    counter = erscheinungen(text_input)

    with open('meine_datei.txt', 'r') as file:
        data = file.read()
        data = data.replace(text_input, text_output)

    with open('meine_datei.txt', 'w') as file:
        file.write(data)

    print(f'Ihr Wort wurde {counter} Mal ersetzt. ')