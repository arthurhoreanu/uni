from ADTBag import ADTBag
from ADTIterator import ADTIterator

def main():
    bag = ADTBag()

    def test_bag():
        bag.add(1)
        bag.add(2)
        bag.add(3)
        bag.add(4)

        assert bag.length() == 4
        assert bag.remove(4) is True
        assert bag.length() == 3
        assert bag.search(3) is True
        assert bag.search(4) is False
        bag.add(2)
        assert bag.nrOccurence(2) == 2

        print("All tests passed for ADTBag")

    test_bag()

    def test_iterator():
        iterator = ADTIterator(bag)
        assert iterator.valid() is True
        iterator.next()
        assert iterator.valid() is True
        assert iterator.getCurrent() == 2
        print("All tests passed for ADTIterator")

    test_iterator()

main()