#include "LinkedListV3.h"
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
  {
    // Test for destructing empty
    LinkedList empty;
  }
  {
    // Test for destructing single item
    LinkedList single;
    single.push_back(10);
  }
  std::cout << '\n';
  LinkedList values;
  int value;
  values.print();
  values.print_reverse();
  datafile >> value;
  while (datafile) {
    values.push_back(value);
    datafile >> value;
  }
  datafile.close();
  std::cout << "Printing Forward:\n";
  values.print();

  std::cout << "\nPrinting Reversed:\n";
  values.print_reverse();
}