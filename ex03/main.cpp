/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:58 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/23 18:49:53 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

int main(void){
	Bureaucrat prof("Professor",1);
	Intern slave;

	try{
		AForm* shruberry = slave.makeForm("shruberry", "a house");
		AForm* robotomy = slave.makeForm("robotomy", "Bender");
		AForm* pardon = slave.makeForm("pardon", "Roberto");
		prof.signForm(*shruberry);
		prof.signForm(*robotomy);
		prof.signForm(*pardon);
		delete shruberry;
		delete robotomy;
		delete pardon;
	}catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		AForm* shruberry = slave.makeForm("shru-berry", "a house");
		delete shruberry;
	}catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}