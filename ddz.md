## Перечень долгосрочных домашних заданий

## Выбор задания

Внутри группы повторы вариантов заданий не допускаются.

В соответствующем issue [7323](http://gitlabnto/anetto/timp/issues/5), [7324](http://gitlabnto/anetto/timp/issues/4), [7325](http://gitlabnto/anetto/timp/issues/6) нужно оставить запись по указанному формату. При повторах вариантов заданий считается, что вариант принадлежит первому записавшемуся пользователю.

## Требования к отчёту

Отчет представляет собой материал, который в обязательном порядке представляется обучающимся преподавателю в течение семестра. Он содержит описание результатов выполнения задания, обоснование принятых решений, а также доказательство работоспособности разработанной программы. Объем отчета обычно не превышает 10-20 страниц.

Срок сдачи долгосрочного задания и отчета по нему - 15 апреля

Принятый отчет о выполнении долгосрочного домашнего задания является критерием допуска к сдаче экзамена по учебной дисциплине.

Отчет оформляется в соответствии с методическими рекомендациями по оформлению письменных работ на кафедре, которые изложены в пособии [«В.В. Абраменков, Л.В. Митрякова, В.В. Райх, В.А. Тихонов. Оформление письменных работ слушателей: учебно-методическое пособие. М.: Типография в/ч 33965, 2018, 132 с.»](/uploads/bd9aa14286a0ef80dd48a554b777ffe3/Оформление_письменных_работ-2018_3.pdf).


Готовые стили и горячие клавиши реализованы в [шаблоне документа для ЛР](http://gitlabnto/anetto/wiki/wikis/%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD-%D0%B4%D0%BE%D0%BA%D1%83%D0%BC%D0%B5%D0%BD%D1%82%D0%BE%D0%B2).

Отчет должен содержать:
1.	Титульный лист;
1.	Описание задания – в этом подразделе проводится полное описание задания,  описывается суть задачи, анализ входных параметров, область их допустимых значений, анализ условий при которых задача имеет решение (не имеет решения), анализ ожидаемых результатов;
1.	Основная часть:
    -	математическая модель реализуемого алгоритма, включая его теоретическое описание и оценку его вычислительной сложности;
    -	реализация алгоритма, включая листинг программы на языке программирования С++;
    -	практическая оценка вычислительной сложности алгоритма (см. пояснения далее).
1.	Выводы по результатам выполнения долгосрочного задания.

Для практической оценки вычислительной сложности алгоритма производится эксперимент по оценке времени выполнения алгоритма в зависимости от размера входных данных (количество узлов дерева, размер массива строк, количество вершин графа и т.п. в зависимости от варианта задания). Эксперимент проводится в несколько шагов – для различного размера входных данных, что позволяет практически убедиться в том, что время выполнения алгоритма соответствующим образом зависит от размера входных данных (линейная, квадратичная зависимость и т.д.). Размер данных подбирается индивидуально в зависимости от реализуемого алгоритма таким образом, чтобы измеренная скорость работы алгоритма составляла десятки секунд. **Измерения в милли- и наносекундах не допускаются**. Пределах столь малых значений речь идёт не о работе алгоритма, а об измерении случайных перестановок диспетчера задач операционной системы.

Количество шагов эксперимента выбирается самостоятельно, чтобы наглядно продемонстрировать вычислительную сложность алгоритма (Недостаточно использовать две точки для линейной сложности, через две точки можно провести кривую любой формы).

Измерения времени работы алгоритма необходимо производить любым известным программным способом, фиксируя в программе время начала и конца работы алгоритма, с последующим определением времени или с использованием счетчиков и т.п.

Для снижения погрешности экспериментов рекомендуется:
 *	Использовать версию RELEASE, а не DEBUG;
 *	каждый шаг эксперимента повторять несколько раз (не менее 5);
 *	измерения производить на одном и том же оборудовании, в одних и тех же условиях (режим работы, запущенное программное обеспечение). Рекомендуется отключить режимы энергосбережения, отключение неиспользуемых ядер процессора и т.п.

Результаты эксперимента необходимо представить в табличном и графическом виде. Графический вид позволяет наглядно отобразить результат. На графике необходимо совместить теоретическую и практическую оценку вычислительной сложности. Теоретическая изображается в виде кривой, практическая – в виде точек. Пример табличного представления приведен в таблице 1. Пример графического отображения – на рисунке 1.

**Таблица 1 – Пример табличного представления результатов эксперимента**


| Шаг | Кол-во элементов | Эксперимент №1, мс | Эксперимент №2, мс | Эксперимент №3, мс | Эксперимент №4, мс | Эксперимент №5, мс |
| --- | ---------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------ |
| 1 | 100	| 160345	| 150028	| 170654	| 140253	| 180254 | 
| 2 | 200	| 320054	| 330558	| 290658	| 340587	| 280564 | 
| 3 | 300	| 500125	| 520145	| 600258	| 550658	| 580547 | 
| 4 | 400	| 880547	| 900568	| 920587	| 911111	| 930258 | 
| 5 | 500	| 1305847	| 1405874	| 1425588	| 1350258	| 1385473 | 


Для удобства формирования графиков рекомендуется использовать табличный редактор MS Excel. Для построения теоретического графика необходимо аппроксимировать практические значения.

![Перечень_долгосрочных_заданий_2019-1](/uploads/f8fad588ee01402280f8b7645f62f0f1/Перечень_долгосрочных_заданий_2019-1.png)

**Рисунок 1 – Пример квадратичной зависимости, приведенной в таблице 1**

Не должно быть сильных расхождений между практическими и теоретическими значениями, расхождение говорит либо о неправильно проведенном эксперименте, ошибках в алгоритме или неправильном построении теоретического графика. Пример неправильного графика приведен на рисунке 2.

![Перечень_долгосрочных_заданий_2019-2](/uploads/97138a2ee388a78c5b5b411f52a19bde/Перечень_долгосрочных_заданий_2019-2.png)

**Рисунок 2 – Пример неправильно построенного графика**

## Варианты заданий

1 Бинарное дерево. Операция поиска

2 АВЛ-дерево. Операция поиска

3 Красно-черное дерево. Операция поиска

4 В-дерево. Операция поиска

5 Оптимальное бинарное дерево поиска. Операция поиска

6 Куча. Операция поиска

7 Хеш-таблица с разрешением коллизий с помощью связных списков. Операция поиска

8 Префиксное дерево. Операция поиска

9 Поиск подстроки в строке. Алгоритм Кнута-Морриса-Пратта. Операция поиска

10 Поиск подстроки в строке. Алгоритм Бойера-Мура

11 Поиск подстроки в строке. Алгоритм Рабина-Карпа

12 Поиск подстроки в строке. Конечный автомат

13 Алгоритм сортировки «обменная»

14 Алгоритм сортировки «вставкой»

15 Алгоритм сортировки Шелла

16 Алгоритм сортировки «выбором»

17 Алгоритм пирамидальной сортировки

18 Алгоритм сортировки «слиянием»

19 Алгоритм быстрой сортировки

20 Поиск в ширину в неориентированном графе с помощью матрицы смежности

21 Поиск в глубину в неориентированном графе с помощью матрицы смежности

23 Поиск в ширину в ориентированном графе с помощью списка смежности

24 Поиск в глубину в ориентированном графе с помощью списка смежности

26 Построение минимального остовного дерева. Алгоритм Крускала

27 Построение минимального остовного дерева. Алгоритм Прима

28 Нахождение кратчайших путей в графе. Алгоритм А*

29 Нахождение кратчайших путей в графе. Алгоритм Дейкстры

30 Выделение сильносвязных компонент в ориентированном графе
