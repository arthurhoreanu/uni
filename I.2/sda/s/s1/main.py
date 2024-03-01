from ADTBag import ADTBag
from ADTIterator import ADTIterator

def main():
    bag = ADTBag()
    bag.add(2)
    bag.add(3)
    bag.add(5)
    print(bag.b)
    bag.remove(2)
    print(bag.b)
    print(bag.search(3))
    print(bag.size())
    print(bag.nrOccurrences(5))

main()