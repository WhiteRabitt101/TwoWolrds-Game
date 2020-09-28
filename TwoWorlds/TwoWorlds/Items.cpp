#include <iostream>
#include <string>
#include <vector>
#include <time.h> 

#include "Items.h"
#include "Constants.h"
//#include "Player.h"



// setting values of items
    void Items::setItemStats(std::string Name, int power, int w_health)
    {
        //std::string Name;
        //int Power; //dammage that can be delt
        //int wp_health;
        Power = power;
        name = Name;

    };
   Items belt[MAX_ITEMS];
   

    

