#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>

using namespace std;

class MenuItem {
public:
  MenuItem(string ccode, string nname, double pprice);
  ~MenuItem();
  string toString();
  double getPrice();
  string getCode();


protected:
private:
  string code, name;
  double price;
};

#endif // MENUITEM_H
