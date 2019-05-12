//
// Created by apbfor on 22.03.19.
//
#include <bits/stdc++.h>
#include <fstream>
#include "task2-4.h"
using namespace std;




// тестовая программа для обзора возможностей
int main() {
    // количество частей каждого файла
    int num_ways = 1000;

    // размер каждой части
    int run_size = 1000000;

    char input_file[] = "/home/user/Desktop/sort/input.txt";
    char output_file[] = "/home/user/Desktop/sort/output.txt";

    FILE* in = openFile(input_file, "w");

    srand(time(NULL));


    // генерируем входной файл
    for (int i = 0; i < num_ways * run_size; i++)
        fprintf(in, "%d ", rand()%50001);

    fclose(in);

    externalSort(input_file, output_file, num_ways, run_size);

    return 0;
}
