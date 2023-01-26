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
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>
#include <cmath>
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
    // Decryptor(Decryptor&&);                         // Move constructor
    // Decryptor& operator= (Decryptor&&);             // Move assignment operator
    ~Decryptor();                                   // Destructor



    /* Instance Methods (Setters, Getters)*/
    inline void SetSenctenceToDecrypt(string t_sentence);
    inline string GetOriginalSentence() const;
    inline string GetDecryptedSentence() const;
    inline string GetUsedCipher() const;
    inline string GetId() const;
    inline bool IsGivenSentenceGotDecrypted() const;


    /* Ciphers */
    string DecryptUsingAffineCipher(string t_sentenceToGetDecrypted) const;
    void DecryptUsingAffineCipher();

    
    string DecryptUsingAtpashCipher(string t_sentenceToGetDecrypted) const;
    void DecryptUsingAtpashCipher();

    string DecryptUsingBaconianCipher(string t_sentenceToGetDecrypted) const;
    void DecryptUsingBaconianCipher();

    string DecryptUsingCaesarCipher(string t_sentenceToGetDecrypted) const;
    void DecryptUsingCaesarCipher();

    string DecryptUsingMorseCode(string t_sentenceToGetDecrypted) const;
    void DecryptUsingMorseCode();

    string DecryptUsingSimpleSubstitutionCipher(string t_sentenceToGetDecrypted) const;
    void DecryptUsingSimpleSubstitutionCipher();

    // string DecryptUsingVignereCipher(string t_sentenceToGetDecrypted) const;
    // void DecryptUsingVignereCipher();


    /* Operator Overloading (Bitwise) */
    friend istream& operator>> (istream& input, Decryptor& decryptor);
    friend ostream& operator<< (ostream& output, const Decryptor& decryptor); 


    /* Static Methods (Related to class only, have no relation with any object) */
    static int GetTotalNumberOfDecryptorThisClassMade();
    static int GetTotalNumberOfTheAliveDecryptors();
    static string GenerateId(int currentDecryptorsCount);


    /* Helper Functions */
private:
    long Mod(int a, int b) const;
    void ModifyAlphabet(string &t_modifiedAlphabet, string alphabet, string t_key) const;

    template<typename T>
    int GetIndex(vector<T> v, T target) const;

};

