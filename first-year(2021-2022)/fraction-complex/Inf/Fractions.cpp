#include "Fractions.h"

Fractions::Fractions()
{
	_numerator = NULL;
	_denominator = NULL;
}

Fractions::Fractions(int numerator, int denominator)
{
	Reduction(numerator, denominator);
	_numerator = numerator;
	_denominator = denominator;
}

Fractions::Fractions(const Fractions& obj)
{
	_numerator = obj._numerator;
	_denominator = obj._denominator;
}

int Fractions::GCD(int first, int second) const
{
	while (second)
	{
		int temp = first % second;
		first = second;
		second = temp;
	}
	return first;
}

int Fractions::LCM(int first, int second) const
{
	return (first * second) / GCD(first, second);
}

void Fractions::Reduction(int &numerator, int &denominator)
{
	assert(!denominator == 0);

	int gcd = GCD(abs(numerator), abs(denominator));
	
	if (denominator > 0)
	{
		numerator = numerator / gcd;
		denominator = denominator / gcd;
	}
	else
	{
		numerator = -1 * numerator / gcd;
		denominator = -1 * denominator / gcd;
	}
}

std::ostream& operator<<(std::ostream& out, const Fractions& fraction)
{
	if (fraction._denominator == 1)
		return out << fraction._numerator;

	return out << fraction._numerator << "/" << fraction._denominator;
}

std::istream& operator>>(std::istream& in, Fractions& fraction)
{
	int numerator, denominator;
	std::cout << "Enter the numerator and denominator separated by a space" << std::endl;
	in >> numerator >> denominator;

	fraction.Reduction(numerator, denominator);

	fraction._numerator = numerator;
	fraction._denominator = denominator;

	return in;
}

Fractions Fractions::operator+(const Fractions fraction) const
{
	Fractions result;

	int lcm = LCM(abs(fraction._denominator), abs(_denominator));
	int resultNumerator = _numerator * (lcm / _denominator) + fraction._numerator * (lcm / fraction._denominator);

	result = Fractions(resultNumerator, lcm);

	return result;
}

Fractions Fractions::operator+(const int term) const
{
	Fractions fraction = Fractions(term, 1);
	Fractions result;
	
	int lcm = LCM(abs(fraction._denominator), abs(_denominator));
	int resultNumerator = _numerator * (lcm / _denominator) + fraction._numerator * (lcm / fraction._denominator);

	result = Fractions(resultNumerator, lcm);

	return result;
}

Fractions Fractions::operator-(const Fractions fraction) const
{
	Fractions result;

	int lcm = LCM(abs(fraction._denominator), abs(_denominator));
	int resultNumerator = _numerator * (lcm / _denominator) - fraction._numerator * (lcm / fraction._denominator);

	result = Fractions(resultNumerator, lcm);

	return result;
}

Fractions Fractions::operator-(const int subtrahend) const
{
	Fractions fraction = Fractions(subtrahend, 1);
	Fractions result;

	int lcm = LCM(abs(fraction._denominator), abs(_denominator));
	int resultNumerator = _numerator * (lcm / _denominator) - fraction._numerator * (lcm / fraction._denominator);

	result = Fractions(resultNumerator, lcm);

	return result;
}

Fractions Fractions::operator*(const Fractions fraction) const
{
	Fractions result;

	int resultNumerator = _numerator * fraction._numerator;
	int resultDenominator = _denominator * fraction._denominator;

	result = Fractions(resultNumerator, resultDenominator);

	return result;
}

Fractions Fractions::operator*(const int factor) const
{
	Fractions fraction = Fractions(factor, 1);
	Fractions result;

	int resultNumerator = _numerator * fraction._numerator;
	int resultDenominator = _denominator * fraction._denominator;

	result = Fractions(resultNumerator, resultDenominator);

	return result;
}

Fractions Fractions::operator/(const Fractions fraction) const
{
	Fractions result;

	int resultNumerator = _numerator * fraction._denominator;
	int resultDenominator = _denominator * fraction._numerator;

	result = Fractions(resultNumerator, resultDenominator);

	return result;
}

Fractions Fractions::operator/(const int divider) const
{
	Fractions fraction = Fractions(divider, 1);
	Fractions result;

	int resultNumerator = _numerator * fraction._denominator;
	int resultDenominator = _denominator * fraction._numerator;

	result = Fractions(resultNumerator, resultDenominator);

	return result;
}

Fractions& Fractions::operator=(const Fractions fraction)
{
	_numerator = fraction._numerator;
	_denominator = fraction._denominator;
	return *this;
}

Fractions& Fractions::operator=(const int number)
{
	_numerator = number;
	_denominator = 1;
	return *this;
}

Fractions& Fractions::operator=(const double number)
{
	_numerator = number * 1000000;
	_denominator = 1000000;
	Reduction(_numerator, _denominator);
	return *this;
}

Fractions Fractions::operator+() const
{
	return *this;
}

Fractions Fractions::operator-() const
{
	return Fractions(-_numerator, _denominator);
}

Fractions& Fractions::operator++()
{
	_numerator += _denominator;
	return *this;
}

Fractions Fractions::operator++(int)
{
	Fractions fraction = *this;
	++*this;
	return fraction;
}

Fractions& Fractions::operator--()
{
	_numerator -= _denominator;
	return *this;
}

Fractions Fractions::operator--(int)
{
	Fractions fraction = *this;
	--*this;
	return fraction;
}

void Fractions::operator+=(const Fractions fraction)
{
	*this = *this + fraction;
	
}

void Fractions::operator+=(const int term)
{
	*this = *this + term;
}

void Fractions::operator-=(const Fractions fraction)
{
	*this = *this - fraction;
}

void Fractions::operator-=(const int term)
{
	*this = *this - term;
}

void Fractions::operator*=(const Fractions fraction)
{
	*this = *this * fraction;
}

void Fractions::operator*=(const int term)
{
	*this = *this * term;
}

void Fractions::operator/=(const Fractions fraction)
{
	*this = *this / fraction;
}

void Fractions::operator/=(const int term)
{
	*this = *this / term;
}

bool Fractions::operator==(const Fractions fraction) const
{
	if (_numerator == fraction._numerator && _denominator == fraction._denominator)
		return true;
	return false;
}

bool Fractions::operator==(const int temp) const
{
	if (_numerator == temp && _denominator == 1)
		return true;
	return false;
}

bool Fractions::operator<(const Fractions fraction) const
{
	int lcm = LCM(abs(fraction._denominator), abs(_denominator));
	if (_numerator * (lcm / _denominator) < fraction._numerator * (lcm / fraction._denominator))
		return true;
	else 
		return false;
}

bool Fractions::operator<(const int temp) const
{
	Fractions fraction;
	fraction = temp;
	return (*this < fraction);
}

bool Fractions::operator>(const Fractions fraction) const
{
	int lcm = LCM(abs(fraction._denominator), abs(_denominator));
	if (_numerator * (lcm / _denominator) > fraction._numerator * (lcm / fraction._denominator))
		return true;
	else
		return false;
}

bool Fractions::operator>(const int temp) const
{
	Fractions fraction;
	fraction = temp;
	return (*this > fraction);
}

bool Fractions::operator>=(const Fractions fraction) const
{
	if (*this == fraction or *this > fraction)
		return true;
	return false;
}

bool Fractions::operator>=(const int temp) const
{
	if (*this == temp or *this > temp)
		return true;
	return false;
}

bool Fractions::operator<=(const Fractions fraction) const
{
	if (*this == fraction or *this < fraction)
		return true;
	return false;
}

bool Fractions::operator<=(const int temp) const
{
	if (*this == temp or *this < temp)
		return true;
	return false;
}

bool Fractions::operator!=(const Fractions fraction) const
{
	if (*this == fraction)
		return false;
	return true;
}

bool Fractions::operator!=(const int temp) const
{
	if (*this == temp)
		return false;
	return true;
}

Fractions::operator int() const
{
	return _numerator / _denominator;
}

Fractions::operator double() const
{
	return (_numerator * 1.0) / _denominator;
}
