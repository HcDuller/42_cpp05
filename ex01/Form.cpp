/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:18:12 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 14:18:56 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
};
bool checkGrade(int required, int possessed){
	if (required >= possessed)
		return (true);
	return (false);
}
Form::Form(): _name(""),_signed(false),_signGrade(1),_exeGrade(1){};
Form::Form(std::string name, int signGrade, int execGrade): _name(name),_signed(false),_signGrade(sanitizedGradeF(signGrade)),_exeGrade(sanitizedGradeF(execGrade)){};
Form::Form(const Form& origin): _name(origin._name),_signed(origin._signed),_signGrade(origin._signGrade),_exeGrade(origin._exeGrade){};
Form& Form::operator=(const Form& origin){
	this->_signed = origin._signed;
	return (*this);
};
Form::~Form(){};
const std::string& Form::getName(void) const{
	return (this->_name);
};
bool Form::getSigned(void) const{
	return (this->_signed);
};
const int& Form::getSignGrade(void) const{
	return (this->_signGrade);
};
const int& Form::getExeGrade(void) const{
	return (this->_exeGrade);
};
void Form::beSigned(const Bureaucrat& bureaucrat){
	if (this->_signed)
		return;
	if (!checkGrade(this->_signGrade, bureaucrat.getGrade()))
		throw GradeTooLowException();
	this->_signed = true;
};
const char* Form::GradeTooHighException::what() const throw(){
	return ("🚫📝 Grade too high.");
};
const char* Form::GradeTooLowException::what() const throw(){
	return ("🚫📝 Grade too low.");
};
std::ostream& operator<<(std::ostream& lhe, Form& rhe){
	lhe << std::left << std::setw(25) << "📝 " + rhe.getName() << std::endl;
	lhe << std::left << std::setw(25) << "🖋️ Signed: " << boolToEmoji(rhe.getSigned()) << std::endl;
	lhe << std::left << std::setw(25) << "🎖️ Signing grade:" << rhe.getSignGrade() << std::endl;
	lhe << std::left << std::setw(25) << "🎖️ Execution grade:" << rhe.getExeGrade();
	return (lhe);
};
/*

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _exeGrade;
public:
	
};


*/