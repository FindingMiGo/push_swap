/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:58:38 by tisoya            #+#    #+#             */
/*   Updated: 2021/10/21 03:58:38 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (len == 0 || dst == src)
		return (dst);
	if (dst > src)
	{
		d = (unsigned char *)dst + len - 1;
		s = (unsigned char *)src + len - 1;
		while (len--)
			*d-- = *s--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
