#include <iostream>
#include "polynomial.h"

int main()
{
	int p1[] = {-6, 2, 0, 0, 5};
	int p2[] = {-5, -2, 4, 1, -2, 19};

	polynomial poly1(p1, 4);
	polynomial poly2(p2, 5);
	polynomial result;

	result = poly1 + poly2;

	std::cout << "result = " << result << "\n";

	// 5x^4 + 2x + 6
	std::cout << "poly1 = " << poly1 << "\n";
	
	// 19x^5 - 2x^4 + x^3 + 4x^2 + -2x - 5
	std::cout << "poly2 = " << poly2 << "\n";

	return 0;
}