#include <iostream>
#include <string>
#include <vector>


//attack sequence


//variables
char choice;

int enemyHealth;
int playerHealth;
class Player
{
	double health = 100;
}

class Enemy;
{
	double health = 100;
}


int attackSeq()
{
	while (enemyHealth && playerHealth > 100)
	{
		std::cout >> "Would you like to attack?/n enter y for yes or n for no"
		{
			char combat;
			if (combat = 'y')
			{
				enemyHealth - 40;
				if (enemyHealth > 0)
				{
					std::cout >> "Would you like to attack again?/n enter y for yes or n for no";
					char attackAgain;
					if (attackAgain = 'y')
					{
						enemyHealth - 40;

					}

					else if (attackAgain = 'n')
					{
						std::cout >> "Would you like to run away?/n enter y for yes or n for no";
						char flee;
						if (flee = 'y')
						{
							std::cout >> "You ran away!";
							return 0; //exit loop
						}
						else if (flee = 'n')
						{
							return 0;
						}

					}
					else
					{
						std::cout >> "Sorry i didnt get that. "
					}
			

				}
				
			}
			else if (combat = 'n')
			{
				std::cout >> "Would you like to run away?/n enter y for yes or n for no";
				char flee;
				if (flee = 'y')
				{
					std::cout >> "You ran away!";
					return 0; //exit loop
				}
				else if (flee = 'n')
				{
					return 0;
				}
			
			
			

			}

		}
			
	}

}


int main()
{
	std::cout << "You are being attacked! What would you like to do? /n f = fight, e = escape";
	std::cin >> choice;
	{
		if (choice = 'f')
		{
			attackSeq();
		}

		else if (choice = 'e')
		{
			std::cout << "You ran away!";

		}

		else
		{
			std::cout << "Sorry, I didnt get that.";
		}
	}

	return 0;

}