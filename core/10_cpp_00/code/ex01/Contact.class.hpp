#pragma once

#include <string>
#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		bool		set_FirstName(std::string name);
		std::string	get_FirstName(void) const;

		bool		set_LastName(std::string name);
		std::string	get_LastName(void) const;

		bool		set_NickName(std::string name);
		std::string	get_NickName(void) const;

		bool		set_PhoneNumber(std::string name);
		std::string	get_PhoneNumber(void) const;

		bool		set_DarkestSecret(std::string name);
		std::string	get_DarkestSecret(void) const;

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkestsecret;
};
