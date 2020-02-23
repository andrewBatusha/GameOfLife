#include "menu.hpp"
#include <SFML\Graphics\Rect.hpp>
Menu::Menu(){

	shrift.loadFromFile("content/Lato-Black.ttf");
	vibor[0].setFont(shrift);
	vibor[0].setString(" Play ");
	vibor[1].setFont(shrift);
	vibor[1].setString(" Rules ");
	vibor[2].setFont(shrift);
	vibor[2].setString(" Controls ");
	vibor[3].setFont(shrift);
	vibor[3].setString(" Exit ");

	item = 0;
	backgroundTexture.loadFromFile("content/var1.jpg");
	nav.setFont(shrift);
	nav.setCharacterSize(40);
	nav.setOutlineThickness(1.0);
	nav.setFillColor(sf::Color::White);
	nav.setString("Mouse:\nClick cell to change it to alive/dead\nClick left mouse button to change a color\nKeyboard:\nPress <Space> to pause and be able to draw\nPress < -> > to go to next generation\nPress <C> to clear the grid\nPress <0-9> to build a figures\nPress <R> to randomize the grid\nPress<Escape> to back to menu");

	rule.setFont(shrift);
	rule.setCharacterSize(25);
	rule.setOutlineThickness(1.0);
	rule.setFillColor(sf::Color::White);
	rule.setString("The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells,\n each of which is in one of two possible states, alive or dead.\nEvery cell interacts with its eight neighbours.\nAt each step in time, the following transitions occur:\nAny live cell with fewer than two live neighbours dies, as if by underpopulation.\nAny live cell with two or three live neighbours lives on to the next generation.\nAny live cell with more than three live neighbours dies, as if by overpopulation.\nAny dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\nThe rules continue to be applied repeatedly to create further generations.\n\nThe color of a cell is determined by its genes transmitted to it by its parents");

	back.setFont(shrift);
	back.setCharacterSize(60);
	back.setOutlineThickness(1.0);
	back.setFillColor(sf::Color::White);
	back.setString("back to menu");

	title.setFont(shrift);
	title.setCharacterSize(60);
	title.setOutlineThickness(1.0);
	title.setFillColor(sf::Color::White);
	title.setString("Game of Life");
}
void Menu::draw(sf::RenderWindow & window)
{
	window.clear(sf::Color::White);

	int with = window.getSize().x;
	int height = window.getSize().y;

	scaleX = (float)with / backgroundTexture.getSize().x;
	scaleY = (float)height / backgroundTexture.getSize().y;

	background.setTexture(backgroundTexture);
	background.setScale(scaleX,scaleY);

	window.draw(background);

	vibor[0].setPosition(with/2 , height /2 -  60);
	vibor[1].setPosition(with/2 , height /2 + 0 * 60);
	vibor[2].setPosition(with/2 , height /2 + 1 * 60);
	vibor[3].setPosition(with/2 , height /2 + 2 * 60);
	if(sf::IntRect(with/2 - 180, height /2 - 20 - 1 * 60, 300, 40).contains(sf::Mouse::getPosition(window)))
	item = 0;
	else if(sf::IntRect(with/2 - 180, height /2 - 20 - 0 * 60, 300, 40).contains(sf::Mouse::getPosition(window)))
	item = 1;
	else if(sf::IntRect(with/2 - 180, height /2 - 20 + 1 * 60, 300, 40).contains(sf::Mouse::getPosition(window)))
	item = 2;
	else if(sf::IntRect(with/2 - 180, height /2 - 20 + 2 * 60, 300, 40).contains(sf::Mouse::getPosition(window)))
	item = 3;

	for( int i = 0; i < 4; i++)
	{
		if(i == item)
		{
			vibor[i].setFillColor(sf::Color::Green);
			vibor[i].setStyle(sf::Text::Bold | sf::Text::Underlined);
		}
		else
		{
			vibor[i].setFillColor(sf::Color::White);
			vibor[i].setStyle(sf::Text::Bold);
		}

		sf::FloatRect textRect = vibor[i].getLocalBounds();
		vibor[i].setOrigin(textRect.left +textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		vibor[i].setCharacterSize(40);
		vibor[i].setOutlineThickness(1.0f);

		window.draw(vibor[i]);
	}

	title.setPosition(with/2 , 80);
	sf::FloatRect textRect = title.getLocalBounds();
	title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height/2.0f);
	window.draw(title);


	window.display();
	}
void Menu::navigation(sf::RenderWindow &window, int i)
{
  int with = window.getSize().x;
  int height = window.getSize().y;
  while (window.isOpen())
  {
    window.clear(sf::Color::White);
	 sf::Event e;
    while (window.pollEvent(e))
    {
      //Exit to menu
      if (e.type == sf::Event::KeyPressed)
        if (e.key.code == sf::Keyboard::Key::Escape)
          return;
      if (e.type == sf::Event::MouseButtonPressed)
        if (e.mouseButton.button == sf::Mouse::Left)
          if (sf::IntRect(with / 2 - 150, height - 100, 300, 40).contains(sf::Mouse::getPosition(window)))
            return;
    }

    scaleX = (float)with / backgroundTexture.getSize().x;
    scaleY = (float)height / backgroundTexture.getSize().y;
    background.setTexture(backgroundTexture);
    background.setScale(scaleX, scaleY);
    window.draw(background);

		sf::FloatRect textRect;
		if (i == 1){
		rule.setPosition(with / 2, height / 2);
    textRect = rule.getLocalBounds();
    rule.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.5f);
		}
		else if (i == 2){
    nav.setPosition(with / 2, height / 2);
    textRect = nav.getLocalBounds();
    nav.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		}

    back.setPosition(with / 2, height - 80);
    textRect = back.getLocalBounds();
    back.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    if (sf::IntRect(with / 2 - 200, height - 100, 400, 40).contains(sf::Mouse::getPosition(window)))
    {
      back.setFillColor(sf::Color::Red);
      back.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
    else
    {
      back.setFillColor(sf::Color::White);
      back.setStyle(sf::Text::Bold);
    }

    window.draw(back);
		if(i == 1)
    window.draw(rule);
		else if(i == 2)
		window.draw(nav);

    window.display();
  }
}

void Menu::MenuUp()
{
  if (item > 0)
    item--;
}

void Menu::MenuDown()
{
  if (item < 3)
    item++;
}

int Menu::get_item() const
{
  return item;
}