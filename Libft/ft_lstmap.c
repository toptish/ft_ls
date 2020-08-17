/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:30:16 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/17 15:43:20 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_n_nodes(t_list **begin_list, t_list **ending_element)
{
	t_list *temp;

	while (*begin_list != *ending_element)
	{
		temp = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		free(&temp->content);
		free(&temp->content_size);
		free(temp);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *temp;
	t_list *previous;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(result = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	previous = (result);
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(previous->next = ft_lstnew(temp->content, temp->content_size)))
		{
			ft_free_n_nodes(&result, &previous->next);
			return (NULL);
		}
		previous = previous->next;
		lst = lst->next;
	}
	return (result);
}
