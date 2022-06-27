SRCS			=	./utils.c \
					./utils_parsing.c \
					./utils_structuring_one.c \
					./utils_structuring_two.c \
					./utils_structuring_three.c \
					./utils_redirectionning_one.c \
					./utils_redirectionning_two.c \
					./structuring.c \
					./executing.c \
					./groshell.c \
					./parsing.c \
					./freeing_parsing.c \

OBJS			= 	$(SRCS:.c=.o)

LIBS			=  -L ./libft -lft

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

all:			$(OBJS)
				gcc $(CFLAGS) -g3 $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				all

.PHONY:			all clean fclean re bonus