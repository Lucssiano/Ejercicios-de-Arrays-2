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

void inicializarMatriz(char mat[][butacas]);
void inicializarV(int v[]);
void cargaDeDatos(char mat[][butacas]);
int nroButacasMuestra(int n);
int nroButacasReserva(int n);
void puntoA(char mat[][butacas]);
void puntoB(char mat[][butacas]);
void puntoC(char mat[][butacas]);

int main()
{
  char cine[filas][butacas];

  inicializarMatriz(cine);
  cargaDeDatos(cine);
  puntoA(cine);
  puntoB(cine);
  puntoC(cine);

  return 0;
}

void inicializarMatriz(char mat[][butacas])
{
  for (int i = 0; i < filas; i++)
    for (int j = 0; j < butacas; j++)
      mat[i][j] = 'D';
}

void cargaDeDatos(char mat[][butacas])
{
  for (int k = 0; k < butacas; k++)
    cout << nroButacasMuestra(k) << " ";
  cout << endl;
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < butacas; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }

  int fUsuario, bUsuario;
  cout << "¿Que fila y numero de butaca quiere reservar?" << endl; // Poner que sea entre 9 y 12
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
    cargaDeDatos(mat);
  }
}

void puntoA(char mat[][butacas])
{
  int cantDisp = 0, cantR = 0;

  for (int i = 0; i < filas; i++)
    for (int j = 0; j < butacas; j++)
      if (mat[i][j] == 'D')
        cantDisp++;
      else if (mat[i][j] == 'R')
        cantR++;

  cout << "La cantidad de asientos disponibles es: " << cantDisp << endl;
  cout << "La cantidad de asientos reservados es: " << cantR << endl;
}

void puntoB(char mat[][butacas])
{
  cout << "Los numeros de filas que quedaron vacias son:" << endl;
  for (int i = 0; i < filas; i++)
  {
    int j;
    for (j = 0; j < butacas; j++)
      if (mat[i][j] == 'R')
        j = butacas;
    if (j == butacas)
      cout << i + 1 << endl;
  }
}

void puntoC(char mat[][butacas])
{
  int mayor, cantEspec, especXFila = 0, vPosMayor[filas];

  inicializarV(vPosMayor);

  cout << "La o las filas con mayor cantidad de espectadores son: " << endl;

  for (int i = 0; i < filas; i++)
  {
    cantEspec = 0;
    for (int j = 0; j < butacas; j++)
      if (mat[i][j] == 'R')
        cantEspec++;

    if (cantEspec > especXFila)
    {
      especXFila = cantEspec;
      vPosMayor[i] = especXFila;
    }
    else if (cantEspec != 0 && cantEspec == especXFila)
      vPosMayor[i] = especXFila;
  }

  for (int k = 0; k < filas; k++)
    if (vPosMayor[k] != 0 && vPosMayor[k] == especXFila)
      cout << k + 1 << endl;
}

void inicializarV(int v[])
{
  for (int i = 0; i < filas; i++)
    v[i] = 0;
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