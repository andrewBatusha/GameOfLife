#include "painter.hpp"

Painter::Painter(const setting& _set): set(_set) {}
void Painter::update(const std::vector<std::vector<int>>& _cells,const std::vector< std::vector <sf::CircleShape> >& _circles)
{
    cells = _cells;
	circles = _circles;
}

void Painter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for( int row = 0; row < cells.size(); row++ )
    {
        for( int col = 0; col < cells[row].size(); col++)
    	{
        	if(cells[row][col])
        	{
            	target.draw(circles[row][col], states);
        	}
    	}
	}
}