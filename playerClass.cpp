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


class playerClass
{

	//variables

	std::string playerName;
	
	int playerRank;
	
	int playerHealth;
	
	double playerXp;
	
	
	
	
	//functions

	
	/*
	Although i'm not sure, i think the purpose of setName is to give a default name in the case of error
	here we have default name defined as a string rebel, 
	in the case that the player does not choose a name they can choose
	the default
	
	*/
	
	
	
	void setName(std::string nameIn)
	{
		std::string defaultName = "Rebel";

		


		playerName == defaultName;
	
	
	
	
	}





	/*
	The purpose of getName is to get a name from user to be used for the rest of the game
	we create a  variable playerName and store the input into that string

	*/


	std::string getName()
	{
		

		std::cout << " Enter your name here:  ";
			std::cin >> playerName;
		
		
		return  playerName;
	
	
	}



	/*
	Not sure about this, again i'm guessing its meant to set a rank for the default player

	i'm having rank be an int, and assuming max rank is ten. 

	*/
	int setRank()
	{
		int defaultRank = 1;

		playerRank = defaultRank;

		return playerRank;
	
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
	int setHealth()
	{
		playerHealth = 100;

		return playerHealth;
		
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
	double setXp()
	{
		playerXp = 0;

		return playerXp;
	
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
}