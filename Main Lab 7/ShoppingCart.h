//
// Created by Niels Turley on 11/5/20.
//

#ifndef PREP_LAB_7_SHOPPINGCART_H
#define PREP_LAB_7_SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <vector>


using namespace std;

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string name, string todayDate);
    string GetCustomerName() const {
        return customerName;
    }
    string GetDate() const {
        return date;
    }
    void AddItem(ItemToPurchase newItem);
    void RemoveItem(string itemToRemove);
    void UpdateQuantity(string itemToUpdate, int newQuantity);
    int TotalQuantity() const;
    double TotalCost() const;
    void PrintAllDescriptions() const;
    void PrintTotals() const;
private:
    string customerName;
    string date;
    vector<ItemToPurchase> itemList;


};
#endif //PREP_LAB_7_SHOPPINGCART_H
