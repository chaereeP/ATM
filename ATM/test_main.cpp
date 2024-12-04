#include "ATMController.h"
#include "Account.h"
#include "test_Account.h"
#include "test_ATMController.h"
#include <iostream>
#include <cassert>



int main() {
	std::cout << "========== Starting Test Suite ==========\n\n";

	// Run all the tests for Account
	std::cout << "[TEST]Running Account tests...\n";
	int accountTestsResult = testAccount();

	// Run all the tests for ATMController
	std::cout << "[TEST] Running ATMController tests...\n";
	int atmTestsResult = testATMController();

	std::cout << "[PASS] All tests completed successfully.\n";
	return 0;
}