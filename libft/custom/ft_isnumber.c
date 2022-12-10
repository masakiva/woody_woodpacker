/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:55:50 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 17:15:58 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(const char* str)
{
	while (ft_isspace(*str))
		str++;
	if (ft_isdigit(*str) || *str == '-')
		str++;
	else
		return (FALSE);
	while (!ft_isspace(*str) && *str != '\0')
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
