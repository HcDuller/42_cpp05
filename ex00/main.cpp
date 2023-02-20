/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:58 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/20 20:13:31 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void){
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
	return (0);
}