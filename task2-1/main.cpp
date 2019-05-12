//
// Created by 2017-3-11-lim on 2/25/19.
//

#include "task2-1.h"
#include <iostream>

using namespace std;

int main () {


    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    LinkedList< double > doubleList;

    cout << "Размер doubleList getter " << doubleList.GetSize() << endl;

    doubleList.PushBack(5.16);
    doubleList.PushFront(8.199);
    doubleList.PushBack(8.199);
    doubleList.PushBack(8.199);
    doubleList.PushBack(8.199);
    doubleList.PushFront(8.19123);


    cout << "Размер doubleList  getter " << doubleList.GetSize() << endl;


    doubleList.Clear();

    cout << "after Clear " << endl;
    cout << "Размер doubleList getter " << doubleList.GetSize() << endl;

    doubleList.PushBack(8.199);
    doubleList.PushBack(18.199);
    doubleList.PushBack(8998.199);
    doubleList.PushBack(9998.19123);

    doubleList.Print();


    auto it = doubleList.Find(18.199);
    if (it == nullptr) {
        cout << "Не могу найти элемент" << endl;
    } else {
        cout << "element найден: " << it->data << endl;
    }

    cout << "Размер doubleList getter " << doubleList.GetSize() << endl;

    doubleList.Print();
    cout << doubleList.PopFront() << endl;
    doubleList.Print();
    cout << doubleList.PopBack() << endl;
    doubleList.Print();
    cout << "size = " << doubleList.GetSize() << endl;


    return 0;
}