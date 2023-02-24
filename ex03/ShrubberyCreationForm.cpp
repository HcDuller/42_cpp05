/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:23 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/24 15:22:17 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>


void write_tree(std::string target){
	std::fstream writer;
	std::string composedName = getenv("PWD");
	composedName += "/";
	composedName += target + "_shruberry";
	std::string treeContent = TREE;
	const char* fileName = composedName.c_str();
	writer.open(fileName, std::ios_base::out);
	if (!writer.good() || writer.bad())
		return;
	writer << treeContent;
	writer.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(){};
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreation", target, 145, 137){};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin): 
	AForm(origin.getName(), origin.getTarget(), origin.getSignGrade(), origin.getExeGrade()){};
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin){
	this->setSigned(origin.getSigned());
	return (*this);
};
ShrubberyCreationForm::~ShrubberyCreationForm(){};
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getExeGrade())
		throw AForm::UnauthorizedExecutionException();
	write_tree(this->getTarget());
};
std::ostream& operator<<(std::ostream& lhe, ShrubberyCreationForm& rhe){
	lhe << *(AForm*)&rhe << std::endl;
	lhe << std::left << "🎯 Target:         " << rhe.getTarget();
	return (lhe);
};
