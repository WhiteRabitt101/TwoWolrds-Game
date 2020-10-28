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
    // Constructor
    Items();
    Items(std::string nameIn, int powerIn, int w_healthIn);
    std::string listItems() { return name; };
    void setItemStats(std::string Name, int power, int w_health);
    std::string getName() { return name; };
    int getPower() { return Power; };
    int getWeaponHealth() { return w_health;};
   // void setWeaponHealth(int w_health);
    
    void lowerWeaponHealth(int healthIn) { w_health = w_health - healthIn; };
};


#endif // !ITEMS_H