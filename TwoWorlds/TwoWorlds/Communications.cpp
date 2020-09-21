#include "Communications.h"
#include "Items.h"
#include "Player.h"

#include <iostream>
#include <string>

std::string backStory() {

    std::string Openning{ "Lets go to World far away that was united under one ruling force. This World's Society was ran just like a military comlex. \n" 
        "People still laughed, learned, loved,and lost, but with a strange Order.Art and music excisted, but not as wide of a range as here on Earth. \n" 
        "But that world learned the hard way. That without order chaos rises and as the chaos increases all can comes undone\n" 
        "\n\n\n"
        "Now this world still was like any other intelligent world. Full of wide and diverse group of humaniods and as one can imagine not all fit in to this neat and orderly life \n" 
        "\n\n\n" 
        "Which sadly to say, those who do not function well with the Society ...\n" 
        "They don't do so well*..... (*to keep it PG)\n" 
        "Fast forward about 1000 years into this Society and we come to find out this perfect world, with their control, as created a new chaos.\n" 
        "Some decided that they wanted to be free from that control and order!...That is were you come in..\n" 
        "You are an up and inspiring soldier in this Worlds Society, but...will you stay and bring back 'order' to this World. \n" 
        "Or will you free this World and let 'chaos' bring a new..... the choice is yours... :P \n\n" };
    std::cout << "   Lets go to World far away that was united under one ruling force. This World's Society was ran just like a military comlex.\n" <<
        " People still laughed, learned, loved, and lost, but with a strange Order. Art and music excisted, but not as wide of a range as here on Earth. \n" <<
        "But that world learned the hard way. That without order chaos rises and as the chaos increases all can comes undone\n" <<
        "\n\n\n" <<
        "Now this world still was like any other intelligent world. Full of wide and diverse group of humaniods and as one can imagine not all fit in to this neat and orderly life \n" <<
        "\n\n\n" <<
        "Which sadly to say, those who do not function well with the Society ...\n" <<
        "They don't do so well*..... (*to keep it PG)\n" <<
        "Fast forward about 1000 years into this Society and we come to find out this perfect world, with their control, as created a new chaos.\n" <<
        "Some decided that they wanted to be free from that control and order!...That is were you come in..\n" <<
        "You are an up and inspiring soldier in this Worlds Society, but...will you stay and bring back 'order' to this World. \n" <<
        "Or will you free this World and let 'chaos' bring a new..... the choice is yours... :P \n\n";
    return Openning;
}

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