/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countfail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:59:17 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:00:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Notifies a counter that a new test was failed.
 *
 * @param counter (t_counter *): the counter to update.
 */
void	ft_countfail(t_counter *counter)
{
	(counter -> failed)++;
}
