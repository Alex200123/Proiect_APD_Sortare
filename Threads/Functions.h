#include <iostream>
#include <math.h>
#include <chrono>
#include <fstream>
#include "windows.h"
#include "psapi.h"
#include <thread>
using namespace std;
using namespace std::chrono;

void Odd_even_sort_odd_row(int arr[], int n);
void Odd_even_sort_even_row(int arr[], int n);
void Odd_even_sort_column(int** arr, int n);
void Afiasre_matrice(int** matrice, int n);
void Citeste_matrice(int** matrice, int n);
void Shear_sort(int** matrice, int n);
void Creaza_matrice_la_intamplare(int** matrice, int n);
void Creare_fisier_matrice(ofstream& out_file);
void Scriere_in_fisier_matrice(ofstream& out_file, int** matrice, int n);
void Citeste_matricea_din_fisier(ifstream& in_file, int** matrice, int n);
void PrintMemoryInfo(DWORD processID);
void Odd_even_sort_for_column(int** arr, int n, int coloana);