/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:38:41 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:51:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
