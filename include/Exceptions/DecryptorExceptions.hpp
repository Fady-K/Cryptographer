#pragma once
#include <iostream>
#include <exception>
using namespace std;

class DecryptorExceptions
{
    /* Instance Attributes */
protected:
    string m_Message;



public:
    DecryptorExceptions();                      // Default constructor
    DecryptorExceptions(string t_messsge);      // Parametrized constructor
    ~DecryptorExceptions();                     // Destructor


    /* Instance methods */
    virtual const char* what() const noexcept;
};
