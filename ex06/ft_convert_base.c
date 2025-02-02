/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubazan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:14:18 by sdubazan          #+#    #+#             */
/*   Updated: 2020/06/23 15:16:40 by sdubazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t ft_power_s(size_t nb, int power)
{
	if(power == 0)
	{
		return (1);
	}
	if(power < 0)
	{
		return (0);
	}
	return (nb * ft_power_s(nb, power - 1));
}

static size_t ft_getval(char *nbr, char *base_from)
{
	size_t	val;
	int	 i;
	int	 j;
	size_t	len;

	len = ft_strlen(nbr);
	val = 0;
	i = -1;
	while (nbr[++i])
	{
		j = -1;
		while (nbr[i] != base_from[++j]);
		val += j * (len - i ? ft_power_s(10, len - i - 1) : 1);
	}
	return (val);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	size_t	val;
	size_t	len_base;
	int		i;

	val = ft_getval(nbr, base_from);
	len_base = ft_strlen(base_to);
	res = (char*)malloc(sizeof(char) * (32));
	i = 0;
	if (val)
		while (val > 0)
		{
			res[i] = base_to[val % len_base];
			val /= len_base;
			++i;
		}
	else
		res[i++] = base_to[0];
	res[i] = '\0';
	res = ft_strrev(res);
	return (res);
}
