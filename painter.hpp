#pragma once
#include "setting.hpp"
class Painter: public sf::Drawable{
private:
void     draw(sf::RenderTarget& target, sf::RenderStates states) const override;

std::vector< std::vector<sf::CircleShape> > circles;
std::vector<std::vector <int>> cells;
setting set;
public:
Painter(const setting& _set);
void update(const std::vector<std::vector<int>>&,const std::vector< std::vector<sf::CircleShape>>&);


};