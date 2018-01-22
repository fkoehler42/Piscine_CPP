/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:55:14 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/14 19:37:26 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/time.h>
#include "../includes/Game.class.hpp"

Game::Game(void) : _width(MAP_SIZE), _height(MAP_SIZE / 2), _window(NULL),
_map(NULL), _player(NULL), _enemies(NULL) {
	struct timeval	tv;

	this->_enemies = new Enemi*[MAX_ENEMIES];
	srand(tv.tv_usec * tv.tv_sec); // seed rand functions
}

Game::Game(Game const &src) { *this = src; }

Game::~Game(void) {
	Enemi	**enemies = this->getEnemies();
	char	**map = this->getMap();

	if (this->getWindow()) {
		wclear(this->_window);
		delwin(this->getWindow());
	}
	if (enemies && map) {
		for (size_t i = 0; i < MAX_ENEMIES; i++) {
			if (enemies[i] != NULL)
				delete enemies[i];
		}
		delete [] enemies;
		for (size_t i = 0; i < this->getHeight() - 2; i++) {
			delete map[i];
		}
		delete [] map;
	}
	endwin();
}

Game		&Game::operator=(Game const &rhs) {
	this->_width = rhs.getWidth();
	this->_height = rhs.getHeight();
	this->_window = rhs.getWindow();
	this->_map = rhs.getMap();
	this->_player = rhs.getPlayer();
	this->_enemies = rhs.getEnemies();
	return (*this);
}


//// GETTERS ////

unsigned int	Game::getWidth(void) const { return this->_width; }
unsigned int	Game::getHeight(void) const { return this->_height; }
char			**Game::getMap(void) const { return this->_map; }
WINDOW			*Game::getWindow(void) const { return this->_window; }
Player			*Game::getPlayer(void) const { return this->_player; }
Enemi			**Game::getEnemies(void) const { return this->_enemies; }

//// INITIALIZATION ////

int		Game::initGame(Player *player) {
	this->initNcurses();
	if (this->initWindow() != 0)
		return (1);
	this->initMap();
	this->initPlayer(player);
	this->splashScreen();
	this->refresh();
	return (0);
}

void		Game::initNcurses(void) {
	initscr();
	noecho(); // disable input display
	curs_set(0); // hide cursor
	cbreak();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
}

void			Game::initMap(void) {
	int	j = 0;

	this->_map = new char*[this->_height - 2];
	for (size_t i = 0; i < this->_height - 2; i++) {
		this->_map[i] = new char[this->_width - 1];
		j = 0;
		while (j < this->_width - 2) {
			this->_map[i][j] = ' ';
			j++;
		}
		this->_map[i][j] = '\0';
	}
}
int			Game::initWindow(void) {
	int		height, width, input;
	
	getmaxyx(stdscr, height, width);
	if (height < this->_height || width < this->_width)
		return (1);
	this->_window = newwin(this->_height, this->_width,
	(height - this->_height) / 2, (width - this->_width) / 2);
	wattron(this->_window, A_BOLD);
	wattron(this->_window, COLOR_PAIR(1));
	wborder(this->_window, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN);
	keypad(this->_window, TRUE); // accept all keys
	nodelay(this->_window, TRUE);
	return (0);
}

void		Game::initPlayer(Player *player) {
	int x, y;

	x = this->_width / 2 - 3;
	y = this->_height - 3;
	this->_player = player;
	this->_player->setX(x);
	this->_player->setY(y);
	this->setEntitySpot(player);
}

void		Game::splashScreen(void) {
	mvwprintw(this->getWindow(), MAP_SIZE / 6, MAP_SIZE / 2 - 12, "Welcome into ft_retro !");
	mvwprintw(this->getWindow(), MAP_SIZE / 6 + 2, MAP_SIZE / 2 - 12, "Press any key to start");
	wrefresh(this->getWindow());
	nodelay(this->_window, FALSE);
	wgetch(this->getWindow());
	nodelay(this->_window, TRUE);
}

//// HANDLING ////

void		Game::setEntitySpot(AEntity *entity) {
	if (entity != NULL)
		this->_map[entity->getY()][entity->getX()] = entity->getSprite();
}

void		Game::clearMap(void) {
	int j;

	for (size_t i = 0; i < this->_height - 2; i++)
	{
		j = 0;
		while (this->_map[i][j]) {
			this->_map[i][j] = ' ';
			j++;
		}
	}
}

void		Game::updateMap(void) {
	int			i = 0;
	Projectil	**projectils = this->_player->getProjectils();
	Enemi		**enemies = this->getEnemies();

	this->clearMap();
	this->setEntitySpot(this->_player);
	while (projectils[i] != NULL) {
		if (projectils[i]->getY() > -1)
			this->setEntitySpot(projectils[i]);
		i++;
	}
	i = 0;
	while (i < MAX_ENEMIES && enemies[i] != NULL) {
		if (enemies[i]->getY() > -1)
			this->setEntitySpot(enemies[i]);
		i++;
	}

}

void		Game::refresh(void) {
	this->updateMap();
	for (size_t i = 0; i < this->_height - 2; i++)
			mvwprintw(this->getWindow(), i + 1, 1, this->_map[i]);
	wrefresh(this->getWindow());
}

void		Game::addEnemies(void) {
	int		i = 0;
	int		index = 0;
	int 	check = rand() % (MAP_SIZE - 2);
	Enemi	**enemies = this->getEnemies();

	if (rand() < (RAND_MAX / 2)) { // 50% chances of adding a new ennemy
		while (i < MAX_ENEMIES && enemies[i] != NULL && enemies[i]->getY() > -1)
			i++;
		if (i >= MAX_ENEMIES)
			return;
		if (enemies[i] == NULL)
		{
			while (index < i)
			{
				if (enemies[index]->getX() == check)
				{
					enemies[i] = new Enemi(check, -1);
					return;
				}
				index++;
			}
			enemies[i] = new Enemi(check, 0);
		}
		else {
			while (index < i)
			{
				if (enemies[index]->getX() == check)
				{
					enemies[i]->setY(-1);
					return;
				}
				index++;
			}
			enemies[i]->setX(check);
			enemies[i]->setY(0);
    	}
	}
}

void		Game::pushEnemies(void) {
	Enemi	**enemies = this->getEnemies();

	for (size_t i = 0; i < MAX_ENEMIES ; i++)
	{
		if (enemies[i] == NULL || enemies[i]->getY() == -1)
			continue;
		if (enemies[i]->getY() >= ((MAP_SIZE / 2) - 3)) {
			enemies[i]->setY(-1); // invalid the enemi until later repop
			this->getPlayer()->decrementScore();
		}
		else
			enemies[i]->setY(enemies[i]->getY() + 1);
	}
}

int			Game::checkCollisions() {
	Enemi	**enemies = this->getEnemies();
	Projectil	**projectils = this->_player->getProjectils();

	for (size_t i = 0; i < MAX_ENEMIES ; i++) {
		if (enemies[i] != NULL && enemies[i]->getY() > -1) {
			for (size_t j = 0; projectils[j] != NULL ; j++) {
				if (projectils[j] != NULL && projectils[j]->getY() > -1) {
					if ((enemies[i]->getY() == projectils[j]->getY())
					&& enemies[i]->getX() == projectils[j]->getX()) {
						enemies[i]->setY(-1);
						projectils[j]->setY(-1);
						this->getPlayer()->incrementScore();
					}
				}
			}
			if (enemies[i]->getY() == this->_player->getY()
			&& enemies[i]->getX() == this->_player->getX()) {
				this->gameOver();
				return (1);
			}
		}
	}
	return (0);
}

void		Game::pushProjectils() {
	Projectil	**projectils = this->_player->getProjectils();
	for (size_t i = 0; projectils[i] != NULL; i++)
	{
		if (projectils[i]->getY() <= 0)
			projectils[i]->setY(-1); // invalid the projectil for later display
		else
			projectils[i]->setY(projectils[i]->getY() - 1);
	}
}

void		Game::gameOver(void) {
	char	gameO[] = "Game Over";
	char	pressE[] = "Press `escape` to exit";
	int		input;

	nodelay(this->getWindow(), FALSE);
	wclear(this->getWindow());
	wborder(this->_window, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN, ACS_LANTERN);
	mvwprintw(this->getWindow(), MAP_SIZE / 6, (MAP_SIZE / 2) - (strlen(gameO) / 2), gameO);
	mvwprintw(this->getWindow(), MAP_SIZE / 6 + 2, MAP_SIZE / 2 - 11, "Your Score : %09d", this->getPlayer()->getScore());
	mvwprintw(this->getWindow(), MAP_SIZE / 6 + 6, (MAP_SIZE / 2) - (strlen(pressE) / 2), pressE);
	wrefresh(this->getWindow());
	do
		input = wgetch((this->getWindow()));
	while (input != 27);
}

//// SIGNALS ////

int		Game::handleWinResize(void) {
	if (this->getWindow()) {
		wclear(this->getWindow());
		wrefresh(this->getWindow());
		delwin(this->getWindow());
		this->_window = NULL;
	}
	if (this->initWindow() != 0)
		return (1);
	for (size_t i = 0; i < this->_height - 2; i++)
		mvwprintw(this->getWindow(), i + 1, 1, this->_map[i]);
	wrefresh(this->getWindow());
	return (0);
}