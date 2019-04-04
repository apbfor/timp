#!/bin/bash
#2017-3-11-limasov
#6. Подсчитать количество слов в текстовом файле, содержащих букву 'q'.
if [[ $# == 0 ]] 
then 
	echo "path to file and his name as arg in terminal"
	exit 1
fi
file=$1
cat "$file" | grep -o '[^[:space:]]*q[^[:space:]]*' | wc -l
exit 0
