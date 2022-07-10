/* 3) Una empresa cuenta con una flota de vehículos. Se requiere un algoritmo que dada la cantidad de vehículos y las
patentes de los mismos analice los pagos del impuesto al automotor de los mismos del año pasado.
Los pagos se ingresan por teclado, sin orden.
Por cada pago se ingresa:
Mes abonado (1 a 12)
Patente
Importe abonado
El ingreso de datos finaliza con mes cero.
Se pide informar:
a) Por cada vehículo, patente e importe total abonado.
b) Por cada vehículo, patente y meses adeudados.
c) Mes o meses en los que se abonó por todos los vehículos. */

#include <iostream>

using namespace std;

void pagos(int imp[][12], int cantV, int pats[]);
void inicializarImportes(int imp[][12], int cantV);
void puntoA(int imp[][12], int cantV, int pats[]);
void puntoB(int imp[][12], int cantV, int pats[]);
void puntoC(int imp[][12], int cantV);
int secuencial(int v[], unsigned t, int bus);

int main()
{
  int cantidadV;

  do
  {
    cout << "Ingrese la cantidad de vehiculos (mayor y distinta de 0): ";
    cin >> cantidadV;
  } while (cantidadV <= 0);

  int patentes[cantidadV], importes[cantidadV][12];

  for (int i = 0; i < cantidadV; i++)
  {
    cout << "Ingrese la patente del vehiculo " << i + 1 << ": ";
    cin >> patentes[i];
  }

  inicializarImportes(importes, cantidadV);

  pagos(importes, cantidadV, patentes);

  puntoA(importes, cantidadV, patentes);

  puntoB(importes, cantidadV, patentes);

  puntoC(importes, cantidadV);

  return 0;
}

void inicializarImportes(int imp[][12], int cantV)
{
  for (int i = 0; i < cantV; i++)
    for (int j = 0; j < 12; j++)
      imp[i][j] = 0;
}

void pagos(int imp[][12], int cantV, int pats[])
{
  for (int i = 0; i < cantV; i++)
  {
    int mes, pat;

    cout << "Ingrese la patente a abonar: ";
    cin >> pat;

    int posPat = secuencial(pats, cantV, pat);

    while (posPat == -1)
    {
      cout << "Ingrese la patente a abonar: ";
      cin >> pat;
      posPat = secuencial(pats, cantV, pat);
      if (posPat == -1)
        cout << "No se encontro esa patente, debe ingresar otra " << endl;
    }

    cout << "Ingrese el mes a abonar (distinto a cero y de 1 a 12) de la patente " << pat << ": ";
    cin >> mes;

    while (mes != 0)
    {
      if (mes >= 1 && mes <= 12)
      {
        cout << "Ingrese el importe abonado del mes " << mes << ": ";
        cin >> imp[posPat][mes - 1];
      }

      cout << "Ingrese otro mes a abonar (distinto a cero y de 1 a 12) de la patente " << pat << ": ";
      cin >> mes;
    }
  }
}

// Por cada vehículo, patente e importe total abonado.
void puntoA(int imp[][12], int cantV, int pats[])
{
  for (int i = 0; i < cantV; i++)
  {
    int impTotal = 0;
    for (int j = 0; j < 12; j++)
      impTotal += imp[i][j];
    cout << "Patente: " << pats[i] << " Importe total abonado: $" << impTotal << endl;
  }
}

// Por cada vehículo, patente y meses adeudados.
void puntoB(int imp[][12], int cantV, int pats[])
{
  for (int i = 0; i < cantV; i++)
  {
    cout << "Vehiculo " << i + 1 << " Patente: " << pats[i] << " - Meses adeudados ";
    for (int j = 0; j < 12; j++)
      if (imp[i][j] == 0)
        cout << j + 1 << " ";
    cout << endl;
  }
}

// Mes o meses en los que se abonó por todos los vehículos.
void puntoC(int imp[][12], int cantV)
{
  cout << "Mes o meses en los que se abono por todos los vehiculos: ";
}

int secuencial(int v[], unsigned t, int bus)
{
  unsigned i = 0;
  while (i < t && v[i] != bus)
    i++;
  if (i == t)
    return -1;
  else
    return i;
}