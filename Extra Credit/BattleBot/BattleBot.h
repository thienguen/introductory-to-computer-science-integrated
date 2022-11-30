#ifndef BATTLEBOT_H
#define BATTLEBOT_H

#include "BotSegment.h"

using namespace std;

// Statuses for whether a battle round resulted in a win for somebody, a draw, or no end yet
enum class BattleStatus
{
	BOT1_WIN,
	BOT2_WIN,
	DRAW,
	NO_RESULT
};

class BattleBot
{
	BotSegment *bottom;
	void printNextSegment(BotSegment *segment);

public:
	static BattleStatus playBattleRound(BattleBot &bot1, BattleBot &bot2);
	void printBot();
	void addSegment(BotSegment *segment);
	bool hasNoSegments() { return bottom == nullptr; }

	BattleBot() { bottom = nullptr; }
	~BattleBot();
};

#endif
