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

#include <iostream>
#include <string>


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

	
	/*
	Although i'm not sure, i think the purpose of setName is to give a default name in the case of error
	here we have default name defined as a string rebel, 
	in the case that the player does not choose a name they can choose
	the default
	
	*/
	
	
	
	void PlayerClass::setName(std::string nameIn)
	{
		playerName = nameIn;
	}





	/*
	The purpose of getName is to get a name from user to be used for the rest of the game
	we create a  variable playerName and store the input into that string

	*/


	std::string getName()
	{
		return  playerName;
	}



	/*
	Not sure about this, again i'm guessing its meant to set a rank for the default player

	i'm having rank be an int, and assuming max rank is ten. 

	*/
	int setRank()
	{
		playerRank = rankIn;
	
	}



	/*
	I dont know where were storing the data for Rank when it changes

	so for now just return playerRank

	*/
	int getRank()
	{
		return playerRank;
	}




	/*
	I'm just setting a way to revert health back to a default, 

	i'm assuming default health is 100


	
	*/
	void setHealth(int healthIn)
	{
		playerHealth = healthIn;
		
	}

	/*
	
	A function to return the current health
	
	*/

	int getHealth()
	{
		return playerHealth;

	}


	/*
	default experience points

	setting it to 0

	assuming its a double
	*/
	int setXp()
	{
		playerXp = xpIn;
	
	}
	/*
	* returning whatever the current value of playerXp is
	* 
	*/

	double getXp()
	{
		return playerXp;
	
	}


	/*
	* Meant to allow you to check
	* your info, in this case i just made a print statement
	*/

	void playerInfo()
	{
		std::cout << "Your current health is:  " + playerHealth;
		std::cout << "Your current rank is:   " + playerRank;
		std::cout << "Your current experience points equal:  " + playerXp;
	
	
	}
