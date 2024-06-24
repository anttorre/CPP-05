/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:43:17 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/24 15:43:37 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat default")
{
	try
	{
		this->grade = 1;
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade = grade;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
	if (this != &other)
		*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called\n";
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
	{
		try
		{
			if (other.grade < 1)
				throw Bureaucrat::GradeTooHighException();
			else if (other.grade > 150)
				throw Bureaucrat::GradeTooLowException();
			this->grade = other.grade;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
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
	this->grade--;
}

void	Bureaucrat::decrement()
{
	this->grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	o << b.getName() <<", bureaucrat grade " << b.getGrade() <<".";
	return o;
}