/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:48:36 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/27 18:27:27 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm(other)
{
	if (this != &other)
		*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	bool execute = false;
	try
	{
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
		execute = true;
		return execute;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return execute;
	}
}