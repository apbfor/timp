#!/bin/bash
#2017-3-limasov
#4. В текущем каталоге для каждого пользователя из файла passwd создать файл с именем <имя-пользователя>.path содержащий путь к домашней директории пользователя.

count=$(wc -l < /etc/passwd)
echo "in system are" $count "users"

for ((i=1; i<=count; i++))
do 
nameOfUser= cat/etc/passwd | cut --fields=1 --delimiter=:
touch "$nameOfUser.path"

done

