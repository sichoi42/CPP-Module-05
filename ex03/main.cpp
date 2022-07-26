/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:53 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 21:50:43 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	no_named;
	Form	*scf = no_named.makeForm("scf", S_TYPE);
	Form	*rrf = no_named.makeForm("rrf", R_TYPE);
	Form	*ppf = no_named.makeForm("ppf", P_TYPE);
	Form	*wrong = no_named.makeForm("wrong", "wrong");

	(void)wrong;
	Bureaucrat b1("bureau1", 146);
	Bureaucrat b2("bureau2", 73);
	Bureaucrat b3("bureau3", 26);

	b1.signForm(*scf);
	b2.signForm(*rrf);
	b3.signForm(*ppf);

	b1.executeForm(*scf);
	b2.executeForm(*rrf);
	b3.executeForm(*ppf);
	return (0);
}
