/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:47:54 by hde-camp          #+#    #+#             */
/*   Updated: 2023/02/21 18:39:10 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const RobotomyRequestForm& origin);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
	~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
};
std::ostream& operator<<(std::ostream& lhe, RobotomyRequestForm& rhe);