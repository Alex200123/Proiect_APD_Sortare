#include "Functions.h"


int main()
{
    //ofstream out_file;
    ifstream in_file("fisier_matrice_2560x2560.txt");
    int n;
    in_file >> n;
    int** matrice = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrice[i] = new int[n];
    };
    
    Citeste_matricea_din_fisier(in_file, matrice, n);

    //Afiasre_matrice(matrice, n);
    
    auto start = high_resolution_clock::now();
    Shear_sort(matrice, n);
    auto stop = high_resolution_clock::now();
    
    Afiasre_matrice(matrice, n);
    
    
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Time for function completion for matrix of " << n << "^2 is: " << duration.count() 
         << " microseconds" << endl;
    
    for (int i = 0; i < n; i++)
    {
        delete[] matrice[i];
    }
    delete[] matrice;

	return 0;
}