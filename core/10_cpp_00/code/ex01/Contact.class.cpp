#include "Contact.class.hpp"

Contact::Contact(void) :
	_firstname(""),
	_lastname(""),
	_nickname(""),
	_phonenumber(""),
	_darkestsecret("")
{

}

Contact::~Contact(void)
{

}

bool		Contact::set_FirstName(std::string name)
{
	if (name.empty())
		return (false);
	_firstname = name;
	return (true);
};

std::string	Contact::get_FirstName(void) const
{
	return (_firstname);
};

bool		Contact::set_LastName(std::string name)
{
	if (name.empty())
		return (false);
	_lastname = name;
	return (true);
};

std::string	Contact::get_LastName(void) const
{
	return (_lastname);
};

bool		Contact::set_NickName(std::string name)
{
	if (name.empty())
		return (false);
	_nickname = name;
	return (true);
};

std::string	Contact::get_NickName(void) const
{
	return (_nickname);
};

bool		Contact::set_PhoneNumber(std::string number)
{
	if (number.empty())
		return (false);
	_phonenumber = number;
	return (true);
};

std::string	Contact::get_PhoneNumber(void) const
{
	return (_phonenumber);
};

bool		Contact::set_DarkestSecret(std::string secret)
{
	if (secret.empty())
		return (false);
	_darkestsecret = secret;
	return (true);
};

std::string	Contact::get_DarkestSecret(void) const
{
	return(_darkestsecret);
};
