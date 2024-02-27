from draw_symbols import draw_str
from add_symbol import define_symbol

def menu():
    print("1. Symbol schreiben")
    print("2. Symbol hinzufügen")

    opt = int(input())

    match opt:
        case 1:
            draw_str()
        case 2:
            define_symbol()

menu()