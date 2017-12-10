/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:18:18 by psprawka          #+#    #+#             */
/*   Updated: 2017/11/27 22:18:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	hex_table(int x, char type)
{
	static char	lx_tab[17] = HEX_SMALL;
	static char	ux_tab[17] = HEX_LARGE;

	if (type == 'x' || type == 'p')
		return (lx_tab[x]);
	if (type == 'X')
		return (ux_tab[x]);
	return (0);
}

char	*convert_hex(unsigned long int nb, char type)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_memalloc(21);
	if (nb == 0)
		print[i] = '0';
	while (nb != 0)
	{
		print[i++] = hex_table((nb % 16), type);
		nb /= 16;
	}
	return (ft_strrev(print));
}

char	*convert_binary(unsigned long int nb)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_memalloc(33);
	if (nb == 0)
		print[i] = '0';
	while (nb != 0)
	{
		print[i++] = (nb % 2) + 48;
		nb /= 2;
	}
	return (ft_strrev(print));
}

char	*convert_octal(unsigned long int nb)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_memalloc(20);
	if (nb == 0)
		print[i] = '0';
	while (nb != 0)
	{
		print[i++] = (nb % 8) + 48;
		nb /= 8;
	}
	return (ft_strrev(print));
}

char	*convert_uni(wchar_t wide)
{
	char *new = ft_strnew(5);
	
	if (wide < 0x80)
		new[0] = ((wide >> 0) & 0x7F) | 0x00;
	else if (wide < 0x800)
	{
		new[0] = ((wide >> 6) & 0x1F) | 0xC0;
		new[1] = ((wide >> 0) & 0x3F) | 0x80;
	}
	else if (wide < 0x10000)
	{
		new[2] = ((wide >> 0) & 0x3F) | 0x80;
		new[0] = ((wide >> 12) & 0x0F) | 0xE0;
		new[1] = ((wide >> 6) & 0x3F) | 0x80;
		
	}
	else if (wide < 0x10FFFF)
	{
		new[0] = ((wide >> 18) & 0x07) | 0xF0;
		new[1] = ((wide >> 12) & 0x3F) | 0x80;
		new[2] = ((wide >> 6) & 0x3F) | 0x80;
		new[3] = ((wide >> 0) & 0x3F) | 0x80;
	}
	return (new);
}

char	*convert(t_flags *bag, long long int nb)
{
	if (TYPE == 'b')
		return (convert_binary(nb));
	if (TYPE == 'o' || TYPE == 'O')
		return (convert_octal(nb));
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		return (convert_hex(nb, TYPE));
	if (TYPE == 'u' || TYPE == 'U')
		return (ft_itoa(nb));
	return (NULL);
}
