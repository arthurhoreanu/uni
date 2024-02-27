from repository.data_repo import DataRepo
from model.Kunde import Customer


def convert_dictionary_to_customer(dictionary_from_json):
    customer = Customer(-1, "", "")

    customer.id = dictionary_from_json["id"]
    customer.name = dictionary_from_json["name"]
    customer.address = dictionary_from_json["address"]

    return customer


def convert_customer_to_dictionary(customer):
    return customer.copy()


class CustomerRepo(DataRepo):
    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, object_list) -> list:
        return list(map(convert_customer_to_dictionary, self.get_all()))

    def convert_from_string(self, dictionary_list_from_json) -> list:
        return list(map(convert_dictionary_to_customer, dictionary_list_from_json))

    def find_by_name(self, name):
        return list(filter(lambda customer: name.lower() in customer.name.lower(), self.get_all()))

    def find_by_address(self, address):
        return list(filter(lambda customer: address.lower() in customer.address.lower(), self.get_all()))