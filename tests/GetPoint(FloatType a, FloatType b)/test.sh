FILES=test/*
for f in $FILES
do
	#echo "Processing $f file..."
	filename=$(basename "$f")
	extension="${filename##*.}"
	filename="${filename%.*}"
	./exec_main < $f > tmp
	echo "test $f:"
	cat $f
	echo "ans:"	
	cat tmp
    echo "checker $(cat $f tmp | ./exec_c)"
done
