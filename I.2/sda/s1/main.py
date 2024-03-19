from ADTBag import ADTBag
from ADTIterator import ADTIterator

def main():
    bag = ADTBag()

    # test bag
    bag.add(1)
    bag.add(2)
    bag.add(3)
    bag.add(4)

    print(bag.length())
    bag.remove(4)
    print(bag.length())
    print(bag.search(3))
    print(bag.search(4))
    bag.add(2)
    print(bag.nrOccurence(2))

    # test iterator
    ite = ADTIterator(bag)
    print(ite.valid())
    ite.next()
    print(ite.valid())
    print(ite.getCurrent())


main()