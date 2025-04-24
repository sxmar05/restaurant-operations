#include "Menu.h"

#include <fstream>
#include <iostream>
Menu::Menu(ifstream &finput) {
    string line, name, code;
    int val;
    double price;
    finput >> val;
    numItems=val;
    getline(finput, line);

    items = new MenuItem* [numItems];
    for(int i=0; i<numItems; i++) {
        finput >> code >> name >> price;
        items[i] = new MenuItem(code, name, price);
    }
}

MenuItem* Menu:: findItem(string input){
    for(int i=0;i<numItems;i++){
        if(items[i]->getCode() == input){
            return items[i];
        }
    }
    return nullptr;
}

Menu::~Menu()
{
   delete items; //dtor
}
