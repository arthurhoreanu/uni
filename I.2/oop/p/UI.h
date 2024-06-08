//
// Created by Arthur Horeanu on 05.06.2024.
//

#ifndef P_UI_H
#define P_UI_H

#include "Controller.h"

class UI {
    Controller action;
public:
    void console();
    void menu();
    void populateData(Controller &action) const;
    void addProduct();
};



#endif //P_UI_H
