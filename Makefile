NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC = main.c
SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

fclean :
	rm -rf push_swap
