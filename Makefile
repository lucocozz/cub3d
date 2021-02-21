NAME=	cub3d

detected_OS := $(shell uname)

FILE=	main.c					ft_parsing.c			ft_parsing_map.c		\
		ft_cub_utils.c			ft_events.c				ft_keys.c				\
		ft_init_engine.c		ft_raycasting.c			ft_drawing.c			\
		ft_bmp.c				ft_keys2.c				ft_textures.c			\
		ft_parsing_sprite.c		ft_exit_cub.c			ft_sprites.c			\
		ft_sprite_lst.c			ft_screen.c				

BNS= 	main_bonus.c			ft_parsing_bonus.c		ft_parsing_map_bonus.c	\
		ft_parse_utils_bonus.c	ft_events_bonus.c		ft_keys_bonus.c			\
		ft_init_engine_bonus.c	ft_raycasting_bonus.c	ft_screen_bonus.c		\
		ft_bmp_bonus.c			ft_keys2_bonus.c		ft_textures_bonus.c		\
		ft_exit_cub_bonus.c		ft_sprites_bonus.c		ft_sprite_lst_bonus.c	\
		ft_parsing_two_bonus.c	ft_box.c				ft_pixel_bonus.c

SRCS=	$(addprefix sources/, $(FILE))

BONUS=	$(addprefix sources_bonus/, $(BNS))

OBJS_S=		$(SRCS:%.c=%.o)

OBJS_BNS=	$(BONUS:%.c=%.o)

CC=gcc

INCL=		-I includes/

INCL_BNS=	-I includes_bonus/

ifeq ($(detected_OS),Darwin)        # Mac OS X
    CFLAGS= -Wall -Wextra -Werror -I lib42/includes/ -I ./mlx/    \
-L lib42/ -L ./mlx/ -lmlx -l42 -framework OpenGL -framework AppKit -lm #-g3 -fsanitize=address
endif
ifeq ($(detected_OS),Linux)
    CFLAGS= -Wall -Wextra -Werror -I lib42/includes/ -I ./mlx/    \
-L lib42/ -L ./mlx/ -lmlx -l42 -lXext -lX11 -lm #-g3 -fsanitize=address
endif

all: $(NAME)

lib:
	$(MAKE) -C lib42
	$(MAKE) -C mlx

$(NAME): lib
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS) $(INCL)

bonus: lib
	$(CC) $(BONUS) -o $(NAME) $(CFLAGS) $(INCL_BNS)

clean:
	rm -f $(OBJS_S)
	rm -f $(OBJS_BNS)
	$(MAKE) clean -C lib42
	$(MAKE) clean -C mlx

fclean: clean
	rm -f $(NAME)
	cd lib42 && rm -f lib42.a && cd ../

re: fclean all
