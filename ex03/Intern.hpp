/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:42:40 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/28 12:57:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern &other);
		~Intern();
		Intern& operator=(Intern &other);
		AForm*	makeForm(std::string name, std::string target);
};