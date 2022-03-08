NAME			= minirt

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

INCLUDES_DIR	= ./includes/
SOURCES_DIR		= ./sources/
OBJECTS_DIR		= ./objects/

INCLUDES		= $(wildcard $(addsuffix *.h, $(INCLUDES_DIR)))
SOURCES			= $(wildcard $(addsuffix *.c, $(SOURCES_DIR)))
OBJECTS			= $(addprefix $(OBJECTS_DIR), $(notdir $(patsubst %.c, %.o, $(SOURCES))))

VPATH = $(SOURCES_DIR)

$(OBJECTS_DIR)%.o: %.c $(INCLUDES)
					mkdir -p $(OBJECTS_DIR)
					# $(CC) $(CFLAGS) -c $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:				$(NAME)

$(NAME):			$(INCLUDES) $(OBJECTS)
					# $(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
					$(CC) $(CFLAGS)  $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
					$(RM) $(OBJECTS_DIR)

fclean:				clean
					$(RM) $(NAME)

bonus:				all

re:					fclean all
