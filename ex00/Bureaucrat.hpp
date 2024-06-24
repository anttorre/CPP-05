/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:57:16 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/24 15:40:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class  Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(Bureaucrat& other);
		std::string getName() const;
		int	getGrade() const;
		void	setGrade(int grade);
		void	increment();
		void	decrement();

		class  GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "[EXCEPTION] - Bureaucrat grade too high.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "[EXCEPTION] - Bureaucrat grade too low.";
				}
		};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);