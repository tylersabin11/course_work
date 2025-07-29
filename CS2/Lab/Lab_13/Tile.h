#ifndef TILE_H
#define TILE_H

class Tile{
private:
    //Tile data member
    char m_Tile{};

public:
    //Update the tile data member
    void update_tile(char value);
    //Get the value of the tile
    char get_tile(){return m_Tile;}
};

#endif