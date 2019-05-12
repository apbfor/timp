#!/bin/bash
#2017-3-limasov
#1. Создать файл, содержащий строчку с информацией о текущей дате, времени, пользователе.

echo -n $(date) > task2-1.txt
echo -n ' ' >> task2-1.txt
echo -n $(whoami) >> task2-1.txt

