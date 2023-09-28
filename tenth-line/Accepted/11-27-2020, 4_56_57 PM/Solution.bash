// https://leetcode.com/problems/tenth-line

# Read from the file file.txt and output the tenth line to stdout.

i=0;
while read -r line;
do
    i=`expr $i + 1`;
    if [ $i -eq 10 ]
    then
        echo $line;
    fi
done < 'file.txt'