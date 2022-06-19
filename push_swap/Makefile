NAME = push_swap

NAME_BONUS = checker

HEADER = includes/push_swap.h

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

DIR = srcs/

DIR_BONUS = bonus/

SRCS = $(addprefix $(DIR), main.c main_utils.c small_sort.c\
		ft_split.c big_sort.c move_min_elem.c)

SRCS_MAIN = $(addprefix $(DIR), validate_args.c list_utils.c\
			push_swap_utils.c push_swap_cmds.c push_swap_cmd2.c\
			print_msg.c sort_utils.c)

SRCS_BONUS = $(addprefix $(DIR_BONUS), checker.c get_next_line.c\
				get_next_line_utils.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_MAIN = $(patsubst %.c, %.o, $(SRCS_MAIN))

OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(OBJS_MAIN)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(OBJS_MAIN)
	gcc $(FLAG) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_MAIN)

clean :
	rm -f $(OBJS) $(OBJS_MAIN) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus