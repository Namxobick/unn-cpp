#include "Processing�enter.h"

Processing�enter::Processing�enter()
{
}

Processing�enter::Processing�enter(Customer customer)
{
	_customers.Add(customer);
}

Processing�enter::Processing�enter(Vector<Customer> customers)
{
	_customers = customers;
}

void Processing�enter::AddCustomer(Customer customer)
{
	_customers.Add(customer);
}

void Processing�enter::AddCustomers(Vector<Customer> customers)
{
	for (size_t i = 0; i < customers.Size(); i++)
	{
		_customers.Add(customers[i]);
	}
}

Customer& Processing�enter::GetInfo(std::string cardNumber)
{
	for (int i = 0; i < _customers.Size(); i++)
	{
		if (_customers[i].CardNumber == cardNumber)
		{
			return _customers[i];
		}
	}

	std::cout << "Customer not found" << std::endl;
	Customer customer;
	return customer;
}

