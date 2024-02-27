file = "symbols.txt"

def get_symbols():
    dic = {}
    f = open(file, 'r')

    lines = f.readlines()
    for line in lines:
        space = line.split(' ')
        key = space[0]
        val = space[1].strip()
        dic[key] = val

    return dic

def write_to_file(sym, instr):
    dic = get_symbols()
    if dic is not None:
        f = open(file, 'w')
        dic[sym] = instr

        for key in dic.keys():
            f.write(str(key) + ' ' + str(dic[key]) + '\n')