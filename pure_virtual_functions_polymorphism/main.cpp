#include <iostream>
#include <vector>


// Pure virtual functions
class Shape{
private:

public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {}
};

class Open_shape : public Shape{
public:
    virtual ~Open_shape() {}
};

class Closed_shape : public Shape{
public:
    virtual ~Closed_shape() {}
};

class Line : public Open_shape{
public:
    virtual void draw() override{
        std::cout << "Drawing a line " << std::endl;
    }
    virtual void rotate() override{
        std::cout << "Rotating a line " << std::endl;
    }
    virtual ~Line() {}
};

class Circle : public Closed_shape{
public:
    virtual void draw() override{
        std::cout << "Drawing a circle " << std::endl;
    }
    virtual void rotate() override{
        std::cout << "Rotating a circle " << std::endl;
    }
    virtual ~Circle(){}
};

class Square : public Closed_shape{
public:
    virtual void draw() override{
        std::cout << "Drawing a square " << std::endl;
    }
    virtual void rotate() override{
        std::cout << "Rotating a square " << std::endl;
    }
    virtual ~Square(){}
};

void screen_refresh(const std::vector<Shape *> &shapes){
    std::cout << "Refreshing" << std::endl;
    for(const auto p:shapes){
        p->draw();
    }
}

int main(){

    //Shape *ptr = new Circle();
    //ptr->draw();
    //ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    std::vector<Shape *> shapes{s1,s2,s3};
    screen_refresh(shapes);

    delete s1;
    delete s2;
    delete s3;
}