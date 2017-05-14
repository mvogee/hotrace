NAME = hotrace

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
		srcs/create_map.c \
		srcs/hash.c \
		srcs/add_entry_to_map.c \
		srcs/search_map.c \
		srcs/de_libs/gnl.c \
		srcs/de_libs/hr_strchr.c \
		srcs/de_libs/hr_strcpy.c \
		srcs/de_libs/hr_strdel.c \
		srcs/de_libs/hr_strdup.c \
		srcs/de_libs/hr_strjoin.c \
		srcs/de_libs/hr_strlen.c \
		srcs/de_libs/hr_strsub.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
