/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:23 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 18:59:44 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(): AForm(){};
RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequest", target, 72, 45){};
//std::string name, std::string target, int signGrade, int execGrade
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin): 
	AForm(origin.getName(), origin.getTarget(), origin.getSignGrade(), origin.getExeGrade()){};
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin){
	this->setSigned(origin.getSigned());
	return (*this);
};
RobotomyRequestForm::~RobotomyRequestForm(){};
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getExeGrade())
		throw AForm::UnauthorizedExecutionException();
	std::cout << "🫨bzzzzzz...bzzzzzz...bzzzzzz..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "🤯🤯" <<this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "🥵🥵" <<this->getTarget() << "'s Robotomy failed." << std::endl;
	
};
std::ostream& operator<<(std::ostream& lhe, RobotomyRequestForm& rhe){
	lhe << *(AForm*)&rhe << std::endl;
	lhe << std::left << "🎯 Target:         " << rhe.getTarget();
	return (lhe);
};
