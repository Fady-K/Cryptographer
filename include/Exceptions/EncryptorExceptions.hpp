/**
 * @file EncryptorExceptions.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;


class EncryptorExceptions: public exception
{
    /* Instance Attributes */
protected:
    string m_Message;
    

    /* Constructor and destructor */
public:
    EncryptorExceptions();                              // Default constructor
    EncryptorExceptions(string t_message);              // Paramterized constructor
    ~EncryptorExceptions();                             // Destructor


    // override what function
    virtual const char* what() const;
};

