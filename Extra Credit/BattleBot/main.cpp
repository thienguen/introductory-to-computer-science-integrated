#include <iostream>
#include "BotSegment.h"
#include "BattleBot.h"

using namespace std;

void printResult(BattleStatus result_status);
void simulateBattle(BattleBot &bot1, BattleBot &bot2);

int main()
{
	// Print the prompt for tests
	int choice;
	cout << "Run which test case?" << endl;
	cout << "(1) Test printing and adding segments" << endl;
	cout << "(2) Test bot1 wins" << endl;
	cout << "(3) Test bot2 wins" << endl;
	cout << "(4) Test draw" << endl;

	// Read the choice from the user
	cin >> choice;
	while (choice < 1 || choice > 4)
	{
		cout << "Please pick a number between 1 and 4 inclusive" << endl;
		cin >> choice;
	}

	BattleBot bot1, bot2;

	// Go through a battle depending on which test case was picked
	switch (choice)
	{
	case 1: /* Just testing printing and adding segments */
		// Add 4 segments
		bot1.addSegment(new HammerSegment());
		bot1.addSegment(new CannonSegment());
		bot1.addSegment(new CannonSegment());
		bot1.addSegment(new SwordSegment());

		bot1.printBot();
		break;
	case 2: /* Bot 1 wins */
		// Setup bot1
		bot1.addSegment(new HammerSegment());
		bot1.addSegment(new SwordSegment());
		bot1.addSegment(new CannonSegment());

		// Setup bot2
		bot2.addSegment(new CannonSegment());
		bot2.addSegment(new CannonSegment());
		bot2.addSegment(new CannonSegment());

		// Play and print each round
		simulateBattle(bot1, bot2);

		break;
	case 3: /* Bot 2 Wins */
		// Setup bot1
		bot1.addSegment(new HammerSegment());
		bot1.addSegment(new SwordSegment());
		bot1.addSegment(new CannonSegment());

		// Setup bot2
		bot2.addSegment(new SwordSegment());
		bot2.addSegment(new CannonSegment());
		bot2.addSegment(new HammerSegment());

		// Play and print each round
		simulateBattle(bot1, bot2);

		break;
	case 4: /* Draw case */
		// Setup bot1
		bot1.addSegment(new HammerSegment());
		bot1.addSegment(new SwordSegment());
		bot1.addSegment(new CannonSegment());

		// Setup bot2
		bot2.addSegment(new CannonSegment());
		bot2.addSegment(new SwordSegment());
		bot2.addSegment(new HammerSegment());
		bot2.addSegment(new HammerSegment());

		simulateBattle(bot1, bot2);
		break;
	default:
		break;
	}
}

void printResult(BattleStatus result_status)
{
	switch (result_status)
	{
	case BattleStatus::BOT1_WIN:
		cout << "Bot 1 wins!" << endl;
		break;
	case BattleStatus::BOT2_WIN:
		cout << "Bot 2 wins!" << endl;
		break;
	case BattleStatus::DRAW:
		cout << "It's a draw!" << endl;
		break;

	case BattleStatus::NO_RESULT:
		cout << "No result yet" << endl;
		break;
	}
}

void simulateBattle(BattleBot &bot1, BattleBot &bot2)
{
	int round = 0;

	cout << "----------- Initial bots -----------\n";
	
	cout << "Bot1:\n";
	bot1.printBot();

	cout << "\nBot2:\n";
	bot2.printBot();

	BattleStatus result = BattleBot::playBattleRound(bot1, bot2);

	while (result == BattleStatus::NO_RESULT)
	{
		cout << endl
			 << "----------- Round " << round << "-----------\n";
		
		cout << "Bot1:\n";
		bot1.printBot();

		cout << "\nBot2:\n";
		bot2.printBot();

		round++;
		result = BattleBot::playBattleRound(bot1, bot2);
	}

	printResult(result);
}