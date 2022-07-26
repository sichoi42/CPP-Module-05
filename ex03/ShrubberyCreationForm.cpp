/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:46:23 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/26 21:09:43 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : \
	Form(target, S_SIGN, S_EXEC), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm Created!" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm Deleted!" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf) :\
	Form(scf.getTarget(), S_SIGN, S_EXEC), _target(scf.getTarget())
{
	std::cout << GREEN << "Copy ShrubberyCreationForm Created!" << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf)
{
	if (this != &scf)
	{
		_target = scf.getTarget();
		Form::operator=(scf);
		std::cout << GREEN << "Copy Assigned ShrubberyCreationForm Created!" << RESET << std::endl;
	}
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	executable(b);
	std::ofstream fout(_target + "_shrubbery", std::ofstream::out);
	if (!fout.good())
		FileIOException();
	std::string	tree = "                                              .\n"
"                                   .         ;\n"
"      .              .              ;%     ;;\n"
"        ,           ,                :;%  %;\n"
"         :         ;                   :;%;'     .,\n"
",.        %;     %;            ;        %;'    ,;\n"
"  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
"    ;%;      %;        ;%;        % ;%;  ,%;'\n"
"     `%;.     ;%;     %;'         `;%%;.%;'\n"
"      `:;%.    ;%%. %@;        %; ;@%;%'\n"
"         `:%;.  :;bd%;          %;@%;'\n"
"           `@%:.  :;%.         ;@@%;'\n"
"             `@%.  `;@%.      ;@@%;\n"
"               `@%%. `@%%    ;@@%;\n"
"                 ;@%. :@%%  %@@%;\n"
"                   %@bd%%%bd%%:;\n"
"                     #@%%%%%:;;\n"
"                     %@@%%%::;\n"
"                     %@@@%(o);  . '\n"
"                     %@@@o%;:(.,'\n"
"                 `.. %@@@o%::;\n"
"                    `)@@@o%::;\n"
"                     %@@(o)::;\n"
"                    .%@@@@%::;\n"
"                    ;%@@@@%::;.\n"
"                   ;%@@@@%%:;;;.\n"
"               ...;%@@@@@%%:;;;;,..    Gilo97\n"
"\n"
"------------------------------------------------\n"
"Thank you for visiting https://asciiart.website/\n"
"This ASCII pic can be found at\n"
"https://asciiart.website/index.php?art=plants/trees\n";
	fout << tree;
}
