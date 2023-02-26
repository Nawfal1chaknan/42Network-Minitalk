NAME = server client

BONUS = server_bonus client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f
printf = ./ft_printf/libftprintf.a
FILES = server.c client.c
BFILES = server_bonus.c client_bonus.c
UFILE = utils.c
BUFILES = utils_bonus.c

OBJS =	$(FILES:.c=.o)
BOBJS =	$(BFILES:.c=.o)
UOBJ =	$(UFILE:.c=.o)
BUOBJ =	$(BUFILES:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(printf):
	make -C ft_printf

$(NAME) : $(OBJS) $(UOBJ) $(printf)
		$(CC) $(CFLAGS) $(UOBJ) $(printf) server.o -o server
		$(CC) $(CFLAGS) $(UOBJ) $(printf) client.o -o client


$(BONUS) : $(BOBJS) $(BUOBJ) $(printf)
		$(CC) $(CFLAGS) $(BUOBJ) $(printf) server_bonus.o -o server_bonus
		$(CC) $(CFLAGS) $(BUOBJ) $(printf) client_bonus.o -o client_bonus

clean :
		$(RM) *.o ./ft_printf/*.o

fclean : clean
		$(RM) $(NAME) $(BONUS)  ./ft_printf/libftprintf.a

re : fclean all

bonus : $(BONUS)