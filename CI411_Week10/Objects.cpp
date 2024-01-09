// ------------------------
// -- Function definitions
// ------------------------

#include "Objects.h";

void Character::checkIsAlive() //Determines if the object is alive
{
	if (health <= 0) { isAlive = false; }
}

void Character::displayStats() //Displays all stats for each object
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive << "\n\n\n";
}

float Character::timeTakenToDie(float enemyDamage, float enemyCoolDown)
{
	return (health / enemyDamage) * enemyCoolDown;
}

void Character::updateHealth(float time, float enemyCoolDown, float enemyDamage)
{
	health -= (time / enemyCoolDown) * enemyDamage;
}

void characterCreator() //Creating two character objects
{
	PlayerCharacter player1;
	player1.name = "Fiona";
	player1.health = 100;

	NPC NPC01;
	NPC01.name = "Shrek";
	NPC01.health = 0;

	player1.checkIsAlive();
	NPC01.checkIsAlive();

	player1.displayStats();
	NPC01.displayStats();
}

Character::Character()
{
	//cout << "A character has been created\n\n";
	//I have removed this line because it is being called when I created a new object of the derived class
	//And I cannot figure out how to stop it from doing so that I understand
}

Character::Character(string nameInput, float healthInput)
{
	name = nameInput;
	health = healthInput;

	cout << name << " has been spawned with " << health << " health\n";
}

/*void objectWithParametersCreator()
{
	Character player3("Peter", 79);
	Character player4("Daphne", 0);
	Character player5("Chris", 99);
}*/

NPC::NPC()
{
	cout << "A new NPC has been created\n";
}

//Overloaded constructor added for ease of creating an NPC
NPC::NPC(string custmName, int custmOrder)
{
	name = custmName;
	aliveListOrder = custmOrder;
	cout << "A new NPC has been created\n";
}

PlayerCharacter::PlayerCharacter()
{
	cout << "A new Player Character has been created\n";
}

PlayerCharacter::PlayerCharacter(string setName, float setHealth, string setPotionCarrying, int setMana)
{
	name = setName;
	health = setHealth;
	potionCarrying = setPotionCarrying;
	mana = setMana;
	
	cout << "A new Player Character has been created with a name, set health, potion carried, and mana amount\n\n";
}

//Class methods
void NPC::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive;
	//The added statments
	cout << "\nTarget: " << isTarget << "	Leader: " << leader;
	cout << "\nFaction: " << faction << "	Message: " << message << "\n\n\n";
}

void PlayerCharacter::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive;
	//The added statments
	cout << "\nWeapon: " << weapon << "	Damage: " << damage;
	cout << "\nCool Down: " << coolDown << "	XP: " << xp;
	cout << "\nPotion Carrying: " << potionCarrying << "	Mana: " << mana << "\n\n\n";
}

void npcAndPcCreator() //Creates the instances of an NPC and two PCs
{
	NPC NPC1;
	NPC1.name = "Autumn";
	NPC1.health = 100;
	NPC1.speed = 10;
	NPC1.leader = "Jackie Chan";
	NPC1.faction = "The Jackie Clan";
	NPC1.message = "Ohhh, I'm gonna get ya";
	NPC1.displayStats();

	PlayerCharacter PC1;
	PC1.name = "Rose";
	PC1.health = 95;
	PC1.weapon = "Longsword";
	PC1.damage = 10;
	PC1.coolDown = 4;

	PC1.displayStats();

	PlayerCharacter PC2("Blandall", 100, "Potion of Invisibility", 5);
	PC2.displayStats();
}

//--------------------------------------
//----Task 2 Simple Game Loop
//--------------------------------------

//Global variables
bool gameOver = false, validInput = false;
int timesRevived = 0, enemiesSlain = 0, playerChoice;
float pcTimeToDie, enemyTimeToDie;
char playAgainChoice = 'n', seeStats;

//Global Objects
PlayerCharacter PC1("Aurora", 175, "Potion of Jazzy Hands", 15);
NPC NPC1("Geter Priffin", 0);
UniversityStudent UniStu1("University Student", "David Dorrington", "University of Brighton", "University is harder than expected, but it is rewarding beyond expectation", 1);
Miner Miner1("Ernest", "The Pit Boss", "Whoever pays the bills", 2);
CheeseMiner CheMiner1("Mousanne", "The Cheesen One", 3);
PitBoss PBoss1("Wallace", "The Cheese Knees", "Cheese Mine", 4);
Fighter Fighter1("Lone Wolf", "I work alone", "I work alone", 5);

string NPCs[6] = { NPC1.name, UniStu1.name, Miner1.name, CheMiner1.name, PBoss1.name, Fighter1.name};
int deadNPCs[6] = {};

void gameLoop()
{
	//createCharacters(); - No longer in use

	while (gameOver != true)
	{
		cout << "\n\n--------------------------------------------------------------\n";
		cout << "The current stats for all characters are as follows: \n\n\n";
		displayAllObjsStats();

		while (PC1.health > 0)
		{
			fightResult();

			if (enemiesSlain == 6)
			{
				break;
			}
			else
			{
				seeStats = ' ';

				while (seeStats != 'y' && seeStats != 'n')
				{
					cout << "Would you like to see the stats of the characters again? (y/n): ";
					cin >> seeStats;
				}

				if (seeStats == 'y')
				{
					displayAllObjsStats();
				}
				else
				{
					continue;
				}
			}
		}
		playAgain();
	}

	cout << "\n\n--------------------------------------------------------------\n";
	cout << "Have a nice day!";
}

void resetCharacters()
{
	for (int i = 0; i < 6; i++)
	{
		deadNPCs[i] = 0;
	}

	enemiesSlain = 0;

	PC1.health = 150;
	NPC1.health, UniStu1.health, Miner1.health, CheMiner1.health, PBoss1.health, Fighter1.health = 100;
	
	NPC1.name.erase(14, 32);
	NPCs[0] = NPC1.name;

	UniStu1.name.erase(19, 37);
	NPCs[1] = UniStu1.name;

	Miner1.name.erase(7, 25);
	NPCs[2] = Miner1.name;

	CheMiner1.name.erase(9, 27);
	NPCs[3] = CheMiner1.name;

	PBoss1.name.erase(8, 26);
	NPCs[4] = PBoss1.name;

	Fighter1.name.erase(10, 28);
	NPCs[5] = Fighter1.name;

}

void playAgain()
{
	cout << "\n\n--------------------------------------------------------------\n";
	cout << "G A M E  O V E R\n";
	cout << "Thank you for playing\n";
	cout << "Would you like to play again? (y/n): ";
	cin >> playAgainChoice;

	if (playAgainChoice == 'y')
	{
		resetCharacters();
		
		gameOver = false;
	}
	else if (playAgainChoice == 'n')
	{
		gameOver = true;
	}
	else
	{
		cout << "Invalid input\n\n";
		playAgain();
	}
}

void fightResult()
{
	cout << "\n\n--------------------------------------------------------------\n";
	cout << "Please choose from this list who you would like to attack:\n\n";
	for (int i = 0; i < sizeof(NPCs) / sizeof(NPCs[0]); i++)
	{
		cout << i + 1 << ". " << NPCs[i] << "\n";
	}

	validInput = false;

	while (validInput == false)
	{
		cout << "\nPlease enter the number of a character you have not attacked yet: ";
		cin >> playerChoice; //This here is where I fix the issue

		for (int i = 0; i < 6; i++)
		{
			if (playerChoice != deadNPCs[i])
			{
				if (i == 5 && playerChoice >= 1 && playerChoice <= 6)
				{
					validInput = true;
					break;
				}
				else if (i == 5)
				{
					cout << "\nInvalid input";
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "\nInvalid input";
				break;
			}
		}
	}
	
	cout << "\n--------------------------------------------------------------\n";
	cout << "It is time to fight!\n\n";
	cout << PC1.name << " VS " << NPCs[playerChoice - 1] << "\n\n"; //ERROR HERE
	//Okay so do not need to change order of array. Just represent in it that a character is dead

	//This switch statement is used to determine the outcome of the fight, and changes the object's values accordingly
	//This should really be in it's own function so that it can be looped easily
	switch (playerChoice)
	{
	case 1:
		NPC1.isTarget = true;

		pcTimeToDie = PC1.timeTakenToDie(NPC1.damage, NPC1.coolDown);
		enemyTimeToDie = NPC1.timeTakenToDie(PC1.damage, PC1.coolDown);

		if (pcTimeToDie > enemyTimeToDie)
		{
			PC1.updateHealth(enemyTimeToDie, NPC1.coolDown, NPC1.damage);
			NPC1.health = 0;
			NPC1.checkIsAlive();
			NPC1.name += " - D E C E A S E D";
			NPCs[playerChoice - 1] = NPC1.name; //Using a pointer would remove the need for this I believe
			enemiesSlain += 1;
			deadNPCs[0] = 1;

			cout << "You won the fight and have " << PC1.health << " health remaining\n\n";
		}
		else if (pcTimeToDie < enemyTimeToDie)
		{
			NPC1.updateHealth(enemyTimeToDie, PC1.coolDown, PC1.damage);
			PC1.health = 0;
			PC1.checkIsAlive();

			cout << "You have lost the fight. " << NPC1.name << " had " << NPC1.health << " health remaining\n\n";
		}
		else
		{
			PC1.health, NPC1.health = 0;
			PC1.isAlive, NPC1.isAlive = false;

			cout << "You have killed eachother in combat. The fight is won, but at what cost\n\n";
		}

		NPC1.isTarget = false;

		break;
	case 2:
		UniStu1.isTarget = true;

		pcTimeToDie = PC1.timeTakenToDie(UniStu1.damage, UniStu1.coolDown);
		enemyTimeToDie = UniStu1.timeTakenToDie(PC1.damage, PC1.coolDown);

		if (pcTimeToDie > enemyTimeToDie)
		{
			PC1.updateHealth(enemyTimeToDie, UniStu1.coolDown, UniStu1.damage);
			UniStu1.health = 0;
			UniStu1.checkIsAlive();
			UniStu1.name += " - D E C E A S E D";
			NPCs[playerChoice - 1] = UniStu1.name;
			enemiesSlain += 1;
			deadNPCs[1] = 2;

			cout << "You won the fight and have " << PC1.health << " health remaining\n\n";
		}
		else if (pcTimeToDie < enemyTimeToDie)
		{
			UniStu1.updateHealth(enemyTimeToDie, PC1.coolDown, PC1.damage);
			PC1.health = 0;
			PC1.checkIsAlive();

			cout << "You have lost the fight. " << UniStu1.name << " had " << UniStu1.health << " health remaining\n\n";
		}
		else
		{
			PC1.health, UniStu1.health = 0;
			PC1.isAlive, UniStu1.isAlive = false;

			cout << "You have killed eachother in combat. The fight is won, but at what cost\n\n";
		}

		UniStu1.isTarget = false;

		break;
	case 3:
		Miner1.isTarget = true;

		pcTimeToDie = PC1.timeTakenToDie(Miner1.damage, Miner1.coolDown);
		enemyTimeToDie = Miner1.timeTakenToDie(PC1.damage, PC1.coolDown);

		if (pcTimeToDie > enemyTimeToDie)
		{
			PC1.updateHealth(enemyTimeToDie, Miner1.coolDown, Miner1.damage);
			Miner1.health = 0;
			Miner1.checkIsAlive();
			Miner1.name += " - D E C E A S E D";
			NPCs[playerChoice - 1] = Miner1.name;
			enemiesSlain += 1;
			deadNPCs[2] = 3;

			cout << "You won the fight and have " << PC1.health << " health remaining\n\n";
		}
		else if (pcTimeToDie < enemyTimeToDie)
		{
			Miner1.updateHealth(enemyTimeToDie, PC1.coolDown, PC1.damage);
			PC1.health = 0;
			PC1.checkIsAlive();

			cout << "You have lost the fight. " << Miner1.name << " had " << Miner1.health << " health remaining\n\n";
		}
		else
		{
			PC1.health, Miner1.health = 0;
			PC1.isAlive, Miner1.isAlive = false;

			cout << "You have killed eachother in combat. The fight is won, but at what cost\n\n";
		}

		Miner1.isTarget = false;

		break;
	case 4:
		CheMiner1.isTarget = true;

		pcTimeToDie = PC1.timeTakenToDie(CheMiner1.damage, CheMiner1.coolDown);
		enemyTimeToDie = CheMiner1.timeTakenToDie(PC1.damage, PC1.coolDown);

		if (pcTimeToDie > enemyTimeToDie)
		{
			PC1.updateHealth(enemyTimeToDie, CheMiner1.coolDown, CheMiner1.damage);
			CheMiner1.health = 0;
			CheMiner1.checkIsAlive();
			CheMiner1.name += " - D E C E A S E D";
			NPCs[playerChoice - 1] = CheMiner1.name;
			enemiesSlain += 1;
			deadNPCs[3] = 4;

			cout << "You won the fight and have " << PC1.health << " health remaining\n\n";
		}
		else if (pcTimeToDie < enemyTimeToDie)
		{
			CheMiner1.updateHealth(enemyTimeToDie, PC1.coolDown, PC1.damage);
			PC1.health = 0;
			PC1.checkIsAlive();

			cout << "You have lost the fight. " << CheMiner1.name << " had " << CheMiner1.health << " health remaining\n\n";
		}
		else
		{
			PC1.health, CheMiner1.health = 0;
			PC1.isAlive, CheMiner1.isAlive = false;

			cout << "You have killed eachother in combat. The fight is won, but at what cost\n\n";
		}

		CheMiner1.isTarget = false;

		break;
	case 5:
		PBoss1.isTarget = true;

		pcTimeToDie = PC1.timeTakenToDie(PBoss1.damage, PBoss1.coolDown);
		enemyTimeToDie = PBoss1.timeTakenToDie(PC1.damage, PC1.coolDown);

		if (pcTimeToDie > enemyTimeToDie)
		{
			PC1.updateHealth(enemyTimeToDie, PBoss1.coolDown, PBoss1.damage);
			PBoss1.health = 0;
			PBoss1.checkIsAlive();
			PBoss1.name += " - D E C E A S E D";
			NPCs[playerChoice - 1] = PBoss1.name;
			enemiesSlain += 1;
			deadNPCs[4] = 5;

			cout << "You won the fight and have " << PC1.health << " health remaining\n\n";
		}
		else if (pcTimeToDie < enemyTimeToDie)
		{
			PBoss1.updateHealth(enemyTimeToDie, PC1.coolDown, PC1.damage);
			PC1.health = 0;
			PC1.checkIsAlive();

			cout << "You have lost the fight. " << PBoss1.name << " had " << PBoss1.health << " health remaining\n\n";
		}
		else
		{
			PC1.health, PBoss1.health = 0;
			PC1.isAlive, PBoss1.isAlive = false;

			cout << "You have killed eachother in combat. The fight is won, but at what cost\n\n";
		}

		PBoss1.isTarget = false;

		break;
	case 6:
		Fighter1.isTarget = true;

		pcTimeToDie = PC1.timeTakenToDie(Fighter1.damage, Fighter1.coolDown);
		enemyTimeToDie = Fighter1.timeTakenToDie(PC1.damage, PC1.coolDown);

		if (pcTimeToDie > enemyTimeToDie)
		{
			PC1.updateHealth(enemyTimeToDie, Fighter1.coolDown, Fighter1.damage);
			Fighter1.health = 0;
			Fighter1.checkIsAlive();
			Fighter1.name += " - D E C E A S E D";
			NPCs[playerChoice - 1] = Fighter1.name;
			enemiesSlain += 1;
			deadNPCs[5] = 6;

			cout << "You won the fight and have " << PC1.health << " health remaining\n\n";
		}
		else if (pcTimeToDie < enemyTimeToDie)
		{
			Fighter1.updateHealth(enemyTimeToDie, PC1.coolDown, PC1.damage);
			PC1.health = 0;
			PC1.checkIsAlive();

			cout << "You have lost the fight. " << Fighter1.name << " had " << Fighter1.health << " health remaining\n\n";
		}
		else
		{
			PC1.health, Fighter1.health = 0;
			PC1.isAlive, Fighter1.isAlive = false;

			cout << "You have killed eachother in combat. The fight is won, but at what cost\n\n";
		}

		Fighter1.isTarget = false;

		break;
	default:
		cout << "Invalid input. Please enter a number beteen 1 and 6 (inclusive)\n\n";
	}
}

//All the overidden displayStats() methods

void UniversityStudent::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive; //Continue by finishing the display stats, and then by adding 4 more classes
	
	cout << "\nTarget: " << isTarget << "	Leader: " << leader;
	cout << "\nFaction: " << faction << "	Message: " << message;
	//The added statements
	cout << "\nStress: " << stress << "	Free Time: " << freeTime;
	cout << "\nBehind in Work: " << behindInWork << "	Weapon: " << weapon;
	cout << "\nDamage: " << damage << "	Cool Down: " << coolDown << "\n\n\n";
}

void Miner::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive;

	cout << "\nTarget: " << isTarget << "	Leader: " << leader;
	cout << "\nFaction: " << faction << "	Message: " << message;

	cout << "\nTask: " << task << "	Weapon: " << weapon;
	cout << "\nDamage: " << damage << "	Cool Down: " << coolDown << "\n\n\n";
}

void CheeseMiner::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive;

	cout << "\nTarget: " << isTarget << "	Leader: " << leader;
	cout << "\nFaction: " << faction << "	Message: " << message;

	cout << "\nTask: " << task << "	Resource mined: " << resourceMined;
	cout << "\nWeapon: " << weapon << "	Damage: " << damage;
	cout << "\nCool Down: " << coolDown << "\n\n\n";

}

void PitBoss::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive;

	cout << "\nTarget: " << isTarget << "	Leader: " << leader;
	cout << "\nFaction: " << faction << "	Message: " << message;

	cout << "\nExit guarding: " << exitGuarding << "	Weapon: " << weapon;
	cout << "\nDamage: " << damage << "	Cool Down: " << coolDown << "\n\n\n";
}

void Fighter::displayStats()
{
	cout << "The current stats for " << name << " are as follows:";
	cout << "\nName: " << name << "	Health: " << health;
	cout << "\nSpeed: " << speed << "	Alive: " << isAlive;

	cout << "\nTarget: " << isTarget << "	Leader: " << leader;
	cout << "\nFaction: " << faction << "	Message: " << message;

	cout << "\nWeapon: " << weapon << "	Damage: " << damage;
	cout << "\nCool Down: " << coolDown << "\n\n\n";
}


//Constructors for the new classes

UniversityStudent::UniversityStudent(string custmName, string custmLeader, string custmFaction, string custmMessage, int custmOrder) : NPC(custmName, custmOrder)
{
	leader = custmLeader;
	faction = custmFaction;
	message = custmMessage;
}

Miner::Miner()
{
	
}

Miner::Miner(string custmName, string custmLeader, string custmFaction, int custmOrder) : NPC(custmName, custmOrder)
{
	leader = custmLeader;
	faction = custmFaction;
}

CheeseMiner::CheeseMiner()
{
	
}

CheeseMiner::CheeseMiner(string custmName, string custmLeader, int custmOrder) : Miner(custmName, custmLeader, "The Cheese Knees", custmOrder)
{

}

PitBoss::PitBoss(string custmName, string custmFaction, string custmExitGuarding, int custmOrder) : NPC(custmName, custmOrder)
{
	faction = custmFaction;
	exitGuarding = custmExitGuarding;
}

Fighter::Fighter(string custmName, string custmLeader, string custmFaction, int custmOrder)
{
	name = custmName;
	leader = custmLeader;
	faction = custmFaction;
	aliveListOrder = custmOrder;
}

//Characters are created in the main loop using this method
void createCharacters()
{
	//This method was abandonned as I was unable to access this objects globally
}

void displayAllObjsStats()
{
	PC1.displayStats(); //The objects are local and only exist within createCharacters. They need to be global
	NPC1.displayStats();
	UniStu1.displayStats();
	Miner1.displayStats();
	CheMiner1.displayStats();
	PBoss1.displayStats();
	Fighter1.displayStats();
}
//I need to continue by displaying stats and then follow on from there

//Can use the cooldown to work out how long it would take for a character to be killed
//Whoever dies quicker would die, and then the survivors health would be calculated accordingly