#include "Functions.h"




int main(int argc, char** argv)
{
    int myid, numprocs;

    MPI_Status stat;
    int linie_transmisa;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
   


    ifstream in_file("fisier_matrice_320x320.txt");
    int n;
    in_file >> n;
    int* vector = new int[n];
    int** matrice = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrice[i] = new int[n];
    };


    if (myid == numprocs-1)
    {
        Citeste_matricea_din_fisier(in_file, matrice, n);
    }
    
    

    MPI_Barrier(MPI_COMM_WORLD);


    auto start = high_resolution_clock::now();
    for (int i = 1; i <= (int)2 * ceil(log2(n)) + 1; i++)
    {

        if (myid == numprocs - 1)
        {

            for (int j = 0; j < n; j++)
            {
                for (int u = 0; u < n; u++)
                {
                    if (i % 2 != 0)
                    {
                        vector[u] = matrice[j][u];
                    }
                    else
                    {
                        vector[u] = matrice[u][j];
                    }
                }
                for (int u = 0; u < n; u++)
                {
                    MPI_Send(&vector[u], 1, MPI_INT, j % (numprocs - 1), 1, MPI_COMM_WORLD);
                }
            }
            for (int j = 0; j < n; j++)
            {
                for (int u = 0; u < n; u++)
                {
                    MPI_Recv(&vector[u], 1, MPI_INT, j % (numprocs - 1), 1, MPI_COMM_WORLD, &stat);
                }
                for (int u = 0; u < n; u++)
                {
                    if (i % 2 != 0)
                    {
                        matrice[j][u] = vector[u];
                    }
                    else
                    {
                        matrice[u][j] = vector[u];
                    }
                }
            }


        }
       
        if (myid != numprocs - 1)
        {
            for (int z = 0; z < n; z++)
            {
                MPI_Recv(&vector[z], 1, MPI_INT, numprocs - 1, 1, MPI_COMM_WORLD, &stat);
            }
            if (i % 2 != 0)
            {
                if ((myid + 1) % 2 != 0)
                {
                    Odd_even_sort_odd_row(vector, n);
                }
                else
                {
                    Odd_even_sort_even_row(vector, n);
                }
            }
            else
            {
                Odd_even_sort_odd_row(vector, n);
            }
            for (int z = 0; z < n; z++)
            {
                MPI_Send(&vector[z], 1, MPI_INT, numprocs - 1, 1, MPI_COMM_WORLD);
            }

        }
       

        



    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    if (myid == numprocs - 1)
    {
        cout << endl << "Time for function completion for matrix of " << n << "^2 is: " << duration.count()
            << " microseconds from id: " << myid << endl;
    }
    
    MPI_Finalize();

    for (int i = 0; i < n; i++)
    {
        delete[] matrice[i];
    }
    delete[] matrice;

    return 0;
}