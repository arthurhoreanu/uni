from repository.data_repo import DataRepo
from model.Getrank import Drink


def convert_dictionary_to_drink(dictionary_from_json):
    drink = Drink(-1, -1, -1, -1)

    drink.id = dictionary_from_json["id"]
    drink.serving_size = dictionary_from_json["serving_size"]
    drink.price = dictionary_from_json["price"]
    drink.alcohol_content = dictionary_from_json["alcohol_content"]

    return drink


def convert_drink_to_dictionary(drink):
    return drink.copy()


class DrinkRepo(DataRepo):
    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, object_list) -> list:
        return list(map(convert_drink_to_dictionary, self.get_all()))

    def convert_from_string(self, dictionary_list_from_json) -> list:
        return list(map(convert_dictionary_to_drink, dictionary_list_from_json))