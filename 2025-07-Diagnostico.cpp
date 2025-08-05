// 2025-07-Diagnostico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <sstream>
#include <windows.h> // Para SetConsoleOutputCP
using namespace std;
int integerArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void selectMenuOption(int selection);
void playRockPaperScissors();
void findGreaterThanAdjacent();


string determineRockPaperScissorsWinner(string player1, string player2)
{
  if (player1 == "tijeras" && player2 == "papel")
  {
    return "El jugador 1 gana";
  }
  if (player1 == "tijeras" && player2 == "piedra")
  {
    return "El jugador 2 gana";
  }
  if (player1 == "papel" && player2 == "piedra")
  {
    return "El jugador 1 gana";
  }
  if (player1 == "papel" && player2 == "tijeras")
  {
    return "El jugador 2 gana";
  }
  if (player1 == "piedra" && player2 == "papel")
  {
    return "El jugador 2 gana";
  }
  if (player1 == "piedra" && player2 == "tijeras")
  {
    return "El jugador 1 gana";
  }
  if (player1 == player2)
  {
    return "Empate";
  }
  return "Los datos ingresados no corresponden.";
}

string getElementsGreaterThanAdjacent(int numberOfElements)
{
  if (numberOfElements < 3)
  {
    return "";
  }

  string result = "";

  for (int i = 1; i < numberOfElements - 1; i++)
  {
    if ((integerArray[i] > integerArray[i - 1]) && (integerArray[i] > integerArray[i + 1]))
    {
      result += to_string(integerArray[i]) + ", ";
    }
  }
  return result;
}

int main()
{
  SetConsoleOutputCP(CP_UTF8); //Permite imprimir caracteres especiales, ej.: á é ñ

  int menuOption = -1;
  while (menuOption != 0)
  {
    system("cls");
    cout << "Seleccione una opción escribiendo el número correspondiente:" << endl;
    cout << "0 -> Salir del programa." << endl;
    cout << "1 -> Piedra, Papel Tijera." << endl;
    cout << "2 -> Mayor que Adyacentes." << endl;
    cin >> menuOption;
    if (menuOption > 0 && menuOption < 3)
    {
      selectMenuOption(menuOption);
    }
  }
  return 0;
}

void selectMenuOption(int selection)
{
  if (selection == 1)
  {
    playRockPaperScissors();
    return;
  }
  if (selection == 2)
  {
    findGreaterThanAdjacent();
    return;
  }
}

void playRockPaperScissors()
{
  string player1Hand, player2Hand;
  player1Hand = player2Hand = "nothing yet";

  cout << "Juego Piedra Papel Tijeras" << endl;
  cout << "Las opciones son: \"piedra\", \"papel\" y \"tijeras\", escriba en minúsculas." << endl;

  cout << "Escriba la mano del jugador 1: ";
  cin >> player1Hand;

  cout << endl << "Escriba la mano del jugador 2: ";
  cin >> player2Hand;

  cout << determineRockPaperScissorsWinner(player1Hand, player2Hand);
  cout << endl;
  system("pause");
}

void findGreaterThanAdjacent()
{
  int quantity = 0;
  string greaterElements = "";

  cout << "Función para encontrar elementos mayores que sus adyacentes." << endl;
  cout << "Escriba la cantidad de elementos del arreglo (máximo 10): ";
  cin >> quantity;

  if (quantity > 10 || quantity < 0)
  {
    quantity = 10;
    cout << "Cantidad establecida en 10" << endl;
  }

  for (int i = 0; i < quantity; i++)
  {
    cout << "Digite un valor entero para la posicion " << i << ": ";
    cin >> integerArray[i];
  }

  greaterElements = getElementsGreaterThanAdjacent(quantity);
  cout << greaterElements << endl;
  system("pause");
}
