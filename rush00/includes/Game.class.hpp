/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:49:26 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/14 18:58:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#define MAP_SIZE 100
#define NB_CELL (MAP_SIZE - 2) * ((MAP_SIZE / 2) - 3) // available nb of cells (excluding player row)
#define MIN_ENEMIES 2
#define MAX_ENEMIES MAP_SIZE / 2 - 2

#include <ncurses.h>
#include "Player.class.hpp"
#include "Enemi.class.hpp"

class Game {

	public:

		Game(void);
		Game(Game const &src);
		~Game(void);

		Game			&operator=(Game const &rhs);

		unsigned int	getWidth(void) const;
		unsigned int	getHeight(void) const;
		char			**getMap(void) const;
		WINDOW			*getWindow(void) const;
		Player			*getPlayer(void) const;
		Enemi			**getEnemies(void) const;

		int			initGame(Player *player);
		void		splashScreen(void);
		void		setEntitySpot(AEntity *entity);
		void		refresh(void);
		void		addEnemies(void);
		void		pushEnemies();
		int			checkCollisions();
		void		pushProjectils();
		void		gameOver(void);
		int			handleWinResize(void);

	private:

		void		initMap(void);
		void		initNcurses(void);
		int			initWindow(void);
		void		initPlayer(Player *player);
		void		updateMap(void);
		void		clearMap(void);

		unsigned int	_width;
		unsigned int	_height;
		WINDOW			*_window;
		char			**_map;
		Player			*_player;
		Enemi			**_enemies;
};

#endif
