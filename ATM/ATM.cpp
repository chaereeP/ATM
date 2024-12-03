#include "ATMController.h"
#include "Account.h"
#include <iostream>


int main() {
	ATMController atm;
	try {
		atm.createAccount("123456", "1111", 1000);
		atm.createAccount("111111", "1111", 1000);
		atm.insertCard("123456");
		atm.enterPin("1111");
		atm.withdraw(500);
		std::cout << atm.seeBalance() << std::endl;
		atm.deposit(500);
		std::cout << atm.seeBalance() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
};