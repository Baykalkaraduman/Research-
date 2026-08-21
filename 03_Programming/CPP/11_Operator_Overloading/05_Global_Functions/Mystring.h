#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);       // We are defining this previous member functions as global functions
    friend Mystring operator-(const Mystring &obj);                         // Since they are not member they need variables 
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);    // You can use friend lines anywhere you like 
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring();                                                          // No-args constructor
    Mystring(const char *s);                                      // Overloaded constructor
    Mystring(const Mystring &source);                     // Copy constructor
    Mystring( Mystring &&source);                          // Move constructiror
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);    // Copy assignment
    Mystring &operator=(Mystring &&rhs);          // Move assignment
    
    void display() const;

    int get_length() const;                                        // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_
