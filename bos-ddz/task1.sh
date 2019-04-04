#!/bin/bash
path_result=$1
path_input=$2
fullname=$3
numberOnList=11
numberOfGroup=3

cd $path_input

for((i=2;i<=5;i++))
do

count=$(wc -l < $i.txt)
indNum=$(((($numberOnList+($i*$numberOfGroup))%$count)+1))

touch $path_result/task$i-$indNum.sh
echo "#!/bin/bash">$path_result/task$i-$indNum.sh
echo "#$fullname">>$path_result/task$i-$indNum.sh

task=$(cat $i.txt | sed -n $indNum,${indNum}p)
echo "#$task" >> $path_result/task$i-$indNum.sh

chmod +x $path_result/task$i-$indNum.sh

#echo $indNum
done

#echo $fullname
