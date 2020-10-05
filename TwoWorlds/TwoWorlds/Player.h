#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Items.h"
#include "Constants.h"

class PlayerClass
{


private:
	//variables

	std::string playerName;

	int playerRank;

	int playerHealth;

	double playerXp;

	

public:

	Items belt[MAX_ITEMS];


	//prototypes

	PlayerClass();

	PlayerClass(std::string nameIn, int rankIn, int healthIn, double xpIn);

	void setName(std::string nameIn) { playerName = nameIn; };
	std::string getName() { return  playerName; };

	void IncreaseRank(int rankIn) { playerRank = playerRank + rankIn; };
	int getRank() { return playerRank; }

	void setXP(int XP) { playerXp = XP; };
	double getXP() { return playerXp; };
	void setRank(int xpIn) { playerXp = xpIn; };
	void addXp(int xpIn) { playerXp = playerXp + xpIn; };

	void setHealth(int Health) { playerHealth = Health; }
	int getHealth() { return playerHealth; };
	void addHealth(int healthIn) { playerHealth = playerHealth + healthIn; };
	void lowerHealth(int healthin) { playerHealth = playerHealth - healthin; };

	void addItem(Items item);
	void listItems(Items belt[]);


	void Attack(PlayerClass& Op);
	/*
* Meant to allow you to check
* your info, in this case i just made a print statement
*/

	void printPlayerInfo()
	{
		std::cout << "Your current health is:  " << playerHealth;
		std::cout << "Your current rank is:   " << playerRank;
		std::cout << "Your current experience points equal:  " << playerXp;


	}
};

#endif