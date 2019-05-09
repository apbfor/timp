//
// Created by apbfor on 22.03.19.
//
#include <bits/stdc++.h>
#include <fstream>
#include "task2-4.h"
using namespace std;





// Конструктор: Создает кучу из полученного массива, полученного размера
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a; // хранит адрес массива
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

// Рекурсивный метод приведения поддерева с корнем по полученному индексу. Метод предполагает,
// что поддеревья уже приведены к нормальному виду
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

//Своп - функция для двух элементов
void swap(MinHeapNode* x, MinHeapNode* y)
{
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

// Слияние двух подмассивов массива arr[].
// где arr[l..m] - первый подмассив, а arr[m+1..r] - второй подмассив
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //создаем временные массивы
    int L[n1], R[n2];

    //копируем данные во временные массивы L[] R[]
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Сливаем обратно два массива в  arr[l..r]
    i = 0; // Инициализируем индекс первого подмассива
    j = 0; // Инициализируем индекс второго подмассива
    k = l; // Инициализируем индекс подмассива после слияния
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }


    //если в L[] остались элементы, копируем их тоже
    while (i < n1)
        arr[k++] = L[i++];

    //если в R[] остались элементы, копируем их тоже
    while(j < n2)
        arr[k++] = R[j++];
}

// l - левый индекс и r - правый индекс подмассива того массива, который должен быть сортирован
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // сортируем обе половины
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

FILE* openFile(char* fileName, char* mode)
{
    FILE* fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        perror("Ошибка при открытии файла.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Сливаем k сортированных файлов.  Имена файлов 1,2...k
void mergeFiles(char *output_file, int n, int k)
{
    FILE* in[k];
    for (int i = 0; i < k; i++)
    {
        char fileName[2];

        // переводим i в string
        snprintf(fileName, sizeof(fileName), "%d", i);

        // Открываем output файлы в режиме для чтения
        in[i] = openFile(fileName, "r");
    }

    // FINAL OUTPUT FILE
    FILE *out = openFile(output_file, "w");

    // Create a min heap with k heap nodes.  Every heap node
    // has first element of scratch output file
    MinHeapNode* harr = new MinHeapNode[k];
    int i;
    for (i = 0; i < k; i++)
    {
        // break if no output file is empty and
        // index i will be no. of input files
        if (fscanf(in[i], "%d ", &harr[i].element) != 1)
            break;

        harr[i].i = i; // Index of scratch output file
    }
    MinHeap hp(harr, i); // Create the heap

    int count = 0;

    // Now one by one get the minimum element from min
    // heap and replace it with next element.
    // run till all filled input files reach EOF
    while (count != i)
    {
        // Get the minimum element and store it in output file
        MinHeapNode root = hp.getMin();
        fprintf(out, "%d ", root.element);

        // Find the next element that will replace current
        // root of heap. The next element belongs to same
        // input file as the current min element.
        if (fscanf(in[root.i], "%d ", &root.element) != 1 )
        {
            root.element = INT_MAX;
            count++;
        }

        // Replace root with next element of input file
        hp.replaceMin(root);
    }

    // close input and output files
    for (int i = 0; i < k; i++)
        fclose(in[i]);

    fclose(out);
}

// Using a merge-sort algorithm, create the initial runs
// and divide them evenly among the output files
void createInitialRuns(char *input_file, int run_size,
                       int num_ways)
{
    // For big input file
    FILE *in = openFile(input_file, "r");

    // output scratch files
    FILE* out[num_ways];
    char fileName[2];
    for (int i = 0; i < num_ways; i++)
    {
        // convert i to string
        snprintf(fileName, sizeof(fileName), "%d", i);

        // Open output files in write mode.
        out[i] = openFile(fileName, "w");
    }

    // allocate a dynamic array large enough
    // to accommodate runs of size run_size
    int* arr = (int*)malloc(run_size * sizeof(int));

    bool more_input = true;
    int next_output_file = 0;

    int i;
    while (more_input)
    {
        // write run_size elements into arr from input file
        for (i = 0; i < run_size; i++)
        {
            if (fscanf(in, "%d ", &arr[i]) != 1)
            {
                more_input = false;
                break;
            }
        }

        // sort array using merge sort
        mergeSort(arr, 0, i - 1);

        // write the records to the appropriate scratch output file
        // can't assume that the loop runs to run_size
        // since the last run's length may be less than run_size
        for (int j = 0; j < i; j++)
            fprintf(out[next_output_file], "%d ", arr[j]);

        next_output_file++;
    }

    // close input and output files
    for (int i = 0; i < num_ways; i++)
        fclose(out[i]);

    fclose(in);
}

// For sorting data stored on disk
void externalSort(char* input_file,  char *output_file,
                  int num_ways, int run_size)
{
    // read the input file, create the initial runs,
    // and assign the runs to the scratch output files
    createInitialRuns(input_file, run_size, num_ways);

    // Merge the runs using the K-way merging
    mergeFiles(output_file, run_size, num_ways);
}


// Driver program to test above
int main()
{
    // No. of Partitions of input file.
    int num_ways = 10;

    // The size of each partition
    int run_size = 1000;

    char input_file[] = "/home/apbfor/Desktop/sort/input.txt";
    char output_file[] = "/home/apbfor/Desktop/sort/output.txt";

    FILE* in = openFile(input_file, "w");

    srand(time(NULL));

//    ofstream fout = ofstream("input11.txt", ofstream::out);
//    fout << "hello here" <<endl;
//    fout.close();

    // generate input
    for (int i = 0; i < num_ways * run_size; i++)
        fprintf(in, "%d ", rand()%500);

    fclose(in);

    externalSort(input_file, output_file, num_ways,
                 run_size);

    return 0;
}
