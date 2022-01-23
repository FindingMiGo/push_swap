/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:59:04 by tisoya            #+#    #+#             */
/*   Updated: 2021/10/21 03:59:04 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t			i;
	size_t			len;
	unsigned char	*dup;
	unsigned char	*p;

	len = ft_strlen(src);
	p = (unsigned char *)src;
	dup = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (p[i])
	{
		dup[i] = p[i];
		i++;
	}
	dup[i] = '\0';
	return ((char *)dup);
}
