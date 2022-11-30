#include <iostream>

class polynomial
{
public:
	polynomial();
	polynomial(const polynomial &);
	polynomial(int *, int);
	polynomial(int);
	~polynomial();

	polynomial operator*(const polynomial &) const;
	polynomial operator*(int) const;
	polynomial operator+(const polynomial &) const;
	polynomial operator+(int) const;
	const polynomial &operator=(const polynomial &);
	const polynomial &operator=(int);
	polynomial operator-() const;
	polynomial operator-(const polynomial &) const;
	polynomial operator-(int) const;

	friend std::ostream &operator<<(std::ostream &outfile, const polynomial &);
	friend polynomial operator+(int, const polynomial &);
	friend polynomial operator*(int, const polynomial &);
	friend polynomial operator-(int, const polynomial &);

private:
	int degree;
	int *polyExpr;
};