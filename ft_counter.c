/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:53:13 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 15:55:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Returns a new counter with a custom threshold.
 *
 * @param threshold (size_t): the counter's success threshold.
 *
 * @return (t_counter *): new counter.
 */
t_counter	*ft_counter(size_t threshold)
{
	t_counter	*counter;

	counter = malloc(sizeof(*counter));
	if (!counter)
	{
		return (NULL);
	}
	counter -> passed = 0;
	counter -> failed = 0;
	counter -> threshold = 0;
	return (counter);
}
