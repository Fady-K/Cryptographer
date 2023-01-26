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
<<<<<<< HEAD
#include "Exceptions/EncryptorExceptions.hpp"
=======
>>>>>>> b89f85aabbab48cf5c629157cc2b50c3d919990f
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
    static int m_NoEncryptors;
    static int m_NoCurrentEncyptors;


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
    inline void SetSentenceToEncrypt(string t_senctence);
    inline string GetOriginalSenctence() const;

    inline string GetEncryptedSentence() const;
    inline string GetUsedCipher() const;
    inline string GetId() const;

    inline bool IsSentenceGotEncrpyted() const;


    /* Ciphers */
    string EncryptUsingAffineCipher(string t_sentenceToGetEncrypted) const;                   // Affine Cipher
    void EncryptUsingAffineCipher();                                                    // An overloaded version to encrypt a given sentence

    string EncryptUsingAtpashCipher(string t_sentenceToGetEncrypted) const;
    void EncryptUsingAtpashCipher();

    string EncryptUsingBaconianCipher(string t_sentenceToGetEncrypted) const;
    void EncryptUsingBaconianCipher();

    string EncryptUsingCaesarCipher(string t_sentenceToGetEncrypted) const;
    void EncryptUsingCaesarCipher();

    string EncryptUsingMorseCode(string t_sentenceToGetEncrypted) const;
    void EncryptUsingMorseCode();

    string EncryptUsingSimpleSubstitutionCipher(string t_sentenceToGetEncrypted) const;
    void EncryptUsingSimpleSubstitutionCipher();

    string EncryptUsingVignereCipher(string t_sentenceToGetEncrypted) const;
    void EncryptUsingVignereCipher();





    /* Static Methods (Related To Class only) */
    static int GetTotalNumberOfEncryptorsThisClassMade();
    static int GetTotalNumberOfTheAliveEncryptors();
    static string GenerateId(int totalNumberOfEncryptors); 


    /* Helper functions */
public:
    long Mod(int a, int b) const;
    void ModifyAlphabet(string &t_modifiedAlphabet, string t_alphabet, string &t_key) const;
};

