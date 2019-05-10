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

    // Создаем min heap с k узлами. Каждый узел имеет первый элемент из выходного файла
    MinHeapNode* harr = new MinHeapNode[k];
    int i;
    for (i = 0; i < k; i++)
    {
        // выйдет из цикла, если какой то из файлов не пуст, индекс i будет номером входного файла
        if (fscanf(in[i], "%d ", &harr[i].element) != 1)
            break;

        harr[i].i = i; // Индекс взятия из выходного файла
    }
    MinHeap hp(harr, i); // Создаем кучу

    int count = 0;

    // По одному берем минимальный элемент из min heap и заменяем его со следующим элементом.
    // запускаем для всех входных файлов, пока не достигнем конца
    while (count != i)
    {
        // Берем минимальный элемент и сохраняем его в выходном файле
        MinHeapNode root = hp.getMin();
        fprintf(out, "%d ", root.element);

        // Ищем следующий элемент, который заменит текущий корень кучи. Следующий элемент принадлежит тому же входному файлу
        // как текущий минимальный элемент.
        if (fscanf(in[root.i], "%d ", &root.element) != 1 )
        {
            root.element = INT_MAX;
            count++;
        }

        // заменяем корень текущим элементом входного файла
        hp.replaceMin(root);
    }

    // закрываем входные и выходной файлы
    for (int i = 0; i < k; i++)
        fclose(in[i]);

    fclose(out);
}

// Используя алгоритм сортировки слиянием, создаем начальный запуск и делим его на все среди выходных файлов
void createInitialRuns(char *input_file, int run_size,
                       int num_ways)
{
    // для большого входного файла
    FILE *in = openFile(input_file, "r");

    // выходные файлы
    FILE* out[num_ways];
    char fileName[2];
    for (int i = 0; i < num_ways; i++)
    {
        // переводим номер в строку
        snprintf(fileName, sizeof(fileName), "%d", i);

        // открываем выходные файлы в режиме для записи
        out[i] = openFile(fileName, "w");
    }

    // Выделяем динамическйи массив достаточного размера, чтобы вмещать запуск размера run_size
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

        // сортируем массив, используя сортировку слиянием
        mergeSort(arr, 0, i - 1);

        // записываем в подходящий выходной файл
        for (int j = 0; j < i; j++)
            fprintf(out[next_output_file], "%d ", arr[j]);

        next_output_file++;
    }

    // закрываем выходные и входной файлы
    for (int i = 0; i < num_ways; i++)
        fclose(out[i]);

    fclose(in);
}

// для сортировки хранящихся на диске данных
void externalSort(char* input_file,  char *output_file,
                  int num_ways, int run_size)
{
    // читаем входной файл, создаем начальный запуск и назначаем для запуска на выходных файлах

    createInitialRuns(input_file, run_size, num_ways);

    // сливаем запуски
    mergeFiles(output_file, run_size, num_ways);
}


// тестовая программа для обзора возможностей
int main()
{
    // количество частей каждого файла
    int num_ways = 100;

    // размер каждой части
    int run_size = 100000;

    char input_file[] = "/home/apbfor/Desktop/sort/input.txt";
    char output_file[] = "/home/apbfor/Desktop/sort/output.txt";

    FILE* in = openFile(input_file, "w");

    srand(time(NULL));


    // генерируем входной файл
    for (int i = 0; i < num_ways * run_size; i++)
        fprintf(in, "%d ", rand()%50001);

    fclose(in);

    externalSort(input_file, output_file, num_ways, run_size);

    return 0;
}
