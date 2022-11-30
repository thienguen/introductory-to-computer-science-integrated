
#include "polynomial.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

polynomial::polynomial()
{

    degree = -1;
    polyExpr = nullptr;
}

polynomial::polynomial(const polynomial &poly) : degree(poly.degree)
{
    polyExpr = new int[degree + 1];
    for (int i = 0; i <= degree; i++)
        polyExpr[i] = poly.polyExpr[i];
}

polynomial::polynomial(int *p, int degree)
{
    polyExpr = new int[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        polyExpr[i] = p[i];
    }
    this->degree = degree;
}

polynomial::polynomial(int s)
{
    this->degree = 0;
    this->polyExpr = new int[1];
    polyExpr[0] = s;
}

polynomial::~polynomial()
{
    if (this->polyExpr != nullptr)
    {
        delete[] this->polyExpr;
        this->polyExpr = nullptr;
    }
}

polynomial polynomial::operator*(const polynomial &rhs) const
{
    // Createa an array to hold the product of the two polynomials
    int *temp = new int[degree + rhs.degree + 1];

    // Initialize the array to 0
    for (int i = 0; i < degree + rhs.degree + 1; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= rhs.degree; j++)
        {
            temp[i + j] += polyExpr[i] * rhs.polyExpr[j];
        }
    }

    // Create a new polynomial to hold the product
    polynomial result(temp, degree + rhs.degree);

    // Delete the temporary array, or it will be a memory leak
    delete[] temp;

    // Return the product
    return result;
}

polynomial polynomial::operator*(int rhs) const
{
    // multiply a poymonial by a scalar
    int *temp = new int[degree + 1];

    for (int i = 0; i <= degree + 1; i++)
    {
        temp[i] = polyExpr[i] * rhs;
    }

    polynomial result(temp, degree + 1);

    delete[] temp;
    return result;
}

polynomial polynomial::operator+(const polynomial &rhs) const
{
    polynomial addition;

    if (rhs.polyExpr != nullptr && this->polyExpr != nullptr)
    {
        if (this->degree > rhs.degree)
        {
            addition = *this;
            for (int i = 0; i < rhs.degree + 1; i++)
            {
                addition.polyExpr[i] += rhs.polyExpr[i];
            }
        }
        else
        {
            addition = rhs;
            for (int i = 0; i < this->degree + 1; i++)
            {
                addition.polyExpr[i] += this->polyExpr[i];
            }
        }
    }

    return addition;
}

polynomial polynomial::operator+(int rhs) const
{
    // add a polynomial and a scalar
    polynomial result(this->polyExpr, this->degree);

    result.polyExpr[0] += rhs;

    return result;
}

const polynomial &polynomial::operator=(const polynomial &rhs)
{
    // swap the data members
    polynomial temp(rhs);
    std::swap(degree, temp.degree);
    std::swap(polyExpr, temp.polyExpr);

    return temp;
}

const polynomial &polynomial::operator=(int rhs)
{
    // assignment operator that assigns an interger to a polynomia
    delete[] polyExpr;
    degree = 1;
    polyExpr = new int[1];
    polyExpr[0] = rhs;

    return *this;
}

polynomial polynomial::operator-() const
{
    polynomial temp;

    if (this->polyExpr != nullptr)
    {
        temp = *this;

        for (int i = 0; i < (degree + 1); i++)
        {
            if (this->polyExpr[i] > 0)
            {
                temp.polyExpr[i] -= (abs(this->polyExpr[i]) * 2);
            }
            else
            {
                temp.polyExpr[i] += (abs(this->polyExpr[i]) * 2);
            }
        }
    }

    return temp;
}

polynomial polynomial::operator-(const polynomial &rhs) const
{
    int betta = 0;
    int *temp;

    if (this->polyExpr != nullptr && rhs.polyExpr != nullptr)
    {
        if (degree > rhs.degree)
        {
            betta = degree;
            temp = new int[betta + 1];

            for (int i = 0; i <= betta; i++)
            {
                if (i <= rhs.degree)
                {
                    temp[i] = polyExpr[i] - rhs.polyExpr[i];
                }
                else
                {
                    temp[i] = polyExpr[i];
                }
            }
        }
        else
        {
            betta = rhs.degree;
            temp = new int[betta + 1];

            for (int i = 0; i <= betta; i++)
            {
                if (i <= degree)
                {
                    temp[i] = polyExpr[i] - rhs.polyExpr[i];
                }
                else
                {
                    temp[i] = -rhs.polyExpr[i];
                }
            }
        }
    }

    polynomial result(temp, betta);
    delete[] temp;
    return result;
}

polynomial polynomial::operator-(int rhs) const
{
    if (rhs > 0)
    {
        this->polyExpr[0] -= rhs;
    }
    else
    {
        this->polyExpr[0] += rhs;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const polynomial &rhs)
{
    // Print the polynomial in the form of ax^n + bx^n-1 + ... + c
    for (int i = rhs.degree; i >= 0; i--)
    {
        if (rhs.polyExpr[i] != 0)
        {
            if (i == 0)
            {
                out << rhs.polyExpr[i];
            }
            else if (i == 1)
            {
                out << rhs.polyExpr[i] << "x + ";
            }
            else
            {
                out << rhs.polyExpr[i] << "x^" << i << " + ";
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