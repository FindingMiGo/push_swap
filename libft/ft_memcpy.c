/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:58:35 by tisoya            #+#    #+#             */
/*   Updated: 2021/10/21 03:58:35 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (len == 0 || dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
