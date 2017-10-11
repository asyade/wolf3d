/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:42:46 by acorbeau          #+#    #+#             */
/*   Updated: 2017/07/05 02:42:49 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strprefix(const char *str, const char *prefix)
{
	while (*prefix != '\0' && *str != '\0' && *str == *prefix)
	{
		prefix++;
		str++;
	}
	return (*prefix == '\0');
}
