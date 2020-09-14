#pragma once
class PlayerClass
{


private:
	//variables

	std::string playerName;

	int playerRank;

	int playerHealth;

	double playerXp;


public:

	//prototypes

	PlayerClass();

	PlayerClass(std::string nameIn, int rankIn, int healthIn, double xpIn);

	void setName(std::string nameIn);

};