#include "../include/cub3d.h"

int		ft_free_mem(t_list **list)
{
	t_list	*temp;

	if (list == NULL)
		return (-1);
	while ((*list)->content && (*list)->next)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->content);
		free(temp);
	}
	if ((*list)->content)
		free((*list)->content);
	free(*list);
	return (1);
}