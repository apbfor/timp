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

static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

// генерирует кейс <строка, подстрока, позиция>
tuple<string, string, size_t> gen_test_case(size_t max_string_length, size_t max_substring_length) {
    size_t text_length = rand() % max_string_length + 1;
    size_t substring_length = rand() % min(max_substring_length, text_length) + 1;

    string text;
    for (size_t i = 0; i<text_length; ++i)
        text += alphanum[rand() % (sizeof(alphanum) - 1)];

    // выбираем случайный отрезок на строке
    size_t substring_position = rand()%(text_length - substring_length + 1);
    string substring(text.begin() + substring_position, text.begin() + substring_position + substring_length);

    // проверка на отсутствие более ранней подстроки
    if (text.find_first_of(substring) != substring_position)
        return gen_test_case(max_string_length, max_substring_length);

    return make_tuple(text, substring, substring_position);
}


void benchmark(const string& description, size_t samples, size_t max_string_length, size_t max_substring_length) {
    cout << "[*] generating: " << description << endl;
    vector<tuple<string, string, size_t>> test_cases;
    for (int i = 0; i < samples; ++i)
        test_cases.push_back(gen_test_case(max_string_length, max_substring_length));

    cout << "[*] running: simple" << endl;
    auto n_start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    for (auto& c: test_cases)
        if (simple_substring(get<0>(c),get<1>(c)) != get<2>(c))
            throw logic_error("sample failed");
    auto n_end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    cout << "[+] simple:" << (n_end - n_start).count() << "ns" << endl;

    cout << "[*] running: boyer moore" << endl;
    auto bm_start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    for (auto& c: test_cases)
        if (b_m_substring(get<0>(c),get<1>(c)) != get<2>(c))
            throw logic_error("sample failed, test " + get<0>(c) + " ~~ " + get<1>(c) + " %% " + to_string(get<2>(c)));
    auto bm_end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    cout << "[+] boyer moore:" << (bm_end - bm_start).count() << "ns" << endl;
    cout << "[+] boyer_moore/simple = " << float((bm_end - bm_start).count())/(n_end - n_start).count() << endl;
}


int main () {
    benchmark("short str, short subStr", 10, 100, 10);
    benchmark("long str, long subStr", 10, 100000, 100);
    benchmark("long str, short subStr", 10, 100000, 10);
    benchmark("long str, very short subStr", 10, 100000, 5);
    return 0;
}