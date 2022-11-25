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

class ProcessingÑenter
{
private:
	Vector<Customer> _customers;
	//std::vector<Customer> _customers;

public:
	ProcessingÑenter();
	ProcessingÑenter(Customer customer);
	ProcessingÑenter(Vector<Customer> customers);

	void AddCustomer(Customer customer);
	void AddCustomers(Vector<Customer> customers);

	Customer& GetInfo(std::string cardNumber);


};

