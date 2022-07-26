/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:50:37 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 20:54:05 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : \
	Form(target, P_SIGN, P_EXEC), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm Created!" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Deleted!" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) :\
	Form(ppf.getTarget(), P_SIGN, P_EXEC), _target(ppf.getTarget())
{
	std::cout << GREEN << "Copy PresidentialPardonForm Created!" << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf)
{
	if (this != &ppf)
	{
		_target = ppf.getTarget();
		Form::operator=(ppf);
		std::cout << GREEN << "Copy Assigned PresidentialPardonForm Created!" << RESET << std::endl;
	}
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	executable(b);
	std::cout << _target << " has been pardoned by Zaphod Beebleberox." << std::endl;
}
