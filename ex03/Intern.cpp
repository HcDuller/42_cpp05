/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:05 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/23 19:02:33 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

Intern::Intern(){};
Intern::Intern(const Intern& origin){(void)origin;};
Intern& Intern::operator=(const Intern& origin){
	(void)origin;
	return (*this);
};
Intern::~Intern(){};

AForm* Intern::shruberry(std::string& target){
	return (new ShrubberyCreationForm(target));
};
AForm* Intern::robotomy(std::string& target){
	return (new RobotomyRequestForm(target));
};
AForm* Intern::presidential(std::string& target){
	return (new PresidentialPardonForm(target));
};
const char* Intern::InvalidFormException::what() const throw(){
	
	return ("Invalid form.");
};
AForm* Intern::makeForm(std::string formName, std::string formTarget){
	std::string formNames[3] = {"shruberry","robotomy","pardon"};
	std::string description[3] = {"Shrubbery Creation","Robotomy Request","Presidential Pardon"};
	AForm* (Intern::*maker[3])(std::string&) = {&Intern::shruberry,&Intern::robotomy,&Intern::presidential};
	for (int i = 0 ; i < 4; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern created a " << description[i] << "." << std::endl;
			return ((this->*maker[i])(formTarget));
		}
	}
	throw Intern::InvalidFormException();
};