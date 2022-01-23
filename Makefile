NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC =	main.c base_act.c search_val.c few_args.c \
		pre_sort.c arg_check.c init_node.c many_args_btoa.c \
		recorder.c many_args_atob.c free_and_exit.c many_args_btoa2.c optimize.c
SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make bonus -C ./libft

all : $(NAME)

.c.o :
	$(CC) $(FLAGS) -c $< -o $(<:%.c=%.o)

clean :
	make clean -C ./libft
	rm -rf $(OBJS)

fclean :
	make fclean -C ./libft
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY: all clean fclean re .c.o bonus
