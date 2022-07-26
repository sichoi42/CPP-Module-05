/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:35:55 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 20:40:01 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_HPP
# define RANDOM_HPP

class Random
{
	private:
		static int	seed;
		Random();
		~Random();

	public:
		static double	randv(void);
		static double	randr(double min, double max);
};

#endif
