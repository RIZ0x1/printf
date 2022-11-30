CC    =	gcc
FLAGS =	-Wall -Werror -Wextra -c
NAME  =	libftprintf.a

INC =	./hdrs
SRCS =	ft_handlers_utils.c ft_preproc_1.c ft_preproc_2.c ft_other.c ft_printf.c     \
	ft_handlers_dipux.c ft_handlers_scperc.c ft_list_utils_1.c ft_list_utils_2.c \
	ft_postproc_prec_n_width.c ft_major_funcs.c
OBJS = $(SRCS:%.c=%.o)


.PHONY: all clean fclean re

vpath %.a libft
vpath %.c srcs

all: $(NAME)

libft.a:
	make -C libft
	cp libft/$@ $(NAME)

$(NAME): libft.a $(OBJS)
	ar -rc $(NAME) $(filter %.o, $?)

%.o: %.c
	$(CC) $(FLAGS) -I $(INC) $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

