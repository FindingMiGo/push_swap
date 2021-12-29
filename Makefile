NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC =	main.c base_act.c double_act.c comp_act.c few_args_act.c \
		pre_sort.c arg_check.c init_node.c many_args_act.c debug.c
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

test : $(NAME)
	./$(NAME) 6 4 5 3 2 0 1 10 9 100 99

test7 : $(NAME)
	seq -100 100 | shuf | head -n 7 | xargs echo > args.txt
	cat args.txt | xargs ./$(NAME) > result.txt

test100 : $(NAME)
	./debug.sh > args.txt
	@cat args.txt | xargs ./$(NAME) > result.txt
	@cat args.txt
	@cat result.txt | wc -l

chck :
	curl https://projects.intra.42.fr/uploads/document/document/6391/checker_linux -o chck

.PHONY: all clean fclean re bonus
