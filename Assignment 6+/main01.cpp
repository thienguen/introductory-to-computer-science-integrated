#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	int p1[] = {-6, 2, 0, 0, 5};
	int p2[] = {-5, 2, 0, -2};

	polynomial poly1(p1, 4);
	polynomial poly2(p2, 3);
	polynomial result;

	result = poly1 * poly2;
	std::cout << "result = " << result << "\n";
	
	// 5x^4 + 2x + 6
	std::cout << "poly1 = " << poly1 << "\n";
	
	// -2x^3 + 2x - 5
	std::cout << "poly2 = " << poly2 << "\n";

	return 0;
}