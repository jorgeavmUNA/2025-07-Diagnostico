// 2025-07-Diagnostico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
 
#include <iostream>
#include <sstream>
#include <windows.h> // Para SetConsoleOutputCP
using namespace std;
int integerArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void menuSelection(int selection);
void menuOption1();
void menuOption2();


string rockPaperScissors(string player1, string player2)
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

  return "Empate";
}
string greaterThanAdjacent(int numberOfElements)
{
    if (numberOfElements < 3)
    {
        return "";
    }
    numberOfElements--;
    string result = "";

    for (int i = 1; i < numberOfElements;i++)
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
        menuSelection(menuOption);
    }
  }
  return 0;
}

void menuSelection(int selection)
{
    if (selection == 1)
    {
        menuOption1();
        return;
    }
    if (selection == 2)
    {
        menuOption2();
        return;
    }
}

void menuOption1()
{
    string player1Hand, player2Hand;
    player1Hand = player2Hand = "nothing yet";
    cout << "Juego Piedra Papel Tijeras" << endl;
    cout << "Las opciones son: \"piedra\", \"papel\" y \"tijeras\", escriba en minúsculas." << endl;
    cout << "Escriba la mano del jugador 1: ";
    cin >> player1Hand;
    cout << endl << "Escriba la mano del jugador 2: ";
    cin >> player2Hand;
    cout << rockPaperScissors(player1Hand, player2Hand);
    cout << endl;
    system("pause");
}
void menuOption2()
{
    int quantity = 0;
    string greaterElements = "";
    cout << "Función para encontrar elementos mayores que sus adyacentes." << endl;
    cout << "Escriba la cantidad de elementos del arreglo (máximo 10): ";
    cin >> quantity;
    if (quantity > 10 || quantity < 0 )
    {
        quantity = 10;
        cout << "Cantidad establecida en 10" << endl;
    }
    for (int i = 0; i < quantity; i++)
    {
        cout << "Digite un valor entero para la posicion " << i << ": ";
        cin >> integerArray[i];
    }
    greaterElements = greaterThanAdjacent(quantity);
    cout << greaterElements << endl;
    system("pause");
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
