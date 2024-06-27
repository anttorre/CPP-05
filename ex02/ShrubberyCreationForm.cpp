/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:48:31 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/27 12:39:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		std::ofstream out(this->target + "_shrubbery");
		out << "               ,@@@@@@@," << std::endl;
    	out << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    	out << "       ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
   		out << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    	out << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    	out << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    	out << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    	out << "       |o|        | |         | |" << std::endl;
    	out << "       |.|        | |         | |" << std::endl;
    	out << "   .\\. \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    	out.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
