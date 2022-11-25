#include "ATM.h"

int main()
{
	Vector<Customer> customers = { { "1", "Andrey", 7800, "1" },
										{ "2", "Alesha", 100, "2" },
										{ "3", "Stepa", 17800, "3" } };

	ProcessingСenter processingCenter(customers);
	ATM sber(&processingCenter);

	while (true)
	{
		sber.InterfaceATM();
	}
}

