/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:43:17 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/01 15:53:25 by anttorre         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(Bureaucrat& other) : name(other.name)
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

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
		f.beSigned(*this);
		std::cout << *this << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << f.getName() << " because " <<  e.what() << std::endl;
	}	
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	o << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
	return o;
}