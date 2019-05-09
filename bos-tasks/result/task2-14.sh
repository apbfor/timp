#!/bin/bash
#2017-3-11-limasov
#14. Найти в файловой системе файл string.h и определить его владельца.
#path=$(locate "string.h" | head -2 | tail -1) #выводить все файлы и писать всех владельцев
#echo path is $path
#owner=$(ls -l $path | cut --fields=3 --delimiter=' ')
#echo owner is $owner

countOfLines=`find / -name "string.h" 2>/dev/null | wc -l`
for (( i=1; i<=countOfLines; i++ ))
do
	file=`find / -name "string.h" 2>/dev/null | sed -n $i,${i}p`
	info=`ls -l $file`
	#echo "info: $info"
	owner=`echo "$info" | cut --fields=3 --delimiter=' '`
	echo -n "$file"
	echo " owner is $owner"
done 


