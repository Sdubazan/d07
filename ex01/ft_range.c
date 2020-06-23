/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubazan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:53:20 by sdubazan          #+#    #+#             */
/*   Updated: 2020/06/23 14:54:43 by sdubazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int *ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
	{
		return (NULL);
	}
	tab = (int*)malloc(sizeof(*tab) * (max - min));
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
