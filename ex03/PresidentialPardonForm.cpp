/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:23 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 18:59:44 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <string>
#include <iomanip>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm(){};
PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardon", target, 25, 5){};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin): 
	AForm(origin.getName(), origin.getTarget(), origin.getSignGrade(), origin.getExeGrade()){};
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin){
	this->setSigned(origin.getSigned());
	return (*this);
};
PresidentialPardonForm::~PresidentialPardonForm(){};
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getExeGrade())
		throw AForm::UnauthorizedExecutionException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};
std::ostream& operator<<(std::ostream& lhe, PresidentialPardonForm& rhe){
	lhe << *(AForm*)&rhe << std::endl;
	lhe << std::left << "🎯 Target:         " << rhe.getTarget();
	return (lhe);
};
