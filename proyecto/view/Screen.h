#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Screen
{
private:
     void print_quotation(Quotation *quotation);
     void print_title(string option);
     void print_back_to_principal_menu();

public:
     Screen();
     void clean();
     void get_principal_menu(string clothing_store_header, string seller_header);
     void get_quotation_history_menu(vector<Quotation *> quotation_list);
     void get_new_quotation_menu_step_1_name();
     void get_new_quotation_menu_step_2_a_shirt_sleeve_type();
     void get_new_quotation_menu_step_2_b_shirt_collar_type();
     void get_new_quotation_menu_step_2_pants_cut_type();
     void get_new_quotation_menu_step_3_quality();
     void get_new_quotation_menu_step_4_unit_price();
     void get_new_quotation_menu_step_5_stock(int stock);
     void get_new_quotation_menu_result(Quotation *quotation);
};

Screen::Screen()
{
     cout << "Iniciando pantallas..." << endl;
};

void Screen::clean()
{
     system("clear");
}

void Screen::print_title(string option)
{
     cout << "COTIZADOR EXPRESS - " << option << endl;
}

void Screen::print_back_to_principal_menu()
{
     cout << "-------------------------------------------------------------------" << endl;
     cout << "Presiona 3 para volver al menú principal" << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
}

void Screen::print_quotation(Quotation *quotation)
{
     cout << "Número de identificación: " << quotation->get_id_number() << endl;
     cout << "Fecha y Hora de la cotización: " << quotation->get_date();
     cout << "Código del Vendedor: " << quotation->get_seller_code() << endl;
     cout << "Prenda Cotizada: " << quotation->get_clothes_complete_name() << endl;
     cout << "Precio Unitario: $ " << quotation->get_unit_price() << endl;
     cout << "Cantidad de unidades cotizadas: " << quotation->get_quantity() << endl;
     cout << "Precio final: $ " << quotation->get_amount() << endl
          << endl;
}

void Screen::get_principal_menu(string clothing_store_header, string seller_header)
{
     print_title("MENÚ PRINCIPAL");
     cout << "-------------------------------------------------------------------" << endl;
     cout << clothing_store_header << endl;
     cout << "-------------------------------------------------------------------" << endl;
     cout << seller_header << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "SELECCIONE UNA OPCIÓN DEL MENÚ" << endl
          << endl;
     cout << "1) Historial de Cotizaciones" << endl;
     cout << "2) Realizar Cotización" << endl;
     cout << "3) Salir" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Su opción: ";
}

void Screen::get_quotation_history_menu(vector<Quotation *> quotation_list)
{
     print_title("HISTORIAL DE COTIZACIONES");
     print_back_to_principal_menu();
     if (quotation_list.size() == 0)
          cout << "Aún no se han realizado cotizaciones" << endl
               << endl;
     else
          for (int i = 0; i < quotation_list.size(); i++)
          {
               print_quotation(quotation_list[i]);
          }
     print_back_to_principal_menu();
     cout << "Su opción: ";
}

void Screen::get_new_quotation_menu_step_1_name()
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "PASO 1: Selecciona la prenda a cotizar" << endl;
     cout << "1) Camisa" << endl;
     cout << "2) Pantalón" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Su opción: ";
}

void Screen::get_new_quotation_menu_step_2_a_shirt_sleeve_type()
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "PASO 2.a: La camisa a cotizar ¿Es Manga corta?" << endl;
     cout << "1) Sí" << endl;
     cout << "2) No" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Su opción: ";
}

void Screen::get_new_quotation_menu_step_2_b_shirt_collar_type()
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "PASO 2.b: La camisa a cotizar ¿Es Cuello mao?" << endl;
     cout << "1) Sí" << endl;
     cout << "2) No" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Su opción: ";
}

void Screen::get_new_quotation_menu_step_2_pants_cut_type()
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "PASO 2: El pantalón a cotizar ¿Es chupín?" << endl;
     cout << "1) Sí" << endl;
     cout << "2) No" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Su opción: ";
}

void Screen::get_new_quotation_menu_step_3_quality()
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "PASO 3: Seleccione la calidad de la prenda" << endl;
     cout << "1) Standard" << endl;
     cout << "2) Premium" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Su opción: ";
}

void Screen::get_new_quotation_menu_step_4_unit_price()
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Precio unitario: ";
}

void Screen::get_new_quotation_menu_step_5_stock(int stock)
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     cout << "INFORMACIÓN:" << endl;
     cout << "Existe " << stock << " cantidad de unidades en stock de la prenda seleccionada" << endl
          << endl;
     cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" << endl
          << endl;
     cout << "-------------------------------------------------------------------" << endl
          << endl;
     cout << "Cantidad de unidades: ";
}

void Screen::get_new_quotation_menu_result(Quotation *quotation)
{
     print_title("COTIZAR");
     print_back_to_principal_menu();
     print_quotation(quotation);
     print_back_to_principal_menu();
     cout << "Su opción: ";
}