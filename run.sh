gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 main.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c
./a.out $2 &
sleep 1
leaks $! | grep -E "leaks? for"
kill $!