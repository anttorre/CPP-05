/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/26 14:50:16 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	Bureaucrat *b1 = new Bureaucrat("Antonio", 145);
	Bureaucrat *b2 = new Bureaucrat("Juan", 1);

	std::cout << std::endl;

	std::cout << *b1 << "\n" << *b2 << std::endl;
	b1->decrement();
	b2->decrement();
	std::cout << *b1 << "\n" << *b2 << std::endl;
	b1->increment();
	b2->increment();
	std::cout << *b1 << "\n" << *b2 << std::endl;
	b2->increment();

	std::cout << std::endl;

	delete b1;
	delete b2;
}