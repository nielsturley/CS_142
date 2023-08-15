//
// Created by Niels Turley on 11/5/20.
//

#include "ShoppingCart.h"

using namespace std;

void ShoppingCart::AddItem(ItemToPurchase newItem) {
    bool foundItem = false;
    for (unsigned int i = 0; i < itemList.size(); ++i) {
        if (newItem.GetName() == itemList.at(i).GetName()) {
            foundItem = true;
            break;
        }
    }
    if (foundItem) {
        cout << "Item is already found in the cart. It will not be added." << endl;
    }
    else {
        itemList.push_back(newItem);
    }

}

void ShoppingCart::RemoveItem(string itemToRemove) {
    bool foundItem = false;
    int index = 0;
    for (unsigned int i = 0; i < itemList.size(); ++i) {
        if (itemToRemove == itemList.at(i).GetName()) {
            foundItem = true;
            index = i;
            break;
        }
    }

    if (foundItem) {
        itemList.erase(itemList.begin() + index);
    }
    else {
        cout << "Item not found in cart. It will not be removed." << endl;
    }

}

void ShoppingCart::UpdateQuantity(string itemToUpdate, int newQuantity) {
    bool foundItem = false;
    int index = 0;
    for (unsigned int i = 0; i < itemList.size(); ++i) {
        if (itemToUpdate == itemList.at(i).GetName()) {
            foundItem = true;
            index = i;
            break;
        }
    }
    if (foundItem) {
        itemList.at(index).SetQuantity(newQuantity);
    }
    else {
        cout << "Item not found in cart. It will not be modified." << endl;
    }


}

int ShoppingCart::TotalQuantity() const {
    int totalQuantity = 0;
    for (unsigned int i = 0; i < itemList.size(); ++i) {
        totalQuantity += itemList.at(i).GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::TotalCost() const {
    double totalCost = 0.0;
    for (unsigned int i = 0; i < itemList.size(); ++i) {
        totalCost += (itemList.at(i).GetPrice() * itemList.at(i).GetQuantity());
    }
    return totalCost;
}

void ShoppingCart::PrintAllDescriptions() const {
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
    if (itemList.size() == 0) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Item Descriptions" << endl;
        for (unsigned int i = 0; i < itemList.size(); ++i) {
            itemList.at(i).PrintDescription();
        }
    }
}

void ShoppingCart::PrintTotals() const {
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
    if (itemList.size() == 0) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Number of Items: " << TotalQuantity() << endl << endl;
        for (unsigned int i = 0; i < itemList.size(); ++i) {
            itemList.at(i).PrintCost();
        }
        cout << endl << "Total: $" << TotalCost() << endl;
    }
}

ShoppingCart::ShoppingCart() {
    vector<ItemToPurchase> itemList;
    customerName = "Nobody's";
    date = "A long time ago...";
}

ShoppingCart::ShoppingCart(string name, string todayDate) {
    vector<ItemToPurchase> itemList;
    customerName = name;
    date = todayDate;
}

