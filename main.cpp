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
#include "src\Decryptor.cpp"
using namespace std;

int main()
{   
    // // // testing constructors 
    // // Encryptor e1("hello from the other side");
    // // Encryptor e2("hello from the other side");
    // // Encryptor e3("hello from the other side");
    // // Encryptor e34;


    // Decryptor d1("hello");
    // Decryptor d2("decrytpr");
    // Decryptor d3("akcodfadf");
    // Decryptor d4(d1);

    // // cout << "TotalNumber of encryptors: " << Encryptor::GetTotalNumberOfObjectsThisClassMade() << endl;
    // // cout << "CurrentNumber of encryptors: " << Encryptor::GetTotalNumberOfAliveObjects() << endl;



    // // Decryptor d4;
    // // Encryptor e345;

    // cout << "TotalNumber of decryptors: " << Decryptor::GetTotalNumberOfObjectsThisClassMade() << endl;
    // cout << "CurrentNumber of decryptors: " << Decryptor::GetTotalNumberOfAliveObjects() << endl;

    // // cout << "TotalNumber of encryptors: " << Encryptor::GetTotalNumberOfObjectsThisClassMade() << endl;
    // // cout << "CurrentNumber of encryptors: " << Encryptor::GetTotalNumberOfAliveObjects() << endl;

    // Testing all ciphers
    
    // affince cipher decryption
    Decryptor d("TENNC JRCS BTE CBTE WYZE");

    // corret output: hello from the other side
    d.AffineCipher();

    // show 
    cout << d.GetDecryptedSentence() << endl;

    return 0;
}