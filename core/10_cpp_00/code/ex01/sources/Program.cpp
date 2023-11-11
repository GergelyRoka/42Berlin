/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:38:56 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:52:52 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"
#include <iostream>

Program::Program(void)
{
	_run();
};

Program::~Program(void)
{

};

void	Program::_run(void)
{
	std::string line;

	while (true)
	{
		std::cout << START_MESSAGE << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << EOF_MSG << std::endl;
			break ;
		}
		if (!line.empty() && line.length() > 1 && line[line.length() - 1] == '\n')
			line.erase(line.end() - 1);
		if (line == "EXIT")
			return ;
		else if (line == "ADD")
			_add();
		else if (line == "SEARCH")
			_search();
		else
			std::cout << WRONG_CMD_MSG << std::endl;
	}
}

void	Program::_add(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (_get_input(firstName, "First Name")
		&& _get_input(lastName, "Last Name")
		&& _get_input(nickName, "Nickame")
		&& _get_input(phoneNumber, "Phone Number")
		&& _get_input(darkestSecret, "Darkest Secret"))
	{
		_phonebook.add_contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	}

};

void	Program::_search(void) const
{
	_list_contacts();

	while (true)
	{
		int	index = 0;
		std::cout << "Index: ";
		if (std::cin.eof())
			break ;
		std::cin >> index;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		if (index < 1 || _phonebook.get_size() < index)
		{
			std::cout << "Wrong index. Valid is 1.." << _phonebook.get_size() << std::endl;
			continue ;
		}
		_print_contact(index);
		break ;
	}
};

void	Program::_exit(void)
{
	//delete this;
}

void	Program::_list_contacts(void) const
{
	Contact	tmp;

	std::cout << std::right << std::setw(10) << "Index" << "|"
							<< std::setw(10) << "First Name" << "|"
							<< std::setw(10) << "Last Name" << "|"
							<< std::setw(10) << "Nickname" << "|"
							<< std::endl;
	for (int i = 0; i < _phonebook.get_size(); ++i)
	{
		tmp = _phonebook.get_contact(i);
		if (tmp.get_FirstName().length() > 10)
			tmp.set_FirstName(tmp.get_FirstName().substr(0, 9) + ".");
		if (tmp.get_LastName().length() > 10)
			tmp.set_LastName(tmp.get_LastName().substr(0, 9) + ".");
		if (tmp.get_NickName().length() > 10)
			tmp.set_NickName(tmp.get_NickName().substr(0, 9) + ".");
		char c = '1' + i;
		std::cout << std::right << std::setw(10) << std::string(1, c) << "|"
								<< std::setw(10) << tmp.get_FirstName() << "|"
								<< std::setw(10) << tmp.get_LastName() << "|"
								<< std::setw(10) << tmp.get_NickName() << "|"
								<< std::endl;
	}
}

void	Program::_print_contact(int n) const
{
	Contact	tmp;

	tmp = _phonebook.get_contact(n - 1);
	if (tmp.get_FirstName().empty())
	{
		std::cout << "The contact (" << n << ") of the PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "The contact (" << n << ") of the PhoneBook" << std::endl;
	std::cout << std::right << std::setw(17) << "First Name : " << tmp.get_FirstName() << std::endl;
	std::cout << std::right << std::setw(17) << "Last Name : " << tmp.get_LastName() << std::endl;
	std::cout << std::right << std::setw(17) << "Nickname : " << tmp.get_NickName() << std::endl;
	std::cout << std::right << std::setw(17) << "Phone Number : " << tmp.get_PhoneNumber() << std::endl;
	std::cout << std::right << std::setw(17) << "Darkest Secret : " << tmp.get_DarkestSecret() << std::endl;
}

void	Program::_my_trimm(std::string &str)
{
	while(!str.empty() && (str[0] == ' ' || str[0] == '\t'))
		str.erase(0, 1);
	while(!str.empty()
		&& (str[str.length() - 1] == ' ' || str[str.length() - 1] == '\t' || str[str.length() - 1] == '\n'))
		str.erase(0, 1);
}

bool	Program::_get_input(std::string &str, std::string type)
{
	while (true)
	{
		std::cout << std::right << std::setw(17) << type << " : ";
		if (!std::getline(std::cin, str))
			return (false);
		_my_trimm(str);
		if (!str.empty())
			return (true);
		std::cout << ERROR_FORMAT << std::endl;
	}
}
