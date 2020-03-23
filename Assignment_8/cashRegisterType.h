class cashRegisterType
{
public:
    /*Function to retrieve the Amount of Money in the Register*/
    int getCurrentBalance() const;
    /*Function to add money into the Register*/
    void acceptAmount(int amountIn);
    /*Default Constructor*/
    cashRegisterType();
    /*Constructor with Parameters*/
    cashRegisterType(int cashIn);
private:
    /*Variable to store the Cash in the Register*/
    int cashOnHand;
};
