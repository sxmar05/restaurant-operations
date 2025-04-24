#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"
#include <sstream>

// const int MAX_ITEMS_IN_ORDER = 100;

class Order
{
    public:
        // "A1 A2 B1"
        Order(string OrderString, Menu *menup);
        void addItems(string OrderString, Menu *menup);
        void printReceipt();
        ~Order();
        double total(){
            double cost=0;
            for(int i=0;i<numItems;i++)
                cost+=items[i]->getPrice();
            return cost;
        }

    protected:

    private:
        static const int MAX_ITEMS_IN_ORDER = 100;
        int numItems;
        MenuItem *items[MAX_ITEMS_IN_ORDER];
};

#endif // ORDER_H
