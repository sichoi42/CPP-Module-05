/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:53 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 21:15:45 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test1(void)
{
	ShrubberyCreationForm scf("scf");
	Bureaucrat b1("bureau1", 100);
	Bureaucrat b2("bureau2", 138);
	Bureaucrat b3("bureau3", 146);

	b1.signForm(scf);
	b1.executeForm(scf);
	b2.signForm(scf);
	b2.executeForm(scf);
	b3.signForm(scf);
	b3.executeForm(scf);
}

void	test2(void)
{
	RobotomyRequestForm rrf("rrf");
	Bureaucrat b1("bureau1", 42);
	Bureaucrat b2("bureau2", 46);

	b1.signForm(rrf);
	b1.executeForm(rrf);
	b2.signForm(rrf);
	b2.executeForm(rrf);

	for (int i = 0; i < 50; ++i)
	{
		Bureaucrat b3("bureau3", 73);
		b3.signForm(rrf);
		b3.executeForm(rrf);
	}
}

void	test3(void)
{
	PresidentialPardonForm ppf("ppf");
	Bureaucrat b1("bureau1", 1);
	Bureaucrat b2("bureau2", 6);
	Bureaucrat b3("bureau3", 26);


	b1.signForm(ppf);
	b1.executeForm(ppf);
	b2.signForm(ppf);
	b2.executeForm(ppf);
	b3.signForm(ppf);
	b3.executeForm(ppf);
}

int	main(void)
{
	test1();
	// test2();
	// test3();
	return (0);
}
