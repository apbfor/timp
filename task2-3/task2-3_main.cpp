//
// Created by apbfor on 17.03.19.
//

#include <random>
#include <string>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <chrono>

#include "task2-3.h"

using namespace std;
using namespace std::chrono;

static const char aplphabet[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";


void benchmark(const string str, const string subStr){
    auto simple_start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    simple_indexOf(str,subStr);
    auto simple_end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());

    auto bm_start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    b_m_substring(str,subStr);
    auto bm_end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    cout << "*** Бойера-Мура/Простейшая *** = "
         <<float((bm_end - bm_start).count())/(simple_end-simple_start).count() << endl;
}

// генерирует кейс <строка, подстрока, позиция>, служит для быстрого заполнения списка рандомными строками/подстроками
tuple<string, string, size_t> generate_test(size_t max_string_length, size_t max_substring_length) {
    size_t text_length = rand() % max_string_length + 1; //задаем длину для строки
    size_t substring_length = rand() % min(max_substring_length, text_length) + 1;  //задаем длину для подстроки,
                                                                                    //не превышающую длину строки

    //заполняем строку рандомными символами из алфавита
    string text;
    for (size_t i = 0; i<text_length; ++i)
        text += aplphabet[rand() % (sizeof(aplphabet) - 1)];

    // выбираем случайный отрезок на строке с условием, что в итоге длина подстроки не выйдет за пределы строки
    size_t substring_position = rand()%(text_length - substring_length + 1);
    //присваиваем подстроке значение исходной строки в этом месте
    string substring(text.begin() + substring_position, text.begin() + substring_position + substring_length);

    // проверка на отсутствие более ранней подстроки, если нашли - рандом заново
    if (text.find_first_of(substring) != substring_position)
        return generate_test(max_string_length, max_substring_length);

    //если всё в порядке, возвращаем сгенерированный кортеж
    return make_tuple(text, substring, substring_position);
}


void benchmark(const string& description, size_t samples, size_t max_string_length, size_t max_substring_length) {
    cout << "Создаю " << description << endl;
    /* создаем вектор, содержащий кортежи формата text, substring, substring_position,
     * для того, чтобы множественные тесты были достовернее - один проходил слишком быстро и порой не отражал
     * действительное положение вещей
     */
    vector<tuple<string, string, size_t>> test_cases;
    for (int i = 0; i < samples; ++i)
        test_cases.push_back(generate_test(max_string_length, max_substring_length));

    cout << "Запускаю простешую " << endl;
    auto simple_start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    for (auto& it: test_cases)
        if (simple_indexOf(get<0>(it),get<1>(it)) != get<2>(it))
            throw logic_error("ошибка поиска");
    auto simple_end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    cout << "Простейшая :" << (simple_end - simple_start).count() << " наносекунд" << endl;

    cout << "Запускаю алгоритм Бойера-Мура" << endl;
    auto bm_start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    for (auto& c: test_cases)
        if (b_m_substring(get<0>(c),get<1>(c)) != get<2>(c))
            throw logic_error("ошибка поиска, тест " + get<0>(c) + " ~~ " + get<1>(c) + " %% " + to_string(get<2>(c)));
    auto bm_end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    cout << "Бойера - мура:" << (bm_end - bm_start).count() << " наносекунд" << endl;
    cout << "*** Бойера-Мура/Простейшая *** = "
         <<float((bm_end - bm_start).count())/(simple_end-simple_start).count() << endl;
}



int main () {
//    for (int i=0; i<10; ++i){
//        cout << i << ' ';
//    }
//    cout << endl;


    benchmark("короткая строка, короткая подстрока", 10, 100, 10);
    benchmark("длинная строка, длинная подстрока", 10, 100000, 100);
    benchmark("длинная строка, короткая подстрока", 10, 100000, 10);
    benchmark("длинная строка, очень короткая подстрока", 10, 100000, 5);

    //setlocale(LC_ALL, "russian");

    benchmark("asdloip","dloip");
    benchmark("gyhujuy","huju");
    benchmark("yui67hv12bnoi78","7hv12b");
    benchmark("uiop","io");
    benchmark("uiop","i");
    benchmark("yuijoplkjhgfdftyuio876rtfgvbnmlkpo98765rdfgvhjk","76rt");
    benchmark("ПриветМир","Мир");
    cout << simple_indexOf("ПриветМир","Мир") << endl;

    return 0;
}