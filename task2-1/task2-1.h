//
// Created by 2017-3-11-lim on 2/25/19.
//


/* Двусвязный список.
 * Операции: добавление элемента в начало списка;
 * добавление элемента в конец списка;
 * поиск элемента в списке по ключу;
 * удаление элемента по ключу;
 * извлечение элемента с начала списка;
 * извлечение элемента с конца списка;
 * определение количества элементов в списке;
 * очистка списка.
*/


/*
 * Двусвязный список реализован на основе шаблонного класса, полями в котором являются указатели на объекты
 * шаблонной структуры, полями которой являются указатели на предыдущий и следующий элементы в списке, а также
 * содержит поле для данных.
 */

#ifndef TEST_EMPTY_TASK2_1_H
#define TEST_EMPTY_TASK2_1_H

#endif //TEST_EMPTY_TASK2_1_H

#include <iostream>
#include <cstdio>
using namespace std;


template<typename T>
struct Node {
    //конструктор по списку инициализации
    Node(T data, Node<T>* prev, Node<T>* next): data(data), prev(prev), next(next) {}
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template<typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
public:


    Node<T>* GetHead(){return head;} //специально для тестов

    Node<T>* GetTail(){return tail;} //специально для тестов

    ~LinkedList(){
        this->Clear();
    }

    int GetSize(){return size;}

    // Метод добавления элемента в конец списка
    void PushBack(T data) {
        auto tail_new = new Node({data, tail, (Node<T>*)nullptr});
        if (tail != nullptr)
            tail->next = tail_new;
        else
            head = tail_new;
        tail = tail_new;
        size++;
    }

    Node<T>* PopFront1() {
        Node<T> *temp;
        temp = head->next;
        temp->prev = nullptr;
        cout << head->data << endl;
        head = temp;

        size--;
        return temp;
    }

    T PopFront() {
        if(head!=nullptr) {
            T data1;

            Node<T> *temp;
            temp = head->next;
            temp->prev = nullptr;
            data1 = head->data;
            head = temp;

            size--;

            return data1;
        } else return T();
    }

    
    T PopBack() {
       if(tail!= nullptr) {
            T data1;
            data1 = tail->data;
            tail->prev->next = nullptr;
            tail = tail->prev;
            size--;
            return data1;
        }
       else return T();
    }

    // Поиск в списке по ключу
    Node<T>* Find(T data) {
        if (head == nullptr) return nullptr;
        for (auto sp = head; sp != nullptr; sp = sp->next)
            if (sp->data == data) return sp;
        return nullptr;
    }

    // Удаление элемента по ключу
    void Remove(T data) {
        if (head == nullptr) return;
        for (auto sp = head; sp != nullptr; sp = sp->next) {
            if (sp->data == data) {
                if (sp == head) head = sp->next;
                if (sp == tail) tail = sp->prev;
                if (sp->next != nullptr) sp->next->prev = sp->prev;
                if (sp->prev != nullptr) sp->prev->next = sp->next;
                delete sp;
            }
        }
        size--;
    }

    // Метод добавления элемента в начало списка
    void PushFront(T data) {
        auto head_new = new Node({data, (Node<T>*)nullptr, head});
        if (head != nullptr)
            head->prev = head_new;
        else
            tail = head_new;
        head = head_new;
        size++;
    }

    // Определение количества элементов в списке
    void Print() {
        if (head == nullptr)
            cout<<"Список пуст! "<< endl;
        else
        for (auto it = head; it != nullptr; it = it->next)
            cout << it->data << " ";
        cout << endl;

    }

    // Очистить список
    void Clear() {
        for (auto it = head; it != nullptr; it = it->next)
            if (it->prev != nullptr) delete it->prev;
        delete tail;
        head = tail = nullptr;
        size = 0;
    }
    

};


