/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:56 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 15:40:46 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <ostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
private:
	const std::string name;
	int grade;
	Bureaucrat();
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& origin);
	Bureaucrat& operator=(const Bureaucrat& origin);
	~Bureaucrat();
	const std::string& getName() const;
	//there is no setName, name is constant!
	const int& getGrade() const;
	void setGrade(int newGrade);
	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form);
};
std::ostream& operator<<(std::ostream& lhe, Bureaucrat& hermes);