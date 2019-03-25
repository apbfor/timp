//
// Created by apbfor on 17.03.19.
//

/*
 * 5. Поиск подстроки в строке.
 * Простейший алгоритм.
 * Алгоритм Бойера-Мура.
 * Сравнение времени выполнения реализаций указанных алгоритмов.
 */

#include <vector>
#include <string>
#include <map>
#include <iostream>

//для отладки закомментировать
#define NODEBUG

using namespace std;

size_t simple_indexOf(const string &str, const string &subStr) {
    for (auto it = str.begin(); it != str.end(); ++it)
        if (string(it, it+subStr.size()) == subStr)
            return distance(str.begin(), it);
    return string::npos;
}

size_t b_m_substring(const string &str, const string &subStr) {

    // Эвристика плохих символов
    // для каждого символа подстроки (кроме последнего) смотрим, на сколько
    // мы можем сместиться, если он не совпадет
    vector<size_t> bad_symbols(256, 1);
    size_t suffix_length = 0;

    //увеличиваем длину суффикса до тех пор, пока последний символ подстроки
    // совпадает с subStr[subStr.size()-suffix_length-1]
    for ( ; subStr[subStr.size()-1] == subStr[subStr.size()-suffix_length-1]; ++suffix_length);


    for ( size_t i = 0; i < subStr.size() - 1; ++i )
        bad_symbols[subStr[i]] = subStr.size() - i - 1 - suffix_length;
        bad_symbols[subStr.at(subStr.size() - 1)] = 1;

    // Эвристика совпавших суффиксов
    // для каждого [k]+суффикс ищем наиболее правое (->) [^k]+суффикс ранее в строке
    vector<size_t> suffix_shift(subStr.size(), subStr.size());
    for ( size_t i = 0; i < subStr.size(); ++i) {
        for ( size_t j = 1; j <= subStr.size() - i ; ++j ) {
            bool prev_neq = (subStr.size() - i - j - 1) < 0 or
                    subStr[subStr.size() - i - 1] != subStr[subStr.size() - i - j - 1];
            bool range_eq = (i == 0) or equal(subStr.end() - i, subStr.end(), subStr.end() - i - j, subStr.end() - j);
            if (prev_neq && range_eq) {
                suffix_shift[i] = j;
                break;
            }
        }
    }


#ifndef NODEBUG
    cout << "~~~ BAD SYMBOLS ~~~" << endl;
	for (auto& t: subStr)
		cout << "\t" << t;
	cout << endl;
	for ( size_t i = 0; i < subStr.size(); ++i)
		cout << "\t" << bad_symbols[subStr[i]];
	cout << endl << endl;

	cout << "~~~ SUFFIX TABLE ~~~" << endl;
	for (auto& t: subStr)
		cout << "\t" << t;
	cout << endl;
	for ( size_t i = 0; i < subStr.size(); ++i)
		cout << "\t" << suffix_shift[subStr.size() - i - 1];
	cout << endl << endl;
#endif

    for (size_t ending = subStr.size() - 1; ending < str.size(); ) {
#ifndef NODEBUG
        if (ending < 100) {
			cout << str.substr(0, 100) << endl;
			cout << string(ending, ' ') << "^ -- ending" << endl;
		}
#endif
        for (size_t matching = 0; matching < subStr.size(); ++matching) {
#ifndef NODEBUG
            if (ending < 100) {
				cout << string(ending - matching, ' ') << "^ -- matching" << endl;
			}
#endif
            // если очередной символ не совпал, выбираем на сколько символов мы можем сместиться
            if (str[ending - matching] != subStr[subStr.size() - matching - 1]) {
                size_t bad = bad_symbols[str[ending - matching]];
                ending += max(bad, suffix_shift[matching]);
                break;
            }
            // если последний символ совпал, мы нашли решение
            if (matching == subStr.size() - 1 )
                return ending - subStr.size() + 1;
        }
    }

    return string::npos;
}
