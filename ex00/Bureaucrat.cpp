/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:15:59 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 17:48:54 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw(GradeTooLowException());
	if (_grade < 1)
		throw(GradeTooHighException());
	std::cout << GREEN << "Bureaucrat Created!" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat Deleted!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name), _grade(b._grade)
{
	if (_grade > 150)
		throw(GradeTooLowException());
	if (_grade < 1)
		throw(GradeTooHighException());
	std::cout << GREEN << "Copy Bureaucrat Created!" << RESET << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		*(const_cast<std::string *>(&_name)) = b._name;
		_grade = b._grade;
		if (_grade > 150)
			throw(GradeTooLowException());
		if (_grade < 1)
			throw(GradeTooHighException());
		std::cout << GREEN << "Copy Assigned Bureaucrat Created!" << RESET << std::endl;
	}
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	--_grade;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	++_grade;
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	return (o << b.getName() << ", bureaucrat grade " << b.getGrade());
}
