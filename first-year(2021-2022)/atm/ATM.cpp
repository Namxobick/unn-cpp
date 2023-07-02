#include "ATM.h"

ATM::ATM(ProcessingÑenter* processingÑenter)
{
	_processingÑenter = *processingÑenter;

	for (int i = 0; i < 6; i++)
		_banknotesCounsts.Add(int(MaxBanknoteCounts * 0.8));

}

ATM::ATM(ProcessingÑenter* processingÑenter, std::initializer_list<int> array)
{
	_processingÑenter = *processingÑenter;
	_banknotesCounsts = array;
}

int ATM::WithdrawBills(int& amount, int bill, int indexOfBill)
{
	int withdrawBillsCounts = std::min(_banknotesCounsts[indexOfBill], amount / bill);
	amount -= bill * withdrawBillsCounts;

	return withdrawBillsCounts;
}

Customer& ATM::EnterAndChekNumberCard()
{
	while (true)
	{
		std::string CardNumber;
		std::cout << "Enetr CardNumber" << std::endl;
		std::cin >> CardNumber;
		Customer& customer = _processingÑenter.GetInfo(CardNumber);
		if (customer.Name != "")
			return customer;
	}
}

bool ATM::EnterAndChekPinCode(Customer customer)
{
	std::string pinCode;
	int AttemptsOfEnterPinCodeCounts = 0;
	while (customer.PinCode != pinCode)
	{
		std::cout << "Please, Enter your PinCode" << std::endl;
		std::cin >> pinCode;

		AttemptsOfEnterPinCodeCounts++;
		if (AttemptsOfEnterPinCodeCounts == MaxAttemptsOfEnterPinCode)
			return false;
	}

	return true;
}

void ATM::PrintBalance(Customer customer)
{
	std::cout << customer.Balance << std::endl;
}

void ATM::Withdraw(Customer& customer)
{
	std::vector<int> withdrawBanknotesCounsts = { 0, 0, 0, 0, 0, 0 };
	int amount, constAmount;
	do
	{
		std::cout << "Enter a multiple of 100" << std::endl;
		std::cin >> amount;
		constAmount = amount;
	} while (amount % 100 != 0);

	if (amount > customer.Balance)
	{
		std::cout << "ERROR! Insufficient funds" << std::endl;
		return;
	}

	for (int indexOfBanknote = 5; indexOfBanknote > -1; indexOfBanknote--)
	{
		withdrawBanknotesCounsts[indexOfBanknote] = WithdrawBills(amount, Banknotes[indexOfBanknote], indexOfBanknote);
		if (amount == 0)
			break;
	}

	if (amount != 0)
	{
		std::cout << "ERROR! Not enough banknotes at the ATM" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < Banknotes.Size(); i++)
			_banknotesCounsts[i] -= withdrawBanknotesCounsts[i];

		customer.Balance -= constAmount;

		std::cout << "The operation was successful! Your balance is " << customer.Balance << std::endl;
	}
}

void ATM::Deposit(Customer& customer)
{
	std::vector<int> PutBanknotesCounsts = { 0, 0, 0, 0, 0, 0 };
	
	std::cout << "Deposit cash (100, 200, 500, 1000, 2000, 5000)" << std::endl;
	
	for (size_t i = 0; i < PutBanknotesCounsts.size(); i++)
	{
		std::cin >> PutBanknotesCounsts[i];

		if (PutBanknotesCounsts[i] + _banknotesCounsts[i] > MaxBanknoteCounts)
		{ 
			std::cout << "ERROR! There is no place for " << Banknotes[i] << " ruble notes on the cassette. Take " << (PutBanknotesCounsts[i] + _banknotesCounsts[i]) - MaxBanknoteCounts <<" bills!" << std::endl;
			PutBanknotesCounsts[i] = MaxBanknoteCounts - _banknotesCounsts[i];
		}

		_banknotesCounsts[i] += PutBanknotesCounsts[i];
		customer.Balance += PutBanknotesCounsts[i] * Banknotes[i];
	}

	PrintBalance(customer);
}

void ATM::InterfaceATM()
{
	int ATMServices;
	Customer& customer = EnterAndChekNumberCard();

	if (!customer.Workable)
	{
		std::cout << "Your card is blocked" << std::endl;
		return;
	}

	if (!EnterAndChekPinCode(customer))
	{
		std::cout << "Exceeded the number of attempts to enter a PinCode. The card is blocked. Contact a bank employee." << std::endl;
		customer.Workable = false;
		return;
	}

	do
	{
		std::cout << "Select a service (1-4)" << std::endl;
		std::cout << "1) Balance \n2) Withdraw cash \n3) Deposit cash \n4) Return card " << std::endl;
		std::cin >> ATMServices;

		switch (ATMServices)
		{
		case 1:
			PrintBalance(customer);
			break;
		case 2:
			Withdraw(customer);
			break;
		case 3:
			Deposit(customer);
			break;
		case 4:
			break;
		default:
			std::cout << "ERROR" << std::endl;
			ATMServices = 0;
		}

	} while (ATMServices != 4);


}