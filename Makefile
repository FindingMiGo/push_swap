NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC = main.c base_act.c double_act.c composite_act.c small_arg_act.c pre_sort.c arg_check.c init_node.c debug.c
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

mtest : $(NAME)
	valgrind ./$(NAME) 1 1

rand : $(NAME)
	@bash debug.sh
	cat args.txt | xargs valgrind ./$(NAME)
