#ifndef GELI_THESIS_PLAYER
#define GELI_THESIS_PLAYER

class Player
{
public:
    Player():
        m_width(60),
        m_height(60),
        m_posX(20),
        m_posY(20),
        m_velX1(0),
        m_velY1(0),
        m_velX2(0),
        m_velY2(0)
    {}

    int m_width;
    int m_height;

    float m_posX;
    float m_posY;
    float m_velX1;
    float m_velY1;
    float m_velX2;
    float m_velY2;
};

#endif
