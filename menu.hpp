#pragma once

class Menu{
public:
Menu();

void MenuUp();
void MenuDown();
void draw(sf::RenderWindow &window);
int get_item() const;
void navigation(sf::RenderWindow &window, int i);
private:
sf::Text vibor[4], back, nav, title, rule;
sf::Font shrift;
sf::Texture backgroundTexture;
sf::Sprite background;
std::size_t item;
float scaleX, scaleY;

};