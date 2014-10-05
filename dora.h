#ifndef __DORA_H__
#define __DORA_H__

#include <iostream>
#include <string>
#include "human.h"
#include "monster.h"

using namespace std;

const bool CLEAR_SCREEN_DORA = true;

//@brief Utilizes an escape character sequence to clear the screen.
void clearScreenDORA() {
	cout << endl;

	if (CLEAR_SCREEN_DORA)
	{
		cout << "\033c" << endl;
    }

    cout << endl;
}

//Exploring Maze Game using the Leap Motion

class DoraGame {

	private:
		int dice_roll; //Number of rooms that the person can get into. Max is 5 so dice roll is from 1 to 5
		char direction; // Direction that the person want to go into.
		int limit;

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

		//Restore HP
		void useHP(human &);

		void monsterpls(human &, monster &);

		void replay();

};

DoraGame::DoraGame()
: dice_roll(0), direction('M'), limit(3)
{}

void DoraGame::monsterpls(human & hum, monster & mon){
	int choice = 0;

	//while (choice != 3 && mon.returnHP() <= 0){

		while(mon.returnHP() > 0 && hum.HumanHP() > 0){

			hum.determine_luck();

			cout << "You have encountered a " << mon.monsterName() << " !\n";
			cout << mon.monsterName() << " has " << mon.returnHP() << " HP.\n";
			cout << "You have " << hum.HumanHP() << " HP. \n";

			if (hum.luckpls() < 3){
				int hitValue = 0;
				hitValue = mon.monster_hits();
				cout << mon.monsterName() << " hits you for " << hitValue << " damage ";
				hum.HPvalue(hitValue);
				cout << "You have " << hum.HumanHP() << " HP. \n";

			}

			cout << "It's your turn!\n";
			cout << "You're given 3 options, what do you do?\n";
			cout << "1. SMACK IT'S FACE.\n";
			cout << "2. Use a health potion. You have " << limit << " left.\n";
			cout << "3. Run away! It's too scary here.\n";

			cin >> choice;

			if (choice == 1 ){
				mon.damage(hum.damage_to_monster());
				cout << "The monster, " << mon.monsterName() << ", has " << mon.returnHP() << "HP remaining.\n";
				cout << endl;
			}
			else if (choice == 2){
				useHP(hum);
			}
			else if (choice == 3){
				return;
			}

			monsterpls(hum, mon);
		}

		if (hum.HumanHP() <= 0){
			cout << "You have died. Game over.\n";
			replay();
		}

		return;
}//

void DoraGame::monster_room(human & hum, monster & mon, monster & mon2, monster & mon3){

	int number = rand() % 3 + 1;
	//cout << "Your number in monster_room is: " << number << endl;
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

}//

// Enter in the healing room to get healed by the priest.
void DoraGame::heal_room(human & hum){

	if (hum.HumanHP() == hum.HumanMaxHP()){
		cout << "The priest was unable to heal you because you are completely healed.\n";
		cout << "The priest sends you off now.\n";
		return;
	}

	//Initalized healValue
	int healValue = 0;
	int oldhealValue = 0;
	int newhealValue = 0;

	oldhealValue = hum.HumanHP();
	// Your healValue will always be lower the amount of MaxHP that you can get, but around the same amount that you will get
	// You will always at least heal 1 HP.
	healValue = (rand() % hum.HumanMaxHP()) % hum.HumanHP() + 1;
	
	//cout << "Your healValue is: " << healValue;

	//Code for healing your human player.
	hum.HPvalue(healValue);

	newhealValue = hum.HumanHP() - oldhealValue;

	cout << "You have reached the healing room!\n";
	cout << "The priest has just healed you " << newhealValue << " HP.";
	cout << "You have " << hum.HumanHP() << "/" << hum.HumanMaxHP() << "HP.\n";

	return;
}//

void DoraGame::useHP(human & hum){
	if (limit == 0){
		cout << "You have no more potions left! You are unable to heal any HP.\n";
		return;
	}

	hum.HPvalue(20);
	cout << "You used 1 potion, and healed 20HP. You're current HP is at " << hum.HumanHP() << " HP.\n";
	limit--;
}//

monster DoraGame::nameBoss(string name){
	monster alpha = monster(400, 10, 5, name);

	return alpha;
}//

void DoraGame::mystery_room(human & hum, monster & mon, monster & mon2, monster & mon3){
	//cout << "Your luck value is: " << hum.luckpls() << ".\n";

	if (hum.luckpls() > 0 && hum.luckpls() < 2){
		//cout << hum.luckpls();
		monsterpls(hum, mon);
	}
	else{
		monster_room(hum, mon, mon2, mon3);
	}
}//

void DoraGame::dice_rolling(){
	dice_roll = rand() % 4 + 1;
	cout << "Your dice_roll is: " << dice_roll << endl;
}//

void DoraGame::direction_controller(){
	cout << "You have reached a room, and you can go either (N)orth, (S)outh, (W)est, or (E)ast.\n";
	cout << "Choose where you want to go: ";
	cin >> direction;
}

void DoraGame::boss_room(human & hum, string name){	
	monster bossname = nameBoss(name);
	monsterpls(hum, bossname);

	if (bossname.returnHP() <= 0){
		cout << "Wow! You beat the final boss!\n";
		cout << "Congratulations!\n";
		replay();
	}

	return;
	
}

void DoraGame::story(){
	string name1;
	string name2;
	string name3;
	string bossname;

	cout << "Welcome to text RPG, with the leap motion!\n";
	human hum;
	hum.nameCharacter();
	cout << endl;

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
	monster mon2(200, 15, 2, name2);
	monster mon3(400, 20, 3, name3);

	while(hum.HumanHP() >= 0){

		clearScreenDORA();

		cout << "Press ENTER to roll the dice. \n";
		cin.get();
		dice_rolling();
		cout << dice_roll << " is the value you got.\n";

	

		if (dice_roll == 1){
			monster_room(hum, mon1, mon2, mon3);
			hum.humanAddLV(1);
		}

		else if (dice_roll == 2){
			mystery_room(hum, mon1, mon2, mon3);
			hum.humanAddLV(1);
		}
		else if (dice_roll == 3){
			heal_room(hum);
		}
		else {
			boss_room(hum, bossname);
		}
		cin.get();
	}
}

void DoraGame::replay(){
	char yn = '0';
	cout << "Would you like to play again? (y/n): ";
	cin >> yn;

	if(yn != 'n'){
		story();
	}
	exit(0);
}//

#endif