/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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
class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _exeGrade;
	const std::string _target;
protected:
	AForm();
	AForm(const AForm& origin);
	AForm& operator=(const AForm& origin);
	AForm(std::string name, std::string target, int signGrade, int execGrade);
public:
	virtual ~AForm();
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class UnsignedFormException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class UnauthorizedExecutionException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class UnauthorizedSignException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	const std::string& getName(void) const;
	const std::string& getTarget(void) const;
	bool getSigned(void) const;
	void setSigned(bool newSigned);
	const int& getSignGrade(void) const;
	const int& getExeGrade(void) const;
};
std::ostream& operator<<(std::ostream& lhe, AForm& rhe);