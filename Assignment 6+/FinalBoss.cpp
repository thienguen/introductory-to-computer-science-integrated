#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
	int e1[] = {4, 5, 1, 0, 5};
	int e2[] = {2, 3};
	int e3[] = {-8, 4, -3, -2, 1};

	polynomial p1(e1, 4);
	polynomial p2(e2, 1);
	polynomial p3(e3, 4);
	polynomial p4(5);
	polynomial p5;
	polynomial result;


	p5 = 6;

	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p3 = " << p3 << endl;
	cout << "p4 = " << p4 << endl;
	cout << "p5 = " << p5 << endl << endl;

	result = p1 * p2;
	cout << "p1 * p2 = " << result << endl;


	result = p1 * p3;
	cout << "p1 * p3 = " << result << endl;


	result = p1 + p2;
	cout << "p1 + p2 = " << result << endl;


	result = p1 * p5;
	cout << "p1 * p5 = " << result << endl;


	result = p5 + p3;
	cout << "p5 + p3 = " << result << endl;

	result = p1 * p3 + p2;
	cout << "p1 * p3 + p2 = " << result << endl;

	result = p2 - p1;
	cout << "p2 - p1 = " << result << endl;

	result = p3 - 4;
	cout << "p3 - 4 = " << result << endl;

	result = p1 * 3;
	cout << "p1 * 3 = " << result << endl;


	result = p3 + 2;
	cout << "p3 + 2 = " << result << endl;


	result = 3 - p2;
	cout << "3 - p2 = " << result << endl;


	result = 2 * p1;
	cout << "2 * p1 = " << result << endl;


	result = 5 + p2;
	cout << "5 + p2 = " << result << endl << endl;


	return EXIT_SUCCESS;
}