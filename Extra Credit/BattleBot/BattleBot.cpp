#include "BattleBot.h"

/* 
	* Prints all of the bot's segments, starting with the top and ending with the bottom
    * This function provides a wrapper for the first recursive call to print all the segments 
*/

void BattleBot::printBot()
{
	printNextSegment(bottom);
}

/**/
void BattleBot::printNextSegment(BotSegment *segment)
{
	// This function should recursively print all segments above the current one if there are
	// any and then print this segment using its printSegment function
	// (HINT: This should only be about three to four lines.
	// Consider whether head or tail recursion may be appropriate)
	if (segment != nullptr)
	{
		printNextSegment(segment->segmentAbove);
		segment->printSegment();
	}
}

/**/
BattleStatus BattleBot::playBattleRound(BattleBot &bot1, BattleBot &bot2)
{
	// Pointers that can be used to point to the current segments being checked in each bot
	BotSegment *curr1 = bot1.bottom;
	BotSegment *curr2 = bot2.bottom;
	BotSegment *prev1 = nullptr, *prev2 = nullptr;
	
	// Optional boolean to check if someone won at least one round
	// Play through a single round where each corresponding segment in the 2 bots battle against each other

	// * Loop through each bot's segments simultaneously.
	// If the there are no more segments left that haven't fought, we are done battling this round
	// If a segment loses, delete it and update the pointer on the segment below it to point to the one above it
	// Be careful with how you handle the curr and make sure to update the bottom pointer of a bot if a bottom
	// segment loses
	
	// (HINT: Try switching on the result of comparing the segements. Depending on which segment won,
	// update the pointers accordingly)
	// This function will need to return a status on whether one of the two bots won, a draw happened,
	// or nobody has won yet

	// (HINT use the noSegmentsLeft function to check if a bot has lost and for a draw, we can check
	// if all of the battles were ties, otherwise the game has not ended yet)

	while (curr1 != nullptr && curr2 != nullptr)
	{
		int result = BotSegment::compareSegments(curr1, curr2);
		if (result == 1)
		{
			// segment 1 wins, delete segment 2
			if (prev2 == nullptr)
				bot2.bottom = curr2->segmentAbove;
			else
				prev2->segmentAbove = curr2->segmentAbove;

			BotSegment *temp = curr2;
			curr2 = curr2->segmentAbove;
			delete temp;

			// we already updated 2, so we need to advance 1.
			prev1 = curr1;
			curr1 = curr1->segmentAbove;
		}
		else if (result == -1)
		{
			// segment 2 wins, delete segment 1
			if (prev1 == nullptr)
				bot1.bottom = curr1->segmentAbove;
			else
				prev1->segmentAbove = curr1->segmentAbove;

			BotSegment *temp = curr1;
			curr1 = curr1->segmentAbove;
			delete temp;

			// we already updated 1, so we need to advance 2.
			prev2 = curr2;
			curr2 = curr2->segmentAbove;
		}
		else if (result == 0)
		{
			// tie, ehehe
			prev1 = curr1;
			prev2 = curr2;
			curr1 = curr1->segmentAbove;
			curr2 = curr2->segmentAbove;

			if (curr1 == nullptr || curr2 == nullptr)
			{
				if (BotSegment::compareSegments(bot1.bottom, bot2.bottom) == 0)
					return BattleStatus::DRAW;
			}
		}
	}

	return bot1.hasNoSegments() && bot2.hasNoSegments() 
		   ? BattleStatus::DRAW     : bot1.hasNoSegments() 
		   ? BattleStatus::BOT2_WIN : bot2.hasNoSegments() 
		   ? BattleStatus::BOT1_WIN : BattleStatus::NO_RESULT;
}

/**/
void BattleBot::addSegment(BotSegment *segment)
{
	// Add a segment to the top of the BattleBot. 
	// We are given a pointer to the bottom as
	// part of the class (like a head in a linked list)
	// If there are no elements, set the bottom to be the 
	// passed segment, otherwise find where the
	// top is and put the segment there

	if (bottom != nullptr)
	{
		// find the top segment
		BotSegment *tmp = bottom;
		while (tmp->segmentAbove != nullptr)
			tmp = tmp->segmentAbove;

		// set the new segment's segmentAbove 
		tmp->segmentAbove = segment;
		segment->segmentAbove = nullptr;
	}
	else
		bottom = segment;
}

/**/
BattleBot::~BattleBot()
{
	// Destroy all of the remaining segments, starting at the bottom
	// the same as linkedlist start at bottom and delete each segment
	BotSegment *temp = bottom;
	while (temp != nullptr)
	{
		bottom = bottom->segmentAbove;
		delete temp;
		temp = bottom;
	}
}

