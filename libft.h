#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))
# define FT_LONG_MIN	((long)(~FT_LONG_MAX))

# define FT_UINT_MAX	((unsigned)(~0L))
# define FT_INT_MAX		((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN		((int)(~FT_INT_MAX))

#typedef struct		s_list
#{
#	void			*content;
#	size_t			content_size;
#	struct s_list	*next;
#}					t_list;

int					ft_isalpha(int c);
site_t				ft_strlen(const char *s);

#endif