#include <iostream>
#include <ctime>

#include "Account.hpp"

/*--PUBLIC--*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return(Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << _amount << ";closed\n";
}

/*--PRIVATE--*/

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_nbDeposits += 1;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals += 1;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		return (true);
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused\n";
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void )
{
	time_t	taim = time(0);
	tm	*time = gmtime(&taim);
	std::cout << "[" << (time->tm_year + 1900);
	if (time->tm_mon < 9)
		std::cout << "0";
	std::cout << (time->tm_mon + 1);
	if (time->tm_mday < 10)
		std::cout << "0";
	std::cout << time->tm_mday << "_";
	if (time->tm_hour < 9)
		std::cout << "0";
	std::cout << (time->tm_hour + 1 + 1);
	if (time->tm_min < 10)
		std::cout << "0";
	std::cout << (time->tm_min);
	if (time->tm_sec < 10)
		std::cout << "0";
	if (time->tm_sec == 60)
		std::cout << "59";
	else
		std::cout << time->tm_sec;
	std::cout << "] ";
}

Account::Account( void )
{
	_displayTimestamp();
	this->_amount = 0;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}