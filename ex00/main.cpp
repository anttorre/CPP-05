/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/01 15:45:58 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	Bureaucrat *b1 = NULL;
	Bureaucrat *b2 = NULL;
	Bureaucrat *b3 = NULL;
	try
	{
		b1 = new Bureaucrat("Antonio", 145);
		b2 = new Bureaucrat("Juan", 1);
		b3 = new Bureaucrat(*b1);
		std::cout << "b3 :" << *b3 <<std::endl;
		*b3 = *b2;
		std::cout << "b3 :" << *b3 <<std::endl;
		std::cout << "b1: " << *b1 << "\n" << "b2: " << *b2 << std::endl;
		b1->decrement();
		b2->decrement();
		std::cout << "b1: " << *b1 << "\n" << "b2: " << *b2 << std::endl;
		b1->increment();
		b2->increment();
		std::cout << "b1: " << *b1 << "\n" << "b2: " << *b2 << std::endl;
		b2->increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete b1;
	delete b2;
	delete b3;
}