/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:35:45 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/13 00:10:52 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_divide(int n, int fd)
{
	if (n < 10 && n > -10)
	{
		if (n < 0)
			ft_putchar_fd(-1 * n + '0', fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_divide(n / 10, fd);
		ft_divide(n % 10, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_divide(n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_divide(n, fd);
	}
}
