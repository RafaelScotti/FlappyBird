#include "Game.h"

int Game::score = 0;
bool Game::start = false;

Game::Game()
{
	
}

Game::~Game()
{
	
}

int Game::incScore()
{

	if (World::colisao()) {
		
		cout << "\n====================END===================" << endl;
		std::cout << R"(
		  ____    _    __  __ _____    _____     _______ ____
	   	 / ___|  / \  |  \/  | ____|  / _ \ \   / / ____|  _ \
		| |  _  / _ \ | |\/| |  _|   | | | \ \ / /|  _| | |_) |
		| |_| |/ ___ \| |  | | |___  | |_| |\ V / | |___|  _ <
		 \____/_/   \_\_|  |_|_____|  \___/  \_/  |_____|_| \_\
		)";
		cout << "\n  Score: " << Game::score / 18 << endl; // remover o /18
		Game::score = 0;
	
		cout << "\n=======Press UP KEY to play again!========" << endl;
		return 0;
	}
	else {
		if (World::target()) {
			Game::score += 1;
		}	
	}
}

void Game::startGame()
{
	Game::start = true;
}

void Game::restart()
{
}

void Game::save(int score)
{
	
}

void Game::exitGame()
{
}

bool Game::hasStarted()
{
	if (Game::start == true) {
		return true;
	}
	else {
		return false;
	}
}

void Game::update()
{
}

void Game::stop()
{
	Game::start = false;
}
