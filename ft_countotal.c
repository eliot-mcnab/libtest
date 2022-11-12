/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countotal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:04:23 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:05:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Calcualtes the total number of tests counted by a counter.
 *
 * @param counter (t_counter *): the counter to get the test count from.
 *
 * @return (size_t): total number of tests counted by [counter].
 */
size_t	ft_countotal(t_counter *counter)
{
	return (counter -> passed + counter -> failed);
}
