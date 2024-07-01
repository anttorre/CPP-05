/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:43:17 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/01 15:03:35 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat default")
{
	this->grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : name (other.name)
{
	if (this != &other)
		*this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.grade;
		if (other.grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (other.grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::increment()
{
	if (this->grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	if (b.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (b.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	o << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
	return o;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}