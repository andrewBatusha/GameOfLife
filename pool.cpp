#include "pool.hpp"
pool::pool(const setting& _set): set(_set)
{
    circles.assign(set.h_row, std::vector<sf::CircleShape>(set.h_col));
	for( int row = 0; row < circles.size(); row++ )
    {
                for( int col = 0; col < circles[row].size(); col++ )
                {
					circles[row][col].setPosition(col * set.cellSize, row * set.cellSize);
        			circles[row][col].setRadius(set.cellSize/2);
        			circles[row][col].setFillColor(set.backgroundColor);
				}
	}

}
std::vector < std::vector <sf::CircleShape> >& pool::get_circles(){
    return circles;
}

sf::Color pool::colorNeighborsCount(int row, int col) {
        int count_red = 0;
        int count_blue = 0;
        int count_brown = 0;
        int count_caramel = 0;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
             int new_col = (col + j + set.h_col) % set.h_col;
             int new_row = (row + i + set.h_row) % set.h_row;
                if(circles[new_row][new_col].getFillColor() == sf::Color::Red){
                    count_red++;
                }
                else if(circles[new_row][new_col].getFillColor() == sf::Color::Blue){
                    count_blue++;
                }
                else if(circles[new_row][new_col].getFillColor() == sf::Color(0, 204, 0)){
                    count_brown++;
                }
                else if(circles[new_row][new_col].getFillColor() == sf::Color(255, 153, 0)){
                    count_caramel++;
                }
        }
    }
    if (count_red >= 2)
         return sf::Color::Red;
    else if(count_blue >= 2)
        return sf::Color::Blue;
    else if(count_brown >= 2)
        return sf::Color(0, 204, 0);
    else if(count_caramel >= 2)
        return sf::Color(255, 153, 0);
    else
        return sf::Color(255, 51, 204);
}


void pool::workcolor(int row, int col){
    circles[row][col].setFillColor(set.cellColor);
}

void pool::classic_all(){
    for(auto& i: circles)
        for(auto& j: i)
            j.setFillColor (set.backgroundColor);
}

void pool::change_color(){
    if(set.cellColor == sf::Color::Red)
       set.cellColor = sf::Color::Blue;
    else if(set.cellColor == sf::Color::Blue)
       set.cellColor = sf::Color(0, 204, 0);
    else if(set.cellColor == sf::Color(0, 204, 0))
       set.cellColor = sf::Color(255, 153, 0);
    else if(set.cellColor == sf::Color(255, 153, 0))
        set.cellColor = sf::Color::Red;
}
void pool :: random(int row,int col)
        {
                int z = rand()%4 + 0;
                circles[row][col].setFillColor(color[z]);
        }
void pool::set_generation_color(std::vector< std::vector <sf::CircleShape> >&_circles){
    circles = _circles;
}