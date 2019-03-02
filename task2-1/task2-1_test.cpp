//
// Created by apbfor on 28.02.19.
//


#include "iostream"
#include "cstdio"

#include "task2-1.h"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


TEST_CASE("checksize") {

    LinkedList<double> doubleList;
    doubleList.PushBack(12.05);
    doubleList.PushFront(6.18);

    REQUIRE(doubleList.GetSize() == 2);

}

TEST_CASE("find_elem") {
    LinkedList<double> doubleList;
    doubleList.PushFront(6.18);

    SECTION("elem_exists") {

        REQUIRE(doubleList.Find(6.18)->data == 6.18);

    }

    SECTION("elem does not exists") {
        REQUIRE(doubleList.Find(5) == nullptr);
    }
}


TEST_CASE("remove elem") {
    LinkedList<double> doubleList;

    SECTION("Список не пустой") {
        doubleList.PushBack(3.12);
        doubleList.PushBack(6.17);
        doubleList.PushBack(5.96);
        doubleList.PushFront(7.41);

        //удаляем элемент из списка
        doubleList.Remove(3.12);

        REQUIRE(doubleList.Find(3.12) == nullptr);
        REQUIRE(doubleList.GetSize()==3);
    }

    SECTION("Пытаемся удалить из пустого списка") {
        //можно ли считать это тестом? ошибки как бы нет при вызове функции,
        // void функция просто заканчивает выполнение в случае обращения к ней из пустого списка (head == nullptr)
        doubleList.Remove(5.91);
    }
}

TEST_CASE("clear") {
    LinkedList<double> doubleList;
    SECTION("Список не пустой") {
        doubleList.PushBack(3.12);
        doubleList.PushBack(6.17);
        doubleList.PushBack(5.96);
        doubleList.PushFront(7.41);

        doubleList.Clear();

        REQUIRE(doubleList.GetSize()==0);
    }

    SECTION("Список пуст") {
        doubleList.Clear();

        REQUIRE(doubleList.GetSize()==0);
    }

    SECTION("То же самое, но теперь проверяем указатели") {
        doubleList.Clear();

        REQUIRE(doubleList.GetHead()== nullptr);
    }

    SECTION("same things") {
        doubleList.Clear();
        REQUIRE(doubleList.GetTail()== nullptr);

    }
}


TEST_CASE("Pop_Front") {
    LinkedList<double> doubleList;

    SECTION("is not empty") {
        doubleList.PushBack(3.12);
        doubleList.PushBack(6.17);
        doubleList.PushBack(5.96);
        doubleList.PushFront(12.512);

        REQUIRE(doubleList.PopFront() == 12.512);
        REQUIRE(doubleList.PopFront() == 3.12);
    }

    //должен вернуть значение по умолчанию, определенное для каждого типа данных
    SECTION("is empty") {
        REQUIRE(doubleList.PopFront() == 0.0);
        REQUIRE(doubleList.GetSize()==0);
    }
}


TEST_CASE("Pop_Back") {
    LinkedList<double> doubleList;

    SECTION("is not empty") {
        doubleList.PushBack(3.12);
        doubleList.PushBack(6.17);
        doubleList.PushBack(5.96);
        doubleList.PushFront(12.512);

        REQUIRE(doubleList.PopBack() == 5.96);
        REQUIRE(doubleList.PopBack() == 6.17);
    }

    //должен вернуть значение по умолчанию, определенное для каждого типа данных
    SECTION("is empty") {
        REQUIRE(doubleList.PopFront() == 0.0);
        REQUIRE(doubleList.GetSize()==0);
    }

}

