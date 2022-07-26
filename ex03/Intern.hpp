/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:20:08 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 21:44:44 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# define S_TYPE "ShrubberyCreationForm"
# define R_TYPE "RobotomyRequestForm"
# define P_TYPE "PresidentialPardonForm"

# include "Form.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& in);

		Intern&	operator=(const Intern& in);
		Form	*makeForm(const std::string& name, const std::string& type);

		class NoMatchTypeException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Error!!! No Matching Type!");
				}
		};
};

#endif
