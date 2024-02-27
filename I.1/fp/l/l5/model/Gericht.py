from model.Identifizierbar import Identifiable


class Dish(Identifiable):

    def __init__(self, id: int, serving_size: int, price: float):
        super().__init__(id)
        self._serving_size = serving_size
        self._price = price

        if type(self) == Dish:
            raise NotImplementedError("Abstract class cannot be instantiated")

    @property
    def serving_size(self):
        return self._serving_size

    @serving_size.setter
    def serving_size(self, value):
        self._serving_size = value

    @property
    def price(self):
        return self._price

    @price.setter
    def price(self, value):
        self._price = value