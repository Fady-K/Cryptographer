/**
 * @file main.cpp
 * @author Fady Kamal (popfadykamal151617@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include "src\Encryptor.cpp"
using namespace std;

int main()
{   
    // testing constructors 
    Encryptor e1("hello from the other side");
    Encryptor e2("hello from the other side");
    Encryptor e3("hello from the other side");



    cout << Encryptor::GetTotalNumberOfEncryptorThisClassMade() << endl;

    return 0;
}