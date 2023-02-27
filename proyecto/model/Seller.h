#include <iostream>
#include <string.h>

using namespace std;

class Seller
{
private:
    string code;
    string name;
    string lastname;
    ClothingStore *clothing_store;

public:
    Seller(string code,
           string name,
           string lastname,
           ClothingStore *clothing_store);
    string get_complete_name() { return name + " " + lastname; };
    string get_code() { return code; };
};

Seller::Seller(string code,
               string name,
               string lastname,
               ClothingStore *clothing_store)
{
    this->code = code;
    this->name = name;
    this->lastname = lastname;
    this->clothing_store = clothing_store;
};