/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:30:34 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/26 14:29:06 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const		std::string name;
		bool		isSigned;
		const int	gradeRequired;
		const int	gradeToExecute;
	public:
		Form();
		Form(std::string name, int gradeRequired, int gradeToExecute);
		Form(Form &other);
		~Form();
		Form& operator=(Form &other);
		std::string getName() const;
		bool	getIsSigned() const;
		int		getGradeRequired() const;
		int		getGradeToExecute() const;
		void	beSigned(Bureaucrat &b);
	class GradeTooHighException : public std::exception
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

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif