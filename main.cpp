#include <iostream>
#include <fstream>

#include "Table.h"

using namespace std;

int main()
{
    ifstream finput("config.txt");
    Menu menu(finput);

    Table **tables;
    int numTables,tableId, capacity,value;
    //read remaining file & get table information
    string line;
  
    getline(finput,line);//empty spacing line
    finput >> numTables;
    getline(finput,line);//empty spacing line
    tables = new Table* [numTables];
    for(int i=0;i<numTables;i++){
        //cout<<"t"<<tableId<<"C"<<capacity<<endl;
        finput >> tableId >> capacity;
        tables[i] = new Table(tableId, capacity);
    }
    //read the commands and process them!
    bool end = false;
  
    while(!end){
      getline(cin,line);
      if(!isdigit(line[0])){
        end=true;
      }
      else{
        string command;
        istringstream istr(line);
        istr >> tableId;
        //istr >> command;
        getline(istr,command);
        //cout<<"command:"<<command<<"  tableID:"<<to_string(tableId)<<" command[1]:"<<command[1]<<endl;

        if(command[1]=='C'){
          //cout<<"reached C in main";
          tables[tableId-1]->cleanup();
        }
        else if(command[1]=='P'){
          capacity=stoi(command.substr(2));
          tables[tableId-1]->seatParty(capacity);
        }
        else if(command[1]=='O'){
          string orders=command.substr(2);
          istringstream order(orders);
          string item;
          int count=0;
          while(order >> item){
          //  //cout<<"item "<<item<<endl;
            if(menu.findItem(item)){
             count++;
            }
           }
           tables[tableId-1]->placeOrder(orders,&menu,count);
        }
        else if(command[1]=='S'){
          tables[tableId-1]->serve();
          //cout<<"finished s";
        }
      }
      
    }
    
    return 0;
}
