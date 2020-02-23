#include "setting.hpp"
#include "Lordclass.hpp"
int main()
{
    srand(time(NULL));
    setting set;
    std::vector<sf::VideoMode> availiableVideoModes;
    availiableVideoModes = sf::VideoMode::getFullscreenModes();
    set.windowWidth      = availiableVideoModes[0].width;
    set.windowHeight     = availiableVideoModes[0].height;
    set.cellSize = 7;
    set.backgroundColor  = sf::Color(204, 255, 255);
    set.cellColor        = sf::Color::Red;

    set.windowWidth  = set.windowWidth - set.windowWidth % set.cellSize;
    set.windowHeight = set.windowHeight - set.windowHeight % set.cellSize;
    set.h_row = set.windowHeight / set.cellSize;
    set.h_col = set.windowWidth / set.cellSize;
    set.draw = false;
    Lordclass app(set);
    app.run();
    return 0;
};