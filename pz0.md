## Практическое занятие №0. Знакомство с gitlab
[Переход на дополнительную часть](http://gitlabnto/anetto/timp/blob/master/pz0.md#%D0%94%D0%BE%D0%BF%D0%BE%D0%BB%D0%BD%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F-%D1%87%D0%B0%D1%81%D1%82%D1%8C)

Вы находитесь на сайте локально функционирующего **gitlab**. Его доменное имя http://gitlabnto, поэтому будем называть его gitlabnto. Это альтернатива онлайн-ресурсу gitlab. Локальный gitlabnto используется для решения двух задач:
1. Получения материалов к занятиям. [Здесь](http://gitlabnto/root/help/wikis/%D0%9F%D0%BE%D0%BB%D0%B5%D0%B7%D0%BD%D1%8B%D0%B5-%D1%81%D1%81%D1%8B%D0%BB%D0%BA%D0%B8) приведён перечень дисциплин, которые уже адаптированы для gitlabnto.
2. Работы с кодом. Проект в gitlab - это либо типовая работа слушателя по дисциплине, либо самостоятельная работа в виде курсового или дипломного проектирования. Большинство проектов закрыты по ряду соображений, но есть и открытые проекты. Например, такой [диплом](http://gitlabnto/Renzdby/GraphicalNewsExtractor). При использовании gitlabnto слушатель не привязан к конкретной аудитории и может работать из любой машины сети. Кроме того, возможна организация командной разработки.

Широко используемых сервисов для хранения кода онлайн три:
* github
* bitbucket
* gitlab

Фактически, github сейчас стал социальной сетью для программистов. В июне 2018 года Microsoft купила github  - это вынуждает искать альтернативы на тот случай, если github будет закрыт или изменится в негативном плане. 

Из этих трёх альтернатив только у gitlab есть бесплатная версия для локальной установки (так называемый self-hosted вариант). Это позволяет развернуть gitlab в любом подразделении, где есть локальная сеть. Принципы работы со всеми системами одинаковы.

Gitlab - это многофункциональный продукт, который включает в себя
* систему управления репозиториями для системы контроля версий Git - вкладки repository и merge requests слева;
* вики-систему - вкладка wiki;
* систему отслеживания ошибок (bug-tracking system, известные примеры таких систем: Redmine, Bugzilla, Atlassian JIRA, YouTrack) - вкладка issues;
* систему непрерывной доставки кода (continious integration/continious delivery) - вкладка CI/CD.

Gitlab написан на Ruby и Go.

### Первые шаги в gitlab
1. Центральной сущностью gitlab является понятие **проекта**. Проект создаётся пользователем и включает в себя множество файлов (под контролем системы контроля версий git), систему отслеживания ошибок (вкладка issues), и вики-систему. В верху, под меню, указана иерархия anetto\_fullname - timp - Repository, то есть вы находитесь в репозитории проекта timp у пользователя с full name "anetto\_fullname".

1. У каждого пользователя есть учётная запись (username при регистрации). Если username дописать в адресную строку, вы попадёте в профайл пользователя, например, http://gitlabnto/anetto. Откройте эту ссылку в новой вкладке. Посередине страницы вы видите fullname пользователя, дату его регистрации, вкладку activity - на ней цветными квадратиками отражена активность пользователя. Под активностью понимается число его действий по созданию, изменению или удалению текста. Во вкладке **personal projects** вы можете увидеть созданные пользователем проекты. Для anetto это репозитории по нескольким предметам. Зная имя пользователя и название его проекта, легко набрать полный путь http://gitlabnto/anetto/timp. Вернитесь к текущему файлу.

2. В адресной строке браузера сейчас вы видите **gitlabnto/anetto/timp/blob/master/pz0.md**, состоящую из:
  * gitlabnto - доменное имя локального сайта
  * anetto - username учётной записи автора этого проекта
  * timp - название проекта
  * blob - тип отображения записи (например, raw для отображения без форматирования, edit для редактирования и другие)
  * master - ветка, для которой отображается файл (термин "ветка" вы узнаете позже при более детальном знакомстве с git)
  * pz0.md - название того файла, который вы читаете

1. Зарегистрируйте учётную запись, для этого перейдите по ссылке  http://gitlabnto/. Внимательно отнеситесь к правильности full name и остальных полей. Full name служит для удобства других пользователей, которые видят вашу учётную запись. Username используется для входа в систему, и участвует в формировании адреса проекта. **Не забывайте username и пароль**.

1. Создайте проект timp ([инструкция](http://gitlabnto/root/help/wikis/%D0%A1%D0%BE%D0%B7%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5-%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B0)) в gitlabnto.

1. На вкладке overview вам показано множество команд для работы с этим репозиторием. Можете скопировать их на рабочий стол (например, в файл git.txt), так как после создания файла эта подсказка пропадает, и с вами останется только локальная копия на рабочем столе. Перечисленные команды доступны по ссылке [git.md](http://gitlabnto/anetto/timp/blob/master/git.md) или [git_full.md](http://gitlabnto/anetto/timp/blob/master/git_full.md)

1. Создайте файл readme.md. Этот файл нужен другим людям для знакомства с проектом. Readme.md автоматически показывается пользователю, который зашёл в репозиторий. В проекте дисциплины [Безопасность операционных систем](http://gitlabnto/anetto/bos) этот файл используется как оглавление дисциплины, пролистните вниз до его содержимого. Для проектов с открытым исходным кодом readme.md содержит небольшое описание проекта, примеры использования, информацию о лицензии и многое другое.
    * В меню слева должно быть выбрано overview-details. Посередине экрана вы видите название вашего проекта и множество пиктограмм. Нажмите плюс (посередине, где написан адрес), далее new file;
    * Ввести имя файла readme.md;
    * В содержимое readme вписать весь текст из таблицы ниже (первую строку нужно поправить в соответствии с написанным в ней)

    ```markdown
    # Сюда впишите вашу фамилию и номер по журналу в формате год поступления-номер группы-номер по журналу-Фамилия, это позволит понять, что вы скачали нужный репозиторий
    2017-3-07-Иванов
    ## Это пример заголовка
        
    Здесь могут быть написаны разные вещи. Поддерживается markdown разметка, отсюда и расширение .md
    Обратите внимание, что это продолжение первой строки.
    
    А это строка вторая. Это особенность языка разметки.
    
    Есть списки
    1. Как нумерованные.
    1. Обратите внимание, что число "1" слева при отображении превратится в корректный номер.

    * так и маркированные;
    ```
    * Внизу, в commit message впишите "добавлен readme.md", нажимите **commit changes**;
    * Посмотрите на отображаемое содержимое файла. Обратите внимание на корректную нумерацию в списке и другие изменения;

1. Работа с ветками из web-интерфейса
    * Для созданного файла доступны кнопки edit, replace, delete. Зайдите в edit;
    * Теперь работает подсветка синтаксиса. Подробнее о синтаксисе markdown [тут](http://gitlabnto/help/user/markdown#wiki-specific-markdown);
    * Добавьте ссылку на документацию выше в текст своего readme.md. Ссылка на файл должна вести на **содержимое файла readme**, а не в меню его редактирования. Эта ссылка, введённая на новой странице, должна загрузить файл readme.
    * Формат ссылки
    
    ```
    [текст для показа](сама ссылка)
    ```
    * После добавления ссылки вверху вкладку write переключите на preview. Убедитесь, что ссылка отображается корректно;
    * В commit message впишите "добавлена ссылка на документацию";
    * Target branch позволяет указать целевую ветку. Функционал веток допускает одновременное наличие разных версий файлов, среди которых можно переключаться. В обычной работе над ПЗ вам это не пригодится, но стоит попробовать эту возможность. Впишите в target branch название "new_branch" (пробелы не допускаются), галочку start a new merge request уберите. Нажмите commit;
    * Теперь вы видите новую редакцию файла. Вверху есть выпадающий список, в котором отображается "new_branch". Переключите его на master. Это действие вернёт старое содержимое файла. Таким образом, можно иметь две версии файла и легко переключаться между ними. При этом каждую из этих версий можно редактировать независимо, а при надобности - слить вместе;

1. Создание и выполнение issue. Issue - это задачи или тикеты. Предполагается, что любая разработка начинается с постановки задачи (issue). К задаче можно писать комментарии, например, с уточнениями или вариантами решения событий. К задачам относится как разработка нового функционала, так и устранение неисправностей (багов).
    * Зайдите во вкладку issues-list. Нажмите new issue на экране
    * В title впишите "Отчет по практическому занятию 0", в description впишите "освоено создание проекта". Поддерживается markdown, preview позволяет посмотреть результат. Внизу есть ссылка на документацию на markdown.
    * В assignee выберите себя. Перед выполнением submit посмотрите на верхний правый угол экрана, где меню на фиолетовом фоне. Выполните submit, и ещё раз посмотрите в верхнее меню. Теперь появилась белая цифра 1 в зеленом кружочке к пиктограмме issue - значит, вы назначены исполнителем для какого-то задания. Зайдите в это задание, и с помощью желтой кнопки close issue отметье его выполненным. Теперь после обновления страницы цифры у issue не будет.
    * Закрытое issue остаётся в общей истории, помеченное закрытым. Для каждого issue можно вести обсуждение (например, для уточнения задания или проблемы).

### Опрос
1. В целях закрепления материала проводится опрос в виде тестов из 5 вопросов. Нельзя использовать internet explorer. На тест даётся 5 минут, ещё 1 дополнительная минута на отправку результатов. По окончании 6 минут результаты отправятся автоматически. Вверху страницы таймер на 5 минут, последняя минута считается отдельно и выделена красным.
2. В начале теста нужно заполнить данные о себе. Это год поступления, последняя цифра номера группы, порядковый номер по журналу (обязательно 2 цифры, слева дополнить нулём. То есть 01, 02, 11, ..), и фамилия на русском языке. К тесту приступать только после заполнения этих данных.
3. Проходить тест можно многократно, но оценивается только первая попытка.
4. По указанию преподавателя - либо позвать преподавателя по окончании теста для выставления оценки, либо преподаватель сам посмотрит оценки в сводной таблице.
4. [Приступить к опросу по gitlab](http://gitlabnto:5000/bos/gitlab)


## Дополнительная часть
[Входной контроль ](http://gitlabnto:5000/timp/enter) для 2 семестра ТиМП - 10 вопросов, 11 минут. Ответ единственный, если выбор-кружок (radio button). Для ответа в квадратике (checkbox) ответом может быть любое число ответов (даже все) или ни один.

Выбор средства разработки всегда остаётся на усмотрение разработчика:
 - Современные средства разработки (IDE - integrated developer environment) предоставляют многое в одном - компилятор, отладчик, подсветка синтаксиса и многое другое. Примерами служат MS Visual Studio, CLion, PyCharm, Eclipse;
 - Легковесные IDE: MS Visual Code, Atom, NetBeans;
 - Или использовать совсем простые инструменты (notepad++) или гиковские - vim или emacs, которые с помощью различных плагинов могут быть дополнены до полноценной IDE, но собранной индивидуально. Сюда относится также использование консольных средств отладки и компиляции.

Здесь приведены 2 мануала по работе:
- работа в [Windows в Visual Studio](http://gitlabnto/anetto/timp/blob/master/pz0.md#%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0-%D0%B2-windows-git-gui-%D0%B8-visual-studio)
- работа в [Ubuntu в CLion](http://gitlabnto/anetto/timp/blob/master/pz0.md#%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0-%D0%B2-ubuntu-git-%D0%B8-clion)

### Работа в Windows: git gui и Visual Studio
1. Создание репозитория
    * Запустите git gui;
    * Create new repository;
    * Укажите путь к пустому каталогу timp, созданному на рабочем столе, нажмите create;
    * Откройте в проводнике этот каталог. Обратите внимание на созданный каталог .git, который и содержит весь наш репозиторий вместе со служебными файлами;
    * Help - show SSH key - generate key;
    * Ключ скопировать в настройки проекта в gitlabnto (справа сверху - settings, в меню слева SSH keys, скопировать ключ в key, указать в title название my_key), убедиться в корректном добавлении ключа;
    * Remote - Add. Name "origin", location "ssh://git@gitlabnto:2222/user/timp.git" (user надо заменить на вашу учётную запись, а timp - на ваше название проекта, если отличается), пункт fetch immediately;
    * Запрос openSSH are you sure to continue - yes;
    * ![success_repo_fetch](http://gitlabnto/anetto/bos/uploads/366bae4421ace243b2a9b80b6a85f9a6/success_repo_fetch.png)

1. Синхронизация репозитория
    * В git gui открыть repository - git bash;
    * Набрать git pull origin master
    * Эта команда позволяет вытащить (pull) данные из репозитория origin (вы его создавали на шаге remote-add, название origin - стандарт де факто для удалённого репозитория, если он единственный) и эти данные поместит в ветку master (эта ветка создаётся по умолчанию);
    * В проводнике убедитесь, что появился readme.txt с ВАШИМ содержимым;


1. Пробный проект в Visual Studio
    * Создать пустой проект file - new project - visual C++ empty project, путь укажите к папке timp на рабочем столе, снимите галочку create new git repository;
    * В мастере проекта на вкладке "параметры приложения" нажать галочку "пустой проект";
    * В созданном проекте в resource file - add existing item - добавьте свой readme.md;
    * Через visual studio измените файл readme.md, добавьте в конец строку "новые изменения"
    * В git bash наберите 
    
    ```bash
    git add readme.md
    git commit -m 'правки'
    git push origin master
    ```
    * Проверьте через веб-интерфейс, что правки теперь есть и на сервере;
    
    
### Работа в Ubuntu: git и CLion
1. Проверка связи с gitlabnto в виртуальной машине
    * В консоли

    ```bash
    ping gitlabnto
    ```
    * Если пинг есть, то всё хорошо и переходите к следующему пункту (где ssh-keygen). **Если пинга нет**, то выполните

    ```bash
    sudo nano /etc/hosts
    ```
    
    Введите пароль суперпользователя. На пустой строке (обычно третья) впишите

    ```
    192.168.115.103 gitlabnto
    ```
    Нужный IP зависит от сети, в которой вы работаете. Для классов НТО указанный IP верен. В других классах с хостовой ОС можно в консоли выполнить ping gitlabnto и посмотреть IP в выводе (например, 192.168.64.246);
    Сохраните файл, проверьте снова командой ping gitlabnto работоспособность связи.

1. Создание ssh-ключа
    * В консоли выполнить 

    ```bash
    ssh-keygen
    ```
    * Внимательно прочитать вывод, нажать enter на каждый вариант. По указанному на первом шаге пути будет лежать ключ.
    * Выполнить

    ```bash
    cat ~/.ssh/id_rsa.pub
    ```
    * Полученный вывод (ваш открытый ключ, от начала и до конца) скопировать в настройки проекта в gitlabnto (справа сверху - settings, в меню слева SSH keys, скопировать ключ в key, указать в title название по шаблону ubuntu_аудитория, например, ubuntu_113 - при наличии такого ключа можно знать, что из 113 аудитории доступ есть), убедиться в корректном добавлении ключа;
    * Есть 3 способа копирования из консоли. Это правой кнопкой мыши, copy - paste. Это комбинация ctrl+shift+c, ctrl+shift+v. И это использования буфера выделения - весь выделенный текст автоматически копируется. Вставка по нажатию колесика мыши.
    * После этого gitlab знает вас как владельца соответствующих ssh-сертификатов. Следующей командой убедитесь, что gitlab может узнать ваш full name
    
    ```bash
    # на вопрос ответьте yes
    ssh -T git@gitlabnto -p 2222
    ```
    Если в консоли получен верный full name, то всё с ssh сделано правильно.
1. Создание репозитория
    * Открыть терминал на рабочем столе. Вывод **pwd** должен писать /home/user/Desktop. 
    * Если pwd даёт /home/user, то выполните

    ```bash
    cd Desktop
    ```
    * Возвращаемся в файл git.txt, полученный ранее. Если файл не сохраняли, то пользуемся командами ниже. Выполняем несколько команд (использовать **свои данные**, а не указанные ниже). Обратите внимание, что для **git clone** нужно дописать ssh:// в начало и порт 2222 в середину по аналогии с примером ниже

    ```bash
    # настройки локального git - ваше имя пользователя и почта, а также редактор по умолчанию. Используйте логин (name) из gitlabnto вместо "ваш_логин". 
    git config --global user.name "ваш_логин"
    git config --global user.email "ваш_логин@1.ru"
    git config --global core.editor nano
    
    git clone ssh://git@gitlabnto:2222/ваш_логин/timp.git
    ```
    * Будет выдан запрос, доверяете ли вы неизвестному хосту (The authenticity of host '[gitlabnto]:2222' can't be established.) - противодействие атаке "третий посередине" или man in the middle. Введите yes.
    * На рабочем столе появился каталог timp с содержимым вашего репозитория; Выполните
    
    ```bash
    cd timp
    cat readme.md
    ```
    * Убедитесь, что на экране ваш репозиторий.

1. Запустить CLion ярлыком слева (большие буквы CL) - платного средства разработки от JetBrains.

1. Создание проекта в CLion
    * New project, указываем путь к нашему репозиторию /home/user/Desktop/timp
    * ... is not empty:
        * При выборе no Clion за вас создат проект hello world (этот вариант, если у вас почти пустой репозиторий с readme). Рассмотрим этот вариант несколько позже.
        * При выборе yes каталог откроется "как есть" (этот вариант, если вы скачали проект с кодом).
    * выберите yes
    * окно Tip of the day содержит разные полезные горячие клавиши и функции IDE (Integraged Development Environment - интегрированная среда разработки). Можете ознакомиться с содержимым. Уберите галочку show tips on startup, чтобы окно больше не возникало.
    * Открытый проект будет одним проектом по учебной дисциплине. Каждое задание нужно поместить в свой каталог. 
    * В проекте создайте каталог example (правой кнопкой мыши на timp, new->directory). Возникнет сообщение "do you want add the following file to git". На первых порах при работе с git крайне не рекомендуется пользоваться графическим интерфейсом, поэтому поставьте галочку remember, dont ask и нажмите cancel.
    * Теперь нужно скачать из этого репозитория заголовочный файл фреймворка catch2 для тестирования и файлы примеров. Возпользуемся утилитой http, установленной в вашу виртуальную машину. В консоли

    ```bash
    # вы должны быть в /home/user/Desktop/timp
    cd example
    http http://gitlabnto/anetto/timp/raw/master/example/example.cpp > example.cpp
    http http://gitlabnto/anetto/timp/raw/master/example/example.h > example.h
    http http://gitlabnto/anetto/timp/raw/master/example/example_test.cpp > example_test.cpp
    # это конфигурационный файл для проекта в git - убирает некоторые временные файлы из зрения git
    http http://gitlabnto/anetto/timp/raw/master/example/.gitignore > ../.gitignore
    # это фреймворк для тестирования
    http http://gitlabnto/anetto/timp/raw/master/catch.hpp > ../catch.hpp
    ```
    * Создать в корне проекта файл CMakeLists.txt (в CLione правой кнопкой мыши на timp, new file, в git не добавляем) с содержимым:

    ```
    cmake_minimum_required(VERSION 3.13)
    project(test_empty)
    
    set(CMAKE_CXX_STANDARD 14)
    
    add_executable(example_test example/example_test.cpp example/example.cpp example/example.h)
    ```
    * Правой кнопкой мыши на CMakeLists.txt, Load CMake Project. Обратите внимание на созданный в проекте каталог cmake-build-debug.
    * В CLion откройте файл example_test.cpp и выполните run - edit configurations. Слева вверху нажмите плюс, выберите catch.
        * name - example (потом будет task1, task2, ...)
        * target - example (то, что указано в add_executable в CMakeLists.txt)
        * ok, запустите run - run. Отработавшие тесты выдадут 0 в окно run и tests passed: 1 в окно event log (справа-снизу).
    * Добавьте в example_test ещё один TEST_CASE с тестом, содержащим ошибку. Выполните новый код, посмотрите на вывод run и event log для случая, когда часть тестов прошла, а часть некорректна.
    * создайте в example новый файл main.cpp (как C++ source file). Уберите галочку add to targets.
    * содержимое файла main.cpp - выведите hello world и результат вашей функции сложения для некоторой пары чисел.
    * в CMakeLists добавьте строку

    ```
    add_executable(example_main example/main.cpp example/example.cpp example/example.h)
    ```
    * Перезагрузите CMake файл. 
    * **Создайте новую конфигурацию (Run -> Edit Configurations, слева сверху плюсик)** для application (где ранее выбирали Catch, теперь выберите Application) - example_main. Запустите example_main, убедитесь в наличии вывода вашего файла main.cpp. 
    
    Теперь вы умеете запускать произвольный код (как main.cpp) и тесты (как example\_test.cpp) для некоторой созданной вами библиотеки (example.cpp). Различные особенности catch2 доступны [в документации](http://gitlabnto/anetto/catch2/blob/master/README.md).
1. Работа в git
    * В консоли выполните

    ```bash
    # вы должны быть в каталоге /home/user/Desktop/timp
    git status
    ```    
    * Красным отмечены неотслеживаемые файлы - git за ними не следит. Файлы, указанные в .gitignore не отображаются - их git игнорирует.
    * Через CLion измените файл readme.md, добавьте в конец строку "новые изменения"
    * В консоли наберите 
    
    ```bash
    git add readme.md
    git commit -m 'правки'
    git push origin master
    ```
    * Если забудете указать параметр -m в команде commit то будет вызван редактор по умолчанию для описания коммита, необходимо вписать текст и сохранить.
    * Проверьте через веб-интерфейс, что правки теперь есть и на сервере;
    * Используя git add и git commit, добавьте каталог example со всем его содержимым в git-репозиторий (git add example/*), после чего с помощью git push загрузите результаты на gitlab.
    
1. Выполнение заданий

Вы должны четко понимать где находится актуальная (последняя) копия вашего проекта:

* на сервере gitlabnto
* на виртуальной машине
* на носителе (если взяли код через администраторов доделать дома)

Идеальное состояние когда в промежутках между занятиями актуальная копия вашего проекта находится на сервере. Это позволяет вам начать следующее занятие с той же точки в любой аудитории на любом компьютере, либо подойти к преподавателю и показать исходный код.

Для достижения такого состояния необходимо каждое занятие начинать с команды **git pull** (забрать проект) и заканчивать командой **git push** (отдать проект). Если вы работаете на новой виртуальной машине, то вместо команды pull будет clone.

Необходимо добиваться успешного выполнения указанных команд и реагировать на все выводимые ошибки.

Если новое занятие начинается в новом классе, на новом компьютере, или из под учетной записи другого пользователя необходимо заново настроить виртуальную машину:
* поменять настройки процессоров и памяти виртуальной машины
* сгенерировать ssh ключ и прописать его в настройках http://gitlabnto
* сконфигурировать git командами **git config**
* забрать проект с сервера командой **git clone**

Подробный синтаксис команд см. выше.