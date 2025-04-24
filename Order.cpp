#include "Order.h"
#include <string>
#include <sstream>
#include <iomanip>

  // "A1 A2 B1"
Order::Order(string OrderString, Menu *menup){
  numItems=0;
  //go through menu list and find items
  istringstream istr(OrderString);
  string foodItem;
   while(istr>>foodItem){
    MenuItem* orderedfood=menup->findItem(foodItem);
    if(orderedfood!=nullptr){
      //total += orderedfood->getPrice();
      *(items+numItems)=orderedfood;
      numItems++;
    }
    else{
      //item is not on menu
       cout<<"No item with code "<<foodItem<<endl;
    } 
  }

}
void Order:: addItems(string OrderString, Menu *menup){
  istringstream istr(OrderString);
  string foodItem;
  bool flag = true;
  while(istr>>foodItem){
    MenuItem* orderedfood=menup->findItem(foodItem);
    if(orderedfood!=nullptr){
      //total += orderedfood->getPrice();
      *(items+numItems)=orderedfood;
      numItems++;
    }
    else{
      //item is not on menu
       cout<<"No item with code "<<foodItem<<endl;
       flag = false;
    } 
    //return flag;
  }
  
}
void Order::printReceipt(){
  for(int i=0;i<numItems;i++){
    cout<<items[i]->toString()<<endl;
  }
  cout<<setw(24)<<right<<"Total "<<setprecision(4)<<total()<<endl;
}

Order::~Order()
{
    //dtor
  delete *items;
}
