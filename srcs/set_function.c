/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:07:38 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/16 12:21:07 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	set_color(int z, int z1)
{
	if (z || z1)
		return ((int)RED);
	else
		return ((int)WHITE);
}
