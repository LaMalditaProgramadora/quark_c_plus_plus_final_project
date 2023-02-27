#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class QuotationSystem
{
private:
    ClothingStore *clothing_store;
    Seller *seller;
    vector<Quotation *> quotation_list;

public:
    QuotationSystem();
    string get_seller_header() { return seller->get_complete_name() + " | " + seller->get_code(); }
    string get_clothing_store_header() { return clothing_store->get_name() + " | " + clothing_store->get_address(); }
    vector<Quotation *> get_quotation_list() { return quotation_list; }
    Clothes *find_clothes(string quality, string sleeve_type, string collar_type, string cut_type)
    {
        return clothing_store->find_clothes(quality, sleeve_type, collar_type, cut_type);
    };
    void init_data();
    Quotation *add_quotation(int id_number, Clothes *clothes, double unit_price, int quantity);
};

QuotationSystem::QuotationSystem()
{
    cout << "Iniciando sistema de cotización..." << endl;
}

void QuotationSystem::init_data()
{
    clothing_store = new ClothingStore("TIENDA01", "La Tienda de Jimena", "Jr. Luis Torres 678 - Lima");
    seller = new Seller("VENDEDOR01", "Flavia", "Ruiz", clothing_store);

    clothing_store->add_clothes(new Shirt("CAMISA001", "Standard", 100, "Manga corta", "Cuello mao"));
    clothing_store->add_clothes(new Shirt("CAMISA002", "Premium", 100, "Manga corta", "Cuello mao"));
    clothing_store->add_clothes(new Shirt("CAMISA003", "Standard", 150, "Manga corta", "Cuello común"));
    clothing_store->add_clothes(new Shirt("CAMISA004", "Premium", 150, "Manga corta", "Cuello común"));
    clothing_store->add_clothes(new Shirt("CAMISA005", "Standard", 75, "Manga larga", "Cuello mao"));
    clothing_store->add_clothes(new Shirt("CAMISA006", "Premium", 75, "Manga larga", "Cuello mao"));
    clothing_store->add_clothes(new Shirt("CAMISA007", "Standard", 175, "Manga larga", "Cuello común"));
    clothing_store->add_clothes(new Shirt("CAMISA008", "Premium", 175, "Manga larga", "Cuello común"));

    clothing_store->add_clothes(new Pants("PANTALÓN001", "Standard", 750, "Chupín"));
    clothing_store->add_clothes(new Pants("PANTALÓN002", "Premium", 750, "Chupín"));
    clothing_store->add_clothes(new Pants("PANTALÓN003", "Standard", 250, "Común"));
    clothing_store->add_clothes(new Pants("PANTALÓN004", "Premium", 250, "Común"));
};

Quotation *QuotationSystem::add_quotation(int id_number, Clothes *clothes, double unit_price, int quantity)
{
    if (clothes->get_stock() < quantity)
    {
        return NULL;
    }
    Quotation *quotation = new Quotation(id_number, seller, clothes, unit_price, quantity);
    quotation_list.push_back(quotation);
    return quotation;
};