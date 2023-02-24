/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:58 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/24 13:13:34 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
void formTest(){
	std::cout << std::endl << "📜📜📜📜FORM START📜📜📜📜" << std::endl;
	std::cout << "Stack allocation start" << std::endl;
	{
		Bureaucrat hermes("Hermes",33);
		Form	laundry("Laundry", 50, 140);
		Form	acc("Accounting", 30, 50);
		std::cout << hermes << std::endl;
		std::cout << std::endl;
		std::cout << laundry << std::endl;
		std::cout << std::endl;
		std::cout << acc << std::endl;
		std::cout << "Hermes should be able to sign Laundry, but not Accounting." << std::endl;
		hermes.signForm(laundry);
		hermes.signForm(acc);
		std::cout << std::endl;
		std::cout << laundry << std::endl;
		std::cout << std::endl;
		std::cout << acc << std::endl;
	}
	std::cout << "Stack allocation end" << std::endl << std::endl;
	std::cout << "Heap allocation start" << std::endl;
	{
		Bureaucrat* hermes = new Bureaucrat("Hermes",33);
		Form*	laundry = new Form("Laundry", 50, 140);
		Form*	acc = new Form("Accounting", 30, 50);
		std::cout << *hermes << std::endl;
		std::cout << std::endl;
		std::cout << *laundry << std::endl;
		std::cout << std::endl;
		std::cout << *acc << std::endl;
		std::cout << "Hermes should be able to sign Laundry, but not Accounting." << std::endl;
		hermes->signForm(*laundry);
		hermes->signForm(*acc);
		delete hermes;
		delete laundry;
		delete acc;
	}
	std::cout << "Heap allocation end" << std::endl << std::endl;
	std::cout << std::endl << "📜📜📜📜FORM END📜📜📜📜" << std::endl;

};
int main(void){
	bureaucratTest();
	formTest();
	return (0);
}