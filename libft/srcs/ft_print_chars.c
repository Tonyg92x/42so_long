/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:13:22 by aguay             #+#    #+#             */
/*   Updated: 2021/11/03 11:04:02 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_c(va_list s)
{
	char	c;

	c = va_arg(s, int);
	write(1, &c, 1);
}

static void	ft_print_s(va_list s, int *retour)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(s, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*retour += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar_fd(str[i++], 1);
		*retour += 1;
	}
}

//	Fonction utile au printf. Permet d'imprimer soit
//	un charactere, soit une string, soit un %.
int	ft_print_chars(va_list s, int count, char type, int *retour)
{
	if (type == '%')
	{
		ft_putchar_fd('%', 1);
		*retour += 1;
	}
	else if (type == 'c')
	{
		ft_print_c(s);
		*retour += 1;
	}
	else if (type == 's')
		ft_print_s(s, retour);
	count++;
	return (count);
}
