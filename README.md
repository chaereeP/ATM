# ATM

## Build Instruction
### Build the project
```
g++ -o atm Account.cpp ATMController.cpp test_ATMController.cpp test_Account.cpp test_main.cpp
```
```
./atm 
```

### Clone the repository
```
git clone git@github.com:chaereeP/ATM.git
```
```
cd atm
```

## 
## Description
This project simulates an ATM Controller with the following features:
- Create Account
- Insert Card
- Validate Pin
- See Balance
- Deposit and witrhdraw money

## Testing
- Test card insertion
- Test invalid pin handling
- Test invalid account selection
- Test invalid behavior when no account is selected
- Test invalid behavior when no PIN is inserted
- Test invalid deposit and withdraw amount