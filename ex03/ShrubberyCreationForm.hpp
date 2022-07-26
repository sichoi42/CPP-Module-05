/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:35:25 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 20:49:53 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# define S_SIGN 145
# define S_EXEC 137

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(const std::string& target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& scf);

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& scf);
		const std::string&		getTarget(void) const;
		virtual void			execute(const Bureaucrat& b) const;
};

#endif
