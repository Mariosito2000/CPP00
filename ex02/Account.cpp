#include "Account.hpp"
#include <iostream>
#include <ctime>

/*--PUBLIC--*/

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
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
	std::cout << "accounts:%d;total:%d;deposits:%d;withdrawals:%d\n",
	getNbAccounts(), getTotalAmount(), getNbDeposits(), getNbWithdrawals();
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;
	std::cout << "index:%d;amount:%d;created\n", this->_accountIndex, this->_amount;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:%d;amount:%d;closed\n", _accountIndex, _amount;
	delete (this);
}

/*--PRIVATE--*/

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_nbDeposits += 1;
	std::cout << "index:%d;p_amount:%d;", this->_accountIndex, this->_amount;
	this->_amount += deposit;
	std::cout << "deposit:%d;amount:%d;nb_deposits:%d\n", deposit, this->_amount, this->_nbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals += 1;
		std::cout << "index:%d;p_amount:%d;", this->_accountIndex, _amount;
		this->_amount -= withdrawal;
		std::cout << "withdrawal:%d;amount:%d;nb_withdrawals:%d\n", withdrawal, _amount, _nbWithdrawals;
		return (true);
	}
	else
	{
		std::cout << "index:%d;p_amount:%d;withdrawal:refused\n", _accountIndex, _amount;
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
	std::cout << "index:%d;amount:%d;deposits:%d;withdrawals:%d;\n",this->_accountIndex;
}

void	Account::_displayTimestamp( void )
{
	time_t	taim = time(0);
	tm	*time = gmtime(&taim);
	char* dt = ctime(&taim);
	dt = asctime(time);
	std::cout << "Time is [" << dt << std::endl;
}

Account::Account( void )
{
	_displayTimestamp();
	this->_amount = 0;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	std::cout << "index:%d;amount:%d;created\n", _accountIndex, _amount;
}