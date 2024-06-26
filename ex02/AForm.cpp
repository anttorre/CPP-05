/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:54:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/26 13:11:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : name("Default AForm"), isSigned(false), gradeRequired(1), gradeToExecute(1)
{
	std::cout << "AForm Default constructor called\n";
}

AForm::AForm(std::string name, int gradeRequired, int gradeToExecute) : name(name), isSigned(false), gradeRequired(gradeRequired), gradeToExecute(gradeToExecute)
{
	try
	{
		if (gradeRequired <= 0)
			throw AForm::GradeTooHighException();
		else if (gradeRequired > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::AForm(AForm &other) : name(other.name), isSigned(other.isSigned), gradeRequired(other.gradeRequired), gradeToExecute(other.gradeToExecute)
{
	try
	{
		if (other.gradeRequired < 1)
			throw AForm::GradeTooHighException();
		else if (other.gradeRequired > 150)
			throw AForm::GradeTooLowException();
		std::cout << "AForm Copy constructor called\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called\n";
}

AForm& AForm::operator=(AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int	AForm::getGradeRequired() const
{
	return this->gradeRequired;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->gradeRequired)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& o, const AForm &f)
{
	std::string sign = "false";
	if (f.getIsSigned() == true)
		sign = "true";
	o << "\n-----------------AForm info-----------------\n";
	o << "AForm name: " << f.getName() << ".\nRequired grade: " << f.getGradeRequired() << ".\nGrade to execute: " << f.getGradeToExecute() << ".\nAForm signed: " << sign;
	return o;
}