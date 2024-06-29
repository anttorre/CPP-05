/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:43:17 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/29 13:52:14 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat default")
{
	this->grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try
	{
		this->grade = grade;
		if (this->grade > 150)
		{
			this->grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		else if (this->grade < 1)
		{
			this->grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
		try
		{
			this->grade = other.grade;
			if (other.grade > 150)
			{
				this->grade = 150;
				throw Bureaucrat::GradeTooLowException();
			}
			else if (other.grade < 1)
			{
				this->grade = 1;
				throw Bureaucrat::GradeTooHighException();
			}
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
	try
	{
		if (this->grade - 1 <= 0)
			throw Bureaucrat::GradeTooHighException();
		this->grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrement()
{
	try
	{
		if (this->grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		f.beSigned(*this);
		std::cout << *this << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << f.getName() << " because " <<  e.what() << std::endl;
	}	
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if (form.execute(*this))
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
		else
			std::cout << this->getName() << " couldn't execute " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	try
	{
		if (b.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (b.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		o << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return o;
}