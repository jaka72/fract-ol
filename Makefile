GRN = \033[1;32m
YEL = \033[0;33m
RED = \033[1;31m
WHITE = \033[0m

NAME = fract-ol
FLAGS = -Wall -Wextra -Werror
CC = gcc

HEADER		= fractol.h
OBJ_DIR 	= obj_dir
LIBFT		= libft/libft.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX = -L ./mlx_linux -l mlx -l Xext -l X11 -lm -lz
	RESOLUTION = resol_linux.c
endif
ifeq ($(UNAME_S), Darwin)
	MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
	RESOLUTION = resol_mac.c
endif

C_FILES			=	fractol_main.c \
					draw_image_mandelbrot.c \
					draw_image_julia.c \
					draw_image_burningship.c \
					render.c \
					get_resol_and_init_mlx.c \
					zoom_keys.c \
					zoom_mouse.c \
					move_plane.c \
					move_plane_julia.c \
					my_pixel_put.c \
					fractol_utils.c \
					get_color.c \
					color_schemes.c \
					keys.c \
					define_keys.c

O_FILES 	= $(patsubst %, $(OBJ_DIR)/%, $(C_FILES:.c=.o))


all:	makedir $(NAME)
		@echo "$(GRN)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(GRN)\n --- START MAKEFILE ------------ \n$(WHITE)"
		@echo "$(GRN) Making obj_dir Directory $(WHITE)"
		mkdir -p $(OBJ_DIR)
		@echo "$(GRN)\n Making libft.a$(WHITE)"
		make -C ./libft


$(OBJ_DIR)/%.o: 	%.c  $(HEADER)
		@echo "$(GRN) --- making %.o file --- $(WHITE)"
		gcc -g $(FLAGS) -c $< -o $@


$(NAME): $(O_FILES)
		@echo "$(GRN)\n - Making Fractol Executable --- $(WHITE)"
		gcc $^ $(FLAGS) $(MLX) $(LIBFT) -o $(NAME)

re:		fclean all

clean:
		rm -rf $(OBJ_DIR)
	
fclean:	clean
		cd libft && make fclean
		rm -f fract-ol

.PHONY: fclean clean re all makedir
