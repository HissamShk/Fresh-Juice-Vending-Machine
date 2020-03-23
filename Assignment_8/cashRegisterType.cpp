#include <iostream>
#include "cashRegisterType.h"
using namespace std;
int cashRegisterType::getCurrentBalance() const
{
    return cashOnHand;
}
void cashRegisterType::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}
cashRegisterType::cashRegisterType()
{
    cashOnHand = 500;
}
cashRegisterType::cashRegisterType(int cashIn)
{
    if (cashIn >= 0)
        cashOnHand = cashIn;
    else
        cashOnHand = 500;
}
