#ifndef	PHONEBOOK_H
# define PHONEBOOK_H

#include "../Lib.hpp"

class PhoneBook
{
private:
	Contact		contact[8];
	size_t		amount;
	size_t		oldest;
public:
	void	NewOldest();
	size_t	GetOldest();
	void	AmountPlusOne();
	size_t	GetAmount();
	void	AddContact();
	void	ShowContacts();
	PhoneBook(/* args */);
	~PhoneBook();
};

#endif