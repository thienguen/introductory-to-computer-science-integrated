#ifndef BOTSEG_H
#define BOTSEG_H

#include <iostream>

using namespace std;

// Type enumeration to easily check what type a segment is
enum class SegmentType
{
	SWORD,
	CANNON,
	HAMMER
};

const int segmentLength = 20;

// Abstract base class for robot parts
class BotSegment
{
private:
	SegmentType type;

protected:
	SegmentType getSegmentType() const { return type; }

public:
	BotSegment *segmentAbove;

	static int compareSegments(BotSegment *segment1, BotSegment *segment2);
	virtual void printSegment() = 0;

	BotSegment(SegmentType type)
	{
		this->type = type;
		segmentAbove = nullptr;
	}
	BotSegment(BotSegment *segment_above, SegmentType type)
	{
		segmentAbove = segment_above;
		this->type = type;
	}
	virtual ~BotSegment(){};
};

/// --- Hammer Segment -------------------------------------------------------------------------

///* Bot Segment that uses a hammer
class HammerSegment : public BotSegment
{
public:
	void printSegment();

	HammerSegment() : BotSegment(SegmentType::HAMMER) {}
	HammerSegment(BotSegment *segment_above) : BotSegment(segment_above, SegmentType::HAMMER) {}
	~HammerSegment() {}
};

/// --- Sword Segment -------------------------------------------------------------------------

///* Bot Segment that uses a sword
class SwordSegment : public BotSegment
{
public:
	void printSegment();

	SwordSegment() : BotSegment(SegmentType::SWORD) {}
	SwordSegment(BotSegment *segment_above) : BotSegment(segment_above, SegmentType::SWORD) {}
	~SwordSegment() {}
};

/// --- Cannon Segment -------------------------------------------------------------------------

///* Bot Segment that uses a cannon
class CannonSegment : public BotSegment
{
public:
	void printSegment();

	CannonSegment() : BotSegment(SegmentType::CANNON) {}
	CannonSegment(BotSegment *segment_above) : BotSegment(segment_above, SegmentType::CANNON) {}
	~CannonSegment() {}
};

#endif