/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:48:37 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 20:51:03 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# define P_SIGN 25
# define P_EXEC 5

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	_target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const std::string& target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& ppf);

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ppf);
		const std::string&		getTarget(void) const;
		virtual void			execute(const Bureaucrat& b) const;
};

#endif
