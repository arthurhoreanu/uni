#1
#a
def my_sum(is_odd, filename):

    with open(filename, "r") as f:
        zahlen = f.read().splitlines()

    zahlen = [tuple(z.split(",")) for z in zahlen]

    def ist_primzahl(zahl):
    return zahl > 1 and all(zahl % x for x in range(2, int(zahl ** 0.5) + 1))

    def wird_int(z):
        return int(z[0])

    if is_odd:
        zahlen = list(map(wird_int, filter(lambda z: int(z[1]) % 2 == 1, zahlen)))
    else:
        zahlen = list(map(wird_int, zahlen))

    zahlen = list(filter(ist_primzahl, zahlen))

    return sum(zahlen)

#b
def test_my_sum_is_odd():
  assert my_sum(True, "zahlen.txt") == 526

def test_my_sum_is_not_odd():
  assert my_sum(False, "zahlen.txt") == 526

#2
#a
class BigNumber:

    def _init_(self, number_string):
        self.number_string = number_string
        self.digits = list(reversed(number_string))

    def add(self, other_number):
        if len(self.digits) != len(other_number.digits):
            raise ValueError("Die beiden Zahlen müssen die gleiche Länge haben.")

        digits = []
        carry = 0
        for i in range(len(self.digits)):
            digit1 = self.digits[i]
            digit2 = other_number.digits[i]

            addition = int(digit1) + int(digit2) + carry
            digits.append(str(addition % 10))
            carry = addition // 10

        if carry > 0:
            digits.append(str(carry))

        return "".join(digits)[::-1]

my_number1 = BigNumber("56325663")
my_number2 = BigNumber("96325663")
my_sum = my_number1.add(my_number2)

print(my_sum)