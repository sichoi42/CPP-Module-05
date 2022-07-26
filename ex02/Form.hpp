/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:28:31 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 19:51:54 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_sign;
		const int			_grade_execute;

		Form(void);

	public:
		Form(const std::string name, const int grade_sign, const int grade_execute);
		virtual ~Form();
		Form(const Form& f);

		Form&				operator=(const Form& f);
		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeSign(void) const;
		int					getExecuteSign(void) const;
		void				beSigned(const Bureaucrat& b);
		void				executable(const Bureaucrat& b) const;
		virtual void		execute(const Bureaucrat& b) const = 0;

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

		class DoesNotSignedException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Error!!! Form does not signed!");
				}
		};

		class FileIOException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Error!!! File Corrupted!");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const Form& b);

#endif
