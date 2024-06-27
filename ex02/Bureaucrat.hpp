/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:57:16 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/27 12:42:42 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

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
		void	signForm(AForm &f);
		void	executeForm(AForm const &form);
		class  GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too high.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too low.";
				}
		};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif