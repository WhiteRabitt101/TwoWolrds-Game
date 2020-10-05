#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <chrono> // for time + delay

#include <vector>
#include "Items.h"
#include "Player.h"
#include "Communications.h"
#include "games.h"




//using namespace std;










int main()
{

    double rank;
    char Play;

    int choice;
    std::string name;
    std::string system_Name;




    //creating players
    PlayerClass System_Mang;
    PlayerClass player_One;
    PlayerClass The_Boss("The Boss", 100, 100, 100);


    // Declare Items  Might not go here??
    /*
        // Potions
    Items health_Pot;
    health_Pot.setItemStats("Health Potion", 55, 100);
    // Weapons
    Items Sword;
    Sword.setItemStats("Sword", 33, 100);
    Items Gun;
    Gun.setItemStats("Gun", 66, 100);
    Items Rocket;
    Rocket.setItemStats("Rocket Launcher", 99, 100);
    */




    // Little Background story to paint the picture


    //calls the back story function from Communications

    backStory();



    //Start of Game


    //initial conversation


    starterConvo(player_One, System_Mang);





    //game starter
    colorGameConvo(player_One);


    bossIntroConvo(player_One,The_Boss);


    //Functions 

    // Hoping that the functions already listed call the other "non player" functions 


    return 0;
}


