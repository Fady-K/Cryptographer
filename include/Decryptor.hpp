/**
 * @file Decryptor.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <bits/stdc++.h>
using namespace std;


class Decryptor
{
    /* Instance Attributes */
protected:
    string m_Id;
    string m_OriginalSentence;
    string m_DecryptedSentence;
    string m_UsedCipher;
    bool m_IsDecrypted;


    /* Static Attributes (related to class only, their life time is the whole program)*/
    static int m_NoDecryptors;
    static int m_NoCurrentDecryptors;

    /* Big 5 and Parametrized constructors */
public:
    Decryptor();                                    // Default constructor
    Decryptor(string t_sentenc);                    // Parametrized constructor
    Decryptor(const Decryptor&);                    // Copy constructor
    Decryptor& operator= (const Decryptor&);        // Copy assignment operator
    Decryptor(Decryptor&&);                         // Move constructor
    Decryptor& operator= (Decryptor&&);             // Move assignment operator
    ~Decryptor();                                   // Destructor



    /* Instance Methods (Setters, Getters)*/
    void SetSenctenceToDecrypt(string t_sentence);
    string GetOriginalSentence();
    string GetDecryptedSentence();
    string GetUsedCipher();
    string GetId();
    bool IsGivenSentenceGotDecrypted():


    /* Ciphers */
    string DecryptUsingAffineCipher(string t_sentenceToGetDecrypted);
    void DecryptUsingAffineCipher();

    
    string DecryptUsingAtpashCipher(string t_sentenceToGetDecrypted);
    void DecryptUsingAtpashCipher();

    string DecryptUsingBaconianCipher(string t_sentenceToGetDecrypted);
    void DecryptUsingBaconianCipher();

    string DecryptUsingCaesarCipher(string t_sentenceToGetDecrypted);
    void DecryptUsingCaesarCipher();

    string DecryptUsingMorseCode(string t_sentenceToGetDecrypted);
    void DecryptUsingMorseCode();

    string DecryptUsingSimpleSubstitutionCipher(string t_sentenceToGetDecrypted);
    void DecryptUsingSimpleSubstitutionCipher();

    string DecryptUsingVignereCipher(string t_sentenceToGetDecrypted);
    void DecryptUsingVignereCipher();


    /* Static Methods (Related to class only, have no relation with any object) */
    static string GetTotalNumberOfDecryptorThisClassMade();
    static string GetTotalNumberOfTheAliveDecryptors();
    static string GenerateId(string currentDecryporsCount);


    /* Helper Functions */
private:
    long Mod(int a, int b);
    string ModifyAlphabet(string &t_modifiedAlphabet, string alphabet, string t_key);

};

