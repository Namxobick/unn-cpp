#pragma once
#include <iostream>
#include <cassert>
#include "Fractions.h"

class Complex
{
private:
	Fractions _reZ;
	Fractions _imZ;

	friend std::ostream& operator << (std::ostream& out, const Complex& ñomplex);
	friend std::istream& operator >> (std::istream& in, Complex& ñomplex);

public:
	Complex();
	Complex(int reZ, int imZ);
	Complex(int reZ);
	Complex(double reZ);
	Complex(Fractions reZ);
	Complex(Fractions reZ, int imZ);
	Complex(int reZ, Fractions imZ);
	Complex(Fractions reZ, Fractions imZ);
	Complex(const Complex& obj);

	Complex operator+(const Complex complex) const;

	Complex operator-(const Complex complex) const;

	Complex operator*(const Complex complex) const;

	Complex operator/(const Complex complex) const;

	Complex operator%(const Complex complex) const;

	Complex operator!() const;

	Complex& operator=(const Complex complex);

	Complex operator+() const;
	Complex operator-() const;

	Complex& operator++();
	Complex operator++(int);

	Complex& operator--();
	Complex operator--(int);

	void operator+=(const Complex complex);

	void operator-=(const Complex complex);

	void operator*=(const Complex complex);

	void operator/=(const Complex complex);

	void operator%=(const Complex complex);

	bool operator==(const Complex complex) const;

	bool operator!=(const Complex complex) const;

	bool operator<(const Complex complex) const;

	bool operator>(const Complex complex) const;

	bool operator<=(const Complex complex) const;

	bool operator>=(const Complex complex) const;

	operator int() const
	{
		return _reZ;
	}

	operator double() const
	{
		return _reZ;
	}

	operator Fractions() const
	{
		return _reZ;
	}

	operator Complex() const
	{
		return *this;
	}
};

