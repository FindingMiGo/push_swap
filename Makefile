NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC = main.c base_action.c double_action.c composite_action.c small_arg_action.c pre_sort.c arg_check.c init_node.c debug.c
SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

fclean :
	rm -rf push_swap
