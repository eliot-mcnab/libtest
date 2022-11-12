/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:15:10 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:24:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Creates a unit test runner.
 *
 * @param threshold (double): required unit test coverage for the test run to
 * 	be considered successful.
 */
t_runner	*ft_runner_create(double threshold)
{
	t_runner	*runner;

	runner = malloc(sizeof(*runner));
	if (!runner)
	{
		return (NULL);
	}
	runner -> counter = ft_counter(threshold);
	return (runner);
}
