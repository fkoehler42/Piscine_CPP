/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:38:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/14 18:14:39 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <csignal>
#include <iostream>
#include "../includes/Game.class.hpp"
#include "../includes/Player.class.hpp"

void	winSizeError(void) {
	char	errMsg[] = "Your window is too small to play, press any key then restart in a larger window.";

	nodelay(stdscr, FALSE);
	printw(errMsg);
	getch();
}

int		updateEntities(Game &game) {
	game.pushEnemies(); // push current ennemies before adding some
	game.addEnemies();
	if (game.checkCollisions() == 1)
		return (1);
	game.pushProjectils();
	if (game.checkCollisions() == 1)
		return (1);
	return (0);
}

int		main(void) {
	Game			game;
	Player			player("Player1");
	int				input;
	struct timeval	tv;
	uint64_t		tenthsOfSec;

	gettimeofday(&tv, NULL);
	tenthsOfSec = (tv.tv_sec * 10) + (tv.tv_usec / 100000); 
	if (game.initGame(&player) != 0) {
		winSizeError();
		return (1);
	}
	while (1) {
		if ((input = wgetch(game.getWindow())) != ERR) {
			if (input == KEY_RESIZE && game.handleWinResize() != 0) {
				winSizeError();
				return (1);
			}
			else if ((input = player.handleInput(input)) == 1)
				return (0);
			else
				game.refresh();
		}
		gettimeofday(&tv, NULL);
		if (((tv.tv_sec * 10) + (tv.tv_usec / 100000)) != tenthsOfSec) {
			tenthsOfSec = (tv.tv_sec * 10) + (tv.tv_usec / 100000);
			if (updateEntities(game) == 1)
				return (0);
			game.refresh();
		}
	}
	return 0;
}
