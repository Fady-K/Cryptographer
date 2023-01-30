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
    // Encryptor e("hello from the other side00");

    // // corret output: hello from the other side
    // e.MorseCode();

    // // // test atpash cipher
    // // e.AtpashCipher();

    // // // test Baconian cipher
    // // e.BaconianCipher();

    // // // ceasar cipher generic version
    // // e.CaesarCipher();

    // // // with another shift
    // // e.CaesarCipher(21);

    // // // testing morse code
    // // e.MorseCode();

    // // // generic version
    // // e.SimpleSubstitutionCipher("hello");

    // // // generic version
    // // e.VignereCipher("hello");
    // // // show 
    // cout << e << endl;

    //////////////////////////////////
    /* testing Decrypting ciphers */
   ///////////////////////////////////

   /*
        Main Testing

        1. test key or any decoding credentials
        2. test decoding using an approved coded and decoded string
        3. 

   */

   // Instantiate object from Decryptor class
   Decryptor d;
   cin >> d;

    /* Testing affine cipher 

        * affine cipher decrypts via a and b
        * a valid range 0: 25
        * b valid values {1, 3, 5, 7, 9, 11, 15, 17, 19, 20, 21}
    */

    // d.AffineCipher(-1, -5);
    // d.AffineCipher(1, 5);
    cout << d << endl;


    
    


    return 0;
}