#include "ATMController.h"
#include <cassert>
#include <iostream>

//Test for Creating Account
void testCreateAccount() {
	ATMController atm;

	// Create a new account
	try {
		atm.createAccount("67890", "2222", 2000);
		std::cout << "\ttestCreateAccount: New account creation passed.\n";
	}
	catch (...) {
		std::cout << "\ttestCreateAccount: Account creation failed.\n";
		assert(false);
	}

	// Try to create the same account
	try {
		atm.createAccount("67890", "2222", 1500);
		assert(false);  // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestCreateAccount: Duplicate account creation blocked.\n";
	}
}

//Test for Inserting Card
void testInsertCard() {
	ATMController atm;
	//Test for valid account
	try {
		atm.insertCard("12345");
		std::cout << "\ttestInsertCard: Card insertion passed.\n";
	}
	catch (...) {
		std::cout << "\ttestInsertCard: Card insertion failed.\n";
		assert(false);
	}

	// Insert an invalid card
	try {
		atm.insertCard("99999");
		assert(false);  // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestInsertCard: Invalid card insertion blocked.\n";
	}
}

//Test for PIN validation
void testEnterPin() {
	ATMController atm;
	atm.insertCard("12345");

	//Test for valid pin
	try {
		atm.enterPin("1111");
		std::cout << "\ttestEnterPin: Valid PIN passed.\n";
	}
	catch (...) {
		std::cout << "\ttestEnterPin: Valid PIN failed.\n";
		assert(false);
	}

	//Test for invalid pin
	try {
		atm.enterPin("1112");
		assert(false);
	}
	catch (...) {
		std::cout << "\ttestEnterPin: Invalid PIN blocked.\n";
	}
}

//Test for Checking Balance
void testSeeBalance() {
	ATMController atm;
	//Test for No Card inserted
	try {
		atm.seeBalance();
		assert(false);
	}
	catch (...) {
		std::cout << "\ttestSeeBalance: No card insertion passed.\n";
	}

	//Test for check balance
	atm.insertCard("12345");
	atm.enterPin("1111");

	// Check balance
	try {
		int balance = atm.seeBalance();
		assert(balance == 1000);
		std::cout << "\ttestSeeBalance: Balance check passed. Balance.\n";
	}
	catch (...) {
		std::cerr << "\ttestSeeBalance: Balance check failed: " << "\n";
		assert(false);
	}
}

//Test for Withdraw
void testATMWithdraw() {
	ATMController atm;
	//Test for No Card inserted
	try {
		atm.withdraw(500);
		assert(false);
	}
	catch (std::invalid_argument e) {
		std::cout << "\ttestATMWithdraw: No card insertion passed.\n";
	}
	atm.insertCard("12345");
	atm.enterPin("1111");

	// Test valid withdrawal
	try {
		atm.withdraw(500);
		assert(atm.seeBalance() == 500);
		std::cout << "\ttestATMWithdraw: Valid withdrawal passed.\n";
	}
	catch (...) {
		std::cout << "\ttestATMWithdraw: Valid withdrawal failed.\n";
		assert(false);
	}

	// Test withdrawal exceeding balance
	try {
		atm.withdraw(3000);
		assert(false);  // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestATMWithdraw: Excess withdrawal blocked.\n";
	}
}


//Test for Deposit
void testATMDeposit() {
	ATMController atm;
	//Test for No Card inserted
	try {
		atm.deposit(500);
		assert(false);
	}
	catch (...) {
		std::cout << "\ttestATMDeposit: No card insertion passed.\n";
	}

	atm.insertCard("12345");
	atm.enterPin("1111");

	// Test valid deposit
	try {
		atm.deposit(500);
		assert(atm.seeBalance() == 1500);
		std::cout << "\ttestATMDeposit: Valid deposit passed.\n";
	}
	catch (...) {
		std::cout << "\ttestATMDeposit: Valid deposit failed.\n";
		assert(false);
	}

	// Test invalid deposit (negative amount)
	try {
		atm.deposit(-100);
		assert(false);  // Should not reach this line
	}
	catch (...) {
		std::cout << "\ttestATMDeposit: Negative deposit blocked.\n";
	}
}


int testATMController() {
	// Run all the tests for ATMController

	try {
		testCreateAccount();
		testInsertCard();
		testEnterPin();
		testSeeBalance();
		testATMWithdraw();
		testATMDeposit();
		std::cout << "All ATMController tests passed.\n\n";
	}
	catch (const std::exception& e) {
		std::cerr << "ATMController Test failed: " << e.what() << "\n\n";
		return 1;
	}
	return 0;

};
