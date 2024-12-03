#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
class Account {
public:
	Account();
	Account(const std::string& accountNumber,const std::string& pin, int balance);
	bool checkPin(const std::string& pin) const;
	int getBalance() const;
	void deposit(int amount);
	void withdraw(int amount);

private:
	std::string accountNumber;
	std::string pin ;
	int balance;
	mutable bool isPinValidated = false;
};


#endif //ACCOUNT_H
