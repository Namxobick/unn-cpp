#pragma once
#include "ProcessingÑenter.h"

class ATM
{
private:
	const Vector<int> Banknotes = { 100, 200, 500, 1000, 2000, 5000 };
	const int MaxAttemptsOfEnterPinCode = 3;
	const int MaxBanknoteCounts = 2000;

	Customer customer;
	ProcessingÑenter _processingÑenter;

	//std::vector<int> _banknotesCounsts;
	Vector<int> _banknotesCounsts;
 
private:
	int WithdrawBills(int& amount, int bill, int indexOfBill);

	Customer& EnterAndChekNumberCard();

	bool EnterAndChekPinCode(Customer customer);

	void PrintBalance(Customer customer);

	void Withdraw(Customer& customer);

	void Deposit(Customer& customer);

public:
	ATM(ProcessingÑenter* processingÑenter);
	ATM(ProcessingÑenter* processingÑenter, std::initializer_list<int> array);

	void InterfaceATM();
};

