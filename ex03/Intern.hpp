/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:26:26 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/23 18:34:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <exception>

class Intern
{
private:
	AForm *shruberry(std::string& target);
	AForm *robotomy(std::string& target);
	AForm *presidential(std::string& target);
public:
	Intern();
	Intern(const Intern& origin);
	Intern& operator=(const Intern& origin);
	~Intern();
	AForm* makeForm(std::string formName, std::string formTarget);
	class InvalidFormException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
};