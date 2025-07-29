#include "Tile.h"
void Tile::update_tile(char value){
    m_Tile = value;
}
char Tile::get_tile(){
    return m_Tile;
}
void Tile::update_piece(char value){
    m_PlayBoard = value;
}
char Tile::get_piece(){
    return m_PlayBoard;
}