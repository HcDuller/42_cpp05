/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:18:12 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 15:46:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iomanip>
#include <iostream>
#include <string>

std::string boolToEmoji(bool b){
	if (b)
		return ("✅");
	return ("❌");
}
int sanitizedGradeF(int grade){
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	return (grade);
};
bool checkGrade(int required, int possessed){
	if (required >= possessed)
		return (true);
	return (false);
}
AForm::AForm(): _name(""),_signed(false),_signGrade(1),_exeGrade(1){};
AForm::AForm(std::string name, int signGrade, int execGrade): _name(name),_signed(false),_signGrade(sanitizedGradeF(signGrade)),_exeGrade(sanitizedGradeF(execGrade)){};
AForm::AForm(const AForm& origin): _name(origin._name),_signed(origin._signed),_signGrade(origin._signGrade),_exeGrade(origin._exeGrade){};
AForm& AForm::operator=(const AForm& origin){
	this->_signed = origin._signed;
	return (*this);
};
AForm::~AForm(){};
const std::string& AForm::getName(void) const{
	return (this->_name);
};
bool AForm::getSigned(void) const{
	return (this->_signed);
};
const int& AForm::getSignGrade(void) const{
	return (this->_signGrade);
};
const int& AForm::getExeGrade(void) const{
	return (this->_exeGrade);
};
void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (this->_signed)
		return;
	if (!checkGrade(this->_signGrade, bureaucrat.getGrade()))
		throw GradeTooLowException();
	this->_signed = true;
};
const char* AForm::GradeTooHighException::what() const throw(){
	return ("🚫📝 Grade too high.");
};
const char* AForm::GradeTooLowException::what() const throw(){
	return ("🚫📝 Grade too low.");
};
const char* AForm::UnsignedFormException::what() const throw(){
	return ("🛑✋ This Form is not signed! ✋🛑");
};
std::ostream& operator<<(std::ostream& lhe, AForm& rhe){
	lhe << std::left << std::setw(25) << "📝 " + rhe.getName() << std::endl;
	lhe << std::left << std::setw(25) << "🖋️ Signed: " << boolToEmoji(rhe.getSigned()) << std::endl;
	lhe << std::left << std::setw(25) << "🎖️ Signing grade:" << rhe.getSignGrade() << std::endl;
	lhe << std::left << std::setw(25) << "🎖️ Execution grade:" << rhe.getExeGrade();
	return (lhe);
};
