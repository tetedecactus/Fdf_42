/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:07:59 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/22 08:55:01 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_int(char *str)
{
	int	nb_bytes;

	nb_bytes = write(1, &*str, ft_strlen(str));
	return (nb_bytes);
}
