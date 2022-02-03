NAME = push_swap
BONUS_NAME = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC =		main.c base_act.c search_val.c few_args.c \
			pre_sort.c arg_check.c init_stack.c many_args_btoa.c \
			recorder.c many_args_atob.c vals.c many_args_btoa2.c optimize.c \
			shutdown.c
SRC_BONUS =	checker.c base_act.c init_stack.c recorder.c arg_check.c vals.c \
			optimize.c double_act.c shutdown.c
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
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus
