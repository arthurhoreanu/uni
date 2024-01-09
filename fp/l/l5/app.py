from controller.controller import Controller
from repository.cooked_dish_repo import CookedDishRepo
from repository.customer_repo import CustomerRepo
from repository.drink_repo import DrinkRepo
from repository.order_repo import OrderRepo
from ui.console import Console

controller = Controller(
    CookedDishRepo("cooked_dishes.json"),
    DrinkRepo("drinks.json"),
    CustomerRepo("customers.json"),
    OrderRepo("orders.json")
)

console = Console(controller)
console.run()
