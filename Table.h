#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
#include "Order.h"

//TABLE status: IDLE --> SEATED --> ORDERED --> SERVED

enum TableStatus { IDLE, SEATED, ORDERED, SERVED};
//                   0     1       2         3

class Table 
{
    public:
        Table(int tableId, int capacity);
        bool seatParty(int numGuests);
        int atTable(){
            return partySize;
        }
        bool hasOrder(){
          if((int)status>=2)
            return true;
          return false;
        }
        void setStatus(int stat){
          status=(TableStatus)stat;
        }
        ~Table();
        // IDLE / ORDERED / SERVED --> ORDEDED
        void placeOrder(string str, Menu *menup, int count);
        void serve(); // ORDERED --> SERVED
        bool cleanup(); // SERVED --> IDLE
        int maxCap();

    protected:

    private:
        int tableId, capacity,guests;
        int partySize,placedOrder;
        TableStatus status; //status = IDLE;
        Order *orderp=nullptr;
        
};

#endif // TABLE_H
