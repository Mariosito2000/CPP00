#ifndef	CONTACT_H
# define CONTACT_H

#include "../Lib.hpp"

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	number;
	std::string	secret;
public:
	void		SetFirstName();
	void		SetLastName();
	void		SetNickname();
	void		SetNumber();
	void		SetSecret();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickname();
	std::string GetNumber();
	std::string GetSecret();
	Contact(/* args */);
	~Contact();
};

#endif