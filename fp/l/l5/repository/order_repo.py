from repository.data_repo import DataRepo
from model.Bestellung import Order
from repository.cooked_dish_repo import convert_dictionary_to_cooked_dish
from repository.drink_repo import convert_dictionary_to_drink


def convert_dictionary_to_order(dictionary_from_json):
    order = Order(-1, -1, [], [])

    order.id = dictionary_from_json["id"]
    order.customer_id = dictionary_from_json["customer_id"]

    order.dishes = list(map(convert_dictionary_to_cooked_dish, dictionary_from_json["dishes"]))
    order.drinks = list(map(convert_dictionary_to_drink, dictionary_from_json["drinks"]))

    order.total_cost = dictionary_from_json["total_cost"]

    return order


def convert_order_to_dictionary(order):
    return order.copy()


class OrderRepo(DataRepo):
    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, object_list) -> list:
        return list(map(convert_order_to_dictionary, self.get_all()))

    def convert_from_string(self, dictionary_list_from_json) -> list:
        return list(map(convert_dictionary_to_order, dictionary_list_from_json))
