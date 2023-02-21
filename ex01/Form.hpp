/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:32:10 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 13:39:56 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Bureaucrat;
class Form
{
private:
	Form();
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _exeGrade;
public:
	Form(const Form& origin);
	Form& operator=(const Form& origin);
	Form(std::string name, int signGrade, int execGrade);
	~Form();
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	void beSigned(const Bureaucrat& bureaucrat);
	const std::string& getName(void) const;
	bool getSigned(void) const;
	const int& getSignGrade(void) const;
	const int& getExeGrade(void) const;
};
std::ostream& operator<<(std::ostream& lhe, Form& rhe);