#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	cnt;

	cnt = 0;
	while (lst)
	{
		cnt += 1;
		lst = lst->next;
	}
	return (cnt);
}
