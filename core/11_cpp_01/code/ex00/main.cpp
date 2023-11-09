#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

int main( void )
{
	std::cout << "\n>>> Test: Zombie::Zombie() + announce >>>\n" << std::endl;
	Zombie first;
	first.announce();

	std::cout << "\n>>> Test: Zombie::Zombie(name) + announce >>>\n" << std::endl;
	Zombie	second("Kupak");
	second.announce();

	std::cout << "\n>>> Test: newZombie(name) + announce + destroy >>>\n" << std::endl;
	Zombie	*third = newZombie("Radics Peti");
	third->announce();
	delete	third;

	std::cout << "\n>>> Test: randomChump(name), 2 times >>>\n" << std::endl;
	randomChump("Joco");
	randomChump("Sassy");

	std::cout << "\n>>> THE END <<<\n" << std::endl;

	return (0);
}
