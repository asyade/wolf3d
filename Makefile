CC = gcc

NAME = wolf

PATH_SRC = srcs/ srcs/parsing/

DIRS =	obj/ \
		obj/map/ \
		obj/render/ \
		obj/cam/ \
		obj/texture/ \
		obj/vector/ \
		obj/ray/ \

SRC = srcs/map/mapReader.c \
		srcs/map/mapParser.c \
		srcs/map/mapCollid.c \
		srcs/render/render.c \
		srcs/cam/cam.c \
		srcs/cam/cam_utils.c \
		srcs/texture/texture.c \
		srcs/texture/texture_reader.c \
		srcs/texture/texture_loader.c \
		srcs/ray/ray.c \
		srcs/vector/vector2d.c \
		srcs/vector/point2d.c \
		srcs/player/player.c \
		srcs/entities/ent_manager.c \
		srcs/entities/ent_powerup.c \
		srcs/player/player_collid.c \
		srcs/main.c

OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -g3 

LIBS = -L./libft -lft

HEADERS = -I includes/ -I libft/includes -I  -lXext -lX11 -lm -lpthread -lSDL2main -lSDL2
 
DEPTHS = Makefile
 
.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) libft/libft.a -o $(NAME) $(FLAGS) $(HEADERS)
	echo "\033[33mCreating  \033[32m[✔] \033[0m$(NAME)"

obj/%.o : $(PATH_SRC)/%.c $(DEPTHS)
	mkdir -p $(DIRS)
	$(CC) -c $< -o $@  $(FLAGS)
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

.PHONY : clean fclean

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all
