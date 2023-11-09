/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:39:05 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 01:39:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::ostringstream	message;

	Account::_displayTimestamp();
	message		<< "accounts:"		<< Account::_nbAccounts			<< ";"
				<< "total:"			<< Account::_totalAmount		<< ";"
				<< "deposits:"		<< Account::_totalNbDeposits	<< ";"
				<< "withdrawals:"	<< Account::_totalNbWithdrawals	<< std::endl;
	std::cout	<< message.str();
}

Account::Account( int initial_deposit )
{
	std::ostringstream	message;

	_accountIndex = Account::_nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	message		<< "index:"		<< _accountIndex	<< ";"
				<< "amount:"	<< _amount			<< ";"
				<< "created"						<< std::endl;
	std::cout	<< message.str();
}

Account::~Account( void )
{
	std::ostringstream	message;

	Account::_displayTimestamp();
	message		<< "index:"		<< _accountIndex	<< ";"
				<< "amount:"	<< _amount			<< ";"
				<< "closed"							<< std::endl;
	std::cout	<< message.str();
}

void	Account::makeDeposit( int deposit )
{
	std::ostringstream	message;

	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	message		<< "index:"			<< _accountIndex		<< ";"
				<< "p_amount:"		<< _amount - deposit	<< ";"
				<< "deposit:"		<< deposit				<< ";"
				<< "amount:"		<< _amount				<< ";"
				<< "nb_deposits:"	<< _nbDeposits			<< std::endl;
	std::cout	<< message.str();
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::ostringstream	message;

	Account::_displayTimestamp();
	message		<< "index:"				<< _accountIndex	<< ";"
				<< "p_amount:"			<< _amount			<< ";";
	if (withdrawal > _amount)
	{
		message << "withdrawal:refused" << std::endl;
		std::cout << message.str();
		return (false);
	}
	_amount -= withdrawal;
	Account::_totalAmount -=withdrawal;
	_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	message		<< "withdrawal:"		<< withdrawal		<< ";"
				<< "amount:"			<< _amount			<< ";"
				<< "nb_withdrawals:"	<< _nbWithdrawals	<< std::endl;
	std::cout	<< message.str();
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	std::ostringstream	message;
	Account::_displayTimestamp();
	message		<< "index:"			<< _accountIndex	<< ";"
				<< "amount:"		<< _amount			<< ";"
				<< "deposits:"		<< _nbDeposits		<< ";"
				<< "whitdrawals:"	<< _nbWithdrawals	<< std::endl;
	std::cout	<< message.str();
}

void	Account::_displayTimestamp( void )
{
	time_t	currentTime;
	struct	tm *localTime;
	std::ostringstream	message;

	time(&currentTime);
	localTime = localtime(&currentTime);
	message		<< "["									<< localTime->tm_year + 1900
				<< std::setw(2)	<< std::setfill('0')	<< localTime->tm_mon + 1
				<< std::setw(2)	<< std::setfill('0')	<< localTime->tm_mday
				<< "_"
				<< std::setw(2)	<< std::setfill('0')	<< localTime->tm_hour
				<< std::setw(2)	<< std::setfill('0')	<< localTime->tm_min
				<< std::setw(2)	<< std::setfill('0')	<< localTime->tm_sec
				<< "] ";
	std::cout	<< message.str();
}
