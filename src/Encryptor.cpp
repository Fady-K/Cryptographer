/**
 * @file Encryptor.cpp
 * @author Fady Kamal (popfadykamal151617@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "..\include\Encryptor.hpp"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Static Attributes and Methods */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Int static variable indicating how many Encryptor object was instantiated from this class.
 * @details It will be incremented as soon as an object be instantaited, including objects with an ended life time.
 */
int Encryptor::m_NoEncryptors = 0;

/**
 * @brief Int static variable indicating to the number of the current Encryptors (life time hasn't ended yet)
 */
int Encryptor::m_NoCurrentEncyptors = 0;


/**
 * @brief This funtion returns the total number of encrptor were instantiated from this class
 * 
 * @return int No.Encryptors
 */
int Encryptor::GetTotalNumberOfEncryptorsThisClassMade(){ return m_NoEncryptors; }


/**
 * @brief  This funtion returns the total number of the alive Encryptors were (their life time hasn't ended yet)
 * 
 * @return int number of the alive encryptors
 */
int Encryptor::GetTotalNumberOfTheAliveEncryptors(){return m_NoCurrentEncyptors; }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Big 5 (Constructors, Destrucotors and Assignment Operators) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This is the default constructor, It initailzes instance attributes with values were determined by class maker 
 * 
 */
Encryptor::Encryptor(): m_OriginalSenctence(""), m_IsEncrypted(false)                           // Default constructor
{
    // increment number of encryptors by one
    Encryptor::m_NoEncryptors ++;
    Encryptor::m_NoCurrentEncyptors ++;
}


/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This a parametrized constructor that initailzes the class member (m_OriginalSentence) with a given sentence to encrypt
 * @param t_sentence A given sentence desired to get encrypted via encryptor object
 */
Encryptor::Encryptor(string t_sentence): m_OriginalSenctence(t_sentence), m_IsEncrypted(false)
{
    // increment number of encryptors by one
    Encryptor::m_NoEncryptors ++;
    Encryptor::m_NoCurrentEncyptors ++;
}


/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This the Default copy constructor that initializes instance attributes of this object with the attribute values of anther encryptor
 * @param t_anotherEncryptor Object of the same type to init this with it's attributes
 */
Encryptor::Encryptor(const Encryptor& t_anotherEncryptor): m_OriginalSenctence(t_anotherEncryptor.m_OriginalSenctence), m_IsEncrypted( t_anotherEncryptor.m_IsEncrypted), m_EncryptedSenctence(t_anotherEncryptor.m_EncryptedSenctence)
{
    // increment number of encryptors by one
    Encryptor::m_NoEncryptors ++;
    Encryptor::m_NoCurrentEncyptors ++;
}


/**
 * @brief An overload for copy assignment operator
 * @details It takes an object of the same type and copy its attributes values to this
 * @return Encryptor& the current object but after being copied
 */
Encryptor& Encryptor::operator=(const Encryptor& t_anotherEncryptor)
{
    // do the copy
    this-> m_OriginalSenctence = t_anotherEncryptor.m_OriginalSenctence;
    this-> m_IsEncrypted = t_anotherEncryptor.m_IsEncrypted;
    this-> m_EncryptedSenctence = t_anotherEncryptor.m_EncryptedSenctence;

    /* 
        return the exact object (*this) as it has just been copied 
        note: this operator returns an Encryptor object that why i dereferenced this pointer
    */

    return *this;   
}


/**
 * @brief Destroy the Encryptor:: Encryptor object
 * 
 */
Encryptor::~Encryptor()
{
    // decrement the current number of life encryptors by one as this has just died
    m_NoCurrentEncyptors --;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* (Instance Methods (Setters and Getters) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief A Setter method for m_OriginalSentence (instance attribute)
 * 
 * @param t_senctence A sentence to get encrpted
 */
inline void Encryptor::SetSentenceToEncrypt(string t_senctence) { m_OriginalSenctence = t_senctence; }


/**
 * @brief A Getter method for m_OriginalSentence (instance attribute)
 * 
 * @return string The Current value of m_OriginalSentence
 */
inline string Encryptor::GetOriginalSenctence() { return m_OriginalSenctence; }


/**
 * @brief A Getter method to return the current value of m_EncryptedSentence (instance attribute)
 * 
 * @return string Value of m_EncryptedSenctence
 */
inline string Encryptor::GetEncryptedSentence() { return m_EncryptedSenctence; }


/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
inline bool Encryptor::IsSentenceGotEncrpyted() { return m_IsEncrypted; }






