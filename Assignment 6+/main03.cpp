#include <iostream>
#include "polynomial.h"

int main()
{
	int p1[] = {-6, 2, 0, 0, 5};
	int p2[] = {-5, 2, 4, -2};

	polynomial poly1(p1, 4);
	polynomial poly2(p2, 3);
	polynomial result, test;

	result = poly1 + poly2 * poly1;
	// this -2x^3 + 4x^2 + 2x + -5
	// rhs 5x^4 + 2x + -6


	std::cout << "result = " << result << "\n";
	std::cout << "-result = " << -result << "\n";

	return 0;
}