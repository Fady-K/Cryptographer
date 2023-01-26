/**
 * @file Decryptor.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "Encryptor.hpp"
#include <vector>
#include <bits/stdc++.h>


/* Notes: incases calling any constructor from derived class, and there was a default in the base, bases default contructor is called first */



class Decryptor: public Encryptor 
{
    /* Instance Attributes (Local Attributes ) */
protected: 
    string m_DecryptedSentence;
    bool m_IsDecrypted;


    /* Static Attributes ( Related to the class only, have nothing to do with objects )*/
    static int m_TotalNoDecryptors;
    static int m_CurrentNoDecryptors;

    /* Big 5 and Parametrized constructor */
public:
    Decryptor();                                    // Default construtctor
    Decryptor(string t_sentence);                   // Parametrized constructor
    Decryptor(const Decryptor& );                   // Copy constructor
    Decryptor& operator= (const Decryptor&);        // Copy assignment operator
    // Decryptor(Decryptor&&);                         // Move constructor
    // Decryptor& operator= (Decryptor&&);             // Move assignment operator
    ~Decryptor();                                   // Destructor



    /* Instance Methods (Setters and Getters ) */
    string GetDecryptedSentence() const;
    bool IsSentenceGotDecrypted() const;                // note: make the function const if it's not modifieing the instance attributes.
                                                        


    /* Ciphers */
    virtual string AffineCipher(string t_sentence) const;
    virtual void AffineCipher();

    virtual string AtpashCipher(string t_sentence) const;
    virtual void AtpashCipher();
    
    virtual string BaconianCipher(string t_sentence) const;
    virtual void BaconianCipher();

    virtual string CaesarCipher(string t_sentence) const;
    virtual void CaesarCipher();

    virtual string MorseCode(string t_sentence) const;
    virtual void MorseCode();

    virtual string SimpleSubstitutionCipher(string t_sentence) const;
    virtual void SimpleSubstitutionCipher();

    // virtual string VignereCipher(string t_sentence) const;
    // virtual void VignereCipher();


    /* Operators Overloading ( bitwise )*/
    friend istream& operator>> (istream& input, Decryptor& decryptor);          // Inertion operator >>
    friend ostream& operator<< (ostream& output, const Decryptor& decryptor);   // Extraction operator <<



    /* Static Methods (Related to class only and have noting to do with any object )*/
    static int GetTotalNumberOfObjectsThisClassMade();
    static int GetTotalNumberOfAliveObjects();


    /* Helper Functions */
protected:
    template <typename T>
    int GetIndex(vector<T> v, T target) const;
};

