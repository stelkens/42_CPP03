/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:45:49 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/27 14:25:24 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(){
	ClapTrap	Pipa("Pipa");
	
	Pipa.attack("Thomas");
	Pipa.attack("Gigi");
	Pipa.takeDamage(9);
	ClapTrap	Pippita(Pipa);
	Pippita.takeDamage(3);
	Pippita.attack("Ape");
	Pipa.beRepaired(4);
	for(int i = 0; i < 8; ++i)
		Pipa.attack("Gigi");
	Pipa.beRepaired(5);
	return 0;
}