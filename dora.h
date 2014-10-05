#ifndef __DORA_H__
#define __DORA_H__

#include <iostream>
#include <string>
#include "human.h"
#include "monster.h"

using namespace std;

//Exploring Maze Game using the Leap Motion

class DoraGame {

	private:
		int dice_roll; //Number of rooms that the person can get into. Max is 5 so dice roll is from 1 to 5
		char direction; // Direction that the person want to go into.

	public:
		//Blank Constructor
		DoraGame();

		// Encounters a monster, can do several actions inside the room for points or run away, and lose points.
		int monster_room(human &, monster &);

		//Can get into this room and heal up. If he wants more hp, you can use gold to buy some more HP. Cannot over buy HP.
		int heal_room(human &);

		//Depends on the person's luck stat. If luck is very high, then positive stuff can happen.
		int mystery_room(human &, monster &, monster &);

		//Needs this function to roll the dice.
		int dice_rolling();

		//This will determine where the person goes.
		char direction_controller();

		// Encounters the boss. Will be able to do three different actions. 
		//Turn based, but the amount of turns the user has depends on the person's luck.
		int boss_room(human &, monster &);


		//Name the boss that the person will fight.
		string nameBoss();

		//Story script. This is the main flow of the actual story.
		void story();

		//Number of enemies that you have killed in a row. Gets to reset to 0 when you run away, or die.
		double kill_streak();

		//Random double value between 0 and 1 to help determine if your attack will hit or not.
		double hit_accuracy();




};

DoraGame::DoraGame()
: dice_roll(0), direction('M'), monster_name("A"), monster_name_2("B"), monster_name_3("C"), boss("dad")
{}

int DoraGame::monster_room(){
	int number = rand() % 3 + 1;
	string monster;

	int choice = 0;

	if (number == 1){
		monster = monster_name;
	}
	else if (number == 2) {
		monster = monster_name_2; 
	}
	else if (number == 3) {
		monster = monster_name_3;
	}

	cout << "You have encountered a " << monster << " !\n";
	cout << "You're given 3 options, what do you do?\n";
	cout << "1. SMACK IT'S FACE.\n";
	cout << "2. Use a health potion. \n";
	cout << "3. Run away! It's too scary here.\n";

	cin >> choice;

	if (choice == 1 ){
		//smack();
	}
	else if (choice == 2){
		//useHP();
	}
	else if (choice == 3){
		//runAway();
	}

}



#endif