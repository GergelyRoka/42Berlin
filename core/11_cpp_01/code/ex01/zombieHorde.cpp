/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:45:46 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 11:45:46 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	if (N < 1)
		return (NULL);

	horde = new Zombie[N];

	if (name.empty())
		return (horde);

	for (int i = 0; i < N; ++i)
	{
		horde[i].setName(name);
	}

	return (horde);
}
