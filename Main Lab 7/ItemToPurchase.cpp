//
// Created by Niels Turley on 11/4/20.
//

#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase() {
    itemDescription = "none";
    itemName = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

void ItemToPurchase::PrintCost() const {
    cout << fixed << setprecision(2);
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}

void ItemToPurchase::PrintDescription() const {
    cout << itemName << ": " << itemDescription << endl;
}

