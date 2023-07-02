#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Vector.h"

struct Customer
{
	std::string CardNumber;
	std::string Name;
	int Balance = 0;
	std::string PinCode;
	bool Workable = true;
};

class Processing�enter
{
private:
	Vector<Customer> _customers;
	//std::vector<Customer> _customers;

public:
	Processing�enter();
	Processing�enter(Customer customer);
	Processing�enter(Vector<Customer> customers);

	void AddCustomer(Customer customer);
	void AddCustomers(Vector<Customer> customers);

	Customer& GetInfo(std::string cardNumber);


};

