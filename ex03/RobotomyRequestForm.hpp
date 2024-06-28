/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:52:21 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/27 17:40:21 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm &other);
		std::string getTarget() const;
		bool execute(Bureaucrat const &executor) const;
};
