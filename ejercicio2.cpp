/* 2) Un negocio de ropa, vende sus artículos en distintos talles. Para realizar la facturación se ingresan los precios de cada
artículo y talle que vende:
código de articulo (1..100)
talle (1..5)
precio
También se dispone de dispone de un conjunto de ventas a facturar, que se ingresan por teclado con los siguientes
datos:
código de artículo (1..100)
talle (1..5)
unidades vendidas
Las ventas finalizan con un código de artículo negativo.
Desarrollar un algoritmo que:
a) informe el precio de la venta, considerando un descuento del 10% si las unidades vendidas son superiores a
tres más el 21% del IVA.
b) al final del proceso emita el siguiente listado, ordenado por artículo y talle ascendente:
Código de Artículo 999
 Talle Unidades Vendidas
 9 99
 9 99
 Total unidades vendidas artículo 9999999
………………………………………..
Total general de unidades vendidas 9999999 */

#include <iostream>

using namespace std;

struct Ropa
{
  int cod, talle, precio;
};

struct Ventas
{
  int cod, talle, unidadesVendidas;
};

void ingresoDatos(Ropa v[]);

int main()
{
  ingresoDatos()
}