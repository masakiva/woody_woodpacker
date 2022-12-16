/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:28:23 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/16 23:10:30 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static ssize_t	recursive(char **line, size_t index, int fd)
{
	char	buf;
	ssize_t	ret;

	ret = read(fd, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		ret = recursive(line, index + 1, fd);
		if (ret != ERROR)
			(*line)[index] = buf;
	}
	else if (ret == 1 && buf == '\n')
	{
		*line = (char *)malloc(sizeof(char) * (index + 2));
		if (*line != NULL)
		{
			(*line)[index] = buf;
			(*line)[index + 1] = '\0';
		}
		else
			ret = ERROR;
	}
	else if (ret != ERROR)
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (*line != NULL)
			(*line)[index] = '\0';
		else
			ret = ERROR;
	}
	return (ret);
}

ssize_t		get_next_line(int fd, char **line)
{
	return (recursive(line, 0, fd));
}
