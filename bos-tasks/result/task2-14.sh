#!/bin/bash
#2017-3-11-limasov
#14. Найти в файловой системе файл string.h и определить его владельца.
path=$(locate "string.h" | head -2 | tail -1)
echo path is $path
owner=$(ls -l $path | cut --fields=3 --delimiter=' ')
echo owner is $owner
