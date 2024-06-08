#include "Order.h"
#include "../Repository//CarRepository.h"
#include "../Repository//CustomerHandlingRepository.h"
#include "../Repository//EmployeeRepository.h"

Order::Order(float totalCost, std::string observation, Customer user, std::string start, std::string end, Car car) : car(car) {
    //order type: reservation (start is given by parameter)

    bool check = callAllValidationFunctions(car, start, end, "Reservation", user);  //requirement B5: Validations
    if (!check) { status = "Error"; return;}  //order is not created; in Repository class, object will not be added if status == Error

    this->totalCost = totalCost;
    this->observation = observation;
    this->customer = user;
    this->status = "Reservation";
    this->start = start;
    this->end = end;

    ///delete once project is finished:
    //time_t now = time(0);
    //orderDate = localtime(&now);
}

Order::Order(float totalCost, std::string observation, Customer user, std::string start, std::string end, Car car,
             Employee employee1)
        : car(car) {
    //order type: currently active (start equals current time)

    bool check = callAllValidationFunctions(car,start,end,"Order",user);
    if (!check) { status = "Error"; return;}  //order is not created

    this->car = car;
    this->employee = employee1;
    this->totalCost = totalCost;
    this->observation = observation;
    this->customer = user;
    this->status = "Order";
    this->start = start;
    this->end = end;
}
Order::Order(int orderNr, std::string orderDate, std::string start, std::string end, std::string status, std::string carLicensePlate,
      std::string customerEmail, std::string employeeEmail, int totalCost, std::string observation)
{
    this->orderNumber = orderNr; this->orderDate = orderDate; this->start = start; this->end = end; this->status = status;

    CarRepository repo;
    this->car = repo.findByLicensePlate(carLicensePlate);

    CustomerHandlingRepository repoC;
    this->customer = repoC.searchCustomersByEmail(customerEmail)[0];

    EmployeeRepository repoE;
    this->employee = repoE.findEmployeeByString(employeeEmail)[0];


    this->totalCost = totalCost;
    this->observation = observation;
}

void Order::setRepository(std::vector<Order> list) {
    repository = list;
}

void Order::setOrderNr(int nr) {
    orderNumber = nr;
}

int Order::getOrderNr() const {
    return orderNumber;
}

void Order::setOrderDate(std::string time){
    orderDate = time;
}

std::string Order::getOrderDate() {
    return orderDate;
}

void Order::setStart(std::string time) {
    start = time;
}

std::string Order::getStart() {
    return start;
}

void Order::setEnd(std::string time) {
    end = time;
}

std::string Order::getEnd() {
    return end;
}

void Order::setStatus(std::string status) {
    this->status = status;
}

std::string Order::getStatus() {
    return status;
}

void Order::setCar(Car car) {
    this->car = car;
}

Car Order::getCar() {
    return car;
}

void Order::setCustomer(Customer user) {
    this->customer = user;
}

Customer Order::getCustomer() {
    return customer;
}

void Order::setEmployee(Employee employee) {
    this->employee = employee;
}

Employee Order::getEmployee() {
    return employee;
}

void Order::setMoney(float sum) {
    totalCost = sum;
}

float Order::getMoney() {
    return totalCost;
}

void Order::setObservation(std::string observation) {
    this->observation = observation;
}

std::string Order::getObservation() {
    return observation;
}


void Order::writeAll() {
    std::cout<<orderNumber<<" ordered on "<<orderDate<<"; from "<<start<<" until "<<end
             <<" (current status: "<<status<<"), total cost: "<<totalCost<<".\n";  //nu toate detaliile apar
    std::cout<<"Ordered by "<<customer.getName()<<", handled by"<<employee.getSurname()<<"\n";
    std::cout<<"-->Observation: "<<observation<<"\n\n";
}



bool Order::callAllValidationFunctions(Car car, std::string begin, std::string end,
                                       std::string status, Customer user) {
    if (checkIfCarIsAlreadyUsed(car,begin,end)) {std::cout<<"\nError: Car is already used on specified date; cannot create order\n"; return false;}

    if (!checkIfBeginIsSmallerOrEqualEnd(begin,end)) {std::cout<<"\nError: Begin time surpasses end time\n"; return false;}

    if (!userHasLessThanFiveReservations(user,status)) {std::cout<<"\nError: number of reservations cannot exceed 5\n"; return false;}

    orderNumber = determineOrderNumber(repository);

    return true;
}

bool Order::checkIfCarIsAlreadyUsed(Car car, std::string begin, std::string end) {
    for (Order obj: repository)
    {
        if (obj.car.getLicensePlate() == car.getLicensePlate())  //an order has been found using the same car; check if the new order wants to use it in an already occupied time period
            if (end >= obj.start && end <= obj.end || begin <= obj.end && begin >= obj.start)
                return true;  //car is used, cannot create order
    }
    return false;
}

bool Order::checkIfBeginIsSmallerOrEqualEnd(std::string begin, std::string end) {
    if (begin <= end) return true;
    return false;
}

bool Order::userHasLessThanFiveReservations(Customer user, std::string status) {
    if (status != "Reservation") return true;  //order is not a reservation, will not be problematic

    int ct=0;
    for (Order obj: repository)
    {
        if (obj.getCustomer().getEmail() == user.getEmail())  //cant have duplicate emails; users can be identified this way then
            ct++;
    }

    if (ct >= 5) return false;  //cannot make order; user reached maximum amount of reservations

    return true;
}

int Order::determineOrderNumber(std::vector<Order> repository) {
    int maxi = 0;
    for (Order obj: repository)
        if (obj.getOrderNr() > maxi)
            maxi = obj.getOrderNr();

    return maxi + 1;
}



std::string Order::toCSV(){
    std::ostringstream oss;
    oss << this->orderNumber << "," << orderDate << "," <<
        start << "," << end << "," <<
        status << "," << car.getLicensePlate() << "," << customer.getEmail() << "," <<
        employee.getEmail() << "," << totalCost << "," << observation << ",";
}

void Order::fromCSV(const std::string &csvLine) {
    //-->how it is saved in the csv file:
    //orderNr orderDateYear orderDateMonth orderDateDay beginYear beginMonth beginDay endYear endMonth endDay
    //status carLicensePlate customerEmail employeeEmail totalCost observation

    std::istringstream ss(csvLine);

    //std::getline(ss, this->orderNumber, ',');  asa pt stringuri

    ss >> this->orderNumber;      //asa pt int-uri
    ss.ignore(1); // Ignore the comma

    std::getline(ss, this->orderDate, ',');

    std::getline(ss, this->start, ',');

    std::getline(ss, this->end, ',');

    std::getline(ss, this->status, ',');

    std::string  carLiscensePlate = this->car.getLicensePlate();
    std::getline(ss, carLiscensePlate, ',');
    this->car.setLicensePlate(carLiscensePlate);

    std::string customerEmail = this->customer.getEmail();
    std::getline(ss, customerEmail, ',');
    this->customer.setEmail(customerEmail);

    std::string employeeEmail = this->employee.getEmail();
    std::getline(ss,employeeEmail,',');
    this->employee.setEmail(employeeEmail);


    ss >> this->totalCost;
    ss.ignore(1);

    std::getline(ss, this->observation, ',');
}
void Order::displayOrder() {
    std::cout << "Order Number: " << orderNumber << "\n";
    std::cout << "Total Cost: " << totalCost << "\n";
    std::cout << "Observation: " << observation << "\n";
    std::cout << "Customer: " << customer.getName() << ", Contact: " << customer.getPhone() << "\n";
    std::cout << "Order Date: "<< orderDate << "\n"
              << "Start Time: " << start << "\n"
              << "End Time: " << end << "\n";
    std::cout << "Car: " << car.getModel() << " " << car.getModel() << ", Plate: " << car.getLicensePlate() << "\n";
    std::cout << "Employee: " << employee.getName() << ", Position: " << employee.getPosition() << "\n";
    std::cout << "Status: " << status << "\n";
}