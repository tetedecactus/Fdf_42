/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:34:56 by olabrecq          #+#    #+#             */
/*   Updated: 2021/06/04 11:54:11 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

int main() 
{
    const char *largestring = "patate";
    const char *smallstring = "patate";
    char *ptr;

    ptr = ft_strnstr(largestring, smallstring, 0);

    printf("%s\n", ptr);
    
    return 0;
}