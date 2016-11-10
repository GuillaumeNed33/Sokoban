#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 450;

class Application
{
private:
    const std::string ICON = "Images/icone.png";
    sf::RenderWindow* m_window;
    sf::Image m_icon;
public:
    Application();
    ~Application();
    void run();
};

#endif // APPLICATION_H
