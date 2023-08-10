#include "../Lib.hpp"

PhoneBook::PhoneBook()
{
	amount = 0;
	oldest = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::AddContact()
{
	int	n;

	if (oldest == 0)
		NewOldest();
	if (amount == 8)
	{
		n = oldest;
		NewOldest();
	}
	else
	{
		AmountPlusOne();
		n = amount;
	}
	contact[n - 1].SetFirstName();
	contact[n - 1].SetLastName();
	contact[n - 1].SetNickname();
	contact[n - 1].SetNumber();
	contact[n - 1].SetSecret();
}

void	PhoneBook::ShowContacts()
{
	std::string	search;

	if (amount == 0)
	{
		std::cout << "\033[0;35mThere are no contacts to show\n\033[0m";
		return;
	}
	for (size_t n = 0; n < GetAmount(); n++)
	{
		for (size_t i = 0; i < 9; i++)
			std::cout << " ";
		std::cout << n + 1;
		std::cout << "|";
		if (contact[n].GetFirstName().length() > 9)
		{
			for (size_t i = 0; i < 9; i++)
				std::cout << contact[n].GetFirstName()[i];
			std::cout << ".";
		}
		else
		{
			for (size_t i = 0; i + contact[n].GetFirstName().length() < 10; i++)
				std::cout << " ";
			for (size_t i = 0; i < contact[n].GetFirstName().length(); i++)
				std::cout << contact[n].GetFirstName()[i];
		}
		std::cout << "|";
		if (contact[n].GetLastName().length() > 9)
		{
			for (size_t i = 0; i < 9; i++)
				std::cout << contact[n].GetLastName()[i];
			std::cout << ".";
		}
		else
		{
			for (size_t i = 0; i + contact[n].GetLastName().length() < 10; i++)
				std::cout << " ";
			for (size_t i = 0; i < contact[n].GetLastName().length(); i++)
				std::cout << contact[n].GetLastName()[i];
		}
		std::cout << "|";
		if (contact[n].GetNickname().length() > 9)
		{
			for (size_t i = 0; i < 9; i++)
				std::cout << contact[n].GetNickname()[i];
			std::cout << ".";
		}
		else
		{
			for (size_t i = 0; i + contact[n].GetNickname().length() < 10; i++)
				std::cout << " ";
			for (size_t i = 0; i < contact[n].GetNickname().length(); i++)
				std::cout << contact[n].GetNickname()[i];
		}
		std::cout << "\n";
	}
	while (search.empty())
	{
		std::cout << "\033[0;34mIntroduce an index to see the contact info\n\033[0m";
		getline(std::cin, search);
		if (std::cin.eof())
		{
			std::cout << "\033[0;31m\nYou forced EOF, now you won't be able to write, bye :_C\033[0m";
			std::exit(1);
		}
		for (size_t i = 0; i < search.length(); i++)
		{
			if (!std::isdigit(search[i]))
			{
				search = "0";
				break;
			}
		}
		if (std::atoi(search.c_str()) > 0 && std::atoi(search.c_str()) < ((int)amount + 1))
			break;
		std::cout << "\033[0;31mThat's not a valid index\n\033[0m";
		search.clear();
	}
	std::cout << "Index:\n" + search + "\n";
	std::cout << "FirstName:\n" + contact[std::atoi(search.c_str()) - 1].GetFirstName() + "\n";
	std::cout << "LastName:\n" + contact[std::atoi(search.c_str()) - 1].GetLastName() + "\n";
	std::cout << "Nickname:\n" + contact[std::atoi(search.c_str()) - 1].GetNickname() + "\n";
	std::cout << "Number:\n" + contact[std::atoi(search.c_str()) - 1].GetNumber() + "\n";
	std::cout << "Darkest secret:\n" + contact[std::atoi(search.c_str()) - 1].GetSecret() + "\n";
}

void	PhoneBook::NewOldest()
{
	if (oldest == 8)
		oldest = 1;
	else
		oldest++;
}

size_t		PhoneBook::GetOldest()
{
	return(oldest);
}

void	PhoneBook::AmountPlusOne()
{
	if (amount == 8)
		return;
	amount++;
}

size_t		PhoneBook::GetAmount()
{
	return(amount);
}

