from repository.cooked_dish_repo import CookedDishRepo
from repository.customer_repo import CustomerRepo
from repository.drink_repo import DrinkRepo
from repository.order_repo import OrderRepo


class Controller:
    def __init__(self,
                 cooked_dish_repo: CookedDishRepo,
                 drink_repo: DrinkRepo,
                 customer_repo: CustomerRepo,
                 order_repo: OrderRepo):

        self.__cooked_dish_repo = cooked_dish_repo
        self.__drink_repo = drink_repo
        self.__customer_repo = customer_repo
        self.__order_repo = order_repo

    def add(self, entity, entity_type):
        if entity_type == "cooked_dish":
            self.__cooked_dish_repo.add(entity)
        elif entity_type == "drink":
            self.__drink_repo.add(entity)
        elif entity_type == "customer":
            self.__customer_repo.add(entity)
        elif entity_type == "order":
            self.__order_repo.add(entity)

    def get_all(self, entity_type):
        entity_list = []

        if entity_type == "cooked_dish":
            entity_list = self.__cooked_dish_repo.get_all()
        elif entity_type == "drink":
            entity_list = self.__drink_repo.get_all()
        elif entity_type == "customer":
            entity_list = self.__customer_repo.get_all()
        elif entity_type == "order":
            entity_list = self.__order_repo.get_all()

        return entity_list

    def get_by_id(self, id, entity_type):
        entity = None

        if entity_type == "cooked_dish":
            entity = self.__cooked_dish_repo.get_by_id(id)
        elif entity_type == "drink":
            entity = self.__drink_repo.get_by_id(id)
        elif entity_type == "customer":
            entity = self.__customer_repo.get_by_id(id)
        elif entity_type == "order":
            entity = self.__order_repo.get_by_id(id)

        return entity

    def delete_by_id(self, id, entity_type):
        if entity_type == "cooked_dish":
            self.__cooked_dish_repo.delete_by_id(id)
        elif entity_type == "drink":
            self.__drink_repo.delete_by_id(id)
        elif entity_type == "customer":
            self.__customer_repo.delete_by_id(id)
        elif entity_type == "order":
            self.__order_repo.delete_by_id(id)

    def update_by_id(self, id, new_entity, entity_type):
        if entity_type == "cooked_dish":
            self.__cooked_dish_repo.update_by_id(id, new_entity)
        elif entity_type == "drink":
            self.__drink_repo.update_by_id(id, new_entity)
        elif entity_type == "customer":
            self.__customer_repo.update_by_id(id, new_entity)
        elif entity_type == "order":
            self.__order_repo.update_by_id(id, new_entity)

    def read_file(self, entity_type):
        if entity_type == "cooked_dish":
            self.__cooked_dish_repo.read_file()
        elif entity_type == "drink":
            self.__drink_repo.read_file()
        elif entity_type == "customer":
            self.__customer_repo.read_file()
        elif entity_type == "order":
            self.__order_repo.read_file()

    def write_to_file(self, entity_type):
        if entity_type == "cooked_dish":
            self.__cooked_dish_repo.write_to_file()
        elif entity_type == "drink":
            self.__drink_repo.write_to_file()
        elif entity_type == "customer":
            self.__customer_repo.write_to_file()
        elif entity_type == "order":
            self.__order_repo.write_to_file()

    def find_customer_by_name(self, name):
        return self.__customer_repo.find_by_name(name)

    def find_customer_by_address(self, address):
        return self.__customer_repo.find_by_address(address)