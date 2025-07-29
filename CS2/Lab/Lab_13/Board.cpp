#include <iostream>
#include "board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Tile.h"


//Loop through the array, and set the index to 0
//Initialize mine_count to 10
Board::Board(int width, int height){
    m_width = width;
    m_height = height;
    m_size = m_width * m_height;
    tile = new Tile[m_size];

    for(int i{0}; i < m_size; i++){
        tile[i].update_tile('0');
    }

    mine_count = 10;
}

void Board::place_mines(){
    //Seed the random number generator 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for(int i{0}; i < mine_count; i++){
        //Produce a random index
        int index = std::rand() % m_size;

        //Check to see if the index is already a mine
        if(tile[index].get_tile() != 'M'){
            //If a mine is not present, place the mine
            tile[index].update_tile('M');
        } else{
            //If no mine is placed, subtract one
            //As we did not place a mine
            i--;
        }
    }
    
}

//Loop through the array, print out the index
void Board::revealed_board(){

    //index = width * row + column

    for(row){
        for(col){
            //index = width * row + column
            // tile[index].print()
        }
    }
    for(int i{0}; i < m_size; i++){
        if(i % m_width == 0 && i != 0){
            std::cout << '\n';
        }
        std::cout << std::setw(2) << tile[i].get_tile() << ' ' ;
    }
    std::cout << '\n';
}

void Board::update_counts(){
    int row{-1};
    int col{0};
    int count{0};
    for(int index{0}; index < m_size; index++){
        if(index % m_width == 0){
            row++;
        }
        //index = width * row + column
        if(tile[index].get_tile() != 'M'){
        //if row is 0
            if(row == 0){
                //if col is 0
                if(col == 0){
                        //check index + m_width, index + m_width + 1, index + 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                    }
                //else if col is (m_width - 1) 
                else if(col == (m_width -1)){
                    //check index + m_width, index + m_width - 1, index -1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else
                else{
                    //check index +/- 1, index + m_width, index + m_width +/- 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
            }
            //else if row is (m_height - 1)
            else if(row == (m_height - 1)){
                //if col is 0 
                if(col == 0){
                    //check index - m_width, index - m_width + 1, index + 1
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else if col is (m_width - 1)
                else if(col == (m_width - 1)){
                    //check index - m_width, index - m_width - 1, index -1
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else
                else{
                    //check index +/- 1, index - m_width, index - m_width +/- 1
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
            }
            //else
            else{
                //if col is 0
                if(col == 0){
                    //check index +/- m_width, index +/- m_width + 1, index + 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else if col is (m_width - 1)
                else if(col == (m_width - 1)){
                    //check index +/- m_width, index +/- m_width - 1, index -1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else
                else{
                    //check index +/- m_width, index +/- m_width +/- 1, index +/- 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width].get_tile() == 'M'){count + 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
            }
        }
        if(col == (m_width - 1)){
            col = 0;
            count = 0;
        }else{
            col++;
            count = 0;
        }
    }
}               