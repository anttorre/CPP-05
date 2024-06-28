/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/28 17:28:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat	*b1 = new Bureaucrat("Antonio", 149);
	Bureaucrat	*b2 = new Bureaucrat("Juan", 26);
	Bureaucrat	*b3 = new Bureaucrat(*b1);
	Form		*f1 = new Form("B1", 150, 100);
	Form		*f2 = new Form("B2", 25, 75);
	

	std::cout << std::endl;

	std::cout << *b3 <<std::endl;
	*b3 = *b2;
	std::cout << "b3 :" << *b3 <<std::endl;

	b1->decrement();
	b1->signForm(*f1);
	b1->signForm(*f2);
	b2->signForm(*f1);
	b2->increment();
	b2->signForm(*f2);
	std::cout << "\nb1: " << *b1 << "\n" << "b2: " << *b2 << std::endl;
	std::cout << *f1 << "\n" << *f2 << std::endl;

	std::cout << std::endl;

	delete b1;
	delete b2;
	delete f1;
	delete f2;
}