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

struct Autos
{
  int mes[12];
  string patente;
  float importe;
};

void pagos(Autos autos[], int cantV);
void mostrarAutos(Autos autos[], int cantV);
void inicializarMeses(Autos autos[], int cantV);

int main()
{
  int cantidadV;

  do
  {
    cout << "Ingrese la cantidad de vehiculos (mayor y distinta de 0): ";
    cin >> cantidadV;
  } while (cantidadV <= 0);

  Autos vecAutos[cantidadV];

  for (int i = 0; i < cantidadV; i++)
  {
    cout << "Ingrese la patente del vehiculo " << i + 1 << ": ";
    cin >> vecAutos[i].patente;
  }

  inicializarMeses(vecAutos, cantidadV);

  pagos(vecAutos, cantidadV);

  mostrarAutos(vecAutos, cantidadV);

  return 0;
}

void inicializarMeses(Autos autos[], int cantV)
{
  for (int i = 0; i < cantV; i++)
    for (int j = 0; j < 12; j++)
      autos[i].mes[j] = false;
}

void pagos(Autos autos[], int cantV)
{
  for (int i = 0; i < cantV; i++)
  {
    int mes, cantMesesIngresados = 0;

    cout << "Ingrese el mes a abonar (distinto a cero y de 1 a 12): ";
    cin >> mes;

    while (mes != 0 && mes >= 1 && mes <= 12 && cantMesesIngresados <= 12)
    {
      cout << "Ingrese el importe abonado: ";
      cin >> autos[i].importe;

      cantMesesIngresados++;

      autos[i].mes[mes - 1] = true;

      cout << "Ingrese el mes a abonar (distinto a cero y de 1 a 12): ";
      cin >> mes;
    }

    cout << "Ingrese la patente de su vehiculo: ";
    cin >> autos[i].patente; // Verificar que exista
  }
}

void mostrarAutos(Autos autos[], int cantV)
{
  for (int i = 0; i < cantV; i++)
  {
    cout << "Patente " << i + 1 << " : " << autos[i].patente << endl;
    cout << "Mes: " << i + 1 << " : " << endl;
    // Guardar los meses que se ingresan
    for (int j = 0; j < 12; j++)
    {
      cout << autos[i].mes[j] << endl;
      cout << "Importe abonado " << j + 1 << " : " << autos[i].importe << endl; // mal
    }
  }
}