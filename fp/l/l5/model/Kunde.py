from model.Identifizierbar import Identifiable


class Customer(Identifiable):
    def __init__(self, id: int, name: str, address: str):
        super().__init__(id)
        self.__name = name
        self.__address = address



    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        self.__name = value

    @property
    def address(self):
        return self.__address

    @address.setter
    def address(self, value):
        self.__address = value

    def copy(self):
        return {'id': self._id,
                'name': self.__name,
                'address': self.__address}