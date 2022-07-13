/* 1) Una empresa de aviación realiza 500 vuelos semanales a distintos puntos del país y requiere desarrollar un programa
para la venta de pasajes. Para ello se ingresan los datos de los 500 vuelos que realiza, sin ningún orden, por cada vuelo
se ingresa:
código de vuelo
cantidad de pasajes disponibles
A continuación se ingresan los datos de los potenciales compradores, el ingreso finaliza con código de vuelo cero, por
cada uno se ingresa:
código de vuelo
cantidad de pasajes solicitados
DNI del solicitante
apellido y nombre del solicitante
Se pide:
a) Para los solicitantes a los cuales se les venden pasajes, emitir el siguiente listado:
  DNI            Apellido y Nombre         Cantidad de pasajes     Código de Vuelo
99999999     xxxxxxxxxxxxxxxxxxxxxxxx             999                    999
99999999     xxxxxxxxxxxxxxxxxxxxxxxx             999                    999
b) Al final del proceso emitir el siguiente listado ordenado por código de vuelo
Código de Vuelo     Pasajes disponibles     Pasajes no vendidos
    9999                   999                     999
    9999                   999                     999
Nota: Se le vende al solicitante si la cantidad de pasajes que solicita está disponible, en caso contrario se computa como
pasajes no vendidos. */

#include <iostream>

using namespace std;

const int cantVuelos = 5;

struct DatosVuelos
{
  int cod, cantPasajes, noVendidos;
};

struct DatosCompradores
{
  int cod, cantPasajesSolic, dni;
  string nombre;
};

void ingresoDeDatos(DatosVuelos v[]);
void compras(DatosVuelos v[]);
void puntoA(DatosCompradores c);
void puntoB(DatosVuelos v[]);
void burbujeo(DatosVuelos v[], unsigned t);
int binaria(DatosVuelos v[], unsigned t, int bus);

int main()
{
  DatosVuelos vuelos[cantVuelos];
  ingresoDeDatos(vuelos);
  burbujeo(vuelos, cantVuelos);
  compras(vuelos);
  puntoB(vuelos);
  return 0;
}

void ingresoDeDatos(DatosVuelos v[])
{
  for (int i = 0; i < cantVuelos; i++)
  {
    cout << "Codigo del vuelo " << i + 1 << ": ";
    cin >> v[i].cod;
    cout << "Cantidad de pasajes disponibles del vuelo " << i + 1 << ": ";
    cin >> v[i].cantPasajes;
    v[i].noVendidos = 0;
  }
}

void compras(DatosVuelos v[])
{
  DatosCompradores compra;
  int pos;

  cout << "Ingrese el codigo de vuelo que quiere comprar: ";
  cin >> compra.cod;

  while (compra.cod != 0)
  {
    pos = binaria(v, 5, compra.cod);

    while (pos == -1)
    {
      cout << "El codigo ingresado no se encontro" << endl;
      cout << "Ingrese el codigo de vuelo que quiere comprar: ";
      cin >> compra.cod;

      pos = binaria(v, 5, compra.cod);
    };

    cout << "Ingrese la cantidad de pasajes que quiere comprar: ";
    cin >> compra.cantPasajesSolic;

    if (compra.cantPasajesSolic >= v[pos].cantPasajes)
    {
      cout << "No poseemos esa cantidad de pasajes para el codigo de vuelo " << compra.cod << endl;
      v[pos].noVendidos += compra.cantPasajesSolic;
    }
    else
    {
      v[pos].cantPasajes -= compra.cantPasajesSolic;
      cout << "Ingrese su DNI: ";
      cin >> compra.dni;
      cout << "Ingrese su nombre: ";
      cin >> compra.nombre;
      puntoA(compra);
    }

    cout << "Ingrese el codigo de vuelo que quiere comprar: ";
    cin >> compra.cod;
  }
}

void puntoA(DatosCompradores c)
{
  cout << "DNI            Apellido y Nombre         Cantidad de pasajes     Codigo de Vuelo" << endl;
  cout << c.dni << "                   " << c.nombre << "                     " << c.cantPasajesSolic << "                      " << c.cod << endl;
}

void puntoB(DatosVuelos v[])
{
  cout << "Codigo de vuelo           Pasajes Disponibles        Pasajes no vendidos" << endl;
  for (int i = 0; i < cantVuelos; i++)
    cout << v[i].cod << "                               " << v[i].cantPasajes << "                              " << v[i].noVendidos << "                      " << endl;
}

void burbujeo(DatosVuelos v[], unsigned t)
{
  unsigned i = 1, j;
  DatosVuelos aux;
  bool cambio;
  do
  {
    cambio = false;
    for (j = 0; j < t - i; j++)
    {
      if (v[j].cod > v[j + 1].cod)
      {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        cambio = true;
      }
    }
    i++;
  } while (i < t && cambio);
}

int binaria(DatosVuelos v[], unsigned t, int bus)
{
  int pos = -1, desde = 0, hasta = t - 1, medio;
  while (desde <= hasta && pos == -1)
  {
    medio = (desde + hasta) / 2;
    if (v[medio].cod == bus)
      pos = medio;
    else
    {
      if (bus < v[medio].cod)
        hasta = medio - 1;
      else
        desde = medio + 1;
    }
  }
  return pos;
}