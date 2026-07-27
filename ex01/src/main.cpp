/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:45:49 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/27 15:22:04 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(){
	ClapTrap	Pipa("Pipa");
	ScavTrap	Robo("Robo");

	Robo.attack("Gugu");
	Pipa.attack("Cobo");
	Robo.takeDamage(80);
	Robo._guardGate();
	Robo._guardGate();
	Pipa.takeDamage(90);
	ScavTrap Ro(Robo);
	Ro.takeDamage(30);
	Robo.beRepaired(34);
	Robo.takeDamage(30);
	
	
	return 0;
}