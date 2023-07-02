#include "ProcessingÑenter.h"

ProcessingÑenter::ProcessingÑenter()
{
}

ProcessingÑenter::ProcessingÑenter(Customer customer)
{
	_customers.Add(customer);
}

ProcessingÑenter::ProcessingÑenter(Vector<Customer> customers)
{
	_customers = customers;
}

void ProcessingÑenter::AddCustomer(Customer customer)
{
	_customers.Add(customer);
}

void ProcessingÑenter::AddCustomers(Vector<Customer> customers)
{
	for (size_t i = 0; i < customers.Size(); i++)
	{
		_customers.Add(customers[i]);
	}
}

Customer& ProcessingÑenter::GetInfo(std::string cardNumber)
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

