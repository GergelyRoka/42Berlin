/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:38:59 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:55:54 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PhoneBook.hpp"

#include <string>
#include <iostream>
#include <iomanip>

#define START_MESSAGE "Commands: ADD, SEARCH, EXIT"
#define WRONG_CMD_MSG "Wrong command. Try again!"
#define EOF_MSG	"Got EOF, program is exiting..."
#define ERROR_FORMAT "Error : the input should contain some fancy character"

class Program
{
	public:
		Program(void);
		~Program(void);

	private:
		PhoneBook	_phonebook;

		void		_run(void);
		void		_add(void);
		void		_search(void) const;
		void		_exit(void);
		void		_list_contacts(void) const;
		void		_print_contact(int n) const;
		void		_my_trimm(std::string &str);
		bool		_get_input(std::string &str, std::string type);
};
