from controller.controller import Controller
from model.GekochterGericht import CookedDish
from model.Kunde import Customer
from model.Getrank import Drink
from model.Bestellung import Order


class Console:
    def __init__(self, controller: Controller):
        self.__controller = controller

    def list_printer(self, entity_type, entity_list):

        type = entity_type.replace("_", " ").title()

        if len(entity_list) > 0:
            print("\n".join(map(lambda ordered_item: f"   {type}: {ordered_item.copy()}", entity_list)))
        else:
            print(f"   {type} list is empty")

    def create_entity(self, entity_type):
        new_entity = None

        if entity_type == "cooked_dish":
            cooked_dish = CookedDish(-1, -1, -1, -1)

            cooked_dish.id = int(input("new id: "))
            cooked_dish.serving_size = int(input("new serving size: "))
            cooked_dish.price = float(input("new price: "))
            cooked_dish.preparation_time = input("new preparation time: ")

            new_entity = cooked_dish

        elif entity_type == "drink":
            drink = Drink(-1, -1, -1, -1)

            drink.id = int(input("new id: "))
            drink.serving_size = int(input("new serving size: "))
            drink.price = float(input("new price: "))
            drink.alcohol_content = int(input("new alcohol content: "))

            new_entity = drink

        elif entity_type == "customer":
            customer = Customer(-1, "", "")

            customer.id = int(input("new id: "))
            customer.name = input("new name: ")
            customer.address = input("new address: ")

            new_entity = customer

        elif entity_type == "order":
            order = Order(-1, -1, [], [])

            order.id = int(input("new id: "))
            order.customer_id = int(input("new customer id: "))

            dishes = []

            while True:
                cooked_dishes_list = self.__controller.get_all("cooked_dish")

                if len(cooked_dishes_list) < 1:
                    break

                self.list_printer("cooked_dish", cooked_dishes_list)

                id = int(input("what would you like to eat?: "))
                print("\n-press -1 to exit")

                if id <= 0:
                    break
                else:
                    dishes.append(self.__controller.get_by_id(id, "cooked_dish"))

            order.dishes = dishes

            drinks = []

            while True:
                drinks_list = self.__controller.get_all("drink")

                if len(drinks_list) < 1:
                    break

                self.list_printer("drink", drinks_list)

                id = int(input("what would you like to drink?: "))
                print("\n-press -1 to exit")

                if id <= 0:
                    break
                else:
                    drinks.append(self.__controller.get_by_id(id, "drink"))

            order.drinks = drinks

            new_entity = order

        return new_entity

    def entity_chooser(self):
        choosen_entity = None
        print("1 - Cooked Dish")
        print("2 - Drink")
        print("3 - Customer")
        print("4 - Order")

        command = input(">>> ")

        if command == "1":
            choosen_entity = "cooked_dish"
        elif command == "2":
            choosen_entity = "drink"
        elif command == "3":
            choosen_entity = "customer"
        elif command == "4":
            choosen_entity = "order"

        return choosen_entity

    def print_menu(self):
        print("Current items:")
        print(f"Cooked dishes: {[cooked_dish.copy() for cooked_dish in self.__controller.get_all('cooked_dish')]}")
        print(f"Drinks: {[drink.copy() for drink in self.__controller.get_all('drink')]}")
        print(f"Customers: {[drink.copy() for drink in self.__controller.get_all('customer')]}")
        print(f"Orders: {[drink.copy() for drink in self.__controller.get_all('order')]}")

        print("\nMain Menu: ")
        print("0 - exit")
        print("1 - add ")
        print("2 - display items ")
        print("3 - find customer by name")
        print("4 - find customer by address")
        print("5 - generate invoice")
        print("6 - update ")
        print("7 - delete ")
        print("8 - menu")
        print("9 - get item by id")



    def run(self):
        self.__controller.read_file("cooked_dish")
        self.__controller.read_file("drink")
        self.__controller.read_file("customer")
        self.__controller.read_file("order")

        self.print_menu()

        command = input("\n Choose a command number : ")

        while command != "0":
            if command == "1":
                entity_type = self.entity_chooser()
                new_entity = self.create_entity(entity_type)

                self.__controller.add(new_entity, entity_type)
                print("added successfully ")
            elif command == "2":
                entity_type = self.entity_chooser()

                self.list_printer(entity_type, self.__controller.get_all(entity_type))

            elif command == "3":
                name = input("name: ")

                self.list_printer("customer", self.__controller.find_customer_by_name(name))


            elif command == "4":
                address = input("address: ")

                self.list_printer("customer", self.__controller.find_customer_by_address(address))

            elif command == "5":
                id = int(input("customer id : "))

                found = None

                for order in self.__controller.get_all("order"):
                    if order.customer_id == id:
                        order.display_invoice()
                        found = order.customer_id

                if not found:
                    print("Try again")
            elif command == "6":
                entity_type = self.entity_chooser()

                self.list_printer(entity_type, self.__controller.get_all(entity_type))

                id = int(input("update item with this id: "))

                new_entity = self.create_entity(entity_type)

                self.__controller.update_by_id(id, new_entity, entity_type)

            elif command == "7":
                entity_type = self.entity_chooser()

                self.list_printer(entity_type, self.__controller.get_all(entity_type))

                id = int(input("delete item with this id: "))

                self.__controller.delete_by_id(id, entity_type)



            elif command == "8":
                self.print_menu()

            elif command == "9":
                entity_type = self.entity_chooser()

                self.list_printer(entity_type, self.__controller.get_all(entity_type))

                id = int(input("get by this id: "))

                print(self.__controller.get_by_id(id, entity_type).copy())


            #if command in ["3", "5", "6", "9", "10"]:
                #self.list_printer("cooked_dish", self.__controller.get_all("cooked_dish"))
                #self.list_printer("drink", self.__controller.get_all("drink"))
                #self.list_printer("customer", self.__controller.get_all("customer"))
                #self.list_printer("order", self.__controller.get_all("order"))


            command = input("\n choose a command number : ")

