#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <chrono> // for time + delay

#include <vector>
#include "Items.h"
#include "Player.h"
#include "Communications.h"





//using namespace std;

//prototypes

//bool Game0(double guess );
std::string Color(PlayerClass &player);
void addItem(Items item);
std::string Numbers(PlayerClass &player);
std::string Boss_Conv(PlayerClass &playerOne);
std::string backStory();
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


   
          backStory();

        //Start of Game
   


    std::cout << "Hey you!\n ";
    std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()
        + std::chrono::seconds(2);           
    while (std::chrono::steady_clock::now() < tend)
    {
        std::cout << "\n";
    }
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
            player_One.addHealth(5);

            std::cout << "Xp + 5\n Health +5\n";
        }
        else {

            std::cout << "Dog:\n Hmmmmm...\n";

        };






        //game starter
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
        } // end else


          // Introduction to The Boss
        std::cout << "\nDog:\nEnjoy the meeting with The Boss____\n\n\n";
        
        // Added this to test the addItem function
        std::cout << "Take this Sword";
        player_One.addItem(player_One, belt, Sword);
       
        
        PlayerClass The_Boss;
        The_Boss.setName("The Boss");
        The_Boss.setHealth(100000);
        The_Boss.setXP(999900);

        std::cout << player_One.getName() << ":\n Hello Sir, you summoned me? \n\n";
        std::cout << The_Boss.getName() << ":\n Ahh yes. \n the new recruit " << player_One.getName() << ", have a seat.\n\n";
        Boss_Conv(player_One);

        {

            //just to test Attack function
            std::cout << " Your being attacked!!\n WHAT DO YOU DO??";
            std::cout << "\n1: Attack \n2: Run Away\n";
            std::cin >> choice;

            while(choice = 1)
            {
                int Wp_Choice;
                int i;
                std::cout << "Choose your Weapon: \n";
                for (int i = 0; i < 4 ; i++)
                {
                    std::cout << i << " : " << belt[i].getName() << "\n";
                }
                std::cin >> Wp_Choice;
                if (Wp_Choice == 3)
                {
                    std::cout << "You used a health Potion!\n Health +55\n";
                    player_One.addHealth(55);
                    
                    
                }
                else
                {
                 player_One.Attack(The_Boss, belt[Wp_Choice]);
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


        return 0;
    
}


//Functions 

    // COLOR GUESSING GAME
std::string Color(PlayerClass &player)//std::string color_gues)//, std::string color)
{
    
    
    std::string Color;
    std::string Color_Gues;
    std::string end = { " \n Wasn't that fun?? :D\n" };

    srand(time(NULL));
    RAND_MAX == 5;
 
    int rand_Num = rand() %5 ;
    while(rand_Num != 0)
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


// Numbers Game
std::string Numbers(PlayerClass &player)
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
        if( i != 4 )
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