NAME=	Cub3d

FILE=	ft_parse_cub.c		ft_parse_cub2.c			ft_cub_utils.c		\
		ft_events.c			ft_keys.c

MAIN=	main.c

SRCS=	$(addprefix sources/, $(FILE))

OBJS_S=	$(SRCS:%.c=%.o)

CC=gcc

CFLAGS= -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib -lmlx -framework opengl -framework AppKit -I includes/ -I lib42/includes/ -L lib42/ -l42 -g3 -fsanitize=address

all: $(NAME)

lib:
	cd lib42 && $(MAKE) && cd ../

$(NAME): lib
	$(CC) $(CFLAGS) $(MAIN) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS_S)
	cd lib42 && $(MAKE) clean && cd ../

fclean: clean
	rm -f $(NAME)
	cd lib42 && rm -f lib42.a && cd ../

re: fclean all