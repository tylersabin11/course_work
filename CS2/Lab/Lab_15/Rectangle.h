#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{

private:
    int m_length{};
    int m_width{};
    int m_area{};

public:
    //Default constructor
    Rectangle();
    //Overloaded constructor
    Rectangle(int,int);
    //Accessors
    void get_length();
    void get_width();
    //Calculate the area
    void calculate_area(){m_area = m_length * m_width;}
    //Display info
    void display_info();

    bool operator == (Rectangle& rhs);
    bool operator != (Rectangle& rhs);
    bool operator < (Rectangle& rhs);
    bool operator > (Rectangle& rhs);
    bool operator <= (Rectangle& rhs);
    bool operator >= (Rectangle& rhs);
    void operator ++ ();
    void operator -- ();
};

#endif