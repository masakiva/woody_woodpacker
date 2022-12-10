/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_str_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:48:07 by mvidal-a          #+#    #+#             */
/*   Updated: 2021/01/09 18:45:23 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**push_str_to_array(char **array, char *str)
{
	size_t	array_size;
	char	**new_array;
	size_t	i;

	if (str == NULL)
		return (NULL);
	array_size = ft_arraylen(array);
	new_array = (char **)malloc(sizeof(char *) * (array_size + 2));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = str;
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}
