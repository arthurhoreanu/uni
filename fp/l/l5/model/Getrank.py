from model.Gericht import Dish


class Drink(Dish):
    def __init__(self, id: int, serving_size: int, price: float, alcohol_content: int):
        super().__init__(id, serving_size, price)
        self.__alcohol_content = alcohol_content

    def copy(self):
        return {'id': self._id,
                'serving_size': self._serving_size,
                'price': self._price,
                'alcohol_content': self.__alcohol_content}

    @property
    def alcohol_content(self):
        return self.__alcohol_content

    @alcohol_content.setter
    def alcohol_content(self, value):
        self.__alcohol_content = value