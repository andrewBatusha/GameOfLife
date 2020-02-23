#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include "setting.hpp"

class cell{
private:
    std::vector <std::vector <int> > generation;
	setting set;
public:
	cell(const setting& _set);
	void random();
	void clear();
	void set_cell(int row, int col, int value);
	int countNeighbour(int, int);
	int get_cell(int, int);
	void  set_generation(std::vector< std::vector <int>>&);
	std::vector<std::vector<int>>& get_generation();
};


#endif // CELL_H_INCLUDED
