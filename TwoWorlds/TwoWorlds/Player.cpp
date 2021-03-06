/*  This file contains the playerClass
The purpose of this class is to define player functions within the game
Member variables : name, rank, health, xp
Member functions : constructors(initialization),
void setName(string nameIn);
string getName() const;
setRank, getRank, setHealth, getHealth, setXp, getXp,
void printPlayerInfo() const;
Special member functions:
 attack
 add rank
 heal another player
/*/
#include <ostream>
#include <iostream>
#include <string>
#include "Player.h"
#include "Items.h"
#include <chrono>
#include <stdlib.h>  // for the random



//constructors

PlayerClass::PlayerClass()
{
    playerName = "John";
    playerRank = 1;
    playerHealth = 100;
    playerXp = 0;
}

PlayerClass::PlayerClass(std::string nameIn, int rankIn, int healthIn, double xpIn)
{
    playerName = nameIn;
    playerRank = rankIn;
    playerHealth = healthIn;
    playerXp = xpIn;
}

//functions

// Add Item to Belt
void PlayerClass::addItem(Items item) {
    // add items to players belt
    belt[1] = item;
    std::cout << " \nAdded " << item.getName() << " to belt\n";







}

void PlayerClass::listItems(Items belt[])
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        std::cout << i << " : " << &belt[i] << "\n";
    }
}





//   ATTACK FUNCTION 
void PlayerClass::Attack(PlayerClass& Op)
{
    int damage;
    int choice;
    bool bOpIsAlive = true;
    //int* dam_ptr{ &damage };

    std::cout << " Your being attacked!!\n WHAT DO YOU DO??";
    std::cout << "\n1: Attack \n2: Run Away\n";
    std::cin >> choice;
    while (choice == 1 && bOpIsAlive)
    {

        int Wp_Choice;
        std::cout << "Choose your Weapon: \n";
        for (int i = 0; i < 4; i++)
        {
            std::cout << i << " : " << belt[i].listItems() << "\n";
        }

        std::cin >> Wp_Choice;
        damage = belt[Wp_Choice].getDamage(); // gets the damage of choosen weapon


        srand(time(NULL));
        RAND_MAX == damage;
        int rand_num = rand() % damage;


        //Op.getHealth();   might not need

      //  int Op_Health = Op.getHealth(); might not need
        std::cout << Op.getName() << " health : " << Op.getHealth() << "\n";

        if (Op.getHealth() >= 0)
        {
            //Op_Health = Op_Health - Weapons.wp_damage(33);

            Op.lowerHealth(rand_num);
            if (Op.playerHealth < 0)
            {
                bOpIsAlive = false;
                std::cout << "Opponent is defeated \n ";
            }
            else
            {
                std::cout << Op.getName() << "'s " << " health: "; // to test 
                std::cout << Op.getHealth() << "\n\n"; // to test 
                std::cout << " Would you like to attack again or run??";
                std::cout << "\n1: Attack \n2: Run Away\n";
                std::cin >> choice;
            }
        }

        else {

            addXp(10);
            std::cout << "You defeated " << Op.getName();

        }
        if (choice == 2)
        {
            std::cout << "/n RUNN FOREST RUNN!!!\n";
        }
    } // end while (choice == 1)
}


/*
Although i'm not sure, i think the purpose of setName is to give a default name in the case of error
here we have default name defined as a string rebel,
in the case that the player does not choose a name they can choose
the default
*/







/*
The purpose of getName is to get a name from user to be used for the rest of the game
we create a  variable playerName and store the input into that string
*/





/*
Not sure about this, again i'm guessing its meant to set a rank for the default player
i'm having rank be an int, and assuming max rank is ten.
*/



/*
I dont know where were storing the data for Rank when it changes
so for now just return playerRank
*/




/*
I'm just setting a way to revert health back to a default,
i'm assuming default health is 100
*/


/*
A function to return the current health
*/




/*
default experience points
setting it to 0
assuming its a double
*/

/*
* returning whatever the current value of playerXp is
*
*/
/*
double getXp()
{
    return playerXp;
}
*/