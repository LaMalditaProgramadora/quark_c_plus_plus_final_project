#include <iostream>
#include <string.h>

using namespace std;

class Pants : public Clothes
{
private:
    string cut_type;

public:
    Pants(string code, string quality, int stock, string cut_type);
    void calculate_unit_price(double &unit_price);
    string get_complete_name() override;
    bool equals(string quality, string sleeve_type, string collar_type, string cut_type) override;
};

Pants::Pants(string code, string quality, int stock, string cut_type)
{
    this->code = code;
    this->name = "Pantalón";
    this->quality = quality;
    this->stock = stock;
    this->cut_type = cut_type;
};

void Pants::calculate_unit_price(double &unit_price)
{
    if (cut_type == "Chupín")
    {
        unit_price *= 0.88;
    }
    calculate_unit_price_by_quality(unit_price);
};

string Pants::get_complete_name()
{
    return name + " - " + cut_type + " - " + quality;
};

bool Pants::equals(string quality, string sleeve_type, string collar_type, string cut_type)
{
    return this->quality == quality && this->cut_type == cut_type;
}