//
// Created by apbfor on 22.03.19.
//

#ifndef TEST_EMPTY_TASK2_4_H
#define TEST_EMPTY_TASK2_4_H

#endif //TEST_EMPTY_TASK2_4_H


struct MinHeapNode
{
    int element; //то, что будем хранить
    int i; //индекс в массиве, откуда взят элемент
};


//своп-функция для двух объектов
void swap(MinHeapNode* x, MinHeapNode* y);
//класс для хранения minHeap
class MinHeap
{
    MinHeapNode* harr; //указатель на массив элементов в куче
    int heap_size;     //размер кучи

public:
    // создает кучу заданного размера
    MinHeap(MinHeapNode a[], int size);

    // восстанавливает поддерево с корнем в полученном индексе
    void MinHeapify(int);

    // получить индекс левого потомка узла с индексом i
    int left(int i) { return (2 * i + 1); }

    //получить индекс правого потомка узла с индексом i
    int right(int i) { return (2 * i + 2); }

    // получаем корень
    MinHeapNode getMin() {  return harr[0]; }

    // заменяем корень новым узлом и приводим к необходимому виду
    // new root
    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};
