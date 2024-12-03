#include "ATMController.h"
#include "Account.h"
#include <stdexcept>
#include <string>



ATMController::ATMController() {
	accounts["12345"] = Account("12345", "1111", 1000);
	accounts["54321"] = Account("54321", "5678", 500);
}

// Create account
void ATMController::createAccount(const std::string accountNumber, const std::string pin, int balance) {
	if (accounts.find(accountNumber) != accounts.end()) {
		throw std::invalid_argument("Account already exists");
	}
	accounts[accountNumber] = Account(accountNumber, pin, balance);
}

// Card insertion
void ATMController::insertCard(const std::string& accountNumber) {
	if (accounts.find(accountNumber) == accounts.end()) {
		throw std::invalid_argument("Invalid account number");
	}
	currentAccount = &accounts[accountNumber];
}

// Enter pin
void ATMController::enterPin(const std::string& pin) {
	if (!currentAccount) {
		throw std::invalid_argument("No card inserted");
	}
	if (!currentAccount->checkPin(pin)) {
		throw std::invalid_argument("Invalid pin");
	}
}

// See balance
int ATMController::seeBalance() const {
	if (!currentAccount) {
		throw std::invalid_argument("No card inserted");
	}
	return currentAccount->getBalance();
}


// withdraw
int ATMController::withdraw(int amount) {
	if (!currentAccount) {
		throw std::invalid_argument("No card inserted");
	}
	if (amount <= 0) {
		throw std::invalid_argument("Withdraw amount must be positive");
	}
	if (currentAccount->getBalance() < amount) {
		throw std::invalid_argument("Insufficient balance");
	}
	currentAccount->withdraw(amount);
	return currentAccount->getBalance();
}

//deposit
int ATMController::deposit(int amount) {
	if (!currentAccount) {
		throw std::invalid_argument("No card inserted");
	}
	if (amount <= 0) {
		throw std::invalid_argument("Deposit amount must be positive");
	}
	currentAccount->deposit(amount);
	return currentAccount->getBalance();
}


