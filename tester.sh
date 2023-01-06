#!/bin/bash

mkdir -p tester/bin/
mkdir -p tester/logs/
mkdir -p tester/out/
mkdir -p tester/diffs/

declare -a containers=(vector stack map set)

for CONT in "${containers[@]}"
do
	echo -e "TESTING $CONT"
	# Compile main files.
	c++ -Werror -Wextra -Werror -std=c++98 -Iincludes src/main_"$CONT".cpp -o tester/bin/"$CONT"_ft -D STL=0 2> tester/logs/"$CONT"_ft.logs
	c++ -Werror -Wextra -Werror -std=c++98 -Iincludes src/main_"$CONT".cpp -o tester/bin/"$CONT"_stl -D STL=1 2> tester/logs/"$CONT"_stl.logs
	if [ $(cat tester/logs/"$CONT"_ft.logs | wc -c ) != "0" ]
		then
			echo -e "\tCOMPILE ERROR"
	else
			# Execute binary files.
			./tester/bin/"$CONT"_ft > tester/out/"$CONT".ft.out
			./tester/bin/"$CONT"_stl > tester/out/"$CONT".stl.out
			# Compute diff on out files.
			diff tester/out/"$CONT".ft.out tester/out/"$CONT".stl.out > tester/diffs/"$CONT".diff
			echo -e "\tDONE."
	fi
done