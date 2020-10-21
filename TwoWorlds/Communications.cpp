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


/*  This file contains the communications program
The purpose of this class is to store communication functions for various dialouge
Member variables : name, rank, health, xp
Member functions : constructors(initialization),
void setName(string nameIn);
string getName() const;

void printPlayerInfo() const;
*/


 /*Function name : Backstory
programmer : Jack Cole
date:09/28/2020

This function is the backstory of the game, basically it reads in a txt file when the program initially runs. 
Parameters :
   none.

    Return value : string
    */


void backStory()
{
    std::string String;
    std::ifstream inFile;

    inFile.open("TwoWorldsIntro.txt");

    if (!inFile) {
        std::cerr << "unable to open TwoWorldsIntro.txt";
        exit(1);
    }

    while (inFile.eof())
    {
        getline(inFile, String);
        std::cout << String;
    }
    inFile.close();

}

/*Function name : Boss_Conv
programmer : Jack Cole
date:09/28/2020

This function is the boss conversation, it determines what path you'll be taking in the game.
Parameters :
   none.

    Return value : string
    */

std::string Boss_Conv(PlayerClass& playerOne)
{

    std::string Light_path{ "The Boss:\nYou better watch your self!\n" };
    std::string Dark_path{ "The Boss:\nYour right it would be! I take care of my people. \nAs long as they fall in line of course..\n" };
    std::string Neutral_path{ "The Boss:\nTaking it all in I see, I like that.\n" };
    int reply;


    std::cout << playerOne.getName() << " I hear your exelling quite fast compaired to your commrads.\n If you keep it up, you might get promoted to one of my inner circles\n\n";
    std::cout << "1: ""Laugh out loud""\n" << "2: ""Thank you Sir! That would be a major honor!""\n" << "3: ""sit in silience""\n";
    std::cin >> reply;
    if (reply = 1)
    {
        playerOne.addXp(10);
        playerOne.lowerHealth(69);
        std::cout << Light_path;
        std::cout << "health = " << playerOne.getHealth() << "\n";
        std::cout << "xp ++ = " << playerOne.getXP();
        return Light_path;
    }
    else if (reply = 2)
    {
        playerOne.addXp(10);
        std::cout << Dark_path;
        std::cout << "\n \n xp ++ = " << playerOne.getXP();
        return Dark_path;
    }
    else if (reply = 3)
    {
        playerOne.addHealth(10);
        playerOne.addXp(5);
        std::cout << Neutral_path;
        return Neutral_path;
    }
    else {
        std::cout << "I do not like to be ignored   \n ";


    }
}

/*Function name :starterConvo
programmer : Jack Cole
date:09/28/2020

This function is the first conversation in the program, player states their name and gets health etc
Parameters :
   none.

    Return value : void
    */


void starterConvo(PlayerClass & player_One,PlayerClass & System_Mang )
/*{
std::cout << "Hey you!\n ";
std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()
+ std::chrono::seconds(2);
while (std::chrono::steady_clock::now() < tend)
{
    std::cout << "\n";
}
*/ {

    std::string name;

std::cout << " Yeah you! What is your name?\n";


std::cin >> name;
player_One.setName(name);

//  System says Hello
System_Mang.setName("Dog");
System_Mang.addHealth(1000000000);
System_Mang.addXp(1000000000);
std::cout << player_One.getName() << "\n Dog:\n it's a pleasure to meet you.\n They call me " << System_Mang.getName() << "\n";


//  Ask rank
// would like to add a "pause", but so far couldn't get it to work


player_One.setRank(1);
std::cout << "\nDog:" "\nSo you must be the new recruit everyone has been talking about.\n Considering that The Boss wants to see you.\n";
int reply;
std::cout << player_One.getName() << ":\n 1: Mind your own buisness \n 2: People are talking about me?\n 3: Look at them and remain silent \n";
std::cin >> reply;

if (reply != 1)
{
    player_One.addXp(5);
   

    std::cout << "Xp + 5\n Health +5\n";
}
else {

    std::cout << "Dog:\n Hmmmmm...\n";

};



}

/*Function name : colorGameConvo
programmer : Jack Cole
date:09/28/2020

This function is a game used to kill time before the initial boss fight
Parameters :
   none.

    Return value : string
    */

void colorGameConvo(PlayerClass& player_One )
{
    char Play;
    int choice;

    std::cout << "So\n " << player_One.getName();
    // add "pause"
    std::cout << " Would you like to play a game while we wait for the Boss?? (Y/N)\n";
    std::cin >> Play;
    while (Play != 'Y' && Play != 'y' && Play != 'N' && Play != 'n' && Play != 'L' && Play != 'l')
    {
        std::cout << "Come on now " << player_One.getName() << " how can you be The One everyone is whispering about if you can't even follow directions? haha\n";
        std::cout << " Simple ""Y"" for Yes, or ""N"" for No (Y/N)\n";
        std::cin >> Play;
    }
    while (Play == 'L' || Play == 'l')
    {
        // Just playing by adding a little "Bug" 
        // Might limit it to an output of 15000 with "for(int i=0;i>15000;i++){  };
        std::cout << """L"" = I'll LOVE YOU TOOOO DEATH!!!!!! \t ";

    }

    if (Play == 'Y' || Play == 'y')
    {

        std::cout << "\n\n";
        std::cout << "Sweeett ;D\n What would you like to play? \n";


        //Game initz
        std::string game_Choice[3] = { "Color ", "Guessing ", "Higher or Lower" };



        for (int i = 0; i < 3; i++) {
            std::cout << i << " = " << game_Choice[i];
        }
        std::cin >> choice;

        std::cout << "Okay! Let's play " << game_Choice[choice] << "\n \n";


        // color game
        if (choice == 0)
        {
            std::cout << Color(player_One);
        }

        // Number game

        if (choice == 1)
        {
            std::cout << Numbers(player_One);
        }
        player_One.addXp(10);// xp bonus for playing gaem
    } // End Playing Game

      // Choicing to Not Play a Game
    else {
        int z = 1;
        int i = 0;
        while (i < z)
        {
            i++;
            z++;
            std::cout << " \t Well this is going to be a long wait\n";
            if (z == 350)
            {
                i = z;
            }
        }
    } // end else}
}

 /* Function name : bossIntroConvo
        programmer : Jack Cole
        date : 09 / 28 / 2020

        This function is the inital meeting with the boss, at present we are using this scenario to test the attack function
        Parameters :
    none.

        Return value : string
        */

void bossIntroConvo(PlayerClass& player_One, PlayerClass The_Boss )
{ // Introduction to The Boss


    int choice;

    Items Sword;
    Sword.setItemStats("Sword", 10, 100);

    std::cout << "\nDog:\nEnjoy the meeting with The Boss____\n\n\n";

    // Added this to test the addItem function
    std::cout << "Take this Sword";
    player_One.addItem(Sword);


    

    std::cout << player_One.getName() << ":\n Hello Sir, you summoned me? \n\n";
    std::cout << The_Boss.getName() << ":\n Ahh yes. \n the new recruit " << player_One.getName() << ", have a seat.\n\n";
    Boss_Conv(player_One);

    {

        //just to test Attack function
        std::cout << " Your being attacked!!\n WHAT DO YOU DO??";
        std::cout << "\n1: Attack \n2: Run Away\n";
        std::cin >> choice;

        while (choice = 1)
        {
            int Wp_Choice;
            int i;
            std::cout << "Choose your Weapon: \n";
            for (int i = 0; i < 4; i++)
            {
                std::cout << i << " : " << player_One.belt[i].getName() << "\n";
            }
            std::cin >> Wp_Choice;
            if (Wp_Choice == 3)
            {
                std::cout << "You used a health Potion!\n Health +55\n";
                player_One.addHealth(55);


            }
            else
            {
                player_One.Attack(The_Boss);
            }
            std::cout << "\n Would you like to attack again?\n";
            std::cin >> choice;



            // Attack(player_One, The_Boss, belt[i]);
        }
        if (choice == 2)
        {
            std::cout << "/n RUNN FOREST RUNN!!!\n";
        }

        std::cout << "HOLDD THE SCREEN\n";

    }


    

}

/* Function name : oldBossConvo
        programmer : Jack Cole
        date : 09 / 28 / 2020

        This function is the first boss conversations and is being saved for reference. 
        Parameters :
    none.

        Return value : string
        */

        //old boss convo senerio
        /*  // MOVING TO COMMUNICATIONS.CPP :)
        //add PLayer to param
        std::string Boss_Conv( PlayerClass &playerOne)
        {

            std::string Light_path{ "The Boss:\nYou better watch your self!\n" };
            std::string Dark_path{ "The Boss:\nYour right it would be! I take care of my people. \nAs long as they fall in line of course..\n" };
            std::string Neutral_path{ "The Boss:\nTaking it all in I see, I like that.\n" };
            int reply;


            std::cout << playerOne.getName() << " I hear your exelling quite fast compaired to your commrads.\n If you keep it up, you might get promoted to one of my inner circles\n\n";
            std::cout << "1: ""Laugh out loud""\n" << "2: ""Thank you Sir! That would be a major honor!""\n" << "3: ""sit in silience""\n";
            std::cin >> reply;
            if (reply == 1)
            {
                playerOne.addXp(10);
                playerOne.lowerHealth(69);
                std::cout << Light_path;
                std::cout << "health = " << playerOne.getHealth() << "\n";
                std::cout << "xp ++ = " << playerOne.getXP();
                return Light_path;
            }
            else if (reply == 2)
            {
                playerOne.addXp(10);
                std::cout << Dark_path;
                std::cout << "\n \n xp ++ = " << playerOne.getXP();
                return Dark_path;
            }
            else if (reply == 3)
            {
                playerOne.addHealth(10);
                playerOne.addXp(5);
                std::cout << Neutral_path;
                return Neutral_path;
            }
            else {
                std::cout << "I do not like to be ignored   \n ";


            }


        }
        */