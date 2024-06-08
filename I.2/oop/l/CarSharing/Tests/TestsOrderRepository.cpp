#include "TestsOrderRepository.h"
#include <iostream>
#include <ctime>

void TestsOrderRepository::testAllOR() {
    std::string fileName = "test_orders.csv";
    OrderRepository repository(fileName);

    testSaveOrder(repository);
    testUpdateOrder(repository);
    testDeleteOrder(repository);
    testSearchOrder(repository);
    testListAllOrders(repository);
}

void TestsOrderRepository::testSaveOrder(OrderRepository &repository) {
    tm start = {0};
    start.tm_year = 2023 - 1900;
    start.tm_mon = 5;
    start.tm_mday = 1;

    tm end = {0};
    end.tm_year = 2023 - 1900;
    end.tm_mon = 5;
    end.tm_mday = 10;

    Car car("ABC123", "Model S", "Tesla", 2020, 12000, 200.0, "Electric", "Automatic", "Red", "new", true);
    Customer customer("john.doe@example.com", "John", "Doe", "password123", "123 Main St", "new", "1234567890", false);
    Employee employee("john.doe@example.com", "John", "Doe", "password123", "Manager", "1980-01-01", "JD", 5000.0, "new");

    Order order(1, "2023-05-01", "2023-05-01", "2023-05-10", "confirmed", car, customer, employee, 2000.0, "no remarks");
    repository.saveOrder(order);

    auto orders = repository.listAllOrders();
    if (orders.size() == 1 && orders[0].getOrderNr() == 1) {
        std::cout << "testSaveOrder passed.\n";
    } else {
        std::cout << "testSaveOrder failed.\n";
    }
}

void TestsOrderRepository::testUpdateOrder(OrderRepository &repository) {
    Car updatedCar("XYZ789", "Model 3", "Tesla", 2021, 10000, 180.0, "Electric", "Automatic", "Blue", "updated", true);
    Customer updatedCustomer("jane.doe@example.com", "Jane", "Doe", "password456", "456 Main St", "updated", "0987654321", false);
    Employee updatedEmployee("jane.doe@example.com", "Jane", "Doe", "password456", "CTO", "1985-05-05", "JD", 6000.0, "updated");

    Order updatedOrder(1, "2023-06-01", "2023-06-01", "2023-06-10", "completed", updatedCar, updatedCustomer, updatedEmployee, 1800.0, "updated remarks");
    repository.updateOrder(updatedOrder);

    auto orders = repository.listAllOrders();
    if (orders.size() == 1 && orders[0].getStatus() == "completed" && orders[0].getCar().getLicensePlate() == "XYZ789") {
        std::cout << "testUpdateOrder passed.\n";
    } else {
        std::cout << "testUpdateOrder failed.\n";
    }
}

void TestsOrderRepository::testDeleteOrder
