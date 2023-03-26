#include "Functions.h"

void Afiasre_matrice(int** matrice, int n)
{
    cout << "Matrice: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

void Citeste_matrice(int** matrice, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrice[" << i << "][" << j << "]=";
            cin >> matrice[i][j];
        }
    }
}



void Creaza_matrice_la_intamplare(int** matrice, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrice[i][j] = rand() % 10000000 + 1;
        }
    }
}

void Creare_fisier_matrice(ofstream& out_file)
{
    out_file.open("fisier_matrice_5120x5120.txt");
    if (!out_file) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
}

void Scriere_in_fisier_matrice(ofstream& out_file, int **matrice, int n)
{
    out_file << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            out_file << matrice[i][j] << " ";
        }
        out_file << endl;
    }
    out_file.close();
}

void Citeste_matricea_din_fisier(ifstream& in_file, int** matrice, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in_file >> matrice[i][j];
        }
    }
}

void PrintMemoryInfo(DWORD processID)
{
    HANDLE hProcess;
    PROCESS_MEMORY_COUNTERS_EX pmc;
    MEMORYSTATUSEX memInfo;

    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ,
        FALSE, processID);
    if (NULL == hProcess)
        return;

    if (GetProcessMemoryInfo(hProcess, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc)))
    {
        cout << "PrivateBytes: " << pmc.PrivateUsage << endl;
    }

    CloseHandle(hProcess);
}