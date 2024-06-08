

#include "OrderController.h"

void OrderController::createOrder(float totalCost, std::string observation, std::string customerPhoneNr, std::string start, std::string end,
                                  std::string carLicensePlate, std::string employeeName, std::string employeeSurname) const{

    EmployeeRepository employeeSearch;
    CustomerHandlingRepository customerSearch("CarSharingFInal/Information/Customers.csv");
    CarRepository carSearch("");//TODO:carfile
    Order newOrder(totalCost, observation, customerSearch.searchCustomersByPhoneNumber(customerPhoneNr)[0], start, end, carSearch.findByLicensePlate(carLicensePlate));
    newOrder.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    newOrder.setRepository(repo.listAllOrders());
    this->repo.saveOrder(newOrder);
}

void OrderController::updateOrder(float totalCost, std::string observation, std::string customerPhoneNr, std::string start, std::string end,
                                  std::string carLicensePlate, std::string employeeName, std::string employeeSurname, int id) {
    //waiting for login info

    Order updatedOrder;
    EmployeeRepository employeeSearch;
    CustomerHandlingRepository customerSearch("CarSharingFInal/Information/Customers.csv");
    CarRepository carSearch("");//TODO: waiting for carfile
    updatedOrder.setCar(carSearch.findByLicensePlate(carLicensePlate));
    updatedOrder.setCustomer(customerSearch.searchCustomersByPhoneNumber(customerPhoneNr)[0]);
    updatedOrder.setEnd(end);
    updatedOrder.setStart(start);
    updatedOrder.setMoney(totalCost);
    updatedOrder.setObservation(observation);
    updatedOrder.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    updatedOrder.setOrderNr(id);
    updatedOrder.setRepository(repo.listAllOrders());
    repo.updateOrder(updatedOrder);
}

void OrderController::completeOrder(int id) {
    Order completed = repo.searchOrder(id);

    Order obj = repo.searchOrder(id);
    string c1(1, obj.getStart()[8]), c2(1, obj.getStart()[9]);
    //c1 + c2 is the day of the start date  (format: YYYY/MM/DD)
    string c3(1, obj.getEnd()[8]), c4(1, obj.getEnd()[9]);
    //c3 + c4 is the day of the end date (format: YYYY/MM/DD)
    float numOfDays = std::stof(c3+c4) - std::stoi(c1+c2);

    string c5(1, obj.getStart()[5]), c6(1, obj.getStart()[6]);
    //c1 + c2 is the month of the start date  (format: YYYY/MM/DD)
    string c7(1, obj.getEnd()[5]), c8(1, obj.getEnd()[6]);
    //c3 + c4 is the month of the end date (format: YYYY/MM/DD)
    float startMonth = std::stof(c5+c6), endMonth = std::stof(c7+c8);
    numOfDays += (endMonth-startMonth) * 30; //a month has 30 days; + 30*amount of months

    completed.setMoney(numOfDays * completed.getCar().getDailyRate());

    completed.setStatus("completed");
    repo.updateOrder(completed);
}

void OrderController::takeAwayOrder(int id, std::string employeeName, std::string employeeSurname) {
    Order change = repo.searchOrder(id);
    EmployeeRepository employeeSearch;
    change.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    repo.updateOrder(change);
}

void OrderController::takeOverOrder(int id, std::string employeeName, std::string employeeSurname) {
    Order change = repo.searchOrder(id);
    EmployeeRepository employeeSearch;
    change.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    repo.updateOrder(change);
}

std::vector<Order> OrderController::listOrders() {
    return repo.listAllOrders();
}

Order OrderController::searchOrder(int id) {
    return repo.searchOrder(id);
}

void OrderController::removeReservation(int orderNr) {
    repo.removeReservation(orderNr);
}