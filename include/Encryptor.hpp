/**
 * @file Encryptor.hpp
 * @author Fady Kamal (popfadykamal151617@gmail.com)
 * @brief Header file holding the Encryptor class
 * @version 0.1
 * @date 2023-01-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;


/**
 * @brief Encryptor class
 */

class Encryptor
{
    /* Instance Attributes  */
protected:
    string m_OriginalSenctence;
    string m_EncryptedSenctence;
    bool m_IsEncrypted;
    

    /* Static Attributes (Related to the class only (has no relation with any object) */
    static int m_NoEncryptors;
    static int m_NoCurrentEncyptors;


    /* Big 5 InAddition to (parametrized constructors) */
public:
    Encryptor();                                // Default constructor
    Encryptor(string t_sentence);              // Parametrized constructor
    Encryptor(const Encryptor &);               // Copy constructor
    Encryptor& operator= (const Encryptor &);   // Copy assignment operator
    // Encryptor(Encryptor &&);                    // Move costructor
    // Encryptor& operator=(Encryptor &&);         // Move assignment operator
    ~Encryptor();                               // Destructor


    /* Instance Methods (Setter and Getters) */
    void SetSentenceToEncrypt(string t_senctence);
    string GetOriginalSenctence();

    string GetEncryptedSentence();

    bool IsSentenceGotEncrpyted();


    /* Ciphers */
    string EncryptUsingAffineCipher(string t_sentenceToGetEncrypted);                   // Affine Cipher
    void EncryptUsingAffineCipher();                                                    // An overloaded version to encrypt a given sentence

    string EncryptUsingAtpashCipher(string t_sentenceToGetEncrypted);
    void EncryptUsingAtpashCipher();

    string EncryptUsingBaconianCipher(string t_sentenceToGetEncrypted);
    void EncryptUsingBaconianCipher();

    string EncryptUsingCaesarCipher(string t_sentenceToGetEncrypted);
    void EncryptUsingCaesarCipher();

    string EncryptUsingMorseCode(string t_sentenceToGetEncrypted);
    void EncryptUsingMorseCode();

    string EncryptUsingSimpleSubstitutionCipher(string t_sentenceToGetEncrypted);
    void EncryptUsingSimpleSubstitutionCipher();

    string EncryptUsingVignereCipher(string t_sentenceToGetEncrypted);
    void EncryptUsingVignereCipher();


    /* Static Methods (Related To Class only) */
    static int GetTotalNumberOfEncryptorThisClassMade();
};
