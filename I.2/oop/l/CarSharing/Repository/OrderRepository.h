#ifndef CARSHARINGFINAL_ORDERREPOSITORY_H
#define CARSHARINGFINAL_ORDERREPOSITORY_H
#include <iostream>
#include <string>
#include <fstream>
#include "../Models/Order.h"
#include "../Models/User.h"
#include <vector>
#include <list>

class OrderRepository {
private:
    std::string filename = "CarSharingFInal/Information/Orders.csv";
    std::vector<Order> orders;

public:
    OrderRepository(std::string &filename);

//    void allOrders();
    //B.4 Auflisten der Bestellungen
    std::vector<Order> showAllOrdersInASpecificTimeInterval(std::vector<Order> repository, std::string start, std::string end);
    static bool compareByTotalPrice(Order c1, Order c2)
    { return c1.getMoney() < c2.getMoney(); }

    void totalSumOfATimeInterval(std::vector<Order> repository, std::string time, std::string type); //time is either a month or a year (ex. January or 2024)

//    std::list<Order> fromFile();

    //--Repository functions--
    //Order findOrderByID -> is included in B4
    void saveOrder(Order obj) const;
    void deleteOrder(Order obj);
    void updateOrder(Order obj);

    std::vector<Order> listAllOrders() const;
    Order searchOrder(int orderID);

    //B.3 -Grama Andrei
    //Order & Reservation handling

    void removeReservation(int orderNr);
    void changeReservation(Order newReservation);

    static std::vector<Order> convertListToVector(std::list<Order> &repo);

    std::vector<Order> readFromCsv();
    void writeToCsv();
};


#endif //CARSHARINGFINAL_ORDERREPOSITORY_H