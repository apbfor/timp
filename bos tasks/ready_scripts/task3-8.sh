#!/bin/bash
#2017-3-limasov
#8. Для двух заданных файлов вычислять их суммарный объем и, в случае если он не равен, нулю ‑ выводить результат на экран.


file1=$1;
file2=$2;
#du returns size of file in Kb
file1size=$(du $file1 | cut --fields=1)

file2size=$(du $file2 | cut --fields=1)

if(($((file1size+file2size))!=0)) 
then echo "file 1 size + file 2 size =" $(($file1size+$file2size)) "kB"
fi
