NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC =	main.c base_act.c double_act.c comp_act.c few_args_act.c \
		pre_sort.c arg_check.c init_node.c many_args_act.c debug.c \
		recorder.c
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
	rm checker_linux

test : $(NAME) checker_linux
	bash ./debug.sh

checker_linux :
	curl https://projects.intra.42.fr/uploads/document/document/6391/checker_linux -o checker_linux
	@chmod +x checker_linux

.PHONY: all clean fclean re bonus checker
