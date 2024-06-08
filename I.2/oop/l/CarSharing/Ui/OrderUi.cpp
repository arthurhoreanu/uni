#include "OrderUi.h"
#include <iomanip>
#include <string>

void OrderUi::displayMenu() {
    std::cout << "Order Management System\n";
    std::cout << "1. Create Order\n";
    std::cout << "2. Update Order\n";
    std::cout << "3. Complete Order\n";
    std::cout << "4. Take Over Order\n";
    std::cout << "5. Take Away Order\n";
    std::cout << "6. List Orders\n";
    std::cout << "7. Search Order\n";
    std::cout << "8. Remove Order\n";
    std::cout << "0. Exit\n";
}

void OrderUi::handleUserInput(int userType) {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createOrder();
                break;
            case 2:
                updateOrder(userType);
                break;
            case 3:
                completeOrder();
                break;
            case 4:
                takeOverOrder();
                break;
            case 5:
                takeAwayOrder();
                break;
            case 6:
                listOrders();
                break;
            case 7:
                searchOrder();
                break;
            case 8:
                if (userType == 3)
                {
                    removeOrder();
                }//remove
                else if (userType <= 2)
                {
                    std::cout<<"Cannot remove order; permissions not granted\n";
                }
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}

void OrderUi::createOrder() {
    float totalCost;
    std::string observation;
    std::string start, end;

    std::cout << "Enter total cost: ";
    std::cin >> totalCost;
    std::cin.ignore();

    std::cout << "Enter observation: ";
    std::getline(std::cin, observation);

    std::cout << "Enter status: ";
    std::getline(std::cin, observation);

    std::string customerName, customerContact;
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "Enter customer contact: ";
    std::getline(std::cin, customerContact);

    std::cout << "Enter start time (year month day; Format: YYYY/MM/DD, for ex. introduce 2004/10/21): ";
    std::cin >> start;

    std::cout << "Enter end time (year month day; Format: YYYY/MM/DD, for ex. introduce 2004/10/21): ";
    std::cin >> end;

    std::string carMake, carModel, carPlate;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter car make: ";
    std::getline(std::cin, carMake);
    std::cout << "Enter car model: ";
    std::getline(std::cin, carModel);
    std::cout << "Enter car plate number: ";
    std::getline(std::cin, carPlate);

    std::string employeeName, employeeSurname;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee surname: ";
    std::getline(std::cin, employeeSurname);

    controller.createOrder(totalCost, observation, customerContact, start, end, carPlate, employeeName, employeeSurname);
    std::cout << "Order created successfully.\n";
}

void OrderUi::updateOrder(int userType) {
    float totalCost;
    std::string observation, status;
    std::string start, end;
    int id;

    std::cout << "Enter order ID to update: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter total cost: ";
    std::cin >> totalCost;
    std::cin.ignore();

    std::cout << "Enter observation: ";
    std::getline(std::cin, observation);

    std::cout << "Enter status: ";
    std::getline(std::cin, status);

    std::string customerName, customerContact;
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "Enter customer contact: ";
    std::getline(std::cin, customerContact);

    std::cout << "Enter start time (year month day; Format: YYYY/MM/DD, for ex. introduce 2004/10/21): ";
    std::cin >> start;

    std::cout << "Enter end time (year month day; Format: YYYY/MM/DD, for ex. introduce 2004/10/21): ";
    std::cin >> end;

    std::string carMake, carModel, carPlate;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter car make: ";
    std::getline(std::cin, carMake);
    std::cout << "Enter car model: ";
    std::getline(std::cin, carModel);
    std::cout << "Enter car plate number: ";
    std::getline(std::cin, carPlate);

    std::string employeeName, employeeSurname;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee surname: ";
    std::getline(std::cin, employeeSurname);
    if((userType == 3 || userType ==  2 ) && status != "Completed") {
        controller.updateOrder(totalCost, observation, customerContact, start, end, carPlate, employeeName,
                               employeeSurname, id);
        std::cout << "Order updated successfully.\n";
    }
    else{
        std::cout << "The order cannot be updated.\n";
    }
}

void OrderUi::completeOrder() {
    int id;
    std::cout << "Enter order ID to complete: ";
    std::cin >> id;
    controller.completeOrder(id);
    std::cout << "Order completed successfully.\n";
}

void OrderUi::takeAwayOrder() {
    int id;

    std::cout << "Enter order ID to take away: ";
    std::cin >> id;

    std::string employeeName, employeePosition, employeeSurname;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee surname: ";
    std::getline(std::cin, employeeSurname);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, employeePosition);

    controller.takeAwayOrder(id, employeeName, employeeSurname);
    std::cout << "Order taken away successfully.\n";
}

void OrderUi::listOrders() {
    auto orders = controller.listOrders();
    for (Order order : orders) {
        order.displayOrder();
    }
}

void OrderUi::searchOrder() {
    int id;
    std::cout<<" Enter order ID to search: ";
    std::cin>>id;
    auto order = controller.searchOrder(id);
    order.displayOrder();
}

void OrderUi::takeOverOrder() {
    int id;

    std::cout << "Enter order ID to take over: ";
    std::cin >> id;

    std::string employeeName, employeePosition, employeeSurname;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee surname: ";
    std::getline(std::cin, employeeSurname);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, employeePosition);

    controller.takeOverOrder(id, employeeName, employeeSurname);
    std::cout << "Order taken over successfully.\n";
}

int OrderUi::removeOrder() {
    int id;
    std::cout<<" Enter order ID to remove: ";
    std::cin>>id;
    controller.removeReservation(id);

}