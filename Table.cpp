#include "Table.h"

Table::Table(int tableId, int capacity)
{
    //ctor
  this->tableId = tableId;
  this->capacity = capacity;
  status = IDLE;
}
bool Table::seatParty(int numGuests){
  //cout<<"my cap "<<capacity;
  if(status!=IDLE){
    cout<<"Table "+to_string(tableId)+" already occupied!\n";
  }
  else if(numGuests <= capacity){
    status=(TableStatus)((int)(status+1));
    guests=numGuests;
    cout<<"Party of "+to_string(numGuests)+" assigned to Table "+to_string(tableId)+"\n";
    return true;
  }//"Party of "+to_string(capacity)+" assigned to Table "+to_string(tableId):tables[tableId-1]->atTable()!=0?"Table "+to_string(tableId)+" already occupied!":"Sorry, max "+to_string(tables[tableId-1]->maxCap())+" seats in Table "+to_string(tableId)+"!";
 
  else{
    cout<<"Sorry, max "+to_string(capacity)+" seats in Table "+to_string(tableId)+"!";
    return false;
  }
}

int Table:: maxCap(){
  return capacity;
}

// IDLE(empty?) / ORDERED / SERVED --> ORDEDED
void Table::placeOrder(string str, Menu *menup,int count){
  //no takeout?? bruh -_-
  if(status==IDLE){
    cout<<"YOU CANT ORDER BITCH"<<endl;
    
  }
  else{
    //cout<<"can order"<<endl;
    
    if(!orderp){
      
      orderp = new Order(str, menup);
      cout<<to_string(count)<<" items ordered for Table "<<to_string(this->tableId)<<endl;
    }
    else{
      cout<<to_string(count)<<" additional items ordered for Table "<<to_string(this->tableId)<<endl;
      orderp->addItems(str, menup);
    }
    status=ORDERED;
  }
 
  
}

void Table::serve(){
  if(status==ORDERED){
    status=SERVED;
    cout<<"Food served in table "+to_string(tableId)<<endl;
    //return true;
  }
  else
    cout<<"Order not placed at Table "+to_string(tableId)+" yet!"<<endl;
  //return false;
  
} // ORDERED --> SERVED
bool Table::cleanup(){
  //cout<<"start cleanup";
  if(status==SERVED){
    status=IDLE;
    cout<<"Table "+to_string(tableId)+" is closed. Here is the bill.\n\nReceipt Table# "<<
    to_string(tableId)<<" Party "<<to_string(guests)<<endl;
    orderp->printReceipt();
    return true;
  }
  cout<<"Food not served for Table "+to_string(tableId)+" yet!";
  return false;
}// SERVED --> IDLE

Table::~Table()
{
   delete orderp; //dtor
}
