NAME	= fractol

CC		= gcc
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
CFLAGS	= -Wall -Werror -Wextra -O2
SRC_PATH = src/
OBJ_PATH = obj/
HEAD	= includes/fractol.h


COMMANDS_DIR	=	$(SRC_PATH)events.c \
					$(SRC_PATH)init.c \
					$(SRC_PATH)main.c \
					$(SRC_PATH)math_utils.c \
					$(SRC_PATH)render.c \
					$(SRC_PATH)string_utils.c

SRCS	=	$(COMMANDS_DIR)

OBJ		= $(patsubst $(SRC_PATH)%.c=.o,$(OBJ_PATH)%.o,$(SRCS))

all: $(NAME)


$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJ) Makefile $(HEAD)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEAD)
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

