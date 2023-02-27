#include <iostream>
#include <string.h>

using namespace std;

class Clothes
{
protected:
    string code;
    string name;
    string quality;
    int stock;
    void calculate_unit_price_by_quality(double &unit_price);

public:
    int get_stock() { return stock; };
    virtual void calculate_unit_price(double &unit_price){};
    virtual string get_complete_name() { return ""; };
    virtual bool equals(string quality, string sleeve_type, string collar_type, string cut_type) { return false; }
};

void Clothes::calculate_unit_price_by_quality(double &unit_price)
{
    if (quality == "Premium")
        unit_price *= 1.3;
}