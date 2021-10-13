/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:05:32 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/12 14:22:45 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* this function take line and delete all separator,
* it return the width of the line minus all the separator 
*/

#include "libft.h"

int width_counter(char *line, char separator)
{
    int i;
    int width;

    width = 0;
    i = 0;
    separator = ' ';
    while (line[i])
    {
        if (line[i] == '-')
            i++;
        if (line[i] != separator)
        {
            width++;
            i++;
        }
        i++;
    }
    return (width);
}