//
// Created by 2017-3-11-lim on 2/25/19.
//

#include "task2-1.h"
#include <iostream>

using namespace std;

int main () {
    LinkedList<int> intList;

    cout << "Размер инициализированного массива: " << intList.size_calc() << endl;

    intList.push_back(1);
    cout << "Добавили один целочисленный элемент: " << intList.size_calc() << endl;

    intList.push_front(2);
    cout << "Добавили еще один целочисленный элемент:" << intList.size_calc() << endl;

    intList.clear();
    cout << "После очистки: " << intList.size_calc() << endl;

    intList.push_back(5);
    intList.push_front(6);
    intList.push_back(6);
    intList.push_front(6);
    intList.push_back(23);
    intList.push_front(7);
    cout << "Добавлены 5,6,6,6,23,7: " << intList.size_calc() << endl;

    intList.remove(6);
    cout << "Удален 6: " << intList.size_calc() << endl;


    auto it = intList.find(5);
    (it == nullptr ? cout << "Не могу найти элемент 5" : cout << "5 найден: " << it->data) << endl;


    return 0;
}