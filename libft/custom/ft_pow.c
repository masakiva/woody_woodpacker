/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:18 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/22 15:17:45 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double nb, int power)
{
	if (power > 0)
		return (nb * ft_pow(nb, power - 1));
	else if (power == 0)
		return (1);
	else
		return (0);
}
