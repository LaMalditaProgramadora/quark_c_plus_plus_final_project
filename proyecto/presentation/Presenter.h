#include <iostream>
#include <string.h>
#include "../model/ClothingStore.h"
#include "../model/Seller.h"
#include "../model/Quotation.h"
#include "../model/Pants.h"
#include "../model/Shirt.h"
#include "QuotationSystem.h"
#include "../view/Screen.h"

using namespace std;

class Presenter
{
private:
    QuotationSystem *quotation_system;
    Screen *screen;
    Clothes *clothes;
    Quotation *quotation;
    int id_number;
    string quality;
    string sleeve_type;
    string collar_type;
    string cut_type;
    double unit_price;
    int quantity;
    int option;
    void present_principal_menu();
    void present_quotation_history_menu();
    void present_new_quotation_menu();
    void clearAuxData();

public:
    Presenter();
    void present_menu();
};

Presenter::Presenter()
{
    clothes = new Clothes();
    quotation = new Quotation();
    quotation_system = new QuotationSystem();
    quotation_system->init_data();
    screen = new Screen();
    id_number = 1;
    quality = "";
    sleeve_type = "";
    collar_type = "";
    cut_type = "";
    unit_price = 0;
    quantity = 0;
    option = 0;
}

void Presenter::clearAuxData()
{
    id_number++;
    quality = "";
    sleeve_type = "";
    collar_type = "";
    cut_type = "";
    unit_price = 0;
    quantity = 0;
}

void Presenter::present_principal_menu()
{
    option = 0;
    while (option != 1 && option != 2 && option != 3)
    {
        screen->clean();
        screen->get_principal_menu(quotation_system->get_clothing_store_header(), quotation_system->get_seller_header());
        cin >> option;
    }
}

void Presenter::present_quotation_history_menu()
{
    option = 0;
    while (option != 3)
    {
        screen->clean();
        screen->get_quotation_history_menu(quotation_system->get_quotation_list());
        cin >> option;
    }
}

void Presenter::present_new_quotation_menu()
{
    option = 0;
    while (option != 1 && option != 2)
    {
        screen->clean();
        screen->get_new_quotation_menu_step_1_name();
        cin >> option;
    }

    if (option == 1)
    {
        option = 0;
        while (option != 1 && option != 2)
        {
            screen->clean();
            screen->get_new_quotation_menu_step_2_a_shirt_sleeve_type();
            cin >> option;
        }
        sleeve_type = option == 1 ? "Manga corta" : "Manga larga";
        option = 0;
        while (option != 1 && option != 2)
        {
            screen->clean();
            screen->get_new_quotation_menu_step_2_b_shirt_collar_type();
            cin >> option;
        }
        collar_type = option == 1 ? "Cuello mao" : "Cuello común";
    }
    else
    {
        option = 0;
        while (option != 1 && option != 2)
        {
            screen->clean();
            screen->get_new_quotation_menu_step_2_pants_cut_type();
            cin >> option;
        }
        cut_type = option == 1 ? "Chupín" : "Común";
    }

    option = 0;
    while (option != 1 && option != 2)
    {
        screen->clean();
        screen->get_new_quotation_menu_step_3_quality();
        cin >> option;
    }
    quality = option == 1 ? "Standard" : "Premium";

    option = 0;
    unit_price = 0;
    while (unit_price <= 0)
    {
        screen->clean();
        screen->get_new_quotation_menu_step_4_unit_price();
        cin >> unit_price;
    }

    clothes = quotation_system->find_clothes(quality, sleeve_type, collar_type, cut_type);
    quantity = 0;
    while (quantity <= 0 || quotation == NULL)
    {
        screen->clean();
        if (quotation == NULL)
        {
            cout << "ERROR: No se puede realizar una cotización sobre una cantidad de stock no disponible" << endl;
            cout << "-------------------------------------------------------------------" << endl;
        }
        screen->get_new_quotation_menu_step_5_stock(clothes->get_stock());
        cin >> quantity;
        if (quantity > 0)
            quotation = quotation_system->add_quotation(id_number, clothes, unit_price, quantity);
    }

    option = 0;
    while (option != 3)
    {
        screen->clean();
        screen->get_new_quotation_menu_result(quotation);
        cin >> option;
    }

    clearAuxData();
}

void Presenter::present_menu()
{
    option = 0;
    present_principal_menu();
    switch (option)
    {
    case 1:
        present_quotation_history_menu();
        present_menu();
        break;
    case 2:
        present_new_quotation_menu();
        present_menu();
        break;
    case 3:
        break;
    }
}
