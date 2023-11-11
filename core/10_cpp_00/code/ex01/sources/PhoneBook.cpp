/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:38:50 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:52:46 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_last = 0;
	_size = SIZE_OF_PHONEBOOK;
}

PhoneBook::~PhoneBook(void)
{
}

bool	PhoneBook::add_contact(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret)
{
	_contacts[_last].set_FirstName(firstName);
	_contacts[_last].set_LastName(lastName);
	_contacts[_last].set_NickName(nickName);
	_contacts[_last].set_PhoneNumber(phoneNumber);
	_contacts[_last].set_DarkestSecret(darkestSecret);
	_last = (_last + 1) % 8;
	return (true);
}

Contact	PhoneBook::get_contact(int n) const
{
	Contact	result;

	if (!(n < 0 || _size - 1 < n))
		result = _contacts[n];
	return (result);
}

int	PhoneBook::get_size(void) const
{
	return (_size);
}
