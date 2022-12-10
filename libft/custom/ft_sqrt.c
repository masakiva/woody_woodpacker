/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:36:12 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/22 18:13:28 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
    int	start;
	int	end;
    int	mid;
	int	mid_sq;
    int	sqrt;

	if (nb < 0)
		return (-1);
	start = 0;
	if (nb <= 46340)
		end = nb;
	else
		end = 46340;
    while (start <= end)
	{
        mid = (start + end) / 2;
		mid_sq = mid * mid;
        if (mid_sq == nb)
		{
			sqrt = mid;
			break ;
		}
        if (mid_sq < nb)
		{
            start = mid + 1;
            sqrt = mid;
        }
        else
            end = mid - 1;
    }
	return (sqrt);
}
