/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:39:38 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 20:42:52 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Random.hpp"

int Random::seed = 0;

Random::Random()
{

}

Random::~Random()
{

}

double	Random::randv(void)
{
	seed = (seed * 123456789 + 12345) & 0x7fffffff;
	return (static_cast<double>(seed) / static_cast<double>(0x80000000));
}

double	Random::randr(double min, double max)
{
	return (randv() * (max - min) + min);
}
