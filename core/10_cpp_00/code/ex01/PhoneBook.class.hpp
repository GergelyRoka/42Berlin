/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:38:53 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 01:38:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once //not standard header guard but supported by the g++ compiler on linux

#include "Contact.class.hpp"

#include <iostream>
#include <iomanip>

#define	SIZE_OF_PHONEBOOK	8

class	PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		bool	add_contact(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret);
		Contact	get_contact(int n) const;
		int		get_size(void) const;

	private:
		Contact	_contacts[SIZE_OF_PHONEBOOK];
		int		_last;
		int		_size;
};
