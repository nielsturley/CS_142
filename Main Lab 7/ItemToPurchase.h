//
// Created by Niels Turley on 11/4/20.
//

#ifndef PREP_LAB_7_ITEMTOPURCHASE_H
#define PREP_LAB_7_ITEMTOPURCHASE_H

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    void SetName(string name);
    string GetName() const {
        return itemName;
    }
    void SetPrice(double price);
    double GetPrice() const {
        return itemPrice;
    }
    void SetQuantity(int quantity);
    int GetQuantity() const {
        return itemQuantity;
    }
    string GetDescription() const {
        return itemDescription;
    }
    void SetDescription(string description);
    void PrintCost() const;
    void PrintDescription() const;
private:
    string itemDescription;
    string itemName;
    double itemPrice;
    int itemQuantity;
};




#endif //PREP_LAB_7_ITEMTOPURCHASE_H
