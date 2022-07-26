/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:53 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 17:27:52 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	catchOperatorError(const Bureaucrat& b, void (Bureaucrat::*f)(void))
{
	try
	{
		(*(const_cast<Bureaucrat *>(&b)).*f)();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	catchCreateError(const std::string& name, int grade)
{
	try
	{
		Bureaucrat tmp(name, grade);
		std::cout << tmp << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	Bureaucrat b1("burea1", 1);
	Bureaucrat b2("burea2", 150);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	catchOperatorError(b1, &Bureaucrat::incrementGrade);
	catchOperatorError(b2, &Bureaucrat::decrementGrade);
	catchCreateError("burea3", 0);
	catchCreateError("burea4", 151);
	return (0);
}
