#pragma once
#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H
#include <string>
#include <iostream>

#include "Player.h"

//contains protypes for the communications cpp functions







	void backStory();
	std::string Boss_Conv(PlayerClass& playerOne);
	void starterConvo(PlayerClass& player_One, PlayerClass& System_Mang);
	void colorGameConvo(PlayerClass& player_One);
	void bossIntroConvo(PlayerClass& player_One,PlayerClass The_Boss);
	void firstFriendConvo(PlayerClass& player_One, PlayerClass& Friend);

	
#endif