#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

using std::cout;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "created" << "\n";
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
}

Account::~Account()
{
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "closed" << "\n";
}

void Account::_displayTimestamp(void)
{
    time_t      t_stmp_ptr;
    struct tm   *t_stmp;

    std::time(&t_stmp_ptr);
    t_stmp = localtime(&t_stmp_ptr);
    cout << "[";
    cout << t_stmp->tm_year + 1900;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
    cout << "] ";
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    cout << "accounts:" << getNbAccounts() << ";"
         << "total:" << getTotalAmount() << ";"
         << "deposits:" << getNbDeposits() << ";"
         << "withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::displayStatus() const{
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "deposits:" << this->_nbDeposits << ";"
         << "withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit){
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	 _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount << ";"
         << "deposit:" << deposit << ";"
         << "amount:" << this->_amount + deposit << ";"
		 << "deposits:" << this->_nbDeposits + 1 << "\n";
	this->_nbDeposits++;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount << ";"
         << "withdrawal:";
	if (withdrawal <= this->_amount)
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
    	cout << withdrawal << ";"
         	 << "amount:" << this->_amount << ";"
		 	 << "withdrawals:" << this->_nbWithdrawals << "\n";
		return (true);
	}
	cout << "refused" << "\n";
	return (false);
	
	
}

int		Account::checkAmount( void ) const{
	if (this->_amount >= 0)
		return 1;
	return 0;
}