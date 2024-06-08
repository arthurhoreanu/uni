#ifndef APP_ORDER_H
#define APP_ORDER_H

#include<string>
#include <list>
#include "sstream"

#include "Employee.h"
#include "Customer.h"
#include "Car.h"
//
class Order {
private:
    int orderNumber;

    std::string orderDate;
    std::string start;
    std::string end;

    std::string status;
    Car car;/** TODO */
    Customer customer;
    Employee employee; /** TODO */
    float totalCost;
    std::string observation;
    static std::vector<Order> repository;
public:


    Order(float totalCost, std::string observation, Customer user, std::string start, std::string end, Car car);
    Order(float totalCost, std::string observation, Customer user, std::string start, std::string end, Car car,
          Employee employee1);

    //only use this constructor when all info is already known (ex. when reading an existing obj from a file)
    Order(int orderNr, std::string orderDate, std::string start, std::string end, std::string status, std::string carLicensePlate,
          std::string customerEmail, std::string employeeEmail, int totalCost, std::string observation);

    Order(){};

    void setRepository(std::vector<Order> list);

    void setOrderNr(int nr);
    int getOrderNr() const;
    void setOrderDate(std::string time);
    std::string getOrderDate();
    void setStart(std::string time);
    std::string getStart();
    void setEnd(std::string time);
    std::string getEnd();
    void setStatus(std::string status);
    std::string getStatus();
    void setCar(Car car);
    Car getCar();
    void setCustomer(Customer user);
    Customer getCustomer();
    void setEmployee(Employee employee);
    Employee getEmployee();
    void setMoney(float sum);
    float getMoney();
    void setObservation(std::string observation);
    std::string getObservation();


    //general function for writing an order's details
    void writeAll();

    //B.5 Validierungen   --> is called everytime when an object is created (in the constructor)
    bool callAllValidationFunctions(Car car, std::string begin, std::string end,
                                    std::string status, Customer user);

    //if the car is already used on the given date, an error occurs
    static bool checkIfCarIsAlreadyUsed(Car car, std::string begin, std::string end);
    //begin must be smaller than end
    static bool checkIfBeginIsSmallerOrEqualEnd(std::string begin, std::string end);
    //a user is not allowed to have more than 5 reservations
    static bool userHasLessThanFiveReservations(Customer user, std::string status);
    //order number is issued automatically by the system
    static int determineOrderNumber(std::vector<Order> repository);   //numbers are made by maximum + 1  (ex. 1 2 3 5 6 7 --> 8)


    //transform obect into csv format
    std::string toCSV();

    //transform object from csv format
    void fromCSV(const std::string &csvLine);

    void displayOrder();
};


#endif //APP_ORDER_H
