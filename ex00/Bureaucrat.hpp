/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:05:11 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 18:03:16 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat(void);

	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& b);

		Bureaucrat&			operator=(const Bureaucrat& b);
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Error!!! Grade too High! (1 <= Grade <= 150)");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Error!!! Grade too Low! (1 <= Grade <= 150)");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b);

#endif
