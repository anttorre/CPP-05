/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:57:59 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/28 14:51:59 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &other)
{
	if (this != &other)
		*this = other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(Intern &other)
{
	(void) other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *s = NULL;
	int i;
	std::string arr[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	for (i = 0; i < 3; i++)
		if (arr[i] == name)
			break;
	switch (i)
	{
		case 0:
			return (s = new ShrubberyCreationForm(target));
		case 1:
			return (s = new PresidentialPardonForm(target));
		case 2:
			return (s = new RobotomyRequestForm(target));
		default:
			std::cout << "The form u trying to create doesn't exist. Try again...";
			return s;
	}
}