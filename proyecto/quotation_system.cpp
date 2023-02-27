#include <iostream>
#include <string.h>
#include "presentation/Presenter.h"

using namespace std;

int main()
{
    Presenter *presenter = new Presenter();
    presenter->present_menu();
    return 0;
}