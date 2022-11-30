#include "BotSegment.h"
#include <iomanip>

using namespace std;

// Cannon beats sword; sword beats hammer; hammer beats cannon;
// Enum goes in weakness order, so adding one checks if the type is the one that beats it
// This function returns -1 if segment1 loses to segment2, 1 if segment1 beats segment2, and 0 if they tie
int BotSegment::compareSegments(BotSegment *segment1, BotSegment *segment2)
{
	// If equal, return 0
	if (segment1->type == segment2->type)
		return 0; 

	// Else figure out if segment1 wins or loses
	return static_cast<int>(segment1->type) == ((static_cast<int>(segment2->type) + 1) % 3) ? 1 : -1;
}

// ------- virtual print overloads (these could be re-worked to use a char variable for code re-use -----------
void HammerSegment::printSegment()
{
	cout << setfill('*') << setw(segmentLength) << "" << setfill(' ') << endl;
	cout << '*' << setw(segmentLength / 2 + 2) << right << "HAMMER" << setw(segmentLength / 2 - 3) << right << '*' << endl;
	cout << setfill('*') << setw(segmentLength) << "" << setfill(' ') << left << endl;
}

void SwordSegment::printSegment()
{
	cout << setfill('x') << setw(segmentLength) << "" << setfill(' ') << endl;
	cout << 'x' << setw(segmentLength / 2 + 2) << right << "SWORD" << setw(segmentLength / 2 - 3) << right << 'x' << endl;
	cout << setfill('x') << setw(segmentLength) << "" << setfill(' ') << left << endl;
}

void CannonSegment::printSegment()
{
	cout << setfill('o') << setw(segmentLength) << "" << setfill(' ') << endl;
	cout << 'o' << setw(segmentLength / 2 + 2) << right << "CANNON" << setw(segmentLength / 2 - 3) << right << 'o' << endl;
	cout << setfill('o') << setw(segmentLength) << "" << setfill(' ') << left << endl;
}