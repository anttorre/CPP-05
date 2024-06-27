/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:31:33 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/27 17:40:48 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm(other)
{
	if (this != &other)
		*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	bool execute = false;
	try
	{
		srand(time(0));
		int random = rand() % 2;
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		if (random)
    		std::cout << target << " has been robotomized\n";
		else
    		std::cout << "Robotomy failed\n";
		execute = true;
		return execute;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return execute;
	}
}