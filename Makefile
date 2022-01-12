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

ARG7 := `seq -100 100 | shuf | head -n 7 | xargs echo`
ARG20 := `seq -100 100 | shuf | head -n 20 | xargs echo`
ARG100 := `seq -100 100 | shuf | head -n 100 | xargs echo`
ARG150 := `seq -100 100 | shuf | head -n 150 | xargs echo`

test7 : $(NAME)
	@echo $(ARG7) > args.txt
	@cat args.txt > result.txt
	@cat args.txt | xargs ./$(NAME) > result.txt
	@cat args.txt > cmp.txt
	@cat result.txt >> cmp.txt

test20 : $(NAME)
	@echo $(ARG20) > args.txt
	@cat args.txt > result.txt
	@cat args.txt | xargs ./$(NAME) > result.txt
	@cat args.txt > cmp.txt
	@cat result.txt >> cmp.txt

test100 : $(NAME)
	@echo $(ARG100) > args.txt
	@cat args.txt > result.txt
	@cat args.txt | xargs ./$(NAME) > result.txt
	@cat args.txt > cmp.txt
	@cat result.txt >> cmp.txt
	@cat result.txt | wc -l

test150 : $(NAME)
	@echo $(ARG150) > args.txt
	@cat args.txt > result.txt
	@cat args.txt | xargs ./$(NAME) > result.txt
	@cat args.txt > cmp.txt
	@cat result.txt >> cmp.txt

test : $(NAME)
	@echo "-4 50 13 -99 86 -26 52 79 19 -42 75 97 -38" > args.txt
	@cat args.txt > result.txt
	@cat args.txt | xargs ./$(NAME) > result.txt
	@cat args.txt > cmp.txt
	@cat result.txt >> cmp.txt


chck :
	curl https://projects.intra.42.fr/uploads/document/document/6391/checker_linux -o chck

.PHONY: all clean fclean re bonus
