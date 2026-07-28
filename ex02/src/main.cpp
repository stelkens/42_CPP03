/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:45:49 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/28 10:31:04 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(){
	ClapTrap	Pipa("Pipa");
	ScavTrap	Robo("Robo");
	FragTrap	Fufu("Fufu");
	FragTrap	a;

	Robo.attack("Gugu");
	Pipa.attack("Cobo");
	Fufu.attack("Luigi");
	Fufu.takeDamage(30);
	Fufu.highFivesGuys();
	a = Fufu;
	a.attack("Mario");
	a.takeDamage(60);
	a.highFivesGuys();
	Robo.guardGate();
	Pipa.takeDamage(90);
	a.beRepaired(70);
	Fufu.takeDamage(75);
	a.takeDamage(75);
	
	return 0;
}