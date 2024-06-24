/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/24 15:46:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	Bureaucrat *b1 = new Bureaucrat("Antonio", 150);
	Bureaucrat *b2 = new Bureaucrat("Juan", 1);

	std::cout << std::endl;

	std::cout << *b1 << "\n" << *b2 << std::endl;

	std::cout << std::endl;

	delete b1;
	delete b2;
}