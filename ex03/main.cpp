/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/28 15:04:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	*b1 = new Bureaucrat("Antonio", 151);
	Bureaucrat	*b2 = new Bureaucrat("Juan", 4);
	AForm		*f1 = new ShrubberyCreationForm("Pepe");
	AForm		*f2 = new RobotomyRequestForm("wakana");
	AForm		*f3 = new PresidentialPardonForm("Murder");

	std::cout << std::endl;
	
	std::cout << "--------MAIN---------" << std::endl;
	b2->signForm(*f1);
	b1->signForm(*f1);
	b1->executeForm(*f1);
	//b2->executeForm(*f1);
	b1->signForm(*f2);
	b2->signForm(*f2);
	b1->executeForm(*f2);
	b2->executeForm(*f2);
	b1->signForm(*f3);
	b2->signForm(*f3);
	b1->executeForm(*f3);
	b2->executeForm(*f3);
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;

	std::cout << std::endl;
	std::cout << "--------COPY TEST---------" << std::endl;
	ShrubberyCreationForm *s1 = new ShrubberyCreationForm("prueba");
	ShrubberyCreationForm *s2 = new ShrubberyCreationForm("pepe");
	*s2 = *s1;
	std::cout << s2->getTarget() << "\n" << s2->getName() << "\n" << s2->getGradeRequired() << "\n" << s2->getGradeToExecute() << std::endl;

	std::cout << std::endl;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (rrf)
		std::cout << *rrf << std::endl;

	std::cout << std::endl;

	delete b1;
	delete b2;
	delete f1;
	delete s1;
	delete s2;
	delete f2;
	delete f3;
	delete rrf;
}