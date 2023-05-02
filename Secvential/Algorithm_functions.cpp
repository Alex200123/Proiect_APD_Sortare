#include "Functions.h"

void Odd_even_sort_odd_row(int arr[], int n)
{
    bool isSorted = false;


    while (!isSorted)
    {
        isSorted = true;

        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }


        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

void Odd_even_sort_even_row(int arr[], int n)
{
    bool isSorted = false;
    
    while (!isSorted)
    {
        isSorted = true;

        for (int i = n - 2; i >= 1; i = i - 2)
        {
            if (arr[i] > arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                isSorted = false;
            }
        }


        for (int i = n - 1; i > 0; i = i - 2)
        {
            if (arr[i] > arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                isSorted = false;
            }
        }
    }
   
}

void Odd_even_sort_column(int** arr, int n)
{


    for (int j = 0; j < n; j++)
    {
        bool isSorted = false;
        while (!isSorted)
        {
            isSorted = true;

            for (int i = 1; i <= n - 2; i = i + 2)
            {
                if (arr[i][j] > arr[i + 1][j])
                {
                    swap(arr[i][j], arr[i + 1][j]);
                    isSorted = false;
                }
            }


            for (int i = 0; i <= n - 2; i = i + 2)
            {
                if (arr[i][j] > arr[i + 1][j])
                {
                    swap(arr[i][j], arr[i + 1][j]);
                    isSorted = false;
                }
            }
        }
    }
}


void Shear_sort(int** matrice, int n)
{
    
    for (int i = 1; i <= (int)2*ceil(log2(n)) + 1; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j % 2 != 0)
                {
                    Odd_even_sort_odd_row(matrice[j - 1], n);
                }
                else
                {
                    Odd_even_sort_even_row(matrice[j - 1], n);
                }
            }
        }
        else
        {
            Odd_even_sort_column(matrice, n);
        }

    }
}
