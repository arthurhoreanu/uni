#include "OrderRepository.h"
#include "../Models/User.h"


OrderRepository::OrderRepository(std::string &filename) {
    this->filename = filename;
    orders = readFromCsv();
}


std::vector<Order> OrderRepository::showAllOrdersInASpecificTimeInterval(std::vector<Order> repository, std::string start, std::string end) {
    std::list<Order> orderList;
    for (Order obj: repository)
    {
        if (obj.getStart() >= start && obj.getStart() >= start && obj.getStart() >= start)
            if (obj.getEnd() <= end && obj.getEnd() <= end && obj.getEnd() <= end)
        {
            orderList.push_back(obj);
        }
    }

    orderList.sort(OrderRepository::compareByTotalPrice);

//    std::cout<<"All orders between the date of "<<&start<<" and "<<&end<<":\n";
//    for (Order obj: orderList)
//    {
//        std::cout<<obj.getOrderNr()<<": price-"<<obj.getMoney()<<", car-"<<obj.getCar().getBrand()<<", customer-"<<obj.getCustomer().getSurname()<<", employee-"<<obj.getEmployee().getSurname();
//    }
    return convertListToVector(orderList);
}


void OrderRepository::totalSumOfATimeInterval(std::vector<Order> repository, std::string time, std::string type) { //type: either month or year
    //YYYY/MM/DD


    if (type == "month")
        for (Order obj: repository)
        {
            string c1(1, obj.getStart()[5]), c2(1, obj.getStart()[6]);
            //c1 + c2 is the month of the start date  (format: YYYY/MM/DD)
            string c3(1, obj.getEnd()[5]), c4(1, obj.getEnd()[6]);
            //c3 + c4 is the month of the end date (format: YYYY/MM/DD)
            if ((c1+c2) <= time && (c3+c4) >= time) //if the month is included in the order's time interval
                std::cout << obj.getOrderNr() << ": price-" << obj.getMoney() << ", car-" << obj.getCar().getBrand() << ", customer-" << obj.getCustomer().getSurname() << ", employee-" << obj.getEmployee().getSurname();
        }
    else
        for (Order obj: repository)
        {
            string c1(1, obj.getStart()[0]), c2(1, obj.getStart()[1]), c3(1, obj.getStart()[2]), c4(1, obj.getStart()[3]);
            //c1 + c2 is the year of the start (format: YYYY/MM/DD)
            string c5(1, obj.getEnd()[0]), c6(1, obj.getEnd()[1]), c7(1, obj.getEnd()[2]), c8(1, obj.getEnd()[3]);
            //c3 + c4 is the year of the end (format: YYYY/MM/DD)
            if ((c1+c2+c3+c4) >= time && (c5+c6+c7+c8) <= time) //if the order time is included in the given year
                std::cout<<obj.getOrderNr()<<": price-"<<obj.getMoney()<<", car-"<<obj.getCar().getBrand()<<", user-"<<obj.getCustomer().getSurname()<<", employee-"<<obj.getEmployee().getSurname();

        }
}


void OrderRepository::saveOrder(Order obj) const {
    //read all current orders into a list, add the new object to the list, then save the new list
    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        repo.push_back(obj1);
    }
    f.close();
    repo.push_back(obj);


    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (auto &obj1 : repo) {
        g << obj1.toCSV() << std::endl;
    }

    g.close();
}

void OrderRepository::deleteOrder(Order obj) {
    //read all current orders into a list, except for the one we want to remove
    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        if (obj1.getOrderNr() != obj.getOrderNr())
            repo.push_back(obj1);
    }
    f.close();

    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (auto &obj1 : repo) {
        g << obj1.toCSV() << std::endl;
    }

    g.close();
}


void OrderRepository::updateOrder(Order obj) {
    //read all current orders into a list, except for the one, which will be replaced by the updated version

    /*int orderNr1; tm* orderDate1, begin1,end1; std::string status1;
    std::string carLicensePlate1; int customerID1, employeeID1;
    float totalCost1; std::string observation1;*/  //partea asta creca vine in UI sau Controller
    //(si se da ca parametru obiectul nou cu acelasi ID ca inainte)

    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        if (obj1.getOrderNr() != obj.getOrderNr())
            repo.push_back(obj1);
        else
            repo.push_back(obj);
    }
    f.close();

    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (auto &obj1 : repo) {
        g << obj1.toCSV() << std::endl;
    }

    g.close();
}

//B.3

void OrderRepository::removeReservation(int orderNr) {

    std::vector<Order> copy;
    for (Order obj: orders)
    {
        if (obj.getOrderNr() != orderNr)
            copy.push_back(obj);
    }
    orders = copy;

    writeToCsv();
}



//B.3.3
void OrderRepository::changeReservation(Order newReservation) {
    std::vector<Order> copy;
    for (Order obj: orders)
    {
        if (obj.getOrderNr() != newReservation.getOrderNr())
            copy.push_back(obj);
        else
        {
            copy.push_back(newReservation);
        }
    }
    orders = copy;

    writeToCsv();
}
std::vector<Order> OrderRepository::listAllOrders() const {
    std::ifstream f(filename);
    std::list<Order> orders;

    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        orders.push_back(obj1);
    }
    f.close();

    return convertListToVector(orders);
}

Order OrderRepository::searchOrder(int orderID) {
    std::ifstream f(filename);

    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);

        if (obj1.getOrderNr() == orderID)
            return obj1;
    }
    f.close();
    std::cout<<"Error: object does not exist";
}


std::vector<Order> OrderRepository::convertListToVector(std::list<Order> &repo) {
    std::vector<Order> newRepo;
    for (Order obj: repo)
        newRepo.push_back(obj);
    return newRepo;
}



std::vector<Order> OrderRepository::readFromCsv() {
    orders.clear();
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Parse each line and create Customer objects
            // Assuming your CSV format is comma-separated
            //
            //
            std::stringstream ss(line);
            std::string orderNr, orderDate, beginDate, endDate, status, carLicensePlate,
            customerEmail, employeeEmail, totalCost, observation;

            std::getline(ss, orderNr, ',');
            int orderNrInt = std::stoi(orderNr);
            std::getline(ss, orderDate, ',');
            std::getline(ss, beginDate, ',');
            std::getline(ss, endDate, ',');
            std::getline(ss, status, ',');
            std::getline(ss, carLicensePlate, ',');
            std::getline(ss, customerEmail, ',');
            std::getline(ss, employeeEmail, ',');
            std::getline(ss, totalCost, ',');
            float totalCostFloat = std::stof(totalCost);
            std::getline(ss, observation, ',');


            orders.emplace_back(orderNrInt, orderDate, beginDate, endDate, status, carLicensePlate,
                                customerEmail, employeeEmail, totalCostFloat, observation);

        }
        file.close();
        return orders;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

}

void OrderRepository::writeToCsv() {

//int orderNr, std::string orderDate, std::string start, std::string end, std::string status, std::string carLicensePlate,
//          std::string customerEmail, std::string employeeEmail, int totalCost, std::string observation
    std::ofstream file(filename);
    if (file.is_open()) {
        for (Order &customer: orders) {
            // Write each customer's data in CSV format
            file << customer.getOrderNr() << ","
                 << customer.getOrderDate() << ","
                 << customer.getStart() << ","
                 << customer.getEnd() << ","
                 << customer.getStatus() << ","
                 << customer.getCar().getLicensePlate() << ","
                 << customer.getCustomer().getEmail() << ","
                 << customer.getEmployee().getEmail() << ","
                 << customer.getMoney() << ","
                 << customer.getObservation() << ","
                 <<  std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}