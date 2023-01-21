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
 */
Encryptor::Encryptor(): m_OriginalSenctence(""), m_EncryptedSenctence("None"), m_UsedCipher("None"), m_IsEncrypted(false)                           // Default constructor
{
    // increment number of encryptors by one
    Encryptor::m_NoEncryptors ++;
    Encryptor::m_NoCurrentEncyptors ++;

    // encryptor id is comprisd of the prefix ENC+NoEncryptors
    m_Id = Encryptor::GenerateId(Encryptor::m_NoEncryptors);

}


/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This a parametrized constructor that initailzes the class member (m_OriginalSentence) with a given sentence to encrypt
 * @param t_sentence A given sentence desired to get encrypted via encryptor object
 */
Encryptor::Encryptor(string t_sentence): m_OriginalSenctence(t_sentence), m_EncryptedSenctence("None"), m_UsedCipher("None"), m_IsEncrypted(false)
{
    // increment number of encryptors by one
    Encryptor::m_NoEncryptors ++;
    Encryptor::m_NoCurrentEncyptors ++;

    // encryptor id is comprisd of the prefix ENC+NoEncryptors
    m_Id = Encryptor::GenerateId(Encryptor::m_NoEncryptors);
    

}


/**
 * @brief Construct a new Encryptor:: Encryptor object
 * @details This the Default copy constructor that initializes instance attributes of this object with the attribute values of anther encryptor
 * @param t_anotherEncryptor Object of the same type to init this with it's attributes
 */
Encryptor::Encryptor(const Encryptor& t_anotherEncryptor): m_OriginalSenctence(t_anotherEncryptor.m_OriginalSenctence), m_UsedCipher(t_anotherEncryptor.m_UsedCipher), m_IsEncrypted( t_anotherEncryptor.m_IsEncrypted), m_EncryptedSenctence(t_anotherEncryptor.m_EncryptedSenctence)
{
    // increment number of encryptors by one
    Encryptor::m_NoEncryptors ++;
    Encryptor::m_NoCurrentEncyptors ++;

    // encryptor id is comprisd of the prefix ENC+NoEncryptors
    m_Id = Encryptor::GenerateId(Encryptor::m_NoEncryptors);
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
 * @brief This function takes a sentence from user then encrypts it using Affine cipher
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Affine_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingAffineCipher (string t_sentenceToGetEncrypted) const
{
    // take a, b, c from the user 
    cout << "Enter The value of (a, b) Where (a*x + b) % 26 Is The Formula of Encryption: ";
    int a, b;
    cin >> a >> b;

    // convert all the message's letters into uppercase
    for (auto &c: t_sentenceToGetEncrypted) c = toupper(c);
    
    // initiallize the Alphabet to fetch the chara position
    string encrpyted;

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
            encrpyted += " ";
            continue;
        }
        else
        {
            // if not then fetch the char index from Alphabet (x), then  use the following foumla to get the new index >> (5x + 8)
            positionInAlphabet = Alphabet.find(chara);  

            // it's guranted that newPosition will be positive therefore i used the regulare division reminder >> %
            newPosition = ((a * positionInAlphabet) + b) % 26;
            newChar = Alphabet[newPosition];
            encrpyted += newChar;
        }
    }

    // return the encrypted message
    return encrpyted;
}


