#ifndef CIRCLE_H
#define CIRCLE_H


class Circle{

private:
    int radius{};

public:
    void set_radius(int value){radius = value;}
    void print_values();

};

#endif