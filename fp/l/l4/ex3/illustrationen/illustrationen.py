def read_file(filename):
    with open(f'illustrationen/{filename}', 'r') as file:
        content = file.read()
    return content

def schere():
    return read_file('schere.txt')

def stein():
    return read_file('stein.txt')

def papier():
    return read_file('papier.txt')

def loser():
    return read_file('loser.txt')

def winner():
    return read_file('winner.txt')

def tie():
    return read_file('tie.txt')