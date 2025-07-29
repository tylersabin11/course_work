/*
Tyler Sabin
Section 004
Lab 18
In this lab we will continue to work with
Linked lists and make a find, and remove
function
*/

#include "LinkedListV2.h"
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
  int count{0};
  values.print();
  datafile >> value;
  while (datafile) {
    values.push_back(value);
    count++;
    datafile >> value;
  }
  datafile.close();
  values.print();
  values.remove(504); // remove the last item
  values.print();
  values.remove(667); // remove the first item
  values.print();
  values.remove(68); // remove a middle item
  values.print();
  values.remove(3);   // remove a non-existant item
  values.remove(441); // remove the last item
  values.remove(891); // remove another middle item
  values.remove(67);  // remove another front item
  values.print();
}