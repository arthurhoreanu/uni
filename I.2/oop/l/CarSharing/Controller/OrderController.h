
#ifndef APP_ORDERCONTROLLER_H
#define APP_ORDERCONTROLLER_H

#include "../Repository/OrderRepository.h"
#include "../Repository/EmployeeRepository.h"
#include "../Repository/CarRepository.h"
#include "../Repository/CustomerHandlingRepository.h"
#include<list>

class OrderController {
private:
    OrderRepository repo;
//    int day = 86400;
public:
    void createOrder(float totalCost, std::string observation, std::string customerPhoneNr, std::string start, std::string end, std::string carLicensePlate, std::string employeeName, std::string employeeSurname) const;

    void updateOrder(float totalCost, std::string observation, std::string customerPhoneNr, std::string start, std::string end, std::string carLicensePlate, std::string employeeName, std::string employeeSurname, int id);

    void completeOrder(int id);

    void takeOverOrder(int id, std::string employeeName, std::string employeeSurname);

    void takeAwayOrder(int id, std::string employeeName, std::string employeeSurname);

    std::vector<Order> listOrders();

    Order searchOrder(int id);

    void removeReservation(int orderNr);
};


#endif //APP_ORDERCONTROLLER_H