/**
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingAffineCipher()
{
    // dry
    m_EncryptedSenctence = Encryptor::EncryptUsingAffineCipher(m_OriginalSenctence);

    // cipher used in encryption process: affine cipher
    m_UsedCipher = "Affine Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user then encrypts it using atpash cipher
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Atpash_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingAtpashCipher(string t_sentenceToGetEncrypted) const
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
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingAtpashCipher()
{
    m_EncryptedSenctence = Encryptor::EncryptUsingAtpashCipher(m_OriginalSenctence);

    // cipher used in encryption process: atpash cipher
    m_UsedCipher = "Atpash Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user then encrypts it using Baconian cipher
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Bacon%27s_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingBaconianCipher(string t_sentenceToGetEncrypted) const
{
    // conver all letter's into upper case 
    for(auto &c: t_sentenceToGetEncrypted) c = toupper(c); // actually this not important i could have neglect it by using full lowercase Alphabet instead of upper case one

    // Alphabet >> any string is an array of buffers 

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
            // fetch it's position from Alphabet
            int position_in_alphabet = Alphabet.find(chara);

            // get the equivelant from code
            string coded_chara = code[position_in_alphabet];
            encrypted += coded_chara;
        }
    }
    
    // return the encrypted message
    return encrypted;
}


/**
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingBaconianCipher()
{
    m_EncryptedSenctence = Encryptor::EncryptUsingBaconianCipher(m_OriginalSenctence);

    // cipher used in encryption process: Baconian Cipher
    m_UsedCipher = "Baconian Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user then encrypts it using Caesar Cipher
 * @details For a more details about caesar cipher check this link: https://en.wikipedia.org/wiki/Caesar_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingCaesarCipher(string t_sentenceToGetEncrypted) const
{
    // convert all letter into upper case
    for (auto &c : t_sentenceToGetEncrypted) c = toupper(c);

    // take shift from user
    cout << "shift: ";
    int shift;
    cin >> shift;
    
    // encrypting credentials
    int position_in_alphabet, new_position;
    string encrpted_message;
    char encrypted;

    // iterate over each char in original and encrypt it
    for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i){
        char character = t_sentenceToGetEncrypted[i];
        if (isspace(character) || (isdigit(character)))
        {
            encrpted_message += character;
            continue;
        }
        else
        {
            position_in_alphabet = Alphabet.find(character);
            new_position = Mod((position_in_alphabet + shift), 26);
            encrypted = Alphabet[new_position];
            encrpted_message += encrypted;
        }
    }

    // return the encrypted message
    return encrpted_message;
   
}


/**
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingCaesarCipher()
{
    m_EncryptedSenctence = Encryptor::EncryptUsingCaesarCipher(m_OriginalSenctence);

    // cipher used in encryption process: Caesar Cipher
    m_UsedCipher = "Caesar Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user then encrpted using MorseCode
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Morse_code
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingMorseCode(string t_sentenceToGetEncrypted) const
{
    // credentials
    string morse_code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----","..---","...--","....-",".....","-....","--....","---..", "----."};

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
            // fetch the character's position in abc
            int position_in_alphabet = Alphabet.find(chara);
            // get the corresponding morse companitation thereafter concatinate it with encrypted
            encrypted += morse_code[position_in_alphabet] + ' ';
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
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingMorseCode()
{
    m_EncryptedSenctence = Encryptor::EncryptUsingMorseCode(m_OriginalSenctence);

    // cipher used in encryption process: Morse code
    m_UsedCipher = "Morse Code";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user then encrpted using Simple Substitution Cipher
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Substitution_cipher
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingSimpleSubstitutionCipher(string t_sentenceToGetEncrypted) const
{
    // convert the message into uppercase
    for (auto &c : t_sentenceToGetEncrypted) c = toupper(c);

    // take the key
    cout << "key: ";
    string key;
    getline(cin >> ws, key);

    // convert key into uppercase
    for (auto &c : key) c = toupper(c);

    string modified_alphabet = "";

    // add the key letter's to the beggining of the modified abc
    for (int i = 0; i < key.length(); ++i)
    {
        modified_alphabet += key[i];
    }

    ModifyAlphabet(modified_alphabet, Alphabet, key);
    string encrypted = "";
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
            int position_in_alphabet = Alphabet.find(chara);
            char new_chara = modified_alphabet[position_in_alphabet];
            encrypted += new_chara;
        }
    }

    // return the encrypted message
    return encrypted;
}


/**
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingSimpleSubstitutionCipher()
{
    m_EncryptedSenctence = Encryptor::EncryptUsingSimpleSubstitutionCipher(m_OriginalSenctence);

    // cipher used in encryption process: Simple Substitution Cipher
    m_UsedCipher = "Simple Substitution Cipher";

    // senctence has been encrypted
    m_IsEncrypted = true;
}


/**
 * @brief This function takes a sentence from user then encrpted using MorseCode
 * @details For details on affice cipher check this link: https://en.wikipedia.org/wiki/Morse_code
 * @details this function doesn't deal with the instance attributes, it's an overload for the basic one 
 * @param t_sentenceToGetEncrypted Original sentence (will be encrypted)
 * @return string Senctenc after being encrypted (Encrypted sentence)
 */
string Encryptor::EncryptUsingVignereCipher(string t_sentenceToGetEncrypted) const
{
    // conver all the message's letters into uppercase
    for (auto &c: t_sentenceToGetEncrypted) c = toupper(c);


    // take the key from the user
    cout << "Key: ";
    string key;
    getline(cin >> ws, key);

    //conver all the key's letter into uppercase
    for (auto &c: key) c = toupper(c);
    

    int count = 0;
    string repted_key;

    for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
    {
        if (count > key.length() - 1)
        {
            count = Mod(count, key.length());
        }

        char chara = key[count];
        repted_key += chara;
        count ++;
    }


    // encrypting credentials
    string encrypted = "";
    int ascii_of_a = int(Alphabet[0]);
    char chara_from_message, chara_from_repted, new_chara;
    int ascii_of_chara_repetd, ascii_of_chara_message;

    for (int i = 0; i < t_sentenceToGetEncrypted.length(); ++i)
    {
        // note that both of message and repted key have the same length
        

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

        chara_from_repted = repted_key[i];
        ascii_of_chara_repetd = int(chara_from_repted);
        
        new_chara = ascii_of_a +  (Mod((ascii_of_chara_message + ascii_of_chara_repetd), 26));
        encrypted += new_chara;
    }

    // return the encrypted message
    return encrypted;

}


/**
 * @brief The Basic Encyrpting that object uses to encrypte instance attribute
 * @details This function is based on the overloaded version: look above
 */
void Encryptor::EncryptUsingVignereCipher()
{
    m_EncryptedSenctence = Encryptor::EncryptUsingVignereCipher(m_OriginalSenctence);

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
    encryptor.SetSentenceToEncrypt(s);

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
    output << "Original Sentence ( Unencrypted ): " << encryptor.GetOriginalSenctence() << "\n" << "Encrypted Senctence: " << encryptor.GetEncryptedSentence() << "\n" << "Used Cipher: " << encryptor.GetUsedCipher() << "\n";

    // return refrence to ostream (incase there is more than one << )
    return output;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* ( Helper Functions ) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return long 
 */
long Encryptor::Mod(int a, int b) const { return (a%b + b) % b; }


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
string Encryptor::GenerateId(int totalNumberOfEncryptors)
{
    /* formula: EN-CurrentNumberOfEncryptors */

    // string to hold the answer
    string id = "";

    // add prefix En- to it
    id += "ENC-";

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
