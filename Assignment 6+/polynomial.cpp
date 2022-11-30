#include "polynomial.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

polynomial::polynomial()
{
    degree = -1;
    polyExpr = nullptr;
}

polynomial::polynomial(const polynomial &poly)
{

    this->degree = poly.degree;
    this->polyExpr = new int[this->degree + 1];

    for (int i = 0; i <= poly.degree; i++)
    {
        this->polyExpr[i] = poly.polyExpr[i];
    }
}

polynomial::polynomial(int *p, int degree)
{

    this->degree = degree;
    this->polyExpr = new int[degree + 1];

    for (int i = 0; i <= degree; i++)
    {
        this->polyExpr[i] = p[i];
    }
}

polynomial::polynomial(int s)
{

    this->degree = 0;

    this->polyExpr = new int[1];

    this->polyExpr[0] = s;
}

polynomial::~polynomial()
{

    if (polyExpr != nullptr)
    {
        delete[] polyExpr;
        polyExpr = nullptr;
    }
}

polynomial polynomial::operator*(int rhs) const
{

    int *temp = new int[degree + 1];

    for (int i = 0; i <= degree; i++)
    {
        temp[i] = polyExpr[i] * rhs;
    }

    polynomial result(temp, degree);

    delete[] temp;
    return result;
}

polynomial polynomial::operator*(const polynomial &rhs) const
{
    int *polymulti = new int[degree + rhs.degree + 1];

    for (int i = 0; i < degree + rhs.degree + 1; i++)
    {
        polymulti[i] = 0;
    }

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= rhs.degree; j++)
        {
            polymulti[i + j] += polyExpr[i] * rhs.polyExpr[j];
        }
    }

    polynomial result(polymulti, degree + rhs.degree);

    delete[] polymulti;

    return result;
}

polynomial polynomial::operator+(const polynomial &rhs) const
{
    polynomial polysumconst;

    if (rhs.polyExpr != nullptr && this->polyExpr != nullptr)
    {
        if (this->degree > rhs.degree)
        {
            polysumconst = *this;

            for (int i = 0; i <= rhs.degree; i++)
            {
                polysumconst.polyExpr[i] += rhs.polyExpr[i];
            }
        }
        else
        {

            polysumconst = rhs;
            for (int i = 0; i <= this->degree; i++)
            {
                polysumconst.polyExpr[i] += this->polyExpr[i];
            }
        }
    }
    return polysumconst;
}

polynomial polynomial::operator+(int rhs) const
{
    this->polyExpr[0] += rhs;
    return *this;
}

const polynomial &polynomial::operator=(const polynomial &rhs)
{
    if (this->polyExpr != nullptr)
    {
        delete[] this->polyExpr;
    }

    if (rhs.polyExpr != nullptr)
    {
        this->degree = rhs.degree;
        this->polyExpr = new int[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            this->polyExpr[i] = rhs.polyExpr[i];
        }
    }
    else
    {
        degree = -1;
        polyExpr = nullptr;
    }

    return *this;
}

const polynomial &polynomial::operator=(int rhs)
{

    delete[] polyExpr;
    degree = 0;
    polyExpr = new int[1];
    polyExpr[0] = rhs;

    return *this;
}

polynomial polynomial::operator-() const
{
    polynomial flip;

    flip.degree = degree;
    flip.polyExpr = new int[flip.degree + 1];

    for (int i = 0; i <= degree; i++)
    {
        flip.polyExpr[i] = ((-1)) * polyExpr[i];
    }

    return flip;
}

polynomial polynomial::operator-(const polynomial &rhs) const
{
    polynomial polyminusconst;

    if (rhs.polyExpr != nullptr && this->polyExpr != nullptr)
    {
        if (this->degree >= rhs.degree)
        {
            polyminusconst = *this;

            for (int i = 0; i <= degree; i++)
            {
                if (i <= rhs.degree)
                {

                    polyminusconst.polyExpr[i] = polyminusconst.polyExpr[i] - rhs.polyExpr[i];
                }
                else
                {
                    polyminusconst.polyExpr[i] = polyminusconst.polyExpr[i];
                }
            }
        }
        else
        {

            polyminusconst = rhs;
            for (int i = 0; i <= rhs.degree; i++)
            {
                if (i <= degree)
                {
                    polyminusconst.polyExpr[i] = this->polyExpr[i] - polyminusconst.polyExpr[i];
                }
                else
                {
                    polyminusconst.polyExpr[i] = 0 - polyminusconst.polyExpr[i];
                }
            }
        }
    }

    return polyminusconst;
}

polynomial polynomial::operator-(int rhs) const
{
    polynomial polyminus;

    polyminus.degree = degree;
    polyminus.polyExpr = new int[polyminus.degree + 1];

    for (int i = 0; i <= degree; i++)
    {
        polyminus.polyExpr[i] = polyExpr[i];
    }

    polyminus.polyExpr[0] -= rhs;
    return polyminus;
}

std::ostream &operator<<(std::ostream &out, const polynomial &rhs)
{
    for (int i = rhs.degree; i >= 0; i--)
    {
        if (rhs.polyExpr[i] < 0)
        {
            out << " - ";
            if (rhs.polyExpr[i] != -1 || i == 0)
            {
                out << " " << abs(rhs.polyExpr[i]);
            }
            if (i > 0)
            {
                out << "x";
            }
            if (i > 1)
            {
                out << '^' << i;
            }
        }
        if (rhs.polyExpr[i] > 0)
        {
            if (i != rhs.degree && rhs.polyExpr[i] > 0)
            {
                out << " + ";
            }

            if (rhs.polyExpr[i] != 1 || i == 0)
            {
                out << rhs.polyExpr[i];
            }
            if (i > 0)
            {
                out << "x";
            }
            if (i > 1)
            {
                out << '^' << i;
            }
        }
    }

    return out;
}

polynomial operator+(int lhs, const polynomial &rhs)
{
    return rhs + lhs;
}

polynomial operator*(int lhs, const polynomial &rhs)
{
    return rhs * lhs;
}

polynomial operator-(int lhs, const polynomial &rhs)
{
    return -rhs + lhs;
}