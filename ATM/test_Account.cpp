#include "Account.h"
#include <cassert>
#include <iostream>
// Test for PIN validation
void testPinValidation() {
	Account account("12345", "1111", 500);

	// Valid PIN
	assert(account.checkPin("1111") == true);
	std::cout << "\ttestPinValidation: Valid PIN passed.\n";
	// Invalid PIN
	assert(account.checkPin("1000") == false);
	std::cout << "\ttestPinValidation: Invalid PIN passed.\n";
}

// Test for balance inquiry
void testBalanceInquiry() {
	Account account("12345", "1111", 500);

	// PIN must be validated before checking balance
	try {
		account.getBalance();
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestBalanceInquiry: Balance inquiry without PIN validation blocked.\n";
	}

	// Validate PIN and check balance
	account.checkPin("1111");
	assert(account.getBalance() == 500);
	std::cout << "\ttestBalanceInquiry: Valid balance inquiry passed.\n";
}

// Test for deposits
void testDeposit() {
	Account account("12345", "1111", 500);

	// Deposit without PIN validation
	try {
		account.deposit(100);
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestDeposit: Deposit without PIN validation blocked.\n";
	}

	// Validate PIN and perform deposit
	account.checkPin("1111");
	account.deposit(200);
	assert(account.getBalance() == 700);
	std::cout << "\ttestDeposit: Valid deposit passed.\n";

	// Negative deposit
	try {
		account.deposit(-100);
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestDeposit: Negative deposit blocked.\n";
	}

	// Zero deposit
	try {
		account.deposit(0);
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestDeposit: Zero deposit blocked.\n";
	}
}


// Test for withdrawal
void testWithdraw() {
	Account account("12345", "1111", 500);

	// Withdraw without PIN validation
	try {
		account.withdraw(100);
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestWithdraw: Withdrawal without PIN validation blocked.\n";
	}

	// Test withdrawal after invalid pin
	try {
		account.checkPin("1000");
		account.withdraw(100);
	}
	catch (...) {
		std::cout << "\ttestWithdraw: Withdrawal after invalid pin passed.\n";
	}

	// Validate PIN and perform withdrawal
	account.checkPin("1111");
	account.withdraw(200);
	assert(account.getBalance() == 300);
	std::cout << "\ttestWithdraw: Valid withdrawal passed.\n";


	// Test negative withdrawal
	try {
		account.withdraw(-100);
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestWithdraw: Negative withdrawal blocked.\n";
	}

	// Test exceeding balance
	try {
		account.withdraw(1000);
		assert(false); // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestWithdraw: Insufficient balance blocked.\n";
	}
}

int testAccount() {
	// Run all the tests for ATMController
	try {
		testPinValidation();
		testBalanceInquiry();
		testDeposit();
		testWithdraw();
		std::cout << "All Account tests passed.\n\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Account Test failed: " << e.what() << "\n\n";
		return 1;
	}
	return 0;
};