#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int WIDTH = 4;
const int HEIGHT = 5;

// Doll class for the findCenter function. This represents a Matryoshka doll with another Doll inside it
// A doll containing no other Dolls will have an innerDoll of nullptr
class Doll
{
	string name;
	unsigned int id;
	static unsigned int count;
	Doll *innerDoll;

public:
	Doll *getInnerDoll() const { return innerDoll; }
	void printDoll() { cout << "Doll: " << id << " " << name << endl; }

	Doll(string name, Doll *inside)
	{
		this->name = name;
		innerDoll = inside;
		id = count;
		count++;
	}
};

//---------------------------- Recursive function implementations ----------------------------

/* Description */
int power(const int &base, int pow)
{
	// Check for the base case; anything to the 0th is trivial to solve
	// Otherwise, recursively take the power of a base with a lower pow
	return (pow == 0) ? 1 : base * power(base, pow - 1);
}

/* Description */
int findBiggestNumber(int arr[], int index)
{
	// Try to find the biggest number in the array. If a base case is hit where the biggest value is trivial,
	// return the result without recursing. Else, try to find the biggest number in the array ending at the index
	// to the left of the current one. Then return the biggest value between that value and the one at the current index.
	// Try not to do more than one recursive call here.
	//(HINT Try using a variable to store the result of your recursive case)

	if (index == 0)
		return arr[index];

	int temp = findBiggestNumber(arr, index - 1);
	return (temp > arr[index]) ? temp : arr[index];
}

/* Description */
void findTheX(char grid[HEIGHT][WIDTH], const int &x, const int &y)
{
	// If the char at the current spot is an X, then we solved it
	// Print the message andmark the spot as a O now to make sure we don't find it twice
	// Else if the char is an 'O', it is either a wall or has been verified
	// to not contain the X

	// If this is not the X or an O, mark this spot as a O then recursively try the right, left, above
	// and below spots only if each ear in bounds of the array

	// You can assume the grid always has dimensions of the consts HEIGHT and WIDTH
	// by the parameter declaration above and that the X is always findable. Consider
	// that with row major arrays, y should come before x when accessing, as well
	// as that the first index is 0, not 1.

	if (grid[y][x] == 'X')
	{
		std::cout << "Found the X at " << x << ", " << y << std::endl;
		grid[y][x] = 'O';
	}
	else if (grid[y][x] != 'O')
	{
		grid[y][x] = 'O';
		if (x + 1 < WIDTH)
			findTheX(grid, x + 1, y);
		if (x - 1 >= 0)
			findTheX(grid, x - 1, y);
		if (y + 1 < HEIGHT)
			findTheX(grid, x, y + 1);
		if (y - 1 >= 0)
			findTheX(grid, x, y - 1);
	}
}

/* Description */
void findCenter(Doll *doll)
{
	// Try to find the center most Doll in a stack of Matryoshka dolls.
	// Print the doll we are currently opening using it's printDoll function and then open the next one
	// If this is the inner most Doll, don't recurse.
	// If this is the second to last Doll, print the message and don't recurse
	// Else, recurse to the next Doll

	doll->printDoll();

	if (doll->getInnerDoll() != nullptr)
		findCenter(doll->getInnerDoll());
}

void printGrid(char grid[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif