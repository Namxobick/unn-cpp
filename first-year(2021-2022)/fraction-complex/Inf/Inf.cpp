#include <iostream>
#include "Fractions.h"
#include "Сomplex.h"
#include "Tcomplex.h"

int main()
{
	Fractions fr1(7, 4), fr2(7, 2), fr3(7, 4);
	Complex cm1(fr1, 8.5), cm2(-6, 7);
	Complex Test = 5;
	Fractions fr4 = fr1 + 5 + fr2;
	Complex Test2 = Test - (Complex)5;
	Complex Test3 = Test + (Complex)5.5;
	Complex Test4 = Test * Test;

	std::cout << cm1 + cm2;
	std::cout << Test4;

	Tcomplex<double, Fractions> Tcm1(5.6, fr1);
	Tcomplex<int, int> Tcm2(fr3, 5);
	Tcomplex<int, double> Tcm3 = Tcm1;
	Tcomplex<int, int> Tcm4 = Tcm1 / Tcm2 / Tcomplex<int, int>(5) / (Tcomplex<Fractions, int>(fr2, 7) * Tcomplex<Fractions, int>(fr2, 7));

	std::cout << Tcm4 << std::endl;

	std::cout << Tcm3 << std::endl;

	std::cout << Tcm1 + Tcm2 + Tcomplex<int, int>(5) + Tcomplex<Fractions, int>(fr2, 7) << std::endl;

	std::cout << Tcm1 - Tcm2 - Tcomplex<int, int>(5) - Tcomplex<Fractions, int>(fr2, 7) << std::endl;

	std::cout << Tcm1 * Tcm2 - Tcomplex<int, int>(5) * (Tcomplex<Fractions, int>(fr2, 7) + Tcomplex<Fractions, int>(fr2, 7)) << std::endl;

	std::cout << Tcm1 / Tcm2 / Tcomplex<int, int>(5) / (Tcomplex<Fractions, int>(fr2, 7) * Tcomplex<Fractions, int>(fr2, 7)) << std::endl;

}

