// doctor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


//variables

int playerHealth;
char answer;


//void type function to heal health, may be int type

void hospital(playerHealth)
{
    if (playerHealth < 100)
    {
        playerHealth = playerHealth - 100 + playerHealth;

        std::cout<< "You are restored to " + playerHealth;
    }

    else
    {
        std::cout<<"You are already at full health");
    }

        
}





int main()
{

    //program that should run
    std::cout << "How much health do you have?";
    std::cin >> playerHealth;

    std::cout << "Would you like to go to the doctor? (y/n)";
    std::cin >> answer;
    

    //if loop calling hospital function
    if (answer = 'y')
    {
        hospital(playerHealth);
          
    }

    else
    {
        std::cout << "Well alright then";
    }
    


    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
