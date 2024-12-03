#include "Account.h"
#include <cassert>
#include <iostream>

void test_() {
	Account account("12345", "1111", 500);

	// Test PIN validation
	assert(account.checkPin("1000") == false);
	assert(account.checkPin("1111") == true);


	// Test balance inquiry
	assert(account.getBalance() == 500);
	// Test balance inquiry after invalid pin
	account.checkPin("1000");
	try {
		account.getBalance();
	}
	catch (...) {
		std::cout << "Balance inquiry after invalid pin passed.\n";
	}

	// Test deposit
	account.checkPin("1111");
	account.deposit(100);
	assert(account.getBalance() == 600);
	// Test deposit after invalid pin
	try {
		account.checkPin("1000");
		account.deposit(100);
	}
	catch (...) {
		std::cout << "Deposit after invalid pin passed.\n";
	}
	// Test negative deposit
	account.checkPin("1111");
	try {
		account.deposit(-100);
	}
	catch (...) {
		std::cout << "Negative deposit passed.\n";
	}


	// Test withdrawal
	account.withdraw(200);
	assert(account.getBalance() == 400);
	// Test withdrawal after invalid pin
	try {
		account.checkPin("1000");
		account.withdraw(100);
		assert(false);
	}
	catch (...) {
		std::cout << "Withdrawal after invalid pin passed.\n";
	}
	// Test negative withdrawal
	account.checkPin("1111");
	try {
		account.withdraw(-100);
		assert(false);
	}
	catch (...) {
		std::cout << "Negative withdrawal passed.\n";
	}
	// Test insufficient balance
	try {
		account.withdraw(1000);
		assert(false);
	}
	catch (...) {
		std::cout << "Insufficient balance passed.\n";
	}
}

int testAccount() {
	// Run all the tests for ATMController

	try {
		test_();
		std::cout << "All Account tests passed.\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << "\n";
		return 1;
	}
	return 0;
};