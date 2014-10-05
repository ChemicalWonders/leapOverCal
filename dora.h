#ifndef __DORA_H__
#define __DORA_H__

#include <iostream>
#include <string>
#include "human.h"

using namespace std;

//Exploring Maze Game using the Leap Motion

class DoraGame {

	private:
		int dice_roll; //Number of rooms that the person can get into. Max is 5 so dice roll is from 1 to 5
		char direction; // Direction that the person want to go into.

		human person;

		//Name of monsters that will appear.
		string monster_name; 
		string monster_name_2;
		string monster_name_3;

		// Name of final boss.
		string boss; 

	public:
		//Blank Constructor
		DoraGame();

		//Only other Contructor
		DoraGame(double hp, double mp, int gold_amount, float luck, double game_points);

		//Destructor
		~DoraGame();

		// Encounters a monster, can do several actions inside the room for points or run away, and lose points.
		int monster_room();

		//Can get into this room and heal up. If he wants more hp, you can use gold to buy some more HP. Cannot over buy HP.
		int heal_room();

		//Depends on the person's luck stat. If luck is very high, then positive stuff can happen.
		int mystery_room();

		//Needs this function to roll the dice.
		int dice_rolling();

		//This will determine where the person goes.
		char direction_controller();

		// Encounters the boss. Will be able to do three different actions. 
		//Turn based, but the amount of turns the user has depends on the person's luck.
		int boss_room();

		//Name the monsters that you will fight. Will name 3 monsters.
		string nameMonster();

		//Name the boss that the person will fight.
		string nameBoss();

		//Story script. This is the main flow of the actual story.
		void story();


};

DoraGame::DoraGame()
: dice_roll(0), direction('M'), human(), monster_name("A"), monster_name_2("B"), monster_name_3("C"), boss("dad")
{}

~DoraGame()
{
	delete DoraGame;
}

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
		smack();
	}
	else if (choice == 2){
		useHP();
	}
	else if (choice == 3){
		runAway();
	}

}



#endif