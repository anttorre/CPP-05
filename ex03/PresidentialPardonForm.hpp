/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:37:12 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/27 17:52:58 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm &other);
		std::string getTarget() const;
		bool execute(Bureaucrat const &executor) const;
};