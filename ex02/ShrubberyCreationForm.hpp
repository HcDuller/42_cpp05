/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:47:54 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 15:51:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm
{
private:
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const ShrubberyCreationForm& origin);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);
	~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) = 0;
};