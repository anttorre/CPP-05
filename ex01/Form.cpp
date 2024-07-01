/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:54:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/01 16:00:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : name("Default Form"), isSigned(false), gradeRequired(1), gradeToExecute(1)
{
}

Form::Form(std::string name, int gradeRequired, int gradeToExecute) : name(name), isSigned(false), gradeRequired(gradeRequired), gradeToExecute(gradeToExecute)
{
	if (this->gradeRequired < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeRequired > 150)
		throw Form::GradeTooLowException();
	if (this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form &other) : name(other.name), isSigned(other.isSigned), gradeRequired(other.gradeRequired), gradeToExecute(other.gradeToExecute)
{
	if (other.gradeRequired < 1)
		throw Form::GradeTooHighException();
	else if (other.gradeRequired > 150)
		throw Form::GradeTooLowException();
	if (other.gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (other.gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form& Form::operator=(Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int	Form::getGradeRequired() const
{
	return this->gradeRequired;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->gradeRequired)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& o, const Form &f)
{
	std::string sign = "false";
	if (f.getIsSigned() == true)
		sign = "true";
	o << "\n-----------------Form info-----------------\n";
	o << "Form name: " << f.getName() << ".\nRequired grade: " << f.getGradeRequired() << ".\nGrade to execute: " << f.getGradeToExecute() << ".\nForm signed: " << sign;
	return o;
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}