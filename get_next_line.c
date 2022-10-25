/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:31:26 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/21 10:13:22 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_line_index(char *str, int count_end)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (count_end)
		return (0);
	return (i);
}

char	*get_stash(char *stash, int fd)
{
	int	i;

	i = 0;
	if (!stash)
		stash = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash || read(fd, stash, 0) < 0)
		return (NULL);
	stash[BUFFER_SIZE] = '\0';
	
}

char	*get_next_line(int fd)
{
	char	*stash[2048];
	char	*str;

	stash[fd] = get_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	if (BUFFER_SIZE < 1 || !stash[fd] || fd < 0)
		return (NULL);
	return (str);
}

int	main(void)
{
	char *str;
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
}
