/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:25:57 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 20:47:36 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Random.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, R_SIGN, R_EXEC), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm Created!" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Deleted!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) :\
	Form(rrf.getTarget(), R_SIGN, R_EXEC), _target(rrf.getTarget())
{
	std::cout << GREEN << "Copy RobotomyRequestForm Created!" << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf)
{
	if (this != &rrf)
	{
		_target = rrf.getTarget();
		Form::operator=(rrf);
		std::cout << GREEN << "Copy Assigned RobotomyRequestForm Created!" << RESET << std::endl;
	}
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	executable(b);
	std::cout << "Do-dododododododoo..!!!" << std::endl;
	if (Random::randr(0, 1) >= 0.5)
		std::cout << "Robotomy Success!!" << std::endl;
	else
		std::cout << "Robotomy Fail... 🥺" << std::endl;
}
