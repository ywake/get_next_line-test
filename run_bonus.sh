gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 main_bonus.c ../get_next_line/get_next_line_bonus.c ../get_next_line/get_next_line_utils_bonus.c
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c
./a.out $2 $3 &
sleep 1
leaks $! | grep -E "leaks? for"
kill $!