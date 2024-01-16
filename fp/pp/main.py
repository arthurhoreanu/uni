#1
#a
def my_sum(is_odd, filename):

    with open(filename, "r") as f:
        zahlen = f.read().splitlines()

    zahlen = [tuple(z.split(",")) for z in zahlen]

    def ungerade_anzahl(zahl):
        anzahl = 0
        while zahl > 0:
            anzahl +=1
            zahl //=10
        if anzahl % 2 == 1:
            return True
        return False

    def wird_int(z):
        return int(z[0])

    if is_odd:
        zahlen = list(map(wird_int, filter(lambda z: int(z[1]) % 2 == 1, zahlen)))
    else:
        zahlen = list(map(wird_int, zahlen))

    zahlen = list(filter(ungerade_anzahl, zahlen))

    return sum(zahlen)

#b
def test_true():
    result_true = my_sum(True, "zahlen.txt")
    assert result_true == 726

def test_false():
    result_false = my_sum(False, "zahlen.txt")
    assert result_false == 853

test_true()
test_false()

#2
#a
class BigNumber:
    def __init__(self, zahl_string):
        self.zahl_string = zahl_string
        self.ziffern = list(reversed(zahl_string))

    def subtract(self, andere_zahl):
        if len(self.ziffern) != len(andere_zahl.ziffern):
            raise ValueError("Die Zahlen müssen die gleiche Länge haben")

        ziffern = []
        borgen = 0

        for i in (range(len(self.ziffern))):
            ziffer1 = int(self.ziffern[i])
            ziffer2 = int(andere_zahl.ziffern[i])
            differenz = ziffer1 - ziffer2 - borgen
            if differenz >= 0:
                ziffern.append(str(differenz))
                borgen = 0
            else:
                ziffern.append(str(differenz + 10))
                borgen = 1

        return "".join(ziffern)[::-1]

    def copy(self):
        neue_ziffern = list(self.ziffern)
        neue_zahl = BigNumber("".join(neue_ziffern))
        return neue_zahl

my_number1 = BigNumber("134")
my_number2 = BigNumber("129")
my_sub = my_number1.subtract(my_number2)
print(my_sub)

#b
class NumberBox:
    def __init__(self):
        self.BigNumbers = []

    def add_number(self, zahl):
        if not isinstance(zahl, BigNumber):
            raise TypeError("Der hinzugefügte Nummer muss ein Big-Number-Objekt sein")
        neue_zahl = zahl.copy()
        self.BigNumbers.append(neue_zahl)

my_number_box = NumberBox()
my_number_box.add_number(my_number1)
my_number_box.add_number(my_number2)