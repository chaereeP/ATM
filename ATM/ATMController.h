#ifndef ATMCONTROLLER_H
#define ATMCONTROLLER_H

#include "Account.h"
#include <map>
#include <string>

class ATMController {
public:
    ATMController();
    void createAccount(const std::string accountNumber, const std::string pin, int balance);
    void insertCard(const std::string& accountNumber);
    void enterPin(const std::string& pin);
    int seeBalance() const;
    int withdraw(int amount);
    int deposit(int amount);

private:
    std::map<std::string, Account> accounts;
    Account* currentAccount = nullptr;


};

#endif // ATMCONTROLLER_H