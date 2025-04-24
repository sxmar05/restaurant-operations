#include "MenuItem.h"
#include <sstream>
//#include <string>
#include <iomanip>

MenuItem::MenuItem(string ccode, string nname, double pprice)
{ 
    code=ccode;
    name=nname;
    price=pprice;
}
string MenuItem::toString() {
  ostringstream oss;
  oss << code <<setw(19)<<right<< name << "   " << price;//you need setw here
  return oss.str();
}
double MenuItem:: getPrice(){
  return price;
}
string MenuItem:: getCode(){
  return code;
}
MenuItem:: ~MenuItem()
{
  ;  //dtor
}
//cout<<fixed<<setw()