#ifndef TILE_H
#define TILE_H

class Tile{
private:
    //Tile data member
    char m_Tile{};
    //Play Board data member
    char m_PlayBoard{};

public:
    //Update the tile data member
    void update_tile(char value);
    //Get the value of the tile
    char get_tile();

    void update_piece(char value);
    char get_piece();
};

#endif