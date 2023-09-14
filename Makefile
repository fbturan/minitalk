NAME = serverclient.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

printf = ./printf/libftprintf.a

CLIENT = client

SERVER = server

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.o
	make -C ./printf
	$(CC) $(CFLAGS) $< $(printf) -o $@
	
$(CLIENT): client.o
	make -C ./printf
	$(CC) $(CFLAGS) $< $(printf) -o $@
	
clean:
	make fclean -C ./printf
	rm server client server.o client.o
	
fclean: clean
	
re: fclean all
	
.PHONY: all clean fclean re

NAME	= push_swap
LIBDIR	= libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRCS	= error.c free.c init.c linked_list.c main.c min_max.c radix.c sort_moves_1.c\
		  sort_moves_2.c sort_moves_3.c tiny_sorts.c
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(SRCS) $(LIBDIR)
	$(CC) $(SRCS) $(LIBDIR) -o $(NAME) $(CFLAGS)

$(LIBDIR):
	@make -C libft/
	@echo "compiled libft.a\n"

clean:
	$(RM) $(OBJS)
	@make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re