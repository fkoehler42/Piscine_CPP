/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 09:34:36 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 21:28:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.class.hpp"

Account::Account(int initial_deposit) : counter(0), _accountIndex(_nbAccounts),
_amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	if (initial_deposit > 0)
		this->_amount = initial_deposit;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return;
}

Account::Account(void) : counter(0), _accountIndex(_nbAccounts),
_amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts += 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	if (deposit > 0) {
		_totalAmount += deposit;
		_totalNbDeposits++;
		this->_amount += deposit;
		this->_nbDeposits++;
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:"
		<< deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	}
	else
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:refused" << std::endl;
	return;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal > 0 && this->checkAmount() && (this->_amount - withdrawal >= 0)) {
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:"
		<< withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount(void) const {
	this->counter++;
	return (this->_amount > 0);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:"
	<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}

int		Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int		Account::getTotalAmount(void) {
	return (_totalAmount);
}

int		Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() <<
	";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return;
}

void	Account::_displayTimestamp(void) {
	time_t		timestamp;
	struct tm	*timeinfo;
	char		current_time[19];

	time(&timestamp);
	timeinfo = std::localtime(&timestamp);
	std::strftime(current_time, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << current_time;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;