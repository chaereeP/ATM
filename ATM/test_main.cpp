#include "ATMController.h"
#include "Account.h"
#include "test_Account.h"
#include "test_ATMController.h"
#include <iostream>
#include <cassert>



int main() {
	std::cout << "Starting tests...\n\n\n";

	// Run all the tests for Account
	std::cout << "Running Account tests...\n";
	int accountTestsResult = testAccount();

	// Run all the tests for ATMController
	std::cout << "Running ATMController tests...\n";
	int atmTestsResult = testATMController();

	std::cout << "All tests completed successfully.\n";
	return 0;
}