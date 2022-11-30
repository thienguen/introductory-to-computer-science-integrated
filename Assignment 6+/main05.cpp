#include <iostream>
#include "polynomial.h"

int main()
{
	int p1[] = {-6, 2, 0, 0, 5};
	int p2[] = {-5, 2, 4, -2};

	polynomial poly1(p1, 4);
	polynomial poly2(p2, 3);
	polynomial result;

	// 20x^4 + 8x - 24
	result = poly1 * 4;

	std::cout << result << "\n";

	// -2x^3 + 4x^2 + 2x + 2
	result = poly2 + 7;

	std::cout << result << "\n";

	// 5x^4 + 2x + 6
	std::cout << "poly1 = " << poly1 << "\n";

	// -2x^3 + 4x^2 + 2x - 5
	std::cout << "poly2 = " << poly2 << "\n";

	return 0;
}