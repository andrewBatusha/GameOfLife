#pragma once
#include "setting.hpp"
#include "pool.hpp"
#include "cell.hpp"
#include "menu.hpp"
#include "painter.hpp"

class Lordclass {
	private:
	sf::RenderWindow window;

	pool Pool;
	Painter painter;
	cell Cell;
	setting set;
	Menu menu;

	sf::Font font;
	sf::Text counter;
	sf::Mouse mouse;
	std::size_t gen_counter;

	public:
	Lordclass(const setting& _set);
	void run();
	private:
	void draw();
	void random();
	void handleInput();
	void gamelife();
	void n_generation();
    void menu_action();
	void figures(int, const sf::Vector2i& mousePos);





};