#include <iostream>

/*
 * Prototype for a vehicle.
 */

class Vehicle {
    int buildYear;
};

bool isRegistered(Vehicle vehicle){
    return true;
}

/*
 * Return value will be used by the OS.
 * 0: Ok
 * !=0: Error
 */

int main() {
    Vehicle myCar;
   std::cout << isRegistered(myCar);
    return 0;
}