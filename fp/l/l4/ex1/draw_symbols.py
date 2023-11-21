from symbols_dict import get_symbols
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

def draw_instructions(instr, t):
    for char in instr:
        inst_dic[char](t)

def draw_str():
    sym_dict = get_symbols()
    txt = input("Enter the symbol/word you wish to draw: \n")

    t = turtle.Turtle()
    letter_spacing = 8 * get_pace()

    for char in txt:
        t.setheading(0)
        t.up()
        t.setx(t.pos()[0] + letter_spacing)
        t.sety(0)
        t.down()
        if char in sym_dict.keys():
            draw_instructions(sym_dict[char], t)

    turtle.exitonclick()

