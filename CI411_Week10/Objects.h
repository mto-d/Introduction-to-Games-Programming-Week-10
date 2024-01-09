#pragma once

// ------------------------
// -- Function declarations
// -- This is the header
// ------------------------

#include <iostream>
using namespace std;

//void characterCreator();
//void objectWithParametersCreator();
void createCharacters();
void displayAllObjsStats();

class Character
{
public:
	//Attributes
	string name;
	float health = 100, speed = 5, damage = 1, coolDown = 1;
	bool isAlive = true;

	//Constructors
	Character();
	Character(string, float);

	//Methods
	void checkIsAlive();
	void displayStats();
	float timeTakenToDie(float enemyDamage, float enemyCoolDown);
	void updateHealth(float time, float enemyCoolDown, float enemyDamage);
};

void npcAndPcCreator();

class NPC : public Character
{
public:
	//Attributes
	bool isTarget = false; //I don't think that I will use this
	string leader = "No leader", faction = "No faction", message = "Default message";
	int aliveListOrder = 0;

	//Constructor
	NPC();
	NPC(string custmName, int custmOrder);

	//Methods
	void displayStats();
};

class PlayerCharacter : public Character
{
public:
	//Attributes
	string weapon = "Magic Fists", potionCarrying = "No potion";
	float damage = 20, coolDown = 2;
	int xp = 0, mana = 0;

	//Constructors
	PlayerCharacter();
	PlayerCharacter(string name, float health, string potionCarrying, int mana);

	//Methods
	void displayStats();
};

//Task 2 Simple Game Loop
void gameLoop();
void fightResult();
void playAgain();
void resetCharacters();

class UniversityStudent : public NPC
{
public:
	bool stress = true, freeTime = false, behindInWork = true;
	string weapon = "Knowledge";
	float damage = 1, coolDown = 2;

	UniversityStudent(string custmName, string custmLeader, string custmFaction, string custmMessage, int custmOrder);

	void displayStats();
};

class Miner : public NPC
{
public:
	string task = "Work in the mines", weapon = "Pickaxe";
	float damage = 3, coolDown = 4;

	Miner();
	Miner(string custmName, string custmLeader, string custmFaction, int custmOrder);

	void displayStats();
};

class CheeseMiner : public Miner
{
public:
	string resourceMined = "Cheese", message = "Mining cheese is not as good as you'd think";

	CheeseMiner();
	CheeseMiner(string custmName, string custmLeader, int custmOrder);

	void displayStats();
};

class PitBoss : public NPC
{
public:
	string weapon = "Really big pickaxe", leader = "I am my own boss", exitGuarding;
	float damage = 30, coolDown = 3;

	PitBoss(string custmName, string custmFaction, string custmExitGuarding, int custmOrder);

	void displayStats();
};

class Fighter : public NPC
{
public:
	string weapon = "Sharp thing";
	float damage = 6, coolDown = 2;

	Fighter(string custmName, string custmLeader, string custmFaction, int custmOrder);

	void displayStats();
};