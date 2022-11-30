#include <iostream>
#include "polynomial.h"

int main()
{
	int p1[] = {-6, 2, 0, 0, 5};
	int p2[] = {-5, 2, 4, -2};

	polynomial poly1(p1, 4);
	polynomial poly2(p2, 3);
	polynomial result;

	result = poly2 - poly1;
	std::cout << "result = " << result << "\n";

	return 0;
}