/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:04:55 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/20 18:21:40 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*buff_dest;
	char	*buff_src;

	i = 0;
	if (!src && !dest)
		return (dest);
	buff_dest = (char *)dest;
	buff_src = (char *)src;
	while (i < n)
	{
		*buff_dest = *buff_src;
		buff_dest++;
		buff_src++;
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t oldlen, size_t newlen)
{
	void	*newptr;

	if (!ptr)
		return (NULL);
	else if (oldlen >= newlen)
		return (ptr);
	else
	{
		newptr = malloc((newlen + 1) * sizeof(char));
		if (!newptr)
			return (NULL);
		ft_memcpy(newptr, ptr, oldlen);
		free(ptr);
	}
	return (newptr);
}
