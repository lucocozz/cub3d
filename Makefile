NAME=	Cub3d

FILE=	ft_parsing.c		ft_parsing2.c			ft_cub_utils.c		\
		ft_events.c			ft_keys.c				ft_init_engine.c	\
		ft_raycasting.c		ft_engine.c				ft_bmp.c			\
		ft_keys2.c			ft_textures.c			ft_parsing3.c		\
		ft_exit_cub.c
		
SPRITE=	ft_sprites.c		ft_sprite_lst.c

MAIN=	main.c

SRCS=	$(addprefix sources/, $(FILE)) $(addprefix sources/sprites/, $(SPRITE))

OBJS_S=	$(SRCS:%.c=%.o)

CC=clang

CFLAGS= -Wall -Wextra -Werror -I includes/ -I lib42/includes/			\
-I /usr/local/include -L lib42/ -L /usr/local/lib -lmlx -l42 -lXext -lX11	\
-lm -lbsd -g#-g3 -fsanitize=address

all: $(NAME)

lib:
	$(MAKE) -C lib42

$(NAME): lib
	$(CC) $(MAIN) $(SRCS) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJS_S)
	$(MAKE) clean -C lib42

fclean: clean
	rm -f $(NAME)
	cd lib42 && rm -f lib42.a && cd ../

re: fclean all
