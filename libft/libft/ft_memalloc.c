/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <acorbeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:45:16 by acorbeau          #+#    #+#             */
/*   Updated: 2017/09/16 22:04:28 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
	{
		ft_putendl_fd("malloc() failure, exit", 2);
		exit(1);
	}
	ft_bzero(ret, size);
	return (ret);
}

void	*ft_salloc(size_t size)
{
	void	*ret;

	if (!(ret = malloc(size)))
	{
		ft_putendl_fd("malloc() failure, exit", 2);
		exit(1);
	}
	return (ret);
}