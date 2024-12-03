#include "Account.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
Account::Account()
	: accountNumber(""), pin(""), balance(0) {}

Account::Account(const std::string& accountNumber, const std::string& pin, int initialBalance)
	: accountNumber(accountNumber), pin(pin), balance(initialBalance) {}

bool Account::checkPin(const string& inputpin) const {
	if (pin == inputpin) {
		isPinValidated = true;
		return true;
	}
	isPinValidated = false;
	return false;
}

int Account::getBalance() const {
	if (!isPinValidated) {
		throw invalid_argument("Pin not validated");
	}
	return balance;
}

void Account::deposit(int amount) {
	if (!isPinValidated) {
		throw invalid_argument("Pin not validated");
	}
	if (amount <= 0) {
		throw invalid_argument("Deposit amount must be positive");
	}
	balance += amount;
}

void Account::withdraw(int amount) {
	if (!isPinValidated) {
		throw invalid_argument("Pin not validated");
	}
	if (amount < 0) {
		throw invalid_argument("Withdraw amount must be positive");
	}
	if (balance < amount) {
		throw invalid_argument("Insufficient balance");
	}
	balance -= amount;
}