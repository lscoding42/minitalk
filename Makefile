SERVER	= server
CLIENT	= client
CC		= gcc
FLAGS	= -Wall -Werror -Wextra

SRCS	=	./srcs/atoi.c\
			./srcs/lesputs.c\
			./srcs/lesstrs.c\
			./srcs/server_utils.c\
			./srcs/client_utils.c\

OBJS = ${SRCS:.c=.o}

all : $(OBJS) $(SERVER) $(CLIENT)

$(SERVER) : server.o minitalk.h
	@$(CC) server.o $(SRCS) -o $@

$(CLIENT) : client.o minitalk.h
	@$(CC) client.o $(SRCS) -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(OBJS)

re: fclean all