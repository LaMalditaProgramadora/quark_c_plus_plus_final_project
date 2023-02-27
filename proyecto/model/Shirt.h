#include <iostream>
#include <string.h>

using namespace std;

class Shirt : public Clothes
{
private:
    string sleeve_type;
    string collar_type;

public:
    Shirt(string code, string quality, int stock, string sleeve_type, string collar_type);
    void calculate_unit_price(double &unit_price) override;
    string get_complete_name() override;
    bool equals(string quality, string sleeve_type, string collar_type, string cut_type) override;
};

Shirt::Shirt(string code, string quality, int stock, string sleeve_type, string collar_type)
{
    this->code = code;
    this->name = "Camisa";
    this->quality = quality;
    this->stock = stock;
    this->sleeve_type = sleeve_type;
    this->collar_type = collar_type;
};

void Shirt::calculate_unit_price(double &unit_price)
{
    if (sleeve_type == "Manga corta")
    {
        unit_price *= 0.9;
    }
    if (collar_type == "Cuello mao")
    {
        unit_price *= 1.03;
    }
    calculate_unit_price_by_quality(unit_price);
};

string Shirt::get_complete_name()
{
    return name + " - " + sleeve_type + " - " + collar_type + " - " + quality;
};

bool Shirt::equals(string quality, string sleeve_type, string collar_type, string cut_type)
{
    return this->quality == quality && this->sleeve_type == sleeve_type && this->collar_type == collar_type;
}