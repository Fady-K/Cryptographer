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
const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Static Attributes and Methods */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Int static variable indicating how many Encryptor object was instantiated from this class.
 * @details It will be incremented as soon as an object be instantaited, including objects with an ended life time.
 */
int Encryptor::m_NoObjects = 0;

/**
 * @brief Int static variable indicating to the number of the current Encryptors (life time hasn't ended yet)
 */
int Encryptor::m_CurrentNoObjects = 0;


/**
 * @brief This funtion returns the total number of encrptor were instantiated from this class
 * 
 * @return int No.Encryptors
 */
int Encryptor::GetTotalNumberOfObjectsThisClassMade(){ return m_NoObjects; }


/**
 * @brief  This funtion returns the total number of the alive Encryptors were (their life time hasn't ended yet)
 * 
 * @return int number of the alive encryptors
 */
int Encryptor::GetTotalNumberOfAliveObjects(){return m_CurrentNoObjects; }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Big 5 (Constructors, Destrucotors and Assignment Operators) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This is the default constructor, It initailzes instance attributes with values were determined by class maker 
 */
Encryptor::Encryptor(): m_OriginalSenctence(""), m_EncryptedSenctence("None"), m_UsedCipher("None"), m_IsEncrypted(false)                           // Default constructor
{
    // increment number of encryptors by one
    Encryptor::m_NoObjects ++;
    Encryptor::m_CurrentNoObjects ++;

    // encryptor id is comprisd of the prefix ENC+NoEncryptors
    m_Id = Encryptor::GenerateId(Encryptor::m_NoObjects);

}


/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This a parametrized constructor that initailzes the class member (m_OriginalSentence) with a given sentence to encrypt
 * @param t_sentence A given sentence desired to get encrypted via encryptor object
 */
Encryptor::Encryptor(string t_sentence): m_OriginalSenctence(t_sentence), m_EncryptedSenctence("None"), m_UsedCipher("None"), m_IsEncrypted(false)
{
    // increment number of encryptors by one
    Encryptor::m_NoObjects ++;
    Encryptor::m_CurrentNoObjects ++;

    // encryptor id is comprisd of the prefix ENC+NoEncryptors
    m_Id = Encryptor::GenerateId(Encryptor::m_NoObjects);
    

}


/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This the Default copy constructor that initializes instance attributes of this object with the attribute values of anther encryptor
 * @param t_anotherEncryptor Object of the same type to init this with it's attributes
 */
Encryptor::Encryptor(const Encryptor& t_anotherEncryptor): m_OriginalSenctence(t_anotherEncryptor.m_OriginalSenctence), m_UsedCipher(t_anotherEncryptor.m_UsedCipher), m_IsEncrypted( t_anotherEncryptor.m_IsEncrypted), m_EncryptedSenctence(t_anotherEncryptor.m_EncryptedSenctence)
{
    // increment number of encryptors by one
    Encryptor::m_NoObjects ++;
    Encryptor::m_CurrentNoObjects ++;

    // encryptor id is comprisd of the prefix ENC+NoEncryptors
    m_Id = Encryptor::GenerateId(Encryptor::m_NoObjects);
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
    this-> m_UsedCipher = t_anotherEncryptor.m_UsedCipher;
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
    m_CurrentNoObjects --;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* (Instance Methods (Setters and Getters) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief A Setter method for m_OriginalSentence (instance attribute)
 * 
 * @param t_senctence A sentence to get encrpted
 */
inline void Encryptor::SetSentence(string t_senctence) { m_OriginalSenctence = t_senctence; }


/**
 * @brief A Getter method for m_OriginalSentence (instance attribute)
 * 
 * @return string The Current value of m_OriginalSentence
 */
inline string Encryptor::GetOriginalSenctence() const { return m_OriginalSenctence; }


/** 
 * @brief A Getter method to return the current value of m_EncryptedSentence (instance attribute)
 * 
 * @return string Value of m_EncryptedSenctence
 */
inline string Encryptor::GetEncryptedSentence() const { return m_EncryptedSenctence; }


/** 
 * @brief A Getter method to return the current value of m_UsedCipher (instance attribute)
 * 
 * @return string Value of m_UsedCipher
 */
inline string Encryptor::GetUsedCipher() const {return m_UsedCipher; }


/**
 * @brief A Getter method to return the this encryptor id (instance attribute)
 * 
 * @return string Value of m_Id
 */
inline string Encryptor::GetId() const {return m_Id; }


/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
inline bool Encryptor::IsSentenceGotEncrpyted() const { return m_IsEncrypted; }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* (Instance Methods (Ciphers) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief This function takes a sentence from user and encrypts it using Affine cipher
 * @details For more details on affice cipher check this link: https://en.wikipedia.org/wiki/Affine_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @param a First constant in encrypting formula (a x + b) mod 26
 * @param b Second constant in encryping formula  (a x + b) mod 26
 * @return string Sentence after being encrypted (Encrypted sentence) 
 */
string Encryptor::AffineCipher (string t_sentenceToGetEncrypted, const int& a, const int& b) const
{
    // convert all the message's letters into uppercase
    for (auto &c: t_sentenceToGetEncrypted) c = toupper(c);
    
    // initiallize the Alphabet to fetch the chara position
    string encrypted;

    int positionInAlphabet, newPosition;
    char newChar;

    // iterate over each chara of the message
    for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
    {
        // fetch each chara in the message
        char chara = t_sentenceToGetEncrypted[i];

        // check if the char is space, add space to encrypted char and continue
        if (chara == ' ')
        {
            encrypted += " ";
            continue;
        }
        else
        {
            try
            {
                // if not then fetch the char index from Alphabet (x), then  use the following foumla to get the new index >> (5x + 8)
                positionInAlphabet = Alphabet.find(chara);

                // check for position validaty in alphabet
                if (!(positionInAlphabet >= 0 && positionInAlphabet <= 25))
                {
                    throw(EncryptorExceptions("Invalid Alphabet Index, You Have Entered A Non Alphabet letter!"));
                }  
                // check for a range, valid range(0, 25);
                else if (!(a >= 0 && a <= 25))
                {
                    // handel the exception
                    throw(EncryptorExceptions("Constant a is out of valid range 0 : 25 !"));
                }
                
                // check for b value, valid value {1,3,5,7,9,11,15,17,19,21,23,25}
                // invalid if b is even or not in valid range or b == 13
                else if ((b % 2 == 0) || !(b >= 0 && b <= 25) || (b == 13))
                {
                    // throw encryptor error exception
                    throw(EncryptorExceptions("Constant b is a not valid!, Accepted values {1,3,5,7,9,11,15,17,19,21,23,25}"));
                }
                else
                {
                    try
                    {
                        // it's guranted that newPosition will be positive therefore i used the regulare division reminder >> %
                        newPosition = ((a * positionInAlphabet) + b) % 26;
                        newChar = Alphabet[newPosition];
                        encrypted += newChar;
                    }
                    catch(...)
                    {
                        // exit failure
                        fprintf(stderr, "Affine Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);

                        // general purpose exception
                        cout << "!! Can't find an encrypted equivalent !!" << endl;

                        // exits
                        exit(EXIT_FAILURE);
                    }
                }
            }
            catch(EncryptorExceptions e)
            {
                fprintf(stderr, "Affine Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);
                cout << e.what() << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    // return the encrypted message
    return encrypted;
}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look above
 * @param a First constant in encrypting formula (a x + b) mod 26
 * @param b Second constant in encryping formula  (a x + b) mod 26
 */
void Encryptor::AffineCipher(const int& a, const int& b)
{
    // dry
    m_EncryptedSenctence = Encryptor::AffineCipher(m_OriginalSenctence, a, b);

    // cipher used in encryption process: affine cipher
    m_UsedCipher = "Affine Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user and encrypts it using atpash cipher
 * @details For more details on atpash cipher check this link: https://en.wikipedia.org/wiki/Atpash_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::AtpashCipher(string t_sentenceToGetEncrypted) const
{
    // store space'index
    string message_without_space;

    int spaces_index[t_sentenceToGetEncrypted.length() + 1];
    int count = 0;
    for(int i = 0; i < t_sentenceToGetEncrypted.length(); i++)
        {

            if (t_sentenceToGetEncrypted[i] == ' ')
            {

                spaces_index[count] = i;
                count++;

            }
        }
    
        // to remove char from string 
    t_sentenceToGetEncrypted.erase(remove(t_sentenceToGetEncrypted.begin(),t_sentenceToGetEncrypted.end(), 32), t_sentenceToGetEncrypted.end());


    // convert string into upper case
    for(auto &c : t_sentenceToGetEncrypted) c = toupper(c);
    string inverted_alphabet = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string encrypted = "";

    // covert string into array of chars
    char chars_of_message[t_sentenceToGetEncrypted.length() + 1];
    strcpy(chars_of_message, t_sentenceToGetEncrypted.c_str());

    //loop over array of chars and fech each char's position in abs
    for (int i = 0; i < t_sentenceToGetEncrypted.length(); i++){
        char chara = t_sentenceToGetEncrypted[i];
        // position in Alphabet >> find
        int position_in_Alphabet = Alphabet.find(chara);

        // get the equivilant encrpted char of inverted Alphabet
        encrypted += inverted_alphabet[position_in_Alphabet];
    }

    count = 0;
    string encryptedMessage;


    int i = 0;
    while (i < t_sentenceToGetEncrypted.length())
    {

        if (spaces_index[count] == encryptedMessage.length())
        {
            encryptedMessage += ' ';
            count ++; 
        }

        encryptedMessage += encrypted[i];
        i++;

    }

    // return the encrypted message
    return encryptedMessage;
}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::AtpashCipher()
{
    m_EncryptedSenctence = Encryptor::AtpashCipher(m_OriginalSenctence);

    // cipher used in encryption process: atpash cipher
    m_UsedCipher = "Atpash Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user and encrypts it using Baconian cipher
 * @details For details on Baconian cipher cipher check this link: https://en.wikipedia.org/wiki/Bacon%27s_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Sentence after being encrypted (Encrypted sentence)
 */
string Encryptor::BaconianCipher(string t_sentenceToGetEncrypted) const
{
    // conver all letter's into upper case 
    for(auto &c: t_sentenceToGetEncrypted) c = toupper(c); // actually this not important i could have neglect it by using full lowercase Alphabet instead of upper case one

    // array cipher
    string code[26] = {"aaaaa ", "aaaab ", "aaaba ", "aaabb ", "aabaa ", "aabab ", "aabba ", "aabbb ", "abaaa ", "abaab ", "ababa ", "ababb ", "abbaa ", "abbab ", "abbba ", "abbbb ", "baaaa ", "baaab ", "baaba ", "baabb ", "babaa ", "babab ", "babba ", "babbb ", "bbaaa ", "bbaab "};
    string encrypted;

    // iteration over the message
    for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
    {
        char chara = t_sentenceToGetEncrypted[i];
        
        // check if chara is space
        if (chara == ' ')
        {   // if chara == space append 4spaces to ecrypted one 

            encrypted += "   ";
            continue;
        }
        // check if the chara is digit
        else if (isdigit(chara))
        {
            encrypted += chara;
            continue;
        }
        else
        {
            try
            {
                // fetch it's position from Alphabet
                int position_in_alphabet = Alphabet.find(chara);

                // check if a valid index
                if (!(position_in_alphabet >= 0 && position_in_alphabet <= 25))
                {
                    throw(EncryptorExceptions("Invalid Alphabet Index, You Have Entered A Non Alphabet letter!"));
                } 
                else
                {
                    try
                    {
                        // get the equivelant from code
                        string coded_chara = code[position_in_alphabet];
                        encrypted += coded_chara;
                    }
                    catch(...)
                    {
                        // exit failure
                        fprintf(stderr, "Baconian Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);

                        // general purpose exception
                        cout << "!! Can't find an encrypted equivalent !!" << endl;

                        // exits
                        exit(EXIT_FAILURE);
                    }

                } 
            }
            // catch the exception
            catch(EncryptorExceptions e)
            {
                // exit failure
                fprintf(stderr, "Baconian Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);

                // general purpose exception
                cout << e.what() << endl;

                // exits
                exit(EXIT_FAILURE);
            }
            
        }
    }
    
    // return the encrypted message
    return encrypted;
}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::BaconianCipher()
{
    m_EncryptedSenctence = Encryptor::BaconianCipher(m_OriginalSenctence);

    // cipher used in encryption process: Baconian Cipher
    m_UsedCipher = "Baconian Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user and encrypts it using Caesar Cipher
 * @details For a more details about caesar cipher check this link: https://en.wikipedia.org/wiki/Caesar_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @param shift a required int for the encryption process
 * @return string Sentence after being encrypted (Encrypted sentence)
 */
string Encryptor::CaesarCipher(string t_sentenceToGetEncrypted, const int& shift) const
{
    // convert all letter into upper case
    for (auto &c : t_sentenceToGetEncrypted) c = toupper(c);
    
    // encrypting credentials
    int position_in_alphabet, new_position;
    string encrpted_message;
    char encrypted;

    // iterate over each char in original and encrypt it
    for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
    {
        // equivalant chararcter
        char character = t_sentenceToGetEncrypted[i];

        // caesar cipher encrypts only alphabet, there fore any thing else won't be encryted
        if (!isalpha(character))
        {
            encrpted_message += character;
        }
        else
        {
            try
            {
                // encrypt it using  caeser cipher
                // fetch it's position from Alphabet
                position_in_alphabet = Alphabet.find(character);

                // check if a valid index
                if (!(position_in_alphabet >= 0 && position_in_alphabet <= 25))
                {
                    throw(EncryptorExceptions("Invalid Alphabet Index, You Have Entered A Non Alphabet letter!"));
                }
                // check if valid shift
                // shift valid range 0: 25
                else if (!(shift >= 0 && shift <= 25))
                {
                    // throw a out of range error
                    throw(EncryptorExceptions("Shift is out of valid range 0: 25!"));
                } 
                else
                {
                    try
                    {
                        // encrypt this char
                        new_position = Utility::Mod((position_in_alphabet + shift), 26);
                        encrypted = Alphabet[new_position];
                        encrpted_message += encrypted;
                    }
                    catch(...)
                    {
                        // exit failure
                        fprintf(stderr, "Baconian Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);

                        // general purpose exception
                        cout << "!! Can't find an encrypted equivalent !!" << endl;

                        // exits
                        exit(EXIT_FAILURE);     
                    }

                }
            } 
            catch(EncryptorExceptions e)
            {
                // cause for failure
                fprintf(stderr, "Caesar Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);

                // general purpose exception
                cout << e.what() << endl;

                // exits
                exit(EXIT_FAILURE);
            }
            catch(...)
            {
                // exit failure
                fprintf(stderr, "Baconian Cipher() failed in file %s at line # %d\n", __FILE__,__LINE__);

                // general purpose exception
                cout << "!! Baconian Cipher Failed !!" << endl;

                // exits
                exit(EXIT_FAILURE);            
            }

        }
    }

    // return the encrypted message
    return encrpted_message;
}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look above
 * @details For a more details about caesar cipher check this link: https://en.wikipedia.org/wiki/Caesar_cipher
 * @param shift a required int for the encryption process
 */
void Encryptor::CaesarCipher(const int& shift)
{
    m_EncryptedSenctence = Encryptor::CaesarCipher(m_OriginalSenctence, shift);

    // cipher used in encryption process: Caesar Cipher
    m_UsedCipher = "Caesar Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user and encrypt it using MorseCode
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Morse_code
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Sentence after being encrypted (Encrypted sentence)
 */
string Encryptor::MorseCode(string t_sentenceToGetEncrypted) const
{
    // credentials
    string morse_code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----","..---","...--","....-",".....","-....","--....","---..", "----."};
    
    // alphabet + digits
    string Alphabet = ::Alphabet + "0123456789";

    // conver all the message's letters into uppercase
    for (auto &c : t_sentenceToGetEncrypted) c = toupper(c);

    // this an empty string to concatinate
    string encrypted = "";

    // iterate over the message
    for (int i = 0; i < t_sentenceToGetEncrypted.length(); i++)
    {
        // fetch character by index from the message
        char chara = t_sentenceToGetEncrypted[i];

        // if chara is space or digit append it without any configration
        if (isspace(chara))
        {
            encrypted += chara;
            continue;
        }
        else
        {
            try
            {
                // fetch the character's position in abc
                int position_in_alphabet = Alphabet.find(chara);

                // check if valid char 
                if (!(position_in_alphabet >=0 && position_in_alphabet <= 36))
                {
                    throw(EncryptorExceptions("You have entered character that has no code in morse code table!"));
                }
                else
                {
                    try
                    {
                        // get the corresponding morse companitation thereafter concatinate it with encrypted
                        encrypted += morse_code[position_in_alphabet] + ' ';
                    }
                    catch(exception e)
                    {
                        // exception cause
                        fprintf(stderr, "MorseCode() failed in file %s at line # %d\n", __FILE__,__LINE__);

                        // general message
                        cout << e.what() << endl;

                        // exit failure
                        exit(EXIT_FAILURE);
                    }
                }
            }
            catch(EncryptorExceptions e)
            {
                // exit failure
                fprintf(stderr, "MorseCode() failed in file %s at line # %d\n", __FILE__,__LINE__);

                // general purpose exception
                cout << e.what() << endl;

                // exits
                exit(EXIT_FAILURE);            
            }
        }
    }

    // // display the message
    // cout << "################################" << endl;
    // cout << "Note: Every Letter is seperated by (one space) and Every word seperated by (Two Spaces) !! " << endl;
    // cout << "Encrypted Message " << encrypted << endl;
    // cout << "################################" << endl;


    // return the encrypted message
    return encrypted;

}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look abovee
 * @details For details on Morse Code check this link: https://en.wikipedia.org/wiki/Morse_code
 */
void Encryptor::MorseCode()
{
    m_EncryptedSenctence = Encryptor::MorseCode(m_OriginalSenctence);

    // cipher used in encryption process: Morse code
    m_UsedCipher = "Morse Code";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user and encrypts it via Simple Substitution Cipher
 * @details For details on Simple Substitution Cipher check this link: https://en.wikipedia.org/wiki/Substitution_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @param t_key an essential string for the encryption process
 * @return string sentence after being encrypted (Encrypted sentence)
 */
string Encryptor::SimpleSubstitutionCipher(string t_sentenceToGetEncrypted, const string& t_key) const
{
    // empty string to hold encryped sentence
    string encrypted = "";

    // modifed alphabet
    string modified_alphabet = "";

    try
    {
        // convert the message into uppercase
        for (auto &c : t_sentenceToGetEncrypted) c = toupper(c);

        /*
         * key constraints
         * length == 26
         * can't include special characters or digits
        */

        if (!Utility::IsComprisedOfAbc(t_key))
        {
            throw(EncryptorExceptions("Key must be comprised alphabet letter only, can't have special characters or digits!"));
        }
        else if (t_key.length() != 26)
        {
            // throw invalid range
            throw(EncryptorExceptions("Key must be comprised of 26 char!"));

        }
        else
        {
            // tmp version of key to convert it into upper cases (to make insencetive to case)
            string key = t_key;

            // convert key into uppercase
            for (auto &c : key) c = toupper(c);

            // add the key letter's to the beggining of the modified abc
            for (int i = 0; i < key.length(); ++i)
            {
                modified_alphabet += key[i];
            }

            // generate the new alphabet bases the given key
            ModifyAlphabet(modified_alphabet, Alphabet, key);

            // iterate over the message and encrypt
            for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
            {
                char chara = t_sentenceToGetEncrypted[i];

                // if the chara existing in the message is space or digit append it without any modification
                if ((chara == ' ') || (isdigit(chara)))
                {
                    encrypted += chara;
                    continue;
                }

                // if not then encrypt the chara
                else
                {
                    try
                    {
                        // fetch position from abc
                        int position_in_alphabet = Alphabet.find(chara);

                        // check if valid char (in alphabet)
                        if (!(position_in_alphabet >= 0 && position_in_alphabet <= 25))
                        {
                            // throw out of range error
                            throw(EncryptorExceptions("You have entered a character that has no equivalent in encrypted alphabet, (special characters cannot be encoded)!"));

                        }
                        else
                        {
                            // fetch the equivelant from modified alphabet
                            char new_chara = modified_alphabet[position_in_alphabet];

                            // append it to encrypted
                            encrypted += new_chara;
                        }

                    }
                    catch(EncryptorExceptions e)
                    {
                        // exception cause
                        fprintf(stderr, "SimpleSubstitutionCipher() faild in file %s at line # %d\n", __FILE__, __LINE__);

                        // error message
                        cout << e.what() << endl;

                        // exits the program
                        exit(EXIT_FAILURE);
                    }

                }
            }

        }

    }
    catch(EncryptorExceptions e)
    {
        // exception cause
        fprintf(stderr, "SimpleSubstitutionCipher() faild in file %s at line # %d\n", __FILE__,__LINE__);

        // error message
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }
    catch(exception e)
    {
        // exception cause
        fprintf(stderr, "SimpleSubstitutionCipher() faild in file %s at line # %d\n", __FILE__,__LINE__);

        // error message (general one)
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }


    // return the encrypted message
    return encrypted;
}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look above
 * @details For details on Simple SubstitutionC ipher check this link: https://en.wikipedia.org/wiki/Substitution_cipher
 * @param t_key an essential string for the encryption process
 */
void Encryptor::SimpleSubstitutionCipher(const string& t_key)
{
    m_EncryptedSenctence = Encryptor::SimpleSubstitutionCipher(m_OriginalSenctence, t_key);

    // cipher used in encryption process: Simple Substitution Cipher
    m_UsedCipher = "Simple Substitution Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user, and encrypts it using Vignere Cipher
 * @details For a more details on Vignere cipher check this link: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
 * @details This function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @param t_key An essential string for the encrypting process
 * @return string Sentence after being encrypted (Encrypted sentence)
 */
string Encryptor::VignereCipher(string t_sentenceToGetEncrypted, const string& t_key) const
{
    /* encrypting credentials */

    // to store a copy from const key (parameter)
    string key;
    
    // char counter
    int counter = 0;

    // to store repeated key
    string repeated_key;

    // conver all the message's letters into uppercase
    for (auto &c: t_sentenceToGetEncrypted) c = toupper(c);

    /* 
        * key constraints
        * can't include special characters or digits
    */
    try
    {
        // check key validation
        if (!Utility::IsComprisedOfAbc(t_key))
        {
            // throw EncryptorExcpetion
            throw(EncryptorExceptions("Key must be comprised of alphabet letters only, can't have special characters or digits!"));
        }
        else
        {
            // tmp version of key to convert it into upper cases (to make insencetive to case)
            key = t_key;
        }
    }
    catch(EncryptorExceptions e)
    {
        // exception cause
        fprintf(stderr, "VignereCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }
    catch(exception e)
    {
        // exception cause
        fprintf(stderr, "VignereCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

        // error message (general)
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }

    // convert all the key's letters into uppercase
    for (auto &c: key) c = toupper(c);

    try
    {
        // form the repeated key
        for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
        {
            if (counter > key.length() - 1)
            {
                counter = Utility::Mod(counter, key.length());
            }

            char chara = key[counter];
            repeated_key += chara;
            counter ++;
        }
    }
    catch(exception e)
    {
        // exception cause
        fprintf(stderr, "VignereCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }

        // encryption credentials
        string encrypted = "";
        int ascii_of_a = int(Alphabet[0]);
        char chara_from_message, chara_from_repeated, new_chara;
        int ascii_of_chara_repeated, ascii_of_chara_message;

    try
    {
        for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
        {
            // note that both of message and repeated key have the same length
            chara_from_message = t_sentenceToGetEncrypted[i];
            if (chara_from_message == ' ')
            {
                encrypted += ' ';
                continue;
            }
            else if (isdigit(chara_from_message))
            {
                encrypted += chara_from_message;
                continue;
            }

            ascii_of_chara_message = int(chara_from_message);

            chara_from_repeated = repeated_key[i];
            ascii_of_chara_repeated = int(chara_from_repeated);
            
            new_chara = ascii_of_a +  (Utility::Mod((ascii_of_chara_message + ascii_of_chara_repeated), 26));
            encrypted += new_chara;
        }
    }
    catch(exception e)
    {
        // exception cause
        fprintf(stderr, "VignereCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }

    // return the encrypted message
    return encrypted;
}


/**
 * @brief The basic function used by object to encrypt instance attribute
 * @details This function is based on the overloaded version: look above
 * @details For a more details on Vignere cipher check this link: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
 * @param t_key An essential string for the encrypting process
 */
void Encryptor::VignereCipher(const string& t_key)
{
    m_EncryptedSenctence = Encryptor::VignereCipher(m_OriginalSenctence, t_key);

    // cipher used in encryption process: Vignere Cipher
    m_UsedCipher = "Vignere Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/*  Operators Overloading ( Bitwise ) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Overloaded the insertion operator >>
 * 
 * @param input reference to istream 
 * @return istream& reference to istream object (incase there is more than one >>) this solves (input >> x >> y) problem
 */
istream& operator>>(istream& input, Encryptor& encryptor)
{
    // take input
    string s;
    getline(input >> ws, s);

    // add sentence
    encryptor.SetSentence(s);

    // return istream refefrence (incase there is more than one >> )
    return input;
}


/**
 * @brief Overloaded the extraction operator <<
 * 
 * @param output reference to ostream
 * @param encryptor reference to encryptor (made it const, as this operator prints only and won't modify the given object)
 * @return ostream& reference to ostream object incase there is more than <<
 */
ostream& operator<<(ostream& output, const Encryptor& encryptor)
{
    // print the encrpytor
    output << "---- Encryptor Details ----\n";
    output << "Id: " << encryptor.GetId() << "\n" << "Original Sentence ( Unencrypted ): " << encryptor.GetOriginalSenctence() << "\n" << "Encrypted Senctence: " << encryptor.GetEncryptedSentence() << "\n" << "Used Cipher: " << encryptor.GetUsedCipher() << "\n";

    // return refrence to ostream (incase there is more than one << )
    return output;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* ( Helper Functions ) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief 
 * 
 * @param t_modifiedAlphabet 
 * @param t_alphabet 
 * @param t_key 
 */
void Encryptor::ModifyAlphabet(string &t_modifiedAlphabet, string t_alphabet, string &t_key) const
{
  // first loop to fetch each char from abc
    for (int i = 0; i < t_alphabet.length(); ++i)
    {
        bool exist_in_key = false;
        char chara = t_alphabet[i];

        // nested loop for comparing chara fetched from abc with the key
        for (int x = 0; x < t_key.length(); ++x)
        {
            if (chara == t_key[x])
            {
                // if chara from abc in key
                exist_in_key = true;
            }
        }

        if (exist_in_key)
        {
            // if in the key then neglect it
            continue;
        }

        else
        {
            t_modifiedAlphabet += chara;
        }
    }
}


/**
 * @brief 
 * 
 * @param currentNumberOfEncryptors 
 * @return string 
 */
string Encryptor::GenerateId(int totalNumberOfEncryptors, bool forEncryptor)
{
    /* formula: EN-CurrentNumberOfEncryptors */

    // string to hold the answer
    string id = "";

    // add prefix En- to it
    if (forEncryptor) id += "ENC-";
    else id += "DEC-";

    // calcualte nDigitsInNumberOfEncryptors thanks to https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
    int nDigitsInNumberOfEncryptors = floor(log10(totalNumberOfEncryptors) + 1);

    // if number of encryptor has one digit then 00 + it
    if (nDigitsInNumberOfEncryptors == 1)
    {
        // add leading zeros
        id += "00";

        // convret current number of encryptos into string and append to id
        id += ('0' + totalNumberOfEncryptors);
    }
    else if (nDigitsInNumberOfEncryptors == 2)
    {
        // add one leading zero
        id += "0";

        // convret current number of encryptos into string and append to id
        id += to_string(totalNumberOfEncryptors);
    }
    else
    {
        // convret current number of encryptos into string and append to id
        id += to_string(totalNumberOfEncryptors);
    }

    // return id
    return id;
}
