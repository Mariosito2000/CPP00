#include "../Lib.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

/*--SETTERS--*/

void	Contact::SetFirstName()
{
	firstName.clear();
	while (firstName.empty())
	{
		std::cout << "Let's set contact's first name >> ";
		getline(std::cin, firstName);
		if (std::cin.eof())
		{
			std::cout << "\033[0;31m\nYou forced EOF, now you won't be able to write, bye :_C\033[0m";
			std::exit(1);
		}
	}
}

void	Contact::SetLastName()
{
	lastName.clear();
	while (lastName.empty())
	{
		std::cout << "Let's set contact's last name >> ";
		getline(std::cin, lastName);
		if (std::cin.eof())
		{
			std::cout << "\033[0;31m\nYou forced EOF, now you won't be able to write, bye :_C\033[0m";
			std::exit(1);
		}
	}
}

void	Contact::SetNickname()
{
	nickname.clear();
	while (nickname.empty())
	{
		std::cout << "Let's set contact's nickname >> ";
		getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << "\033[0;31m\nYou forced EOF, now you won't be able to write, bye :_C\033[0m";
			std::exit(1);
		}
	}
}

void	Contact::SetNumber()
{
	number.clear();
	while(number.empty())
	{
		std::cout << "Let's set contact's number >> ";
		getline(std::cin, number);
		if (std::cin.eof())
		{
			std::cout << "\033[0;31m\nYou forced EOF, now you won't be able to write, bye :_C\033[0m";
			std::exit(1);
		}
	}
}

void	Contact::SetSecret()
{
	secret.clear();
	while (secret.empty())
	{
		std::cout << "Shhh, come on, tell me your contact's darkest secret >> ";
		getline(std::cin, secret);
		if (std::cin.eof())
		{
			std::cout << "\033[0;31m\nYou forced EOF, now you won't be able to write, bye :_C\033[0m";
			std::exit(1);
		}
	}
}

/*--GETTERS--*/

std::string Contact::GetFirstName()
{
	return (firstName);
}

std::string Contact::GetLastName()
{
	return (lastName);
}

std::string Contact::GetNickname()
{
	return (nickname);
}

std::string Contact::GetNumber()
{
	return (number);
}

std::string Contact::GetSecret()
{
	return (secret);
}