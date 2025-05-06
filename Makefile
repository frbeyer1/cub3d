NAME = cub3d
CC = cc
CFLAGS =  -I $(MLX_DIR) -g
CFLAGS = -Wall -Werror -Wextra
DEBUG = -fsanitize=address -g
MLX_DIR	= minilibx-linux
#LIB_DIR = libft-L $(LIB_DIR)
RM = rm -rf
LIBFT_DIR = libft
LIBFT = libft/libft.a
LIBS	=  -L $(MLX_DIR) -lmlx -lX11 -lXext -lm $(LIBFT)

SRC_DIR	=	./src
OBJ_DIR	=	./obj

FILES	= 	main minilibx_utils \
			initalise raycasting \
			raycasting_utils sprites \
			player_movement movement_utils \
			key_hooks drawing time parser \
			check_if_complete check_if_valid \
			get_map_data parser_utils \
			map_copy file_textures ft_close \
			draw_minimap

SRC		=	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJ		=	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re