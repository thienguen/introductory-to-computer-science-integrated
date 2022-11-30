#include <iostream>
#include "recursion.h"

using namespace std;

unsigned int Doll::count = 0;

// First maze to solve
char maze1[HEIGHT][WIDTH] =
{
	{' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' '},
	{'X', ' ', ' ', ' '},
	{' ', ' ', ' ', ' '},
};

// Second maze to solve
char maze2[HEIGHT][WIDTH] = 
{
	{' ', ' ', 'O', ' '},
	{'X', ' ', 'O', ' '},
	{' ', ' ', 'O', ' '},
	{' ', ' ', 'O', ' '},
	{' ', ' ', ' ', ' '},
};

// Array for the biggest number function4
int arr[16]{18, 17, 10, 25, 7, 9, 10, 12, 15, 18, 19, 20, 4, 23, 8, 0};

// Main just calls each of the individual recursion functions
auto main() -> int
{
	int functionToTest = -1;

	// Print a prompt
	cout << "Which function should be tested?" << endl;
	cout << "(1) power" << endl;
	cout << "(2) findBiggestNumber" << endl;
	cout << "(3) findTheX" << endl;
	cout << "(4) findCenter" << endl;

	cin >> functionToTest; // Read in the choice

	while (cin.fail() || functionToTest < 1 || functionToTest > 5)
	{
		cout << "Error, invalid choice. Please pick a number 1-4" << endl;
		cin.ignore(1024, '\n');
		cin.clear();
	}

	// After the read works, run the testing code for the choice
	switch (functionToTest)
	{
	case 1: // Power
		cout << "2^10 = " << power(2, 10) << endl;
		cout << "4^0 = " << power(4, 0) << endl;
		break;
	case 2: // Find biggest number
		cout << "Array = [";
		for (int i = 0; i < 15; i++)
			cout << arr[i] << ", ";
		cout << arr[15] << "]" << endl;
		cout << "Biggest number in the array is " << findBiggestNumber(arr, 15);
		break;
	case 3: // Finds the X
		cout << "---- Maze 1 ----" << endl;
		findTheX(maze1, 1, 1);
		cout << "---- Maze 2 ----" << endl;
		findTheX(maze2, 3, 2);

		std::cout << "What happened after maze 1?" << std::endl;
		printGrid(maze1);
		std::cout << "What happened after maze 1?" << std::endl;
		printGrid(maze2);
		break;
	case 4: // Finding the center Doll
		Doll *innerMost = new Doll("Last One", nullptr);
		Doll *second = new Doll("Blue Doll", innerMost);
		Doll *third = new Doll("Green Doll", second);
		Doll *outerMost = new Doll("Red Doll", third);

		findCenter(outerMost);

		delete innerMost;
		delete second;
		delete third;
		delete outerMost;
		break;
	}
}
