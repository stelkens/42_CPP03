#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool	_guardMode;

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(const std::string name);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap& other);

		void	guardGate(void);
		void	attack(const std::string& target);

};

#endif
