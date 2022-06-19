#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define INVALID_ARGS "not a number"
# define ERROR_MEM "Memory allocation error"
# define DUPLICATE_ARG "duplicate arg"
# define OUT_INT "out of integer range"
# define INVALID_CMD "wrong command"

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				idx;
	int				num;
	struct s_list	*next;
	int				flag;
}					t_list;

typedef struct s_stack
{
	t_list	*stk_a;
	t_list	*stk_b;
	ssize_t	size_a;
	ssize_t	size_b;
	int		next;
	ssize_t	mid;
	ssize_t	max;
	ssize_t	min;
	ssize_t	flag;
	ssize_t	pivot;
	int		*arr;
	char	**arr_cmd;
	ssize_t	idx_cmd;
	ssize_t	max_cmd;
	char	**tmp_cmd;
	ssize_t	tmp_flag;
}			t_stack;

/*---------- MAIN_UTILS ----------*/
void	ft_create_sort_arr(t_stack *cnf);
void	ft_full_stack_idx(t_stack *cnf);
void	ft_optimization_cmd(t_stack *cnf);
/*---------- VALIDATE_ARGS ----------*/
int		ft_validate_args(t_stack *cnf, int ac, char *av[]);
/*---------- LIST_UTILS ----------*/
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
/*---------- PUSH_SWAP_UTILS ----------*/
long	ft_atoi(const char *nptr);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
/*---------- PUSH_SWAP_CMDS ----------*/
void	ft_check_arr_cmd(t_stack *cnf, char *name_cmd);
void	ft_swap(t_list **stk, char *name_cmd, t_stack *cnf);
void	ft_push(t_list **stk_1, t_list **stk_2, char *name_cmd, t_stack *cnf);
void	ft_rotate(t_list **stk, char *name_cmd, t_stack *cnf);
void	ft_rev_rotate(t_list **stk, char *cmd, t_stack *cnf);
/*---------- SORT_UTILS ----------*/
void	ft_set_arr(t_list **s, int *arr, ssize_t size);
void	ft_count_rev_rotate(t_stack *cnf, ssize_t count, int *ar, ssize_t size);
void	ft_count_rotate(t_stack *cnf, ssize_t count, int *ar, ssize_t size);
void	ft_check_arr_cmd(t_stack *cnf, char *name_cmd);
/*---------- SMALL_SORT ----------*/
void	ft_small_sort(t_stack *cnf);
/*---------- BIG_SORT ----------*/
void	ft_big_sort(t_stack *cnf);
/*---------- PRINT_MSG ----------*/
void	ft_free(t_stack *cnf);
void	ft_print_error(t_stack *cnf, char *desc, char *name);
void	ft_print_cmd(char *name_cmd);
/*---------- MOVE_MIN_ELEM ----------*/
void	ft_rotate_min_elem(t_stack *cnf);
void	ft_move_min_elem_v1(t_stack *cnf);
void	ft_move_min_elem_v2(t_stack *cnf);
void	ft_work_min_elem(t_stack *cnf);
/*---------- BONUS ----------*/
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_rev_rotate_all(t_list **stk_a, t_list **stk_b, t_stack *cnf);
void	ft_rotate_all(t_list **stk_a, t_list **stk_b, t_stack *cnf);
void	ft_swap_all(t_list **stk_a, t_list **stk_b, t_stack *cnf);

#endif
