#include "Ñomplex.h"

Complex::Complex()
{
	_reZ = NULL;
	_imZ = NULL;
}

Complex::Complex(int reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(int reZ)
{
	_reZ = reZ;
	_imZ = 0;
}

Complex::Complex(double reZ)
{
	_reZ = reZ;
	_imZ = 0;
}

Complex::Complex(Fractions reZ)
{
	_reZ = reZ;
	_imZ = 0;
}

Complex::Complex(Fractions reZ, int imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(int reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(Fractions reZ, Fractions imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

Complex::Complex(const Complex& obj)
{
	_reZ = obj._reZ;
	_imZ = obj._imZ;
}

std::ostream& operator<<(std::ostream& out, const Complex& ñomplex)
{
	if (ñomplex._reZ == 0)
		return out << ñomplex._imZ << "i" << std::endl;

	if (ñomplex._imZ == 0)
		return out << ñomplex._reZ << std::endl;

	if (ñomplex._imZ < 0)
		return out << ñomplex._reZ << " - " << ñomplex._imZ * (-1) << "i" << std::endl;

	return out << ñomplex._reZ << " + " << ñomplex._imZ << "i" << std::endl;
}

std::istream& operator>>(std::istream& in, Complex& ñomplex)
{
	Fractions reZ, imZ;
	std::cout << "Real part:" << std::endl;
	in >> reZ;
	std::cout << "Imaginary part:" << std::endl;
	in >> imZ;

	ñomplex._reZ = reZ;
	ñomplex._imZ = imZ;
	return in;
}

Complex Complex::operator+(const Complex ñomplex) const
{
	Complex result;
	result._reZ = _reZ + ñomplex._reZ;
	result._imZ = _imZ + ñomplex._imZ;
	return result;
}

Complex Complex::operator-(const Complex ñomplex) const
{
	Complex result;
	result._reZ = _reZ - ñomplex._reZ;
	result._imZ = _imZ - ñomplex._imZ;
	return result;
}

Complex Complex::operator*(const Complex ñomplex) const
{
	Complex result;
	result._reZ = _reZ * ñomplex._reZ - _imZ * ñomplex._imZ;
	result._imZ = _reZ * ñomplex._imZ + _imZ * ñomplex._reZ;
	setlocale(LC_ALL, "Russian");
	std::cout << "Îïåðàòîð Ìîõíàòàÿ òî÷êà ïåðåîïðåäåë¸í. Áóäüòå îñòîðîæíû!" << std::endl;
	return result;
}

Complex Complex::operator/(const Complex ñomplex) const
{
	Complex result;
	result._reZ = (_reZ * ñomplex._reZ + _imZ * ñomplex._imZ) / (ñomplex._reZ * ñomplex._reZ + ñomplex._imZ * ñomplex._imZ);
	result._imZ = (_imZ * ñomplex._reZ - _reZ * ñomplex._imZ) / (ñomplex._reZ * ñomplex._reZ + ñomplex._imZ * ñomplex._imZ);
	return result;
}

Complex Complex::operator%(const Complex complex) const
{
	throw "Ñomplex numbers do not support operator %";
	return Complex();
}

Complex Complex::operator!() const
{
	Complex result;
	result._reZ = _imZ;
	result._imZ = _reZ;
	return Complex();
}

Complex& Complex::operator=(const Complex complex)
{
	_reZ = complex._reZ;
	_imZ = complex._imZ;
	return *this;
}

Complex Complex::operator+() const
{
	return *this;
}

Complex Complex::operator-() const
{
	return Complex(-_reZ, -_imZ);
}

Complex& Complex::operator++()
{
	_reZ++;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex complex = *this;
	++* this;
	return complex;
}

Complex& Complex::operator--()
{
	_reZ--;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex complex = *this;
	--* this;
	return complex;
}

void Complex::operator+=(const Complex complex)
{
	*this = *this + complex;
}

void Complex::operator-=(const Complex complex)
{
	*this = *this - complex;
}

void Complex::operator*=(const Complex complex)
{
	*this = *this * complex;
}

void Complex::operator/=(const Complex complex)
{
	*this = *this / complex;
}

void Complex::operator%=(const Complex complex)
{
	throw "Ñomplex numbers do not support operator %=";
}

bool Complex::operator==(const Complex complex) const
{
	if (_reZ == complex._reZ and _imZ == complex._imZ)
		return true;
	return false;
}

bool Complex::operator!=(const Complex complex) const
{
	if (_reZ == complex._reZ and _imZ == complex._imZ)
		return false;
	return true;
}

bool Complex::operator<(const Complex complex) const
{
	throw "Ñomplex numbers do not support operator <";
	return false;
}

bool Complex::operator>(const Complex complex) const
{
	throw "Ñomplex numbers do not support operator >";
	return false;
}

bool Complex::operator<=(const Complex complex) const
{
	if (*this == complex)
		return true;

	throw "Ñomplex numbers do not support operator <= in this case";
	return false;
}

bool Complex::operator>=(const Complex complex) const
{
	if (*this == complex)
		return true;

	throw "Ñomplex numbers do not support operator >= in this case";
	return false;
}
