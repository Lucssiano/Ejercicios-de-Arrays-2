/* 2) Un negocio de ropa, vende sus artículos en distintos talles. Para realizar la facturación se ingresan los precios de cada
artículo y talle que vende:
código de articulo (1..100)
talle (1..5)
precio
También se dispone de un conjunto de ventas a facturar, que se ingresan por teclado con los siguientes
datos:
código de artículo (1..100)
talle (1..5)
unidades vendidas
Las ventas finalizan con un código de artículo negativo.
Desarrollar un algoritmo que:
a) informe el precio de la venta, considerando un descuento del 10% si las unidades vendidas son superiores a
tres más el 21% del IVA.
b) al final del proceso emita el siguiente listado, ordenado por artículo y talle ascendente:
Código de Artículo  Talle  Unidades Vendidas
      999             9           99

Total unidades vendidas artículo 9999999
………………………………………..
Total general de unidades vendidas 9999999 */

#include <iostream>

using namespace std;

const int cantArticulos = 3, talles = 5;

void ingresoDatos(int m[][talles]);
void inicializarVentas(int mV[][talles]);
void ventas(int mV[][talles]);
void puntoA(int mV[][talles], int m[][talles]);
void puntoB(int mV[][talles]);

int main()
{
  int productos[cantArticulos][talles];
  int matVentas[cantArticulos][talles];
  ingresoDatos(productos);
  inicializarVentas(matVentas);
  ventas(matVentas);
  puntoA(matVentas, productos);
  puntoB(matVentas);
}

void ingresoDatos(int m[][talles])
{
  for (int i = 0; i < cantArticulos; i++)
  {
    for (int j = 0; j < talles; j++)
    {
      cout << "Ingrese un precio para el articulo " << i + 1 << " talle " << j + 1 << ": ";
      cin >> m[i][j];
    }
  }
}

void inicializarVentas(int mV[][talles])
{
  for (int i = 0; i < cantArticulos; i++)
    for (int j = 0; j < talles; j++)
      mV[i][j] = 0;
}

void ventas(int mV[][talles])
{
  int cod, talle, unidadesVendidas;

  cout << "Ingrese un codigo de articulo ";
  cin >> cod;

  while (cod >= 0 && cod <= cantArticulos)
  {
    cout << "Ingrese un talle ";
    cin >> talle;

    cout << "Ingrese las unidades vendidas ";
    cin >> unidadesVendidas;
    mV[cod - 1][talle - 1] += unidadesVendidas;

    cout << "Ingrese un codigo de articulo ";
    cin >> cod;
  }
}

void puntoA(int mV[][talles], int m[][talles])
{
  int precioVenta;
  for (int i = 0; i < cantArticulos; i++)
  {
    precioVenta = 0;
    for (int j = 0; j < talles; j++)
    {
      if (mV[i][j] > 3)
        precioVenta += mV[i][j] * (m[i][j] * 0.1);
      else
        precioVenta += mV[i][j] * m[i][j];
    }
    cout << "El precio de la venta del codigo " << i + 1 << " es $" << precioVenta << endl;
  }
}

void puntoB(int mV[][talles])
{
  int totalGeneral = 0;
  for (int i = 0; i < cantArticulos; i++)
  {
    cout << "Codigo de Articulo: " << i + 1 << endl;
    for (int j = 0; j < talles; j++)
    {
      cout << "Talle: " << j + 1 << endl;
      cout << "Unidades vendidas del articulo " << i + 1 << ": " << mV[i][j] << endl;
      totalGeneral += mV[i][j];
    }
  }
  cout << "Total general de unidades vendidas: " << totalGeneral;
}