NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC =	main.c base_act.c double_act.c composite_act.c small_arg_act.c \
		pre_sort.c arg_check.c init_node.c large_arg_act.c debug.c
SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C ./libft

fclean :
	make fclean -C ./libft
	rm -rf $(NAME) $(OBJS)

ARG7 := `seq -100 100 | shuf | head -n 7 | xargs echo`
ARG100 := `seq -100 100 | shuf | head -n 100 | xargs echo`

test7 : $(NAME)
	./$(NAME) $(ARG7)

test100 : $(NAME)
	./$(NAME) $(ARG100)

.PHONY: all clean fclean re bonus
