from model.Gericht import Dish


class CookedDish(Dish):
    def __init__(self, id: int, serving_size: int, price: float, preparation_time: int):
        super().__init__(id, serving_size, price)
        self.__preparation_time = preparation_time

    def copy(self):
        return {'id': self._id,
                'serving_size': self._serving_size,
                'price': self._price,
                'preparation_time': self.__preparation_time}

    @property
    def preparation_time(self):
        return self.__preparation_time

    @preparation_time.setter
    def preparation_time(self, value):
        self.__preparation_time = value