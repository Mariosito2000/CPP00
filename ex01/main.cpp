#include "Lib.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	order;

	while (true)
	{
		while (order.empty())
		{
			std::cout << "\033[0;33mTell me what you want to do with your phonebook master, ADD, SEARCH or EXIT\n\033[0m";
			getline(std::cin, order);
			if (std::cin.eof())
			{
				std::cout << "\033[0;31mYou forced EOF, now you won't be able to write, bye :_C\033[0m";
				exit(1);
			}
		}
		if (order == "ADD")
			phone_book.AddContact();
		else if (order == "SEARCH")
			phone_book.ShowContacts();
		else if (order == "EXIT")
		{
			std::cout << "\033[0;36mErasing contacts...\n\033[0m";
			break;
		}
		else
			std::cout << "\033[0;31mThat's not on the menu\n\n\033[0m";
		order.clear();
	}
}