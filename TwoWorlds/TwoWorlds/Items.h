#pragma once
#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>
//#include "Player.h"


class Items
{
private:

    std::string name;
    int Power; //dammage that can be delt
    int w_health;

public:

    std::string listItems() { return name; };
    void setItemStats(std::string Name, int power, int w_health);
    std::string getName() { return name; };
    int getDamage() { return Power; };

};


#endif // !ITEMS_H