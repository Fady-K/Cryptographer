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
#include <limits>
#include <cstring>
#include <algorithm>
#include <cmath>
#include "Exceptions/EncryptorExceptions.hpp"
using namespace std;


class Encryptor
{
    /* Instance Attributes  */
protected:
    string m_Id;
    string m_OriginalSenctence;
    string m_EncryptedSenctence;
    string m_UsedCipher;
    bool m_IsEncrypted;
    

    /* Static Attributes (Related to the class only (has no relation with any object) */
    static int m_NoObjects;
    static int m_CurrentNoObjects;


    /* Big 5 InAddition to (parametrized constructors) */
public:
    Encryptor();                                // Default constructor
    Encryptor(string t_sentence);               // Parametrized constructor
    Encryptor(const Encryptor &);               // Copy constructor
    Encryptor& operator= (const Encryptor &);   // Copy assignment operator
    // Encryptor(Encryptor &&);                    // Move costructor
    // Encryptor& operator=(Encryptor &&);         // Move assignment operator
    ~Encryptor();                               // Destructor


    /* Instance Methods (Setter and Getters) */
    inline void SetSentence(string t_senctence);
    inline string GetOriginalSenctence() const;

    inline string GetEncryptedSentence() const;
    inline string GetUsedCipher() const;
    inline string GetId() const;

    inline bool IsSentenceGotEncrpyted() const;


    /* Ciphers */
    string AffineCipher(string t_sentenceToGetEncrypted) const;                   // Affine Cipher
    void AffineCipher();                                                    // An overloaded version to encrypt a given sentence

    string AtpashCipher(string t_sentenceToGetEncrypted) const;
    void AtpashCipher();

    string BaconianCipher(string t_sentenceToGetEncrypted) const;
    void BaconianCipher();

    string CaesarCipher(string t_sentenceToGetEncrypted) const;
    void CaesarCipher();

    string MorseCode(string t_sentenceToGetEncrypted) const;
    void MorseCode();

    string SimpleSubstitutionCipher(string t_sentenceToGetEncrypted) const;
    void SimpleSubstitutionCipher();

    string VignereCipher(string t_sentenceToGetEncrypted) const;
    void VignereCipher();



    /* Static Methods (Related To Class only) */
    static int GetTotalNumberOfObjectsThisClassMade();
    static int GetTotalNumberOfAliveObjects();
    static string GenerateId(int totalNumberOfEncryptors); 


    /* Helper functions */
private:
    long Mod(int a, int b) const;
    void ModifyAlphabet(string &t_modifiedAlphabet, string t_alphabet, string &t_key) const;
};

