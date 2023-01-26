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
    Decryptor d1("hello");

    // d1.DecryptUsingSimpleSubstitutionCipher();

    // /* Testing (Setters And Getters)*/
    // cout << "Id: " << d1.GetId() << endl;
    // cout << "Original Sentence: " << d1.GetOriginalSentence() << endl;
    // cout << "Decrypted Sentence: " << d1.GetDecryptedSentence() << endl;
    // cout << "Used Cipher: " << d1.GetUsedCipher() << endl;
    // cout << "Status of decryption: " << d1.IsGivenSentenceGotDecrypted() << endl;

    for (int i = 0; i < 100; ++i)
    {
        Decryptor d2("herafsd f");
    }

    cout << Encryptor::GetTotalNumberOfEncryptorsThisClassMade() << endl;

    return 0;
}
