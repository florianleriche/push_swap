/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:56:30 by fleriche          #+#    #+#             */
/*   Updated: 2023/03/30 10:29:14 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_is_sign_alone(int argc, char **argv)
{
	int	len;
	int	i;

	i = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (!ft_strncmp(argv[i], "-", len) || !ft_strncmp(argv[i], "+", len))
			return (0);
		i++;
	}
	return (1);
}

long	ps_atoi(char *str, int *ok)
{
	int		i;
	int		sign;
	long	total;

	i = 0;
	sign = 1;
	total = 0;
	while (str[i] && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			*ok = 0;
			return (0);
		}
		total = total * 10 + (str[i++] - '0');
	}
	total = total * (long)sign;
	return (total);
}

void	ps_check_duplicate(int argc, int *tab, int *ok)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while ((i < argc - 1) && (*ok))
	{
		while (j < i)
		{
			if (tab[i] == tab[j])
				*ok = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ps_check_sorted(int argc, int *tab)
{
	int	i;

	i = argc - 2;
	while (i > 0)
	{
		if (tab[i] > tab[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	ps_all_checks(int argc, char **argv, int *tab, int i)
{
	int		j;
	int		ok;
	long	buf;

	i = 1;
	j = argc - 2;
	ok = 1;
	while ((i < argc) && ok)
	{
		buf = ps_atoi(argv[i++], &ok);
		if (buf < -2147483648 || buf > 2147483647)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		tab[j--] = (int)buf;
	}
	ps_check_duplicate(argc, tab, &ok);
	if (!ok || ps_check_sorted(argc, tab))
	{
		if (!ok)
			write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
