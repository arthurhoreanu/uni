from turtle import *
import functools

from symbols_dict import write_to_file
from turtle_move import *

inst_dic = {
    "w": move_forward,
    "s": move_back,
    "d": rotate_right,
    "a": rotate_left,
    "f": move_up,
    "g": move_down,
    ".": draw_dot
}

def define_symbol():
    sym = input("Symbol eingeben: \n")
    t = turtle.Turtle()
    print("W - 10 Pixel vorwärts bewegen")
    print("S - 10 Pixel rückwärts bewegen")
    print("D - Rechts um 45 Grad abbiegen")
    print("A - Links um 45 Grad abbiegen")
    print("F - Stift hoch")
    print("G - Stift unten")

    clear_sym()
    listen()
    for k in 'wasdfg.':
        onkey(functools.partial(event_handler, k, t), k)
    onkey(bye, 'Return')
    mainloop()
    sym_instr = get_sym()
    write_to_file(sym, sym_instr)


def event_handler(key, tur):
    inst_dic[key](tur)