#ifndef __DORA_H__
#define __DORA_H__

using namespace std;

//Exploring Maze Game using the Leap Motion

class DoraGame {

	private:
		int dice_roll; //Number of rooms that the person can get into. Max is 5 so dice roll is from 1 to 5
		char direction;
		double hp; // Health Points
		double mp; // Mana Points
		int gold_amount; // amount of gold that the character has on hand.
		float luck; // Amount of luck that the person has. Will change from room to room based on algorithm.
		double game_points; // Game Score Points
		double bonus; // Bonus points calculated at the end, can lose points based on Algorithm.

		string nameOfCharacter;

		//Name of monsters that will appear.
		string monster_name; 
		string monster_name_2;
		string monster_name_3;

		// Name of final boss.
		string boss; 

	public:
		//Blank Construct
		DoraGame();

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

		//Determines the amount of luck that the person has. Will change from room to room.
		float determine_luck();

		//Used in the beginning to name your character.
		string nameCharacter();

		//Name the monsters that you will fight. Will name 3 monsters.
		string nameMonster();

		//Name the boss that the person will fight.
		string nameBoss();

		//Story script. This is the main flow of the actual story.
		void story();


};





#endif