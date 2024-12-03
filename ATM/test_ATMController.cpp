#include "ATMController.h"
#include <cassert>
#include <iostream>

//Test for Creating Account
void TestCreateAccount() {
	ATMController atm;
	//Test for creating same account
	try {
		atm.createAccount("12345", "1111", 2000);
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
}

//Test for Inserting Card
void TestInsertCard() {
	ATMController atm;

	//Test for invalid account
	try {
		atm.insertCard("11111");
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
}

//Test for PIN validation
void TestEnterPin() {
	ATMController atm;
	//Test for no card inserted
	try {
		atm.enterPin("1111");
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}

	atm.insertCard("12345");
	//Test for invalid pin
	try {
		atm.enterPin("1111");
	}
	catch (std::invalid_argument e) {
	}
	//Test for invalid pin
	try {
		atm.enterPin("1112");
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
}

//Test for Checking Balance
void TestSeeBalance() {
	ATMController atm;
	//Test for No Card inserted
	try {
		atm.seeBalance();
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}

	//Test for check balance
	atm.insertCard("12345");
	atm.enterPin("1111");
	assert(atm.seeBalance() == 1000);
}

//Test for Withdraw
void TestWithdraw() {
	ATMController atm;
	//Test for No Card inserted
	try {
		atm.withdraw(500);
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
	atm.insertCard("12345");
	atm.enterPin("1111");
	atm.withdraw(500);
	assert(atm.seeBalance() == 500);

	//Test for insufficient balance
	try {
		atm.withdraw(600);
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
}


//Test for Deposit
void TestDeposit() {
	ATMController atm;
	//Test for No Card inserted
	try {
		atm.deposit(500);
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}

	//Test for deposit
	atm.insertCard("12345");
	atm.enterPin("1111");
	atm.deposit(500);
	assert(atm.seeBalance() == 1500);

	//Test for invalid amount
	try {
		atm.deposit(-500);
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
	try {
		atm.deposit(0);
		assert(false);
	}
	catch (std::invalid_argument e) {
		assert(true);
	}
}


int testATMController() {
	// Run all the tests for ATMController

	try {
		TestCreateAccount();
		TestInsertCard();
		TestEnterPin();
		TestSeeBalance();

		TestWithdraw();

		TestDeposit();
		std::cout << "All ATMController tests passed.\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << "\n";
		return 1;
	}
	return 0;

};
