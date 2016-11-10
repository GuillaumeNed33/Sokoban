#ifndef MAPSELECTION_H
#define MAPSELECTION_H
#include "View.h"


class MapSelection : public View
{
private:
    const std::string BACKGROUND_IMAGE = "Images/fond.png";
    const std::string SELECTOR = "Images/player.png";

    bool m_nextStep = true;
    int m_level = 1;
    sf::Sprite m_background;
    sf::Texture m_textureFond;

    sf::Sprite m_selector;
    sf::Texture m_textureSelect;

    sf::Font m_font;
    std::string m_levelInfo1 = "Niveau 1 (Facile)";
    sf::Text m_info1;
    std::string m_levelInfo2 = "Niveau 2 (Moyen)";
    sf::Text m_info2;
    std::string m_levelInfo3 = "Niveau 3 (Difficile)";
    sf::Text m_info3;

public:
    MapSelection(sf::RenderWindow* window);
    virtual ~MapSelection();
    bool treatEvents() override;
    void draw() override;
    void synchronize() override;
    bool getNextStep() const;
    int getLevel() const;
};

#endif // MAPSELECTION_H
