#ifndef HOME_H
#define HOME_H

#include "View.h"

class Home : public View
{
private:
    const std::string BACKGROUND_IMAGE = "Images/fd.jpg";
    sf::Sprite m_background;
    sf::Texture m_textureFond;
public:
    Home(sf::RenderWindow* window);
    virtual ~Home();
    bool treatEvents() override;
    void draw() override;
    void synchronize() override;
};

#endif // HOME_H
