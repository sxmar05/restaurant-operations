#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"

class Menu
{
    public:
        Menu(ifstream &finput);
        MenuItem *findItem(string input);
        ~Menu();
    protected:

    private:
        int numItems;
        MenuItem **items;
};

#endif // MENU_H
