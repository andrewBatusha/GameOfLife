#include "cell.hpp"

cell::cell(const setting& _set): set(_set){
  generation.assign(set.h_row, std::vector<int>(set.h_col, 0));
}
void cell :: random()
        {
            for(auto& i: generation)
                for(auto& j : i)
                    j = rand()%2 + 0;
        }

int cell :: countNeighbour(int x, int y){
	int neighbour = 0;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
         int col = (y + i + set.h_col) % set.h_col;
         int row = (x + j + set.h_row) % set.h_row;
         neighbour += generation[row][col];
        }
    }
    neighbour -= generation[x][y];
	return neighbour;
}

int cell::get_cell(int row, int col){
	return generation[row][col];
}
void cell::set_cell(int row, int col, int value){
    generation[row][col] = value;
}

void cell::set_generation(std::vector< std::vector <int> >&_generation){
    generation = _generation;
}
std::vector<std::vector<int>>& cell::get_generation(){
    return generation;
}
void cell::clear(){
    for(auto& i: generation)
        for(auto& j : i)
           j = 0;
}