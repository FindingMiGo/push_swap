NAME = push_swap
BONUS_NAME = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC =	main.c base_act.c search_val.c few_args.c \
		pre_sort.c arg_check.c init_stack.c many_args_btoa.c \
		recorder.c many_args_atob.c free_and_exit.c many_args_btoa2.c optimize.c
SRC_BONUS = checker.c base_act.c init_stack.c recorder.c arg_check.c free_and_exit.c optimize.c
SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCS_BONUS = $(addprefix $(SRCDIR)/, $(SRC_BONUS))
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

ifdef WITH_BONUS
OBJS =		$(OBJS_BONUS)
NAME =		$(BONUS_NAME)
endif

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
	rm -rf $(OBJS_BONUS)

fclean :
	make fclean -C ./libft
	rm -rf $(NAME) $(OBJS)
	rm -rf $(BONUS_NAME) $(OBJS_BONUS)

re : fclean all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re .c.o bonus
