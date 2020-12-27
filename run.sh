cp ../$1/get_next_line.h .
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$3 main.c ../$1/get_next_line.c ../$1/get_next_line_utils.c
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c
if [ $? -eq 0 ]; then
	./a.out $2 &
	sleep 1
	leaks $! | grep -E "leaks? for"
	kill $!
fi
