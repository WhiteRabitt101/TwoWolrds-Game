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


void starterConvo(PlayerClass& player_One, PlayerClass& SystemMan)
{
    std::cout << "Hey you!\n ";
    std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()
        + std::chrono::seconds(2);
    while (std::chrono::steady_clock::now() < tend)
    {
        std::cout << "\n";
    }
    //{

    std::string name;

    std::cout << " Yeah you! What is your name?\n";


    std::cin >> name;
    player_One.setName(name);

    std::cout << "\n Dog:\nIt's a pleasure to meet you. " << player_One.getName() << ",\nThey call me " << SystemMan.getName() << "\n";

    player_One.setRank(1);
    std::cout << "\nDog:" "\nSo you must be the new recruit everyone has been talking about.\n Considering that The Boss wants to see you.\n";
    int reply;
    std::cout << player_One.getName() << ":\n 1: Mind your own buisness \n 2: People are talking about me?\n 3: Look at them and remain silent \n";
    std::cin >> reply;

    if (reply != 1)
    {
        player_One.addXp(5);
        std::cout << SystemMan.getName() << ":\n I Hmm and I can see why. \n";

        std::cout << "\n***Xp+ 5***\n";
    }
    else {
        std::cout << "Dog:\n Hmmmmm...\n";
    };

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
        std::cout << "The Boss:\nI do not like to be ignored...\n ";
    }

    std::cout << "The Boss:\n That will be all. Dismissed\n";
}

void firstFriendConvo(PlayerClass& playerOne, PlayerClass& Friend)
{
    std::cout << "***as you leave The Bosses office, You run into your best and longest friend "<< Friend.getName() <<"***\n\n ";
    std::cout << Friend.getName() << ":\n Hey " << playerOne.getName() << " lets go hit the Recenter and get some training in!!\n";
    playerOne.travelInner();
    //******************************************************************************************************************************************
    //// Testing travelOuter()
    std::cout << Friend.getName() << ":\n OKay I'm bored here lets Leave this base and go to the Ocean OutPost!\n";
    playerOne.travelOuter();
    std::cout << Friend.getName() << ":\n OKay I'm bored here lets Leave this base and go to the the Woods OutPost!\n";
    playerOne.travelOuter();
    //******************************************************************************************************************************************
}

// Beautiful woman convo for Traveling Function

void PlayerClass::meetBeautifulWoman()
{
    PlayerClass Woman("Beautiful Woman", 55, 100, 55, 10000000000);
    int decision;
    std::cout << "*** You bummped into a beautiful woman and spilt her coffee on her!***\n *** What do you do??***\n";
    std::cout << "1: say 'Excuse me , I was just blinded by your radiant beauty!!'\n2: say 'I do apologize! Here let me buy you a new coffee and offer to pay to have your outfit cleaned.\n3: say nothing and just stare at her\n";
    std::cin >> decision;

    if (decision == 1)
    {
        std::cout << Woman.getName() << ":\n'Well aren't you just bold and upfront..'\n'I like that\n";
        std::cout << getName() << ":\n'I bet you do, How about I take you out tonight to make up for it.'";
        std::cout << "*** BLAH BLAH BLAH Romance Romance = Woman becomes your lover which give player unlimited currency***\n";
        addCash(1000000);
        std::cout << "***Cash: " << getCash() << " \n";
        Romance = true;
    }
    else if (decision == 2)
    {
        std::cout << Woman.getName() << ":\n'It's ok! I should have been looking. How about I buy you a coffee instead sweetie?\n ";
        std::cout << "*** BLAH BLAH BLAH Romance Romance = Woman becomes your lover which give player unlimited currency***\n";
        addCash(1000000);
        std::cout << "***Cash: " << getCash() << " \n";
        Romance = true;
    }
    else if (decision == 3)
    {
        std::cout << Woman.getName() << ":\nEXCUSE ME!!! HOW DARE YOU!?!\n";
        // Add Fight funtion here
        std::cout << "***" << Woman.getName() << "walks away and within seconds 10 gaint men appear and beat you to a pulp!***\n *** Manners maketh the man***\n";
        lowerHealth(86);
    }
}
void PlayerClass::meetSironWoman()
{

    PlayerClass Woman("Beautiful Woman", 55, 100, 55, 10000000000);
    int decision;
    
    std::cout << "*** You bummped into a beautiful woman and spilt her coffee on her!***\n *** What do you do??***\n";
    std::cout << "1: say 'Excuse me , I was just blinded by your radiant beauty!!'\n2: say 'I do apologize! Here let me buy you a new coffee and offer to pay to have your outfit cleaned.\n3: say nothing and just stare at her\n";
    std::cin >> decision;

    if (decision == 1)
    {
        std::cout << Woman.getName() << ":\nWell aren't you just bold and upfront.\nI like that\n";
        std::cout << getName() << ":\nI bet you do, How about I take you out tonight to make up for it.\n";
        std::cout << "*** BLAH BLAH BLAH Romance Romance = Woman becomes your...***\n***OH NO!!! She is a Siron and killed YOU***\n";
        lowerHealth(100);
        if (getHealth() <= 0)
        {
            std::cout << "\n*** YOU DIED :( ***\n";
            exit(0);
        }
    }
    else if (decision == 2)
    {
        std::cout << Woman.getName() << ":\n'It's ok! I should have been looking. How about I buy you a coffee instead sweetie?\n ";
        std::cout << "*** BLAH BLAH BLAH Romance Romance = Woman becomes your...***\n***OH NO!!! She is a Siron and killed YOU***\n";
        lowerHealth(100);
        if (getHealth() <= 0)
        {
            std::cout << "\n*** YOU DIED :( ***\n";
            exit(0);
        }

    }
    else if (decision == 3)
    {
        std::cout << Woman.getName() << ":\nEXCUSE ME!!! HOW DARE YOU!?!\n";
        // Add Fight funtion here
        std::cout << "***" << Woman.getName() << "walks away and within seconds 10 gaint men appear and beat you to a pulp!***\n *** Manners maketh the man***\n";
        lowerHealth(86);
    }
}//end SironWoman


/*Function name :starterConvo
programmer : Jack Cole
date:09/28/2020

This function is the first conversation in the program, player states their name and gets health etc
Parameters :
   none.

    Return value : void
    */



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

void bossIntroConvo(PlayerClass& player_One, PlayerClass The_Boss)
{ // Introduction to The Boss


    int choice;

    //vvvvvvvvv RELOCATE vvvvvvvvvvv
    Items Sword("Sword", 10, 100);
    Items Gun("Gun", 56, 100);
    Items Rocket("Rocket Launcher", 51, 100);



    std::cout << "\nDog:\nEnjoy the meeting with The Boss____\n\n\n";

    // Added this to test the addItem function
    std::cout << "Take this Sword..";
    player_One.addItem(Sword);
    std::cout << "\t and this gun..just incase (Dog starts to laugh as you walk away)\n ";
    player_One.addItem(Gun);

    // ^^^^^^^^^^ RELOCATE ^^^^^^^^^^^^^^^


    std::cout << player_One.getName() << ":\n Hello Sir, you summoned me? \n\n";
    std::cout << The_Boss.getName() << ":\n Ahh yes. \n the new recruit " << player_One.getName() << ", have a seat.\n\n";
    Boss_Conv(player_One);
    {
       //player_One.Attack(The_Boss, player_One);
        std::cout << "HOLDD THE SCREEN\n";
    }
} // end Boss Convo

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