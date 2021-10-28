GRN = \033[1;32m
YEL = \033[0;33m
RED = \033[1;31m
WHITE = \033[0m

NAME = fractol
FLAGS = -Wall -Wextra -Werror
CC = gcc

OBJ_DIR 	= obj_dir
LIBFT		= libft/libft.a

BONNUS 		= 0

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX = -L ./mlx_linux -l mlx -l Xext -l X11 -lm -lz
	RESOLUTION = resol_linux.c
endif
ifeq ($(UNAME_S), Darwin)
	MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
	RESOLUTION = resol_mac.c
endif


ifeq ($(BONNUS),0)
	C_MAIN = fractol_main.c
else
	C_MAIN = 
endif

C_BONUS			=	
					
C_COMMON		=	calculate_mandelbrot.c \
					draw_image.c \
					get_resol_and_init_mlx.c \
					zoom.c \
					move_plane.c \
					my_pixel_put.c \
					fractol_utils.c \
					get_color.c \
					keys.c

O_MAIN		= $(patsubst %, $(OBJ_DIR)/%, $(C_MAIN:.c=.o))
O_COMMON 	= $(patsubst %, $(OBJ_DIR)/%, $(C_COMMON:.c=.o))
O_BONUS		= $(patsubst %, $(OBJ_DIR)/%, $(C_BONUS:.c=.o))


ifeq ($(BONNUS),0)
	OBJ_FILES = $(O_MAIN) $(O_COMMON)
else
	OBJ_FILES = $(O_MAIN) $(O_COMMON) $(O_BONUS)
endif


all:	makedir $(NAME)
		@echo "$(GRN)\n--- MAKEFILE DONE ------------ \n$(WHITE)"
		
makedir:
		@echo "$(GRN)\n --- START MAKEFILE ------------ \n$(WHITE)"
		@echo "$(GRN) Making obj_dir Directory $(WHITE)"
		mkdir -p $(OBJ_DIR)
#		mkdir -p $(OBJ_DIR)/main $(OBJ_DIR)/main_utils  $(OBJ_DIR)/check_map_file
#		mkdir -p $(OBJ_DIR)/get_hits  $(OBJ_DIR)/get_new_position $(OBJ_DIR)/get_next_line 
#		mkdir -p $(OBJ_DIR)/read_map_data $(OBJ_DIR)/read_texture $(OBJ_DIR)/bonus

		@echo "$(GRN)\n Making libft.a$(WHITE)"
		make -C ./libft


$(OBJ_DIR)/%.o: 	%.c
#		@echo "$(YEL) --- making %.o file --- $(WHITE)"
		gcc -g $(FLAGS) -I./mlx_linux -c $< -o $@


$(NAME): $(OBJ_FILES)
		@echo "$(GRN)\n - Making cub3D Executable --- $(WHITE)"
		gcc $^ $(FLAGS) $(MLX) $(LIBFT) -o $(NAME)

bonus:
		@echo "$(GRN)\n--- Start Makefile Cub3D, (Bonus == $(BONNUS), System == $(UNAME_S)) --- $(WHITE)"
		@$(MAKE) $(MAKEDIR) BONNUS=1


re:		fclean all


clean:
		rm -rf $(OBJ_DIR)
#		cd libft && make fclean
		

fclean:	clean
		cd libft && make fclean
		rm -f cub3D

.PHONY: fclean bonus clean re all mlx clean_mlx
