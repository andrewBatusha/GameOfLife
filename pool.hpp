#include "setting.hpp"

class pool{
	private:
	std::vector < std::vector <sf::CircleShape> > circles;
	std::vector<sf::Color> color { sf::Color::Blue, sf::Color::Red, sf::Color(0, 204, 0), sf::Color(255, 153, 0)};
	setting set;
	public:
	pool(const setting& _set);
	sf::Color colorNeighborsCount(int row, int col);
	void set_generation_color(std::vector< std::vector <sf::CircleShape> >&);
	void random(int,int);
	void workcolor(int, int);
	void classic_all();
	void change_color();
	std::vector < std::vector <sf::CircleShape>>& get_circles();


};