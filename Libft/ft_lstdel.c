/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:56:26 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/16 17:39:55 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst && alst)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		temp = (*alst);
		while ((temp))
		{
			ft_lstdelone(alst, del);
			*alst = temp->next;
			temp = (*alst);
		}
	}
}
