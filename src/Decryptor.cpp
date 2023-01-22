/**
 * @file Decryptor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../include/Decryptor.hpp"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Static Attributes and Methods */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Int static variable indicating how many Decryptor object was instantiated from this class.
 * @details It will be incremented as soon as an object be instantaited, including objects with an ended life time.
 */
int Decryptor::m_NoDecryptors = 0;

/**
 * @brief Int static variable indicating to the number of the current Decryptors (life time hasn't ended yet)
 */
int Decryptor::m_NoCurrentDecryptors = 0;


/**
 * @brief This funtion returns the total number of Decryptors were instantiated from this class
 * 
 * @return int No.Decryptors
 */
int Decryptor::GetTotalNumberOfDecryptorThisClassMade(){ return m_NoDecryptors; }


/**
 * @brief  This funtion returns the total number of the alive Decryptors were (their life time hasn't ended yet)
 * 
 * @return int number of the alive Decryptors
 */
int Decryptor::GetTotalNumberOfTheAliveDecryptors(){return m_NoCurrentDecryptors; }


/**
 * @brief 
 * 
 * @param currentDecryptorsCount 
 * @return string 
 */
string Decryptor::GenerateId(int currentDecryptorsCount)
{
    /* formula: EN-currentDecryptorsCount */

    // string to hold the answer
    string id = "";

    // add prefix En- to it
    id += "DEC-";

    // calcualte nDigitsInNumberOfDecryptors thanks to https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
    int nDigitsInNumberOfDecryptors = floor(log10(currentDecryptorsCount) + 1);

    // if number of Decryptor has one digit then 00 + it
    if (nDigitsInNumberOfDecryptors == 1)
    {
        // add leading zeros
        id += "00";

        // convret current number of Decryptors into string and append to id
        id += ('0' + currentDecryptorsCount);
    }
    else if (nDigitsInNumberOfDecryptors == 2)
    {
        // add one leading zero
        id += "0";

        // convret current number of Decryptors into string and append to id
        id += to_string(currentDecryptorsCount);
    }
    else
    {
        // convret current number of Decryptors into string and append to id
        id += to_string(currentDecryptorsCount);
    }


    // return id
    return id;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Big 5 (Constructors, Destrucotors and Assignment Operators) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Decryptor::Decryptor(): m_OriginalSentence(""), m_DecryptedSentence("None"), m_UsedCipher("None"), m_IsDecrypted(false)
{
    // increment number of Decryptors by one
    Decryptor::m_NoDecryptors ++;
    Decryptor::m_NoCurrentDecryptors ++;

    // Decryptor id is comprisd of the prefix ENC+NoDecryptors
    m_Id = Decryptor::GenerateId(Decryptor::m_NoDecryptors);
}



