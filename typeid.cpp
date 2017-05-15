#include <algorithm>
#include <list>
#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>

class Shape {
    public: virtual ~Shape(){}
};

class Circle : public Shape {
};

class Rectangle : public Shape {
};

int main()
{
    // Create a list containing integers
    std::list<Shape*> shape_list;

    Circle c;
    Rectangle r;
    shape_list.push_back(&c);
    shape_list.push_back(&c);
    shape_list.push_back(&r);

    int s_num = 0, c_num = 0, r_num = 0;
    std::list<Shape*>::iterator it = shape_list.begin();
    while (it != shape_list.end()) {
        if (typeid(**it) == typeid(Shape)) {
            s_num++;
        }

        if (typeid(**it) == typeid(Circle)) {
            c_num++;
        }

        if (typeid(**it) == typeid(Rectangle)) {
            r_num++;
        }

        it++;
    }

    std::cout << "s_num: " << s_num << ", c_num: " << c_num << ", r_num: " << r_num << std::endl;


    s_num = 0, c_num = 0, r_num = 0;
    it = shape_list.begin();
    while (it != shape_list.end()) {
        Circle* c = dynamic_cast<Circle*>(*it);
        if (c != NULL) {
            c_num++;
        }

        Rectangle* r = dynamic_cast<Rectangle*>(*it);
        if (r != NULL) {
            r_num++;
        }

        it++;
    }

    std::cout << "s_num: " << s_num << ", c_num: " << c_num << ", r_num: " << r_num;
}
