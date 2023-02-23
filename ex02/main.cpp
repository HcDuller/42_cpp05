/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:58 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/23 19:04:47 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <iostream>


void bureaucratTest(){
	std::cout << std::endl << "💼💼💼💼BUREAUCRAT START💼💼💼💼" << std::endl;
	std::cout << "Stack allocation start" << std::endl;
	try{
		Bureaucrat hermes("Hermes",33);
		Bureaucrat fry("Fry",150);
		Bureaucrat professor("Professor",1);
		std::cout << hermes << std::endl;
		std::cout << fry << std::endl;
		std::cout << professor << std::endl;
		Bureaucrat bender("Bender",0);
		std::cout << bender << std::endl;
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Stack allocation end" << std::endl << std::endl;
	std::cout << "Heap allocation start" << std::endl;
	try{
		Bureaucrat* hermes = new Bureaucrat("Hermes",33);
		Bureaucrat* fry = new Bureaucrat("Fry",150);
		Bureaucrat* professor = new Bureaucrat("Professor",1);
		std::cout << *hermes << std::endl;
		std::cout << *fry << std::endl;
		std::cout << *professor << std::endl;
		delete hermes;
		delete fry;
		delete professor;
		Bureaucrat* bender = new Bureaucrat("Bender",151);
		delete bender;
		std::cout << *bender << std::endl;
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Heap allocation end" << std::endl << std::endl;
	std::cout << std::endl << "💼💼💼💼BUREAUCRAT END💼💼💼💼" << std::endl;
};
void shrubberyTest(){
	std::cout << std::endl << "🌳🌳🌳🌳SHRUBBERY START🌳🌳🌳🌳" << std::endl << std::endl;
	{
		ShrubberyCreationForm form("Homer's house");
		Bureaucrat hermes("Hermes",33);
		hermes.signForm(form);
		hermes.executeForm(form);
	}
	std::cout << std::endl << "🌳🌳🌳🌳SHRUBBERY END🌳🌳🌳🌳🌳" << std::endl;
};
void robotomyTeste(){
	std::cout << std::endl << "🤖🤖🤖🤖ROBOTOMY START🤖🤖🤖🤖" << std::endl << std::endl;
	std::srand(time(NULL));
	{
		RobotomyRequestForm benderForm("Bender");
		RobotomyRequestForm robertoForm("Roberto");
		RobotomyRequestForm hedForm("Hedonismbot");
		Bureaucrat fry("Fry",140);
		Bureaucrat hermes("Hermes",70);
		Bureaucrat prof("Professor",1);
		fry.signForm(benderForm);
		fry.signForm(robertoForm);
		fry.signForm(hedForm);
		hermes.signForm(benderForm);
		hermes.signForm(robertoForm);
		hermes.signForm(hedForm);
		prof.signForm(benderForm);
		prof.signForm(robertoForm);
		prof.signForm(hedForm);
		fry.executeForm(benderForm);
		hermes.executeForm(benderForm);
		prof.executeForm(benderForm);
	}
		std::cout << std::endl << "🤖🤖🤖🤖ROBOTOMY END🤖🤖🤖🤖🤖" << std::endl;
};
void presidentialTest(){
	std::cout << std::endl << "🤴🤴🤴🤴PRESIDENTIAL START🤴🤴🤴🤴" << std::endl << std::endl;
	{
		PresidentialPardonForm benderForm("Bender");
		PresidentialPardonForm robertoForm("Roberto");
		PresidentialPardonForm hedForm("Hedonismbot");
		Bureaucrat fry("Fry",140);
		Bureaucrat hermes("Hermes",73);
		Bureaucrat prof("Professor",1);
		fry.signForm(benderForm);
		fry.signForm(robertoForm);
		fry.signForm(hedForm);
		hermes.signForm(benderForm);
		hermes.signForm(robertoForm);
		hermes.signForm(hedForm);
		prof.signForm(benderForm);
		prof.signForm(robertoForm);
		prof.signForm(hedForm);
		fry.executeForm(benderForm);
		hermes.executeForm(benderForm);
		prof.executeForm(benderForm);

	}
	std::cout << std::endl << "🤴🤴🤴🤴PRESIDENTIAL END🤴🤴🤴🤴🤴" << std::endl;
};
int main(void){
	bureaucratTest();
	shrubberyTest();
	robotomyTeste();
	presidentialTest();
	// formTest();
	return (0);
}