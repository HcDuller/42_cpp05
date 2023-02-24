/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:53:11 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/24 13:15:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>

int sanitizedGrade(int grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (grade);
};
Bureaucrat::Bureaucrat(): name(""), grade(150){};
Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
	sanitizedGrade(grade);
};
Bureaucrat::Bureaucrat(const Bureaucrat& origin): name(origin.name){
	*this = origin;
};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin){
	this->grade = origin.grade;
	return (*this);
};
Bureaucrat::~Bureaucrat(){
	//std::cout << "💀 " << << this->name << " 💀" << std::endl;
};
const std::string& Bureaucrat::getName() const{
	return (this->name);
};
const int& Bureaucrat::getGrade() const{
	return (this->grade);
};
void Bureaucrat::setGrade(int newGrade){
	this->grade = sanitizedGrade(newGrade);
};
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("🚫🤕 Grade too high.");
};
const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("🚫🤕 Grade too low.");
};
void Bureaucrat::incrementGrade(){
	this->setGrade(this->grade - 1);
};
void Bureaucrat::decrementGrade(){
	this->setGrade(this->grade + 1);
};
std::ostream& operator<<(std::ostream& lhstream, Bureaucrat& hermes){
	lhstream << std::left << std::setw(25) << "🧑‍💼 " + hermes.getName() << "| Grade 🎖️: " << std::right << std::setw(3) << hermes.getGrade();
	return (lhstream);
}
void Bureaucrat::signForm(AForm& form){
	if (form.getSigned())
	{
		std::cout << "🧑‍💼 " + this->getName() << " can't sign " << form.getName() << ", it is already signed." << std::endl;
		return;
	}
	try{
		form.beSigned(*this);
		std::cout << "🧑‍💼 " + this->getName() << " signed a " << form.getName() << " form for " << form.getTarget() <<std::endl;
	}catch(std::exception& e){
		std::cout << "🧑‍💼 " + this->getName() << " can't sign " << form.getName();
		std::cout << ". Reason: " << e.what() << std::endl;;
	}
};
void Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
		std::cout << "🧑‍💼 " + this->getName() << " executed " << form.getName() << "." << std::endl;
	}catch(std::exception& e){
		std::cout << this->getName() << " can't execute " << form.getName() << ". Reason: " << std::endl;
		std::cout << e.what() << std::endl;
	}
};
