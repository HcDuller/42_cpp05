/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
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

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const PresidentialPardonForm& origin);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
	~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
};
std::ostream& operator<<(std::ostream& lhe, PresidentialPardonForm& rhe);