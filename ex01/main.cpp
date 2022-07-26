/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:53 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 18:27:31 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	catchCreateError(const std::string& name, int grade_sign, int execute_sign)
{
	try
	{
		Form tmp(name, grade_sign, execute_sign);
		std::cout << tmp << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	catchCreateError("form1", 1, 150);
	catchCreateError("form2", 0, 150);
	catchCreateError("form3", 1, 151);
	catchCreateError("form4", 0, 151);

	Form f("form", 40, 150);
	std::cout << f << std::endl;
	Bureaucrat b1("bureau1", 50);
	std::cout << b1 << std::endl;
	Bureaucrat b2("bureau2", 30);
	std::cout << b2 << std::endl;
	b1.signForm(f);
	b2.signForm(f);
	return (0);
}
