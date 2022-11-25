#pragma once
#include <iostream>
#include <cassert>
#include <complex>
#include "Fractions.h"

template<class T1, class T2>
class Tcomplex
{
private:
	Fractions _reZ;
	Fractions _imZ;

	template<class A, class B>
    friend std::ostream& operator << (std::ostream& out, const Tcomplex<A, B>& complex);

	template<class A, class B>
	friend std::istream& operator >> (std::istream& in, Tcomplex<A, B>& complex);

public:

    Tcomplex();
    Tcomplex(T1 reZ);
    Tcomplex(T1 reZ, T2 imZ);
    Tcomplex(const Tcomplex& complex);

	Tcomplex<T1, T2> operator+ (const Tcomplex<T1, T2> complex) const;

	Tcomplex<T1, T2> operator- (const Tcomplex<T1, T2> complex) const;

	Tcomplex<T1, T2> operator* (const Tcomplex<T1, T2> complex) const;

	Tcomplex<T1, T2> operator/ (const Tcomplex<T1, T2> complex) const;

	Tcomplex<T1, T2>& operator=(const Tcomplex<T1, T2> complex);

	template<class T3, class T4>
	operator Tcomplex<T3, T4>()
	{
		Tcomplex<T3, T4> complex(_reZ, _imZ);
		return complex;
	}
};

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex()
{
	_reZ = 0;
	_imZ = 0;
}

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex(T1 reZ, T2 imZ)
{
	_reZ = reZ;
	_imZ = imZ;
}

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex(const Tcomplex& complex)
{
	_reZ = complex._reZ;
	_imZ = complex._imZ;
}

template<class T1, class T2>
Tcomplex<T1, T2>::Tcomplex(T1 reZ)
{
	_reZ = reZ;
	_imZ = 0;
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& out, const Tcomplex<T1, T2>& complex)
{
	if (complex._reZ == 0)
		return out << (T2)complex._imZ << "i" << std::endl;

	if (complex._imZ == 0)
		return out << (T1)complex._reZ << std::endl;

	if (complex._imZ < 0)
		return out << (T1)complex._reZ << " - " << (T2)complex._imZ * (-1) << "i" << std::endl;

	return out << (T1)complex._reZ << " + " << (T2)complex._imZ << "i" << std::endl;
}

template<class T1, class T2>
std::istream& operator>>(std::istream& in, Tcomplex<T1, T2>& complex)
{
	Fractions reZ, imZ;
	std::cout << "Real part:" << std::endl;
	in >> reZ;
	std::cout << "Imaginary part:" << std::endl;
	in >> imZ;

	complex._reZ = reZ;
	complex._imZ = imZ;
	return in;
}

template<class T1, class T2>
Tcomplex<T1, T2> Tcomplex<T1, T2>::operator+(const Tcomplex<T1, T2> complex) const
{
	return { this->_reZ + complex._reZ, this->_imZ + complex._imZ };
}

template<class T1, class T2>
Tcomplex<T1, T2> Tcomplex<T1, T2>::operator-(const Tcomplex<T1, T2> complex) const
{
	return { this->_reZ - complex._reZ, this->_imZ - complex._imZ };
}

template<class T1, class T2>
Tcomplex<T1, T2> Tcomplex<T1, T2>::operator*(const Tcomplex<T1, T2> complex) const
{
	Fractions reZ = this->_reZ * complex._reZ - this->_imZ * complex._imZ;
	Fractions imZ = _reZ * complex._imZ + _imZ * complex._reZ;

	return { reZ,  imZ };
}

template<class T1, class T2>
Tcomplex<T1, T2> Tcomplex<T1, T2>::operator/(const Tcomplex<T1, T2> complex) const
{
	Fractions reZ = (_reZ * complex._reZ + _imZ * complex._imZ) / (complex._reZ * complex._reZ + complex._imZ * complex._imZ);
	Fractions imZ = (_imZ * complex._reZ - _reZ * complex._imZ) / (complex._reZ * complex._reZ + complex._imZ * complex._imZ);
	return { reZ, imZ };
}

template<class T1, class T2>
Tcomplex<T1, T2>& Tcomplex<T1, T2>::operator=(const Tcomplex<T1, T2> complex)
{
	_reZ = complex._reZ;
	_imZ = complex._imZ;
	return *this;
}


