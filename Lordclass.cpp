#include "Lordclass.hpp"

Lordclass::Lordclass(const setting& _set):
gen_counter(0),
set(_set),
window({_set.windowWidth, _set.windowHeight}, "Conway's Game of Life", sf::Style::Fullscreen),
Cell(_set),
Pool(_set),
painter(_set)
{
    random();
    sf::Image icon32;
    sf::Image icon16;
    icon32.loadFromFile("content/icon_32.jpg");
    icon16.loadFromFile("content/icon_16.jpg");
    window.setIcon(32,32,icon32.getPixelsPtr());
    window.setIcon(16,16,icon16.getPixelsPtr());
	font.loadFromFile("content/Lato-Black.ttf");
    counter.setFont(font);
    counter.setFillColor(sf::Color::White);
    counter.setOutlineColor(sf::Color::Black);
    counter.setOutlineThickness(2);
    counter.setCharacterSize(15);
    counter.setPosition(5, 5);
}

void Lordclass::run(){
	while(window.isOpen())
    {
        menu.draw(window);
        menu_action();
    }
}
void Lordclass::menu_action(){
    sf::Event e;
    while(window.pollEvent(e))
    {
        if(e.type == sf::Event::Closed)
            window.close();
        if(e.type == sf::Event::MouseButtonPressed)
            if(e.mouseButton.button == sf::Mouse::Left)
                switch(menu.get_item())
                {
                    case 0:
                        gamelife();
                        break;
                    case 1:
                        menu.navigation(window, 1);
                        break;
                    case 2:
                        menu.navigation(window, 2);
                        break;
                    case 3:
                        window.close();
                        break;
                    default:
                        break;
                }
        if (e.type == sf::Event::KeyPressed)
    {
      if (e.key.code == sf::Keyboard::Key::Escape)
        window.close();
      if (e.key.code == sf::Keyboard::Key::Up)
      {
        menu.MenuUp();
      }
      if (e.key.code == sf::Keyboard::Key::Down)
      {
        menu.MenuDown();
      }
      if (e.key.code == sf::Keyboard::Key::Return)
      {
        switch (menu.get_item())
        {
        case 0:
          gamelife();
          break;
        case 1:
          menu.navigation(window, 1);
          break;
        case 2:
          menu.navigation(window, 2);
          break;
        case 3:
          window.close();
          break;
        default:
          break;
        }
      }
    }
  }
}
void Lordclass::gamelife(){
    while(window.isOpen()){
        handleInput();
        n_generation();
        draw();
    }
}
void Lordclass::handleInput()
{
    sf::Event e;
    while(window.pollEvent(e))
    {
        if(e.type == sf::Event::Closed)
            window.close();

        if(e.type == sf::Event::MouseButtonPressed)
        {
            if(e.mouseButton.button == sf::Mouse::Left){
                for(int row = 0; row < set.h_row; row++)
                    for(int col = 0; col < set.h_col; col++)
                    {
                        sf::Vector2i pos(col * set.cellSize, row * set.cellSize);
                        sf::Vector2i size(set.cellSize, set.cellSize);
                        if(sf::IntRect(pos, size).contains(sf::Mouse::getPosition(window)))
                        {
                        if(Cell.get_cell(row, col))
                            Cell.set_cell(row, col, 0);
                        else
                        {
                            Cell.set_cell(row, col, 1);
                            Pool.workcolor(row, col);
                            }

                        }
                    }
            }
            if(e.mouseButton.button == sf::Mouse::Right){
                Pool.change_color();
            }
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Space)
        {
            set.draw = !set.draw;
        }
         if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::R)
        {
            random();
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::C)
        {

            set.draw = false;
            Cell.clear();
            Pool.classic_all();
            gen_counter = 0;
            counter.setString("Generation:" + std::to_string(0));

        }
         if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape)
        {
            run();
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Right)
        {
            set.draw = true;
            n_generation();
            draw();
            set.draw = false;
        }

        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num0)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(0, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num1)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(1, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num2)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(2, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num3)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(3, mousePos);

        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num4)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(4, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num5)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(5, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num6)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(6, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num7)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(7, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num8)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(8, mousePos);
        }
        if(e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Num9)
        {
            sf::Vector2i mousePos = mouse.getPosition(window);
            figures(9, mousePos);
        }
    }
}
void Lordclass::n_generation(){
    if(set.draw){
		gen_counter++;
        counter.setString("Generation:" + std::to_string(gen_counter));
		std::vector< std::vector <int> > New;
        std::vector< std::vector <sf::CircleShape> > new_c;
        New.assign(set.h_row, std::vector<int>(set.h_col, 0));
        //new_c.assign(set.h_row, std::vector<sf::CircleShape>(set.h_col));
        new_c = Pool.get_circles();
        for(int row = 0; row < New.size(); row++)
            for(int col = 0; col < New[row].size(); col++)
            {
                int count = Cell.countNeighbour(row, col);
                if(Cell.get_cell(row, col))
                {
                    if(count < 2 || count > 3)
                    {
                        New[row][col] = 0;
                        new_c[row][col].setFillColor(set.backgroundColor);
                    }
                    else
                        New[row][col] = 1;
                }
                else if(!Cell.get_cell(row, col))
                {
                    if(count == 3){
                        New[row][col] = 1;
                        sf::Color born = Pool.colorNeighborsCount(row,col);
                        new_c[row][col].setFillColor(born);
                    }
                    else{
                        New[row][col] = 0;
                    }
                }
            }
        Cell.set_generation(New);
        Pool.set_generation_color(new_c);
    }

    painter.update(Cell.get_generation(), Pool.get_circles());
}
void Lordclass::draw()
{
    // Clearing the window
   window.clear(set.backgroundColor);

   window.draw(painter);

   window.draw(counter);

    // Internally swapping buffers
    window.display();
}

void Lordclass::figures(int i,const sf::Vector2i& mousePos){
    std::ifstream in;
        switch(i)
        {
        case 1:
            in.open("content/figures/glindergun.txt");
            break;
        case 2:
            in.open("content/figures/spacefiller1.txt");
            break;
        case 3:
            in.open("content/figures/spacefiller2.txt");
            break;
        case 4:
            in.open("content/figures/oscillator1.txt");
            break;
        case 5:
            in.open("content/figures/galaxy.txt");
            break;
        case 6:
            in.open("content/figures/glinder.txt");
            break;
        case 7:
            in.open("content/figures/wave.txt");
            break;
        case 8:
            in.open("content/figures/idk.txt");
            break;
        case 9:
            in.open("content/figures/idk2.txt");
            break;
        case 0:
            in.open("content/figures/id3.txt");
            break;
        default:
            break;
        }
    std::size_t row = 0, col = 0;
    char c;
    while(!in.eof()){
        c = in.get();
        if( c == 'O' && row+mousePos.y/set.cellSize < Cell.get_generation().size() && col+mousePos.x/set.cellSize < Cell.get_generation()[0].size()){
            Cell.set_cell(row+mousePos.y/set.cellSize, col+mousePos.x/set.cellSize, 1);
            Pool.workcolor(row+mousePos.y/set.cellSize, col+mousePos.x/set.cellSize);
        }
       else if(c == '.' && row+mousePos.y/set.cellSize < Cell.get_generation().size() && col+mousePos.x/set.cellSize < Cell.get_generation()[0].size())
            Cell.set_cell(row+mousePos.y/set.cellSize, col+mousePos.x/set.cellSize, 0);
        col++;
        if(c == '\n'){
            row++;
            col = 0;
        }
    }
    in.close();
                painter.update(Cell.get_generation(), Pool.get_circles());
                window.draw(painter);
}
void Lordclass::random(){
    Cell.random();
            for(int row = 0; row < Cell.get_generation().size(); row++)
                for(int col = 0; col < Cell.get_generation()[row].size(); col++)
                    if(Cell.get_cell(row,col))
                        Pool.random(row,col);
                gen_counter = 0;
                painter.update(Cell.get_generation(), Pool.get_circles());
                window.draw(painter);
}