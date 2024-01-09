from functools import reduce
from operator import add

from model.Identifizierbar import Identifiable


class Order(Identifiable):
    def __init__(self, id, customer_id, dishes: list, drinks: list):
        super().__init__(id)
        self.__customer_id = customer_id
        self.__dishes = dishes
        self.__drinks = drinks
        self.__total_cost = self.calculate_total()

    def copy(self):
        return {'id': self._id,
                'customer_id': self.__customer_id,
                'dishes': [dish.copy() for dish in self.__dishes],
                'drinks': [drink.copy() for drink in self.__drinks],
                'total_cost': self.__total_cost}


    def customer_id(self):
        return self.__customer_id


    def customer_id(self, value):
        self.__customer_id = value

    @property
    def dishes(self):
        return self.__dishes

    @dishes.setter
    def dishes(self, value):
        self.__dishes = value

    @property
    def drinks(self):
        return self.__drinks

    @drinks.setter
    def drinks(self, value):
        self.__drinks = value

    @property
    def total_cost(self):
        return self.__total_cost

    @total_cost.setter
    def total_cost(self, value):
        self.__total_cost = value

    def calculate_total(self):
        dishes_list_of_prices = [dish.price for dish in self.__dishes]

        drinks_list_of_prices = [drink.price for drink in self.__drinks]


        if dishes_list_of_prices or drinks_list_of_prices:
            return reduce(add, dishes_list_of_prices + drinks_list_of_prices)
        else:
            return 0

    def __create_invoice(self):
        drinks_and_dishes = self.__drinks + self.__dishes
        total_string = "\nTotal: " + str(self.calculate_total())


        return "\n".join(map(lambda ordered_item: "Ordered: " + str(ordered_item.copy()), drinks_and_dishes)) \
               + total_string

    def display_invoice(self):
        print(self.__create_invoice())