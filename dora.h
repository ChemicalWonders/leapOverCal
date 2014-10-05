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
		void monster_room(human &, monster &, monster &, monster &);

		//Can get into this room and heal up. If he wants more hp, you can use gold to buy some more HP. Cannot over buy HP.
		void heal_room(human &);

		//Depends on the person's luck stat. If luck is very high, then positive stuff can happen.
		void mystery_room(human &, monster &, monster &, monster &);

		//Needs this function to roll the dice.
		void dice_rolling();

		//This will determine where the person goes.
		void direction_controller();

		// Encounters the boss. Will be able to do three different actions. 
		//Turn based, but the amount of turns the user has depends on the person's luck.
		void boss_room(human &, string);


		//Name the boss that the person will fight.
		monster nameBoss(string);

		//Story script. This is the main flow of the actual story.
		void story();

		//Number of enemies that you have killed in a row. Gets to reset to 0 when you run away, or die.
		double kill_streak();

		//Random double value between 0 and 1 to help determine if your attack will hit or not.
		double hit_accuracy();

		//Damage dealt to monster(s)
		void smack(human &, monster &);

		//Restore HP
		void useHP(human &);

		void monsterpls(human &, monster &);

};

DoraGame::DoraGame()
: dice_roll(0), direction('M')
{}

void DoraGame::monsterpls(human & hum, monster & mon){
	int choice = 0;

	cout << "You have encountered a " << mon.monsterName() << " !\n";
	cout << "You're given 3 options, what do you do?\n";
	cout << "1. SMACK IT'S FACE.\n";
	cout << "2. Use a health potion. \n";
	cout << "3. Run away! It's too scary here.\n";

	cin >> choice;

	if (choice == 1 ){
		smack(hum, mon);
	}
	else if (choice == 2){
		useHP(hum);
	}
	else if (choice == 3){
		exit(0);
	}
}

void DoraGame::monster_room(human & hum, monster & mon, monster & mon2, monster & mon3){

	int number = rand() % 3 + 1;
	monster monValue;

	if (number == 1){
		monValue = mon;
	}
	else if (number == 2){
		monValue = mon2;
	}
	else if (number == 3){
		monValue = mon3;
	}

	monsterpls(hum, monValue);

}

void DoraGame::heal_room(human & hum){

	int healValue = rand() % (hum.HumanMaxHP() - hum.HumanHP());
	hum.HPvalue(healValue);

	cout << "You have reached the healing room!]\n";
	cout << "The priest has just healed you " << healValue << " HP.";
	cout << "You have " << hum.HumanHP() << " out of  " << hum.HumanMaxHP() << ".\n";
}

void DoraGame::smack(human & hum, monster & mon){
	mon.damage(hum.damage_to_monster());
}

void DoraGame::useHP(human & hum){
	hum.HPvalue(20);
}

monster DoraGame::nameBoss(string name){
	monster alpha = monster(500, 25, 5, name);

	return alpha;
}

double DoraGame::hit_accuracy(){
	double value = rand() % 1;
	return value;
}

void DoraGame::mystery_room(human & hum, monster & mon, monster & mon2, monster & mon3){
	cout << "Your luck value is: " << hum.luckpls() << ".\n";

	if (hum.luckpls() > 0 && hum.luckpls() < 50){
		cout << hum.luckpls();

		monsterpls(hum, mon);
	}
	else{
		monster_room(hum, mon, mon2, mon3);
	}
}

void DoraGame::dice_rolling(){
	dice_roll = rand() % 3 + 1;
}

void DoraGame::direction_controller(){
	cout << "You have reached a room, and you can go either (N)orth, (S)outh, (W)est, or (E)ast.\n";
	cout << "Choose where you want to go: ";
	cin >> direction;
}

void DoraGame::boss_room(human & hum, string name){	
	monster bossname = nameBoss(name);
	monsterpls(hum, bossname);

	cout << "Wow! You beat the final boss!\n";
	cout << "Congratulations!\n";
	exit(1);
}

void DoraGame::story(){
	string name1;
	string name2;
	string name3;
	string bossname;

	cout << "Welcome to text RPG, with the leap motion!\n";
	human hum;
	hum.nameCharacter();

	cout << "Enter a name for your boss character: ";
	cin >> bossname;
	cout << endl;

	cout << "Enter a name for a monster: ";
	cin >> name1;
	cout << endl;

	cout << "Enter a second name for a monster: ";
	cin >> name2;
	cout << endl;

	cout << "Enter a third name for a monster: ";
	cin >> name3;
	cout << endl;

	monster mon1(100, 10, 1, name1);
	monster mon2(200, 20, 2, name2);
	monster mon3(400, 25, 3, name3);
	

	cout << "Press ENTER to roll the dice. \n";
	cin.ignore();
	cin.get();
	dice_rolling();
	cout << dice_roll << " is the value you got.\n";

	while(hum.HumanHP() != 0){

		if (dice_roll == 1){
			monster_room(hum, mon1, mon2, mon3);
		}

		else if (dice_roll == 2){
			mystery_room(hum, mon1, mon2, mon3);
		}
		else if (dice_roll == 3){
			heal_room(hum);
		}
		else {
			boss_room(hum, bossname);

		}
	}




}

#endif