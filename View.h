#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class View
{
protected:
    const std::string SOUND = "Sounds/musique.wav";
    sf::RenderWindow* m_window;
    static sf::Music m_music;
    static bool m_charge;
public:
    View(sf::RenderWindow* window);
    virtual ~View();
    virtual void draw() = 0;
    virtual void synchronize() = 0;
    virtual bool treatEvents() = 0;
};

#endif // VIEW_H_INCLUDED
