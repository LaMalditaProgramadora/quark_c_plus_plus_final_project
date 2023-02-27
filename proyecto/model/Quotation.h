#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

class Quotation
{
private:
    int id_number;
    time_t date;
    Seller *seller;
    Clothes *clothes;
    double unit_price;
    int quantity;
    double amount;

public:
    Quotation();
    Quotation(int id_number, Seller *seller, Clothes *clothes, double unit_price, int quantity);
    int get_id_number() { return id_number; };
    string get_date() { return ctime(&date); };
    string get_seller_code() { return seller->get_code(); }
    string get_clothes_complete_name() { return clothes->get_complete_name(); }
    double get_unit_price() { return unit_price; };
    int get_quantity() { return quantity; };
    double get_amount() { return amount; };
};

Quotation::Quotation()
{
}

Quotation::Quotation(int id_number, Seller *seller, Clothes *clothes, double unit_price, int quantity)
{
    this->id_number = id_number;
    this->date = time(0);
    this->seller = seller;
    this->clothes = clothes;
    this->unit_price = unit_price;
    this->quantity = quantity;
    clothes->calculate_unit_price(unit_price);
    this->amount = quantity * unit_price;
};