#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(const std::string name);
		~FragTrap();

		FragTrap &operator=(const FragTrap& other);

		void	highFivesGuys(void);
		void	attack(const std::string& target);

};

#endif
