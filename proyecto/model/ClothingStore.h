#include <iostream>
#include <string.h>
#include <vector>
#include "Clothes.h"

using namespace std;

class ClothingStore
{
private:
    string code;
    string name;
    string address;
    vector<Clothes *> clothes_list;

public:
    ClothingStore(string code, string name, string address);
    string get_name() { return name; };
    string get_address() { return address; };
    void add_clothes(Clothes *clothes);
    Clothes *find_clothes(string quality, string sleeve_type, string collar_type, string cut_type);
};

ClothingStore::ClothingStore(string code, string name, string address)
{
    this->code = code;
    this->name = name;
    this->address = address;
};

void ClothingStore::add_clothes(Clothes *clothes)
{
    clothes_list.push_back(clothes);
}

Clothes *ClothingStore::find_clothes(string quality, string sleeve_type, string collar_type, string cut_type)
{
    for (int i = 0; i < clothes_list.size(); i++)
    {
        if (clothes_list[i]->equals(quality, sleeve_type, collar_type, cut_type))
            return clothes_list[i];
    }
    return clothes_list[0];
}