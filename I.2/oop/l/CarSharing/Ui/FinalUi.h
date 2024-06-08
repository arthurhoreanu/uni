//
// Created by Darius on 5/28/2024.
//

#ifndef CARSHARINGFINAL_FINALUI_H
#define CARSHARINGFINAL_FINALUI_H

#include "../Models/User.h"
#include "CarUi.h"
#include "EmployeeUi.h"
#include "CustomerHandlingUi.h"
#include "OrderUi.h"

class FinalUi {


private:
    void displayMenuEmployee();
    void handleMenuEmployee();

public:
    void runAll();
};


#endif //CARSHARINGFINAL_FINALUI_H
