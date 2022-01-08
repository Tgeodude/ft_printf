NAME	=	libftprintf.a

SRCS = ft_printf.c \
	   	ft_printf_utils_1.c \
		ft_printf_utils_2.c \

HEADER	=	ft_printf.h

OBJ	=	$(patsubst %.c, %.o, $(SRCS))
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		ar rcs $(NAME) $?

%.o	:	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@$(RM) $(NAME)

re	:	fclean all
