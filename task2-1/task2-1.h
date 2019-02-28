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


#include <cstdio>


template<typename T>
struct Node {
    Node(T data, Node<T>* prev, Node<T>* next): data(data), prev(prev), next(next) {}; //конструктор по списку инициализации
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template<typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    // Метод добавления элемента в конец списка
    void push_back(T data) {
        auto new_tail = new Node({data, tail, (Node<T>*)nullptr});
        tail != nullptr ? tail->next : head = new_tail;
        tail = new_tail;
    }

    // Метод добавления элемента в начало списка
    void push_front(T data) {
        auto new_head = new Node({data, (Node<T>*)nullptr, head});
        head != nullptr ? head->prev : tail = new_head;
        head = new_head;
    }

    // Поиск в списке по ключу
    Node<T>* find(T data) {
        if (head == nullptr) return nullptr;
        for (auto sp = head; sp != nullptr; sp = sp->next)
            if (sp->data == data) return sp;
        return nullptr;
    }

    // Удаление элемента по ключу
    void remove(T data) {
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
    }

    // Определение количества элементов в списке
    size_t size_calc() {
        size_t counter = 0;
        if (head == nullptr) return 0;
        for (auto it = head; it != nullptr; it = it->next, ++counter);
        return counter;
    }

    // Очистить список
    void clear() {
        for (auto it = head; it != nullptr; it = it->next)
            if (it->prev != nullptr) delete it->prev;
        delete tail;
        head = tail = nullptr;
    }
    
    ~LinkedList(){
        this->clear();
    }
};


