/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubazan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:11:45 by sdubazan          #+#    #+#             */
/*   Updated: 2020/06/23 15:13:19 by sdubazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		tab++;
	}
}
