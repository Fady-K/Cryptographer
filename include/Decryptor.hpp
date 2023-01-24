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
#include "Encryptor.hpp"




class Decryptor: public Encryptor 
{
    /* Instance Attributes (Local Attributes ) */
protected:
    string m_DecryptedSentence;
    bool m_IsDecrypted;


    /* Big 5 and Parametrized constructor */
public:
    Decryptor();                                    // Default construtctor
    Decryptor(string t_sentence);                   // Parametrized constructor
    Decryptor(const Decryptor& );                   // Copy constructor
    Decryptor& operator= (const Decryptor&);        // Copy assignment operator
    Decryptor(Decryptor&&);                         // Move constructor
    Decryptor& operator= (Decryptor&&);             // Move assignment operator
    ~Decryptor();                                   // Destructor



    /* Instance Methods (Setters and Getters ) */
    void GetDecryptedSentence() const;
    void IsSentenceGotDecrypted() const;                // note: make the function const if it's not modifieing the instance attributes.
                                                        


    /* Ciphers */
    virtual string AffineCipher(string t_sentence);
    virtual void AffineCipher();

    virtual string AtpashCipher(string t_sentence);
    virtual void AtpashCipher();
    
    virtual string BaconianCipher(string t_sentence);
    virtual void BaconianCipher();

    virtual string CaesarCipher(string t_sentence);
    virtual void CaesarCipher();

    virtual string MorseCode(string t_sentence);
    virtual void MorseCode();

    virtual string SimpleSubstitutionCipher(string t_sentence);
    virtual void SimpleSubstitutionCipher();

    virtual string VignereCipher(string t_sentence);
    virtual void VignereCipher();


    /* Operators Overloading ( bitwise )*/
    friend istream& operator>> (istream& input, Decryptor& decryptor);          // Inertion operator >>
    friend ostream& operator<< (ostream& output, const Decryptor& decryptor);   // Extraction operator <<





};

