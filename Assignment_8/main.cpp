/*Two Classes (Juice Machine) by Hissamuddin Shaikh*/
#include <iostream>
#include "cashRegisterType.h"
#include "dispenserType.h"
#include <iomanip>
using namespace std;
/*Function Setup(Prototypes)*/
void InterfaceandInputSetup();
void DispenseProduct(dispenserType& Product, cashRegisterType& cashDeposited);
char InputErrorControl(char);
/*Main Function*/
int main()
{
    /*Variable and Object Setup*/
    cashRegisterType CRT;
    dispenserType AppleJuice(5,95);
    dispenserType OrangeJuice(5,80);
    dispenserType MangoJuice(5,75);
    dispenserType BananaJuice(5,50);
    char Selection;
    char A;
    /*Set up for showing the option for Juices*/
    InterfaceandInputSetup();
    cin >> Selection;
    /*Error Control for Selection*/
    A = InputErrorControl(Selection);
    /*Dispensing Setup*/
    while (A != 'E')
    {
        switch (A)
        {
            case 'A':
                DispenseProduct(AppleJuice, CRT);
                break;
            case 'B':
                DispenseProduct(OrangeJuice, CRT);
                break;
            case 'C':
                DispenseProduct(MangoJuice, CRT);
                break;
            case 'D':
                DispenseProduct(BananaJuice, CRT);
                break;
            default:
                cout << endl << setw(22) << "Invalid selection." << endl;
                cout << endl << setw(75) << "-----------------------------------------------------------------------" << endl;
                break;
        }
    /*Setup for the End Condition*/
    InterfaceandInputSetup();
    cin >> Selection;
    /*Error Control for Selection*/
    A = InputErrorControl(Selection);
    }
    return 0;
}
/*Setup for the Function to Display the Menu*/
void InterfaceandInputSetup()
{
    cout << endl << setw(31) << "Fresh-Juice Vending Machine" << endl << endl;
    cout << setw(19) << "A - Apple Juice" << endl << endl;
    cout << setw(20) << "B - Orange Juice" << endl << endl;
    cout << setw(19) << "C - Mango Juice" << endl << endl;
    cout << setw(20) << "D - Banana Juice" << endl << endl;
    cout << setw(20) << "E - Exit Program" << endl << endl;
    cout << setw(82) << "Please Enter A, B, C, D, or E, depending on which Juice you wish to purchase: ";
}
/*Setup for the Function to make sure that the Program interprets the User Input Correctly*/
char InputErrorControl(char Input)
{
    if (Input == 'a')
        Input = 'A';
    else if (Input == 'b')
        Input = 'B';
    else if (Input == 'c')
        Input = 'C';
    else if (Input == 'd')
        Input = 'D';
    else if (Input == 'e')
        Input = 'E';

    return Input;
}
/*Setup for the Function to take Money in and Dispense Product*/
void DispenseProduct(dispenserType& Product, cashRegisterType& cashDeposited)
{
    int MoneyEntered;
    int MoneyNeeded;
    int MoneyChange;
    if (Product.getNoOfItems() > 0)
    {
        cout << endl << setw(19) << "Please Deposit " << Product.getCost()
             << " Cents: ";
        cin >> MoneyEntered;
        if ( MoneyEntered < Product.getCost())
        {
            cout << endl <<setw(19) << "Please Deposit "
            << Product.getCost()- MoneyEntered << " Cents more: ";
            cin >> MoneyNeeded;
            MoneyEntered = MoneyEntered + MoneyNeeded;
        }
        if ( MoneyEntered < Product.getCost())
        {
            cout<< endl << setw(58) <<"**Transaction Terminated, due to Insufficient Funds.**" << endl;
        }
        if (MoneyEntered == Product.getCost())
        {
            cashDeposited.acceptAmount(MoneyEntered);
            Product.makeSale();
            cout << endl << setw(61) << "Collect your Item from the Bottom of the Vending Machine." << endl;
            cout << endl<< setw(12)<< "Enjoy!!." << endl;
        }
        else if (MoneyEntered > Product.getCost())
        {
            MoneyChange = MoneyEntered - Product.getCost();
            cashDeposited.acceptAmount(Product.getCost());
            Product.makeSale();
            cout << endl << setw(76)<< "Collect your Item from the Bottom of the Vending Machine, and Change of " <<
            MoneyChange <<" Cents from the Change Compartment." << endl;
            cout << endl<< setw(12)<< "Enjoy!!." << endl;
        }
        cout << endl << setw(75) << "-----------------------------------------------------------------------" << endl;
    }
    else
        {
            cout << endl <<setw(33) << "Sorry, this Item is Sold Out." << endl;
            cout << endl << setw(75) << "-----------------------------------------------------------------------" << endl;
        }
}
