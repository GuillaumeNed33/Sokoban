#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "View.h"
#include "Player.h"
#include "Level.h"

class GameView : public View
{
private:
    const std::string BACKGROUND = "Images/fond.png";
    const std::string PLAYER = "Images/player.png";
    const std::string POKEBALL = "Images/poke.jpg";
    const std::string CHECK = "Images/check.png";
    const std::string SUCCESS = "Images/complete.png";
    const std::string WALL = "Images/wall.png";
    const std::string VICTORY = "Images/victory.png";

    int m_level;
    bool m_end = false;
    std::string m_mapName = "Map/";
    Level* m_map;
    Player* m_player;

    sf::Sprite m_background;
    sf::Sprite m_wall;
    sf::Sprite m_perso;
    sf::Sprite m_completeObj;
    sf::Sprite m_obj;
    sf::Sprite m_pokeball;
    sf::Sprite m_victory;

    sf::Texture m_textureFond;
    sf::Texture m_Textwall;
    sf::Texture m_Textperso;
    sf::Texture m_TextcompleteObj;
    sf::Texture m_Textobj;
    sf::Texture m_TextPokeball;
    sf::Texture m_TextVictory;

public:
    GameView(sf::RenderWindow* window, int level);
    virtual ~GameView();
    void draw() override;
    void synchronize() override;
    bool treatEvents() override;
    void loadImages();
    void reset();
};

#endif // GAMEVIEW_H
