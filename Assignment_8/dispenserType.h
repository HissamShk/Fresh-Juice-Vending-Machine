class dispenserType
{
public:
    /*Function to show the Number of Items, present in the Machine.*/
    int getNoOfItems() const;
    /*Function to retrieve the cost that has been set.*/
    int getCost() const;
    /*Function to decrement the stock of an item by 1 on sale*/
    void makeSale();
    /*Default Constructor*/
    dispenserType();
    /*Constructor with Parameters*/
    dispenserType(int setNoOfItems, int setCost);
private:
    /*Variable to store the Number of Items in the Dispenser*/
    int numberOfItems;
    /*Variable to store the Cost of an Item*/
    int cost;
};
