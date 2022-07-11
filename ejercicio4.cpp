/* 4) Se desea desarrollar un sistema de reservas de entradas para un cine.
La sala consta de 12 filas numeradas de la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central,
con las butacas impares a la derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando con la letra D
las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una reserva se deberá
actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba ocupada se debe informar al usuario
para que seleccione otra.
El proceso de reserva finaliza con una fila con un número negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.  */

#include <iostream>

using namespace std;

const int filas = 12, butacas = 9;

void inicializarMatriz(char mat[][butacas], int cf, int cc);
void cargaDeDatos(char mat[][butacas], int cf, int cc);
int nroButacasMuestra(int n);
int nroButacasReserva(int n);

int main()
{
  char cine[filas][butacas];

  inicializarMatriz(cine, filas, butacas);
  cargaDeDatos(cine, filas, butacas);

  return 0;
}

void inicializarMatriz(char mat[][butacas], int cf, int cc)
{
  for (int i = 0; i < cf; i++)
    for (int j = 0; j < cc; j++)
      mat[i][j] = 'D';
}

void cargaDeDatos(char mat[][butacas], int cf, int cc)
{
  for (int k = 0; k < cc; k++)
    cout << nroButacasMuestra(k) << " ";
  cout << endl;
  for (int i = 0; i < cf; i++)
  {
    for (int j = 0; j < cc; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }

  int fUsuario, bUsuario;
  cout << "¿Que fila y numero de butaca quiere reservar?" << endl;
  cout << "Fila: ";
  cin >> fUsuario;
  cout << "Butaca: ";
  cin >> bUsuario;

  while (mat[fUsuario - 1][nroButacasReserva(bUsuario)] == 'R')
  {
    cout << "Debe ingresar una fila y una butaca que no este reservada" << endl;
    cout << "Fila: ";
    cin >> fUsuario;
    cout << "Butaca: ";
    cin >> bUsuario;
  }

  if (fUsuario >= 0)
  {
    mat[fUsuario - 1][nroButacasReserva(bUsuario)] = 'R';
    cargaDeDatos(mat, cf, cc);
  }
}

int nroButacasMuestra(int n)
{
  int butaca;
  switch (n)
  {
  case 0:
    butaca = 8;
    break;
  case 1:
    butaca = 6;
    break;
  case 2:
    butaca = 4;
    break;
  case 3:
    butaca = 2;
    break;
  case 4:
    butaca = 1;
    break;
  case 5:
    butaca = 3;
    break;
  case 6:
    butaca = 5;
    break;
  case 7:
    butaca = 7;
    break;
  case 8:
    butaca = 9;
    break;
  }
  return butaca;
}

int nroButacasReserva(int n)
{
  int butaca;
  switch (n)
  {
  case 8:
    butaca = 0;
    break;
  case 6:
    butaca = 1;
    break;
  case 4:
    butaca = 2;
    break;
  case 2:
    butaca = 3;
    break;
  case 1:
    butaca = 4;
    break;
  case 3:
    butaca = 5;
    break;
  case 5:
    butaca = 6;
    break;
  case 7:
    butaca = 7;
    break;
  case 9:
    butaca = 8;
    break;
  }
  return butaca;
}