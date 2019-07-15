/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:04:50 by msorin            #+#    #+#             */
/*   Updated: 2017/12/04 17:05:25 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nblen(int nb)
{
	size_t	ret;
	int		t;

	ret = 1;
	if (nb == 0)
		return (ret);
	if (nb < 0)
		ret++;
	if (!(nb / 10))
		return (ret);
	t = nb;
	while (t / 10)
	{
		t /= 10;
		ret++;
	}
	return (ret);
}
