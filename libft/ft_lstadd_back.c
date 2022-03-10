#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	if (!lst)
		return ;
	else if (!*lst)
	{
		*lst = new;
		return ;
	}
	prev = ft_lstlast(*lst);
	prev->next = new;
}
