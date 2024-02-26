/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:14:26 by bdemetz           #+#    #+#             */
/*   Updated: 2023/10/06 17:21:48 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printb.h"

static unsigned int	printf_prct_count(const char *input)
{
	unsigned int	i;
	unsigned int	cpt;

	i = 0;
	cpt = 0;
	while (i + cpt < ft_strlen(input))
	{
		if (input[i + cpt] == '%')
			cpt++;
		i++;
	}
	return (cpt);
}

static int	print_ptr(unsigned long long ptr)
{
	int	cpt;

	cpt = 0;
	if (!ptr)
		return (ft_putstr_fd ("(nil)", 1));
	cpt = check_w(cpt, printb("0x"));
	cpt = check_w(cpt,
			ft_putnbr_base_long_long(ptr, "0123456789abcdef"));
	return (cpt);
}

static int	char_trtm(char c, va_list args)
{
	int	error;

	error = 0;
	if (c == 'c')
		error = ft_putchar_fd((char) va_arg(args, int), 1);
	else if (c == 's')
		error = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		error = print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		error = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		error = ft_putunsigned_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		error = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		error = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'L')
		error = ft_putchar_fd('%', 1);
	else if (c == '%')
		error = ft_putchar_fd('%', 1);
	else
		error = -1;
	return (error);
}

int	printb(const char *in, ...)
{
	va_list			args;
	int				cpt;
	int				i;
	int				write_count;

	if (in == NULL)
		return (-1);
	i = -1;
	write_count = 0;
	cpt = printf_prct_count(in);
	va_start(args, in);
	while ((unsigned)++i < ft_strlen(in))
	{
		if ((cpt > 0 || (in[i + 1] && in[i + 1] == '%')) && in[i] == '%')
		{
			write_count = check_w(write_count, char_trtm(in[++i], args));
			if (write_count == -1)
				return (-1);
			cpt--;
		}
		else if (ft_putchar_fd(in[i], 1) == -1)
			return (-1);
	}
	va_end(args);
	return (ft_strlen(in) + write_count - (printf_prct_count(in) * 2));
}
