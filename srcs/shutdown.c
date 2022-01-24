/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:36:31 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/25 00:36:56 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shutdown(void)
{
	vals_storage(NULL, NULL, NULL, NULL);
	exit(EXIT_FAILURE);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	shutdown();
}
