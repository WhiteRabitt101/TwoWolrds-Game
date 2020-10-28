#include <iostream>
#include <string>
#include <vector>
#include <time.h> 

#include "Items.h"
#include "Constants.h"
//#include "Player.h"

// Item Constructors
Items::Items()
{
    name = "empty";
    Power = 0;
    w_health = 0;
}

Items::Items(std::string nameIn, int powerIn, int w_healthIn)
{
    name = nameIn;
    Power = powerIn;
    w_health = w_healthIn;
}

/*
Items Sword("Sword", 15, 100);

Items Gun("Gun", 56, 100);
// Gun.setItemStats("Gun", 25, 100);
Items Rocket("Rocket Launcher", 51, 100);
    
    Not Workinging here
*/


// setting values of items
void Items::setItemStats(std::string Name, int power, int w_health)
{
    //std::string Name;
    //int Power; //dammage that can be delt
    //int wp_health;
    Power = power;
    name = Name;

};
//Items belt[MAX_ITEMS];