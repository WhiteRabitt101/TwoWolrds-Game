
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


/*  This file contains the functions not related to the player
* 
* 
The purpose of this class is to define non-player functions within the game
Member variables : name, rank, health, xp
Member functions : 

string Color()
string Numbers()


Special member functions:
 attack
 add rank
 heal another player
/*/


/* Function name : Color
        programmer : Jack Cole
        date : 09 / 28 / 2020

        This is the function that runs the color game

        Return value : string
        */


        
std::string Color(PlayerClass& player)//std::string color_gues)//, std::string color)
{


    std::string Color;
    std::string Color_Gues;
    std::string end = { " \n Wasn't that fun?? :D\n" };

    srand(time(NULL));
    RAND_MAX == 5;

    int rand_Num = rand() % 5;
    while (rand_Num != 0)
    {
        rand_Num = rand() % 5;
        std::cout << rand_Num;

        // color red
        if (rand_Num == 3)
        {
            Color = "Red";
            std::cout << "Okay, One moment please as I think of a color.\n ";
            std::cout << " Got it!! You get three hints: \n 1st\n This is the color often linked with passion, desire, and rage. \t ;) ";
            std::cin >> Color_Gues;
            if (Color_Gues != Color)
            {
                std::cout << "\n two more hints.... \n  2nd \n This color is linked to summer and heat \t X_0 ";
                std::cin >> Color_Gues;
                if (Color != Color_Gues)
                {

                    std::cout << "\nLast hint DUN DUN DUN____\n This color is the same color as Mars in Earths solar system\n";
                    std::cin >> Color_Gues;
                    if (Color_Gues != Color)
                    {
                        std::cout << "\n My friend, the color was Red haha\n\n";
                        return end;
                    }
                }
            }

            if (Color == Color_Gues)
            {
                player.addHealth(5);
                std::cout << "\n Way to go my friend. You got it! :P \n\n";
                return end;
            }
        }



        // color Blue
        if (rand_Num == 1)
        {
            Color = "Blue";
            std::cout << "Okay, One moment please as I think of a color.\n ";
            std::cout << " Got it!! You get three hints: \n 1st\n This color is often linked with cool, and calm \t ~_~ "; // write in hints
            std::cin >> Color_Gues;
            if (Color_Gues != Color)
            {
                std::cout << "\n two more hints.... \n  2nd\n This color is linked to winter, cold, and things that are moist\n";
                std::cin >> Color_Gues;
                if (Color != Color_Gues)
                {

                    std::cout << "\nLast hint DUN DUN DUN____\n It is the color of the planet Neptune in Earths Solar system\n";
                    std::cin >> Color_Gues;
                    if (Color_Gues != Color)
                    {
                        std::cout << "\n My friend, the color was Blue haha\n\n";
                        return end;
                    }
                }

            }
            if (Color == Color_Gues)
            {
                player.addHealth(5);
                std::cout << " Nice! You got it  :)\n\n";
                return end;
            }

        }

        // color yellow
        if (rand_Num == 2)
        {
            Color = "Yellow";
            std::cout << "Okay, One moment please as I think of a color.\n ";
            std::cout << " Got it!! You get three hints: \n 1st\n This color is linked to a small flying creature on Earth that helps plant life. \n "; // write in hints
            std::cin >> Color_Gues;
            if (Color_Gues != Color)
            {
                std::cout << "\n two more hints.... \n 2nd \n This color reminds me of older electric lighting ";
                std::cin >> Color_Gues;
                if (Color != Color_Gues)
                {

                    std::cout << "\nLast hint DUN DUN DUN____\n Red light + Green light = _ _ _ _ _ _ light.. ;)";
                    std::cin >> Color_Gues;
                    if (Color_Gues != Color)
                    {
                        std::cout << "\n My friend, the color was Yellow haha\n\n";
                        return end;
                    }

                }
            }
            if (Color_Gues == Color)
            {
                player.addHealth(5);
                std::cout << "Way to go my friend! Thats correct :)\n\n";
                return end;

            }

        }

        // color green
        if (rand_Num == 4)
        {
            Color = "Green";
            std::cout << "Okay, One moment please as I think of a color.\n ";
            std::cout << " Got it!! You get three hints: \n 1st\n This color is linked to food that kids usually do not enjoy eating  "; // write in hints
            std::cin >> Color_Gues;
            if (Color != Color_Gues)
            {
                std::cout << "\n two more hints.... \n 2nd \n This color has a Earthy feel, but not dirty earthy. Lol ";
                std::cin >> Color_Gues;
                if (Color != Color_Gues)
                {
                    std::cout << "\n Last hint DUN DUN DUN____\n Blue + Yellow = ....";
                    std::cin >> Color_Gues;
                    if (Color != Color_Gues)
                    {
                        std::cout << "\n My friend, the color was Green hahaha\n\n";
                        return end;
                    }

                }
            }
            if (Color == Color_Gues)
            {
                player.addHealth(5);
                std::cout << "Way to go my friend! Thats correct :)";
                return end;
            }


        } // end of 4 = Green

        // color purple
        else if (rand_Num == 5)
        {
            Color = "Purple";
            std::cout << "Okay, One moment please as I think of a color.\n ";
            std::cout << " Got it!! You get three hints: \n 1st\n This color is known in Earths history as a Royal color in some cultures "; // write in hints
            std::cin >> Color_Gues;
            if (Color != Color_Gues)
            {
                std::cout << "\n two more hints.... \n 2nd \n This is the Color of the Crab Nebula\n \t \t Extra hint Think of Prince (Earth musician) \n";
                std::cin >> Color_Gues;
                if (Color != Color_Gues)
                {
                    std::cout << "\n Last hint DUN DUN DUN____\n In American Military, there is a Medal with this name in it\n \t...it does get the Heart ;} \n";
                    std::cin >> Color_Gues;
                    if (Color_Gues != Color)
                    {
                        std::cout << "\n My friend, the color was Purple LOL \n";
                        return end;
                    }

                }
            }
            else if (Color == Color_Gues)
            {
                player.addHealth(5);
                std::cout << "Way to go my friend! Thats correct :D";
                return end;
            }
        }

        std::cout << "\n\nI apologize, but it would seem that you don't have the time. \n";
    }// End While rand_Num != 0 


    return end;
}


/* Function name : Numbers
        programmer : Jack Cole
        date : 09 / 28 / 2020

        This is the function that runs the numbers game

        Return value : string
        */

std::string Numbers(PlayerClass& player)
{

    std::string win{ " Congrats. That was fun!\n" };
    std::string lose{ " Close, but no cigar\n Wasn't that fun?!\n" };
    int num_gues;


    srand(time(NULL));
    RAND_MAX == 10;

    int num = rand() % 5;

    std::cout << " Okay, guess a number 1-10. You get 3 guesses ;P ";
    std::cin >> num_gues;
    int i = 1;
    while (i < 3)
    {

        if (num == num_gues)
        {
            std::cout << "Way to go you got it!\n";
            player.addXp(10);
            std::cout << "xp ++ = " << player.getXP();
            return win;
        }
        i++;
        if (i != 4)
        {
            std::cout << "ehhh, nooo friend. Please try again you got this!\n";
            std::cin >> num_gues;
        }

        else {
            return lose;
        }
    }

    return lose;




}