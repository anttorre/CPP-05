/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/26 17:52:02 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
int main()
{
	Bureaucrat	*b1 = new Bureaucrat("Antonio", 151);
	Bureaucrat	*b2 = new Bureaucrat("Juan", 26);

	b1->decrement();
	b2->increment();
	std::cout << "\n" << *b1 << "\n" << *b2 << std::endl;

	std::cout << std::endl;

	delete b1;
	delete b2;
}