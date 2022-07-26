/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:26:16 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 21:51:11 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern Created!" << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << RED << "Intern Deleted!" << RESET << std::endl;
}

Intern::Intern(const Intern& in)
{
	(void)in;
	std::cout << GREEN << "Copy Intern Created!" << RESET << std::endl;
}

Intern&	Intern::operator=(const Intern& in)
{
	(void)in;
	if (this != &in)
		std::cout << GREEN << "Copy Assigned Intern Created!" << RESET << std::endl;
	return (*this);
}

Form	*Intern::makeForm(const std::string& name, const std::string& type)
{
	std::string	type_list[3] = {S_TYPE, R_TYPE, P_TYPE};
	try
	{
		for (int i = 0; i < 3; ++i)
		{
			if (type_list[i] == type)
			{
				std::cout << "Intern creates " << type << std::endl;
				switch (i)
				{
				case 0:
					return (new ShrubberyCreationForm(name));
					break ;
				case 1:
					return (new RobotomyRequestForm(name));
					break ;
				case 2:
					return (new PresidentialPardonForm(name));
					break ;
				}
			}
		}
		throw(NoMatchTypeException());
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}
