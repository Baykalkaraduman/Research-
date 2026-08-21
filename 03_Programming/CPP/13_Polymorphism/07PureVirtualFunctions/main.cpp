/**
 * ============================================================================
 * FILE: abstract_classes_and_pure_virtuals.cpp
 * DESCRIPTION: 
 * Demonstrates the use of Pure Virtual Functions and Abstract Base Classes (ABCs).
 * It shows how ABCs define interfaces that force derived concrete classes to 
 * implement specific behaviors, guaranteeing a uniform polymorphic interface.
 * ============================================================================
 */

#include <iostream>
#include <vector>

/**
 * ============================================================================
 * CLASS: Shape (Abstract Base Class / Interface)
 * Because it contains at least one pure virtual function, it becomes abstract.
 * You CANNOT instantiate an object of type Shape directly.
 * ============================================================================
 */
class Shape {           
private:
    // Attributes common to all shapes could go here (e.g., color, position)
public:
    // Pure virtual functions (denoted by '= 0').
    // They act as a strict contract: Any concrete derived class MUST implement these.
    virtual void draw() = 0;   
    virtual void rotate() = 0;   
    
    // Virtual destructor is mandatory for proper memory cleanup of derived classes
    virtual ~Shape() { }
};

/**
 * ============================================================================
 * INTERMEDIATE CLASSES: Open_Shape, Closed_Shape
 * These inherit from Shape but DO NOT implement the pure virtual functions.
 * Therefore, they remain Abstract Base Classes themselves.
 * ============================================================================
 */
class Open_Shape: public Shape {    
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  
public:
    virtual ~Closed_Shape() { };
};

/**
 * ============================================================================
 * CONCRETE CLASSES: Line, Circle, Square
 * These classes inherit from the intermediate abstract classes and provide 
 * implementations for EVERY pure virtual function. They can be instantiated.
 * ============================================================================
 */
class Line: public Open_Shape {     
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};

/**
 * ============================================================================
 * FUNCTION: screen_refresh
 * Demonstrates polymorphic rendering. It accepts a vector of Base pointers.
 * It doesn't care what the actual shapes are, as long as they fulfill the 
 * 'Shape' contract (i.e., they have a draw() method).
 * ============================================================================
 */
void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    // Dynamic binding at work: Calls the correct draw() for each concrete object
    for (const auto p: shapes) 
        p->draw();
}

int main() {
    
    // =========================================================
    // COMPILER ERRORS (Abstract Classes cannot be instantiated)
    // =========================================================
    // Shape s;                     // ERROR: Shape is abstract
    // Shape *p = new Shape();      // ERROR: Shape is abstract
    
    // Circle c;                    // This is perfectly valid (Concrete Class)
    // c.draw();

    // =========================================================
    // DYNAMIC POLYMORPHISM IN ACTION
    // =========================================================
    // Base pointers pointing to Concrete Derived objects
    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    // Storing them in a uniform polymorphic collection
    std::vector<Shape *> shapes {s1, s2, s3};
        
    // Passing the collection to a generic function
    screen_refresh(shapes);
    
    // Memory cleanup (Calling the virtual destructors)
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}