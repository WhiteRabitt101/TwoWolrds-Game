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
#include <chrono>
#include <stdlib.h>  // for the random

#include "Communications.h"
#include "Player.h"
#include "Items.h"

//constructors

PlayerClass::PlayerClass()
{
    playerName = "John";
    playerRank = 1;
    playerHealth = 100;
    playerXp = 0;
    playerCash = 10;
}

PlayerClass::PlayerClass(std::string nameIn, int rankIn, int healthIn, double xpIn, int cashIn)
{
    playerName = nameIn;
    playerRank = rankIn;
    playerHealth = healthIn;
    playerXp = xpIn;
    playerCash = cashIn;
}

//functions

// Add Item to Belt
void PlayerClass::addItem(Items itemIn) {
    // add items to players belt
    bool placed = false;
    
    for(int i = 0; i<MAX_ITEMS; i++)
    {
        if(belt[i].getPower() ==0 && !placed)
        {
            belt[i] = itemIn;
            placed = true;
        }
    }
    std::cout << " \n***Added " << itemIn.getName() << " to belt***\n";
}

// Shows Items On Belt
void PlayerClass::listItemsOnBelt()
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if(belt[i].getWeaponHealth()  !=0)// this is testing if weapon is "Broken" /0 health
        {
            std::cout << i << " : " << belt[i].getName()  << "\n";
        }
     }
}

//**************************************************************************************************************************************************



//**************************************************************************************************************************************************

//   Wanting to add A fight sequence where the oppenenr does damage to player

int PlayerClass::CalcOpDamageToPlayer(PlayerClass& Op) 
{
    int damageDelt;
    
    srand(time(NULL));
    int randNum = 1; // rand() % 2;*************************************************
    if(randNum==1)
    {
        damageDelt = Op.getRank() - getRank();
        std::cout << "*** Your Health is: " << getHealth() << "***\n";
    }
    else {
        damageDelt = 0;
        std::cout << "***You evaded " << Op.getName() << "'s attack!***\n";
    }
    return damageDelt;
}


//   ATTACK FUNCTION 
void PlayerClass::Attack(PlayerClass& Op)
{
    int damage;
    int choice;
    bool bOpIsAlive = true;
    
    std::cout << "*** Your being attacked!!**\n*** WHAT DO YOU DO??";
    std::cout << "\n1: Attack \n2: Run Away\n";
    std::cin >> choice;
    while (choice == 1 && bOpIsAlive)
    {
       int Wp_Choice;
        std::cout << "Choose your Weapon: \n";

       listItemsOnBelt(); // lists items on belt
        std::cin >> Wp_Choice;

        damage = belt[Wp_Choice].getPower(); // gets the damage of choosen weapon


        srand(time(NULL));
       
        int rand_num = rand() % damage;


        //      std::cout << Op.getName() << "health : " << Op.getHealth() << "\n";

      //   rand_num = 0; // ADDED 4 TESTING ONLY

        if (Op.getHealth() >= 0)
        {
            if (rand_num != 0)
            {
                Op.lowerHealth(rand_num);
                belt[Wp_Choice].lowerWeaponHealth(1);
            }
            else { std::cout << "\n***" << Op.getName() << " evaded your attack!***\n"; }

            if (Op.playerHealth < 0)
            {
                bOpIsAlive = false;
                std::cout << "***" << Op.getName() << " is defeated!!! ***\n ";
            }
            else
            {
                std::cout << "***" << Op.getName() << "'s " << " health: " << "***"; // to test 
                std::cout << Op.getHealth() << "***\n\n"; // to test 
            }
            // This is the part where the oppenent attacks the player
            damage = CalcOpDamageToPlayer(Op);
            lowerHealth(damage);
            if (getHealth() <= 0)
            {
                std::cout << "\n*** YOU DIED :( ***\n";
                exit(0);
            }
           
            if (Op.getHealth() != 0)
            {
               std::cout << " Would you like to attack again or run??";
               std::cout << "\n1: Attack \n2: Run Away\n";
               std::cin >> choice;
            }                 
        }//end Op alive/might be alive ha

        else {

            addXp(10);
            std::cout << "You defeated " << Op.getName() << "!!!!";

        }
        if (choice == 2)
        {
            std::cout << "/n RUNN FOREST RUNN!!!\n";
        }
    } // end while (choice == 1)
}

void PlayerClass::travelOuter()
{

    std::cout << "*** Traveling***\n";
    std::cout << "*** Traveling***\n";
    srand(time(NULL));
    int randSitch = rand() % 6;

    if (randSitch == 1)
    {
        std::cout << "\n*** OHH NOO!! BANDITS!!***\n";
        int randFightersCount = rand() % 6; // This randomizes the number of bandits Player has to fight
        std::cout << "*** Looks like " << randFightersCount << " of them!***\n";
        for (int i =0; i <= randFightersCount; i++)
        {
           
            PlayerClass Bandit("Bandit", 6, 100, 1, 0);
            if (i == randFightersCount)// Gotta fight a Boss at the end, you know?
            {

                PlayerClass BanditLeader("Bandit Leader", 10, 100, 1, 0);
                std::cout << "*** Looks like all thats left is " << BanditLeader.getName() << " ***\n";
                Attack(BanditLeader);
            }
            else
            {
              Attack(Bandit);
            }
        }
    }//end if(bandits)
    else if (randSitch == 3)
    {
        int randTreasure = rand() % 200;
        std::cout << "\n*** Lucky day!! You found some treasure!!***\n";
        addCash(randTreasure);
        std::cout << "*** " << getCash() << " has been added to your cash***\n ";
    }
    else if (randSitch == 6)
    {
        Items LegendaySword("Legendary Sword of Anubus", 120, 10); // since overpowered, lower health
        addItem(LegendaySword);
    }
    else if (randSitch == 0 || randSitch == 5 || randSitch == 4 || randSitch == 2)
    {
        std::cout << "\n***You've made it to your destination with nothing exciting happening..this time***\n";
    }

}// end travelOuter
void PlayerClass::travelInner()
{
    std::cout << "\n\n*** Traveling***\n";
    std::cout << "*** Traveling***\n\n\n";
    srand(time(NULL));
    
   //int randSenerio = 1; // for testing **************************************************************************
   int randSenerio = rand() % 5;//******************************************************************************
    if (randSenerio == 1)
    {
        PlayerClass Mugger("Mugger", 10, 100, 1,0);
        std::cout << "*** OH NO!! Your being mugged!!*** \n ";
        Attack(Mugger);
    }
    else if (randSenerio == 2)
    {
        meetBeautifulWoman();
        
    }
    else if (randSenerio == 3)
    {
        meetSironWoman();
    }
    else if (randSenerio == 4)
    {
        std::cout << "\n***Lucky day!! You found some money!!***\n";
        addCash(rand()%50);
        std::cout << "Cash:" <<getCash()<<"\n";
    }
}


