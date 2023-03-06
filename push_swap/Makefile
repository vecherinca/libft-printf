NAME = push_swap
NAME_CHECKER = checker
CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =  \
	 ./checkthestack.c    \
	./indexes.c    \
	./itoa.c    \
	./list_operations.c    \
	./main.c    \
	./median.c    \
	./movefastest.c    \
	./numberofmoves.c    \
	./pa_pb.c    \
	./push_swap.c    \
	./ra_rb_rr.c    \
	./random3.c    \
	./random5.c    \
	./random100.c       \
	./rra_rrb_rr.c        \
	./sa_sb_ss.c    \
	./utils.c    \

BONUS = \
	check/checker.c \
	check/define_lists.c \
	check/list_operations_bonus.c \
	check/pa_pb_bonus.c \
	check/ra_rb_rr_bonus.c \
	check/rra_rrb_rr_bonus.c \
	check/sa_sb_ss_bonus.c \
	check/utils_bonus.c \
	check/utils2.c \
	check/gnl/get_next_line.c \
	check/gnl/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ}

.o: .c
	${CC} -c ${CFLAGS} $< -o $@

bonus: ${BONUS_OBJ}
	${CC} ${CFLAGS} -o $(NAME_CHECKER) $(BONUS_OBJ)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)
	
fclean: clean
	rm -f $(NAME) $(NAMR)

re: fclean all

.PHONY: all clean fclean re all bonus