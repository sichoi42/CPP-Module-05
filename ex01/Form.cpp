/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:34:23 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/27 19:30:25 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : \
_name(name), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	_is_signed = false;
	if (_grade_sign > 150 || _grade_execute > 150)
		throw(GradeTooLowException());
	if (_grade_sign < 1 || _grade_execute < 1)
		throw(GradeTooHighException());
	std::cout << GREEN << "Form Created!" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << RED << "Form Deleted!" << RESET << std::endl;
}

Form::Form(const Form& f) : \
_name(f._name), _is_signed(f._is_signed), _grade_sign(f._grade_sign), _grade_execute(f._grade_execute)
{
	if (_grade_sign > 150 || _grade_execute > 150)
		throw(GradeTooLowException());
	if (_grade_sign < 1 || _grade_execute < 1)
		throw(GradeTooHighException());
	std::cout << GREEN << "Copy Form Created!" << RESET << std::endl;
}

Form&	Form::operator=(const Form& f)
{
	if (this != &f)
	{
		_is_signed = f._is_signed;
		*(const_cast<std::string *>(&_name)) = f._name;
		*(const_cast<int *>(&_grade_sign)) = f._grade_sign;
		*(const_cast<int *>(&_grade_execute)) = f._grade_execute;
		if (_grade_sign > 150 || _grade_execute > 150)
			throw(GradeTooLowException());
		if (_grade_sign < 1 || _grade_execute < 1)
			throw(GradeTooHighException());
		std::cout << GREEN << "Copy Assigned Form Created!" << RESET << std::endl;
	}
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_is_signed);
}

int	Form::getGradeSign(void) const
{
	return (_grade_sign);
}

int	Form::getExecuteSign(void) const
{
	return (_grade_execute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw(GradeTooLowException());
}

std::ostream&	operator<<(std::ostream& o, const Form& b)
{
	return (o << b.getName() << ", Form Grade Sign " << b.getGradeSign() << " , Form Grade Execute " << b.getExecuteSign());
}
