import turtle

sym = ""
pace = 3

def get_pace():
    return pace

def move_forward(t):
    t.forward(pace)
    global sym
    sym += 'w'

def move_back(t):
    t.backward(pace)
    global sym
    sym += 's'

def rotate_right(t):
    t.right(45)
    global sym
    sym += 'd'

def rotate_left(t):
    t.left(45)
    global sym
    sym += 'a'

def move_up(t):
    t.up()
    global sym
    sym += 'f'


def move_down(t):
    t.down()
    global sym
    sym += 'g'

def draw_dot(t):
    t.dot(10)
    global sym
    sym += '.'

def clear_sym():
    global sym
    sym = ""

def get_sym():
    global sym
    return sym