/*
Tyler Sabin
Section 004
Lab 17- Linked Lists
In this lab we are going to practice creating
functions for linked lists and get more practice
with pointers
*/

#include "LinkedList.h"
#include <fstream>
#include <iostream>

int main() {
  std::string filename;
  std::cout << "Enter a data file: ";
  std::cin >> filename;
  std::ifstream datafile;
  datafile.open(filename);
  if (!datafile) {
    std::cout << "ERROR: " << filename << " could not open...\n";
    return 0;
  }
  std::cout << '\n';
  LinkedList values;
  int value;
  char side;
  //int count{0};
  values.print();
  datafile >> side >> value;
  while (datafile) {
    if (side == 'f') {
      values.push_front(value);
    } else if (side == 'b') {
      values.push_back(value);
    }
    values.print();
    datafile >> side >> value;
  }

  datafile.close();
}