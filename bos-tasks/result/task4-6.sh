#!/bin/bash
#2017-3-11-limasov
#6. В заданном каталоге произвести сортировку файлов по размеру: файлы с размером меньше 1кБ переместить в директорию sort.1, файлы с размером больше 1кБ и меньше 1MБ переместить в директорию sort.1000, остальные файлы переместить в директорию sort.mega.

if [[ $# == 0 ]]
then
	path="./"
else
	path=$1
fi

mkdir "sort.1"
mkdir "sort.1000"
mkdir "sort.mega"

for file in `ls ${path}`
do
	if [[ !(-f "$file") ]]
	then 
		echo "$file is not a file!"
		continue
	fi
	
	echo "Processing $file file"
	size=$(du $file | cut --fields=1)
	echo "File size is $size"
	if [[ size > 1 || size < 1024 ]]
	then
		mv -v $file ${path}/"sort.1000"
	elif [[ size < 1 ]] 
	then
		mv -v $file ${path}/"sort.1"
	else
		mv -v $file ${path}/"sort.mega"
	fi 
		
done
