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
const string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


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

/**
 * @brief Construct a new Decryptor:: Decryptor object
 * @details This is the default constructor, It initailzes instance attributes with values were determined by class maker 
 */
Decryptor::Decryptor(): m_OriginalSentence(""), m_DecryptedSentence("None"), m_UsedCipher("None"), m_IsDecrypted(false)
{
    // increment number of Decryptors by one
    Decryptor::m_NoDecryptors ++;
    Decryptor::m_NoCurrentDecryptors ++;

    // Decryptor id is comprisd of the prefix ENC+NoDecryptors
    m_Id = Decryptor::GenerateId(Decryptor::m_NoDecryptors);
}


/**
 * @brief Construct a new Decryptor:: Decryptor object
 * @details This a parametrized constructor that initailzes the class member (m_OriginalSentence) with a given sentence to Decrypt
 * @param t_sentence A given sentence desired to get Decrypted via Decryptor object
 */
Decryptor::Decryptor(string t_sentence): m_OriginalSentence(t_sentence), m_DecryptedSentence("None"), m_UsedCipher("None"), m_IsDecrypted(false) 
{
    // increment number of Decryptors by one
    Decryptor::m_NoDecryptors ++;
    Decryptor::m_NoCurrentDecryptors ++;

    // Decryptor id is comprisd of the prefix ENC+NoDecryptors
    m_Id = Decryptor::GenerateId(Decryptor::m_NoDecryptors);
}


/**
 * @brief Construct a new Decryptor:: Decryptor object
 * @details This a parametrized constructor that initailzes the class member (m_OriginalSentence) with a given sentence to Decrypt
 * @param t_sentence A given sentence desired to get Decrypted via Decryptor object
 */
Decryptor::Decryptor(const Decryptor& t_anotherDecryptor): m_OriginalSentence(t_anotherDecryptor.m_OriginalSentence), m_DecryptedSentence(t_anotherDecryptor.m_DecryptedSentence), m_UsedCipher(t_anotherDecryptor.m_UsedCipher), m_IsDecrypted(t_anotherDecryptor.m_IsDecrypted)
{
    // increment number of Decryptors by one
    Decryptor::m_NoDecryptors ++;
    Decryptor::m_NoCurrentDecryptors ++;

    // Decryptor id is comprisd of the prefix DEC+NoDecryptors
    m_Id = Decryptor::GenerateId(Decryptor::m_NoDecryptors);
}


/**
 * @brief An overload for copy assignment operator
 * @details It takes an object of the same type and copy its attributes values to this
 * @return Decryptor& the current object but after being copied
 */
Decryptor& Decryptor::operator= (const Decryptor& t_anotherDecryptor)
{
    // do the copy
    m_OriginalSentence = t_anotherDecryptor.m_OriginalSentence;
    m_DecryptedSentence = t_anotherDecryptor.m_DecryptedSentence;
    m_UsedCipher = t_anotherDecryptor.m_UsedCipher;
    m_IsDecrypted = t_anotherDecryptor.m_IsDecrypted;

    /* 
        return the exact object (*this) as it has just been copied 
        note: this operator returns an Decryptor object that why i dereferenced this pointer
    */
    return *this;
}


/**
 * @brief Destroy the Decryptor:: Decryptor object
 * 
 */
Decryptor::~Decryptor(){}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Instance methods (Setters, Getters) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Decryptor::SetSenctenceToDecrypt(string t_sentence){ m_OriginalSentence = t_sentence; }

string Decryptor::GetOriginalSentence() const { return m_OriginalSentence; }

string Decryptor::GetDecryptedSentence() const { return m_DecryptedSentence; }

string Decryptor::GetUsedCipher() const { return m_UsedCipher; }

string Decryptor::GetId() const { return m_Id; }

bool Decryptor::IsGivenSentenceGotDecrypted() const { return m_IsDecrypted; }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Instance Methods ( Ciphers ) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string Decryptor::DecryptUsingAffineCipher(string t_sentence) const 
{
    cout << "Enter The value of (c, b) Where c / (y - b) % 26 Is The Formula of Decryption: ";
    int c, b;
    cin >> c >> b;


    // convert all the t_sentence's letters into uppercase
    for (auto &c : t_sentence) c = toupper(c);
    
    string decrypted;
    char chara;
    int position_in_abc;
    int new_position;
    // for each chara in t_sentence
    for (int i = 0; i < t_sentence.length(); ++i)
    {
        chara = t_sentence[i];
        if (chara == ' ')
        {
            decrypted += " ";
            continue;

        }
        else
        { 

            position_in_abc = abc.find(chara);
            // utilizatin of mod_for_all function >> incase the outcome of the decypting formula is negative 
            new_position = Mod((c / (position_in_abc - b)), 26);
            char new_chara = abc[new_position];
            decrypted += new_chara;

        }
    }

    // return the decrypted t_sentenceToGetDecrypted
    return decrypted;

}


void Decryptor::DecryptUsingAffineCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::DecryptUsingAffineCipher(m_OriginalSentence);

    // cipher used in decrypting process: affine cipher
    m_UsedCipher = "Affine Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}



string Decryptor::DecryptUsingAtpashCipher(string t_sentenceToGetDecrypted) const 
{
     // store space'index
    string t_sentenceToGetDecrypted_without_space;

    int spaces_index[t_sentenceToGetDecrypted.length() + 1];
    int count = 0;
    for(int i = 0; i < t_sentenceToGetDecrypted.length(); i++)
        {

            if (t_sentenceToGetDecrypted[i] == ' ')
            {

                spaces_index[count] = i;
                count++;

            }
        }
    
        // to remove char from string 
    t_sentenceToGetDecrypted.erase(remove(t_sentenceToGetDecrypted.begin(),t_sentenceToGetDecrypted.end(), 32), t_sentenceToGetDecrypted.end());


    // convert string into upper case
    for(auto &c : t_sentenceToGetDecrypted) c = toupper(c);
    string inverted_abc = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string decrypted = "";

    // covert string into array of chars
    char chars_of_t_sentenceToGetDecrypted[t_sentenceToGetDecrypted.length() + 1];
    strcpy(chars_of_t_sentenceToGetDecrypted, t_sentenceToGetDecrypted.c_str());

    //loop over array of chars and fech each char's position in abs
    for (int i = 0; i < t_sentenceToGetDecrypted.length(); i++){
        
        char chara = t_sentenceToGetDecrypted[i];

        // position in abc >> find
        int position_in_abc = abc.find(chara);

        // get the equivilant encrpted char of inverted abc
        
        decrypted += inverted_abc[position_in_abc];
    }

    count = 0;
    string decryptedt_sentenceToGetDecrypted;


    int i = 0;
    while (i < t_sentenceToGetDecrypted.length())
    {

        if (spaces_index[count] == decryptedt_sentenceToGetDecrypted.length())
        {
            decryptedt_sentenceToGetDecrypted += ' ';
            count ++; 
        }

        decryptedt_sentenceToGetDecrypted += decrypted[i];
        i++;

    }

    // return the decrypted t_sentenceToGetDecrypted
    return decryptedt_sentenceToGetDecrypted;

}


void Decryptor::DecryptUsingAtpashCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::DecryptUsingAtpashCipher(m_OriginalSentence);

    // cipher used in decrypting process: atpash cipher
    m_UsedCipher = "Atpash Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}




string Decryptor::DecryptUsingBaconianCipher(string t_sentenceToGetDecrypted) const 
{
    string decrypted = "";

    // abc
    // vector of code >> i use vector as it's dynamic therefore i wil not want the user to enter the length
    vector<string> code = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};


    // string to form char
    string tmp = "";

    // decrypted t_sentenceToGetDecrypted
    for (int i = 0; i < t_sentenceToGetDecrypted.size(); ++i)
    {
        if (isspace(t_sentenceToGetDecrypted[i]))
        {
            // check next
            if(isalpha(t_sentenceToGetDecrypted[i - 1]))
            {
                // decrypt
                decrypted += abc[GetIndex(code, tmp)];

                // empty temp
                tmp = "";
            }
            else
            {
                // check three to add space
                if (isspace(t_sentenceToGetDecrypted[i + 1]) && isspace(t_sentenceToGetDecrypted[i + 2]))
                {
                    decrypted += " ";
                }
            }

        }
        else
        {
            // not space then check if alpha added to temp else append it to decrypted
            if (isalpha(t_sentenceToGetDecrypted[i]))
            {
                tmp += t_sentenceToGetDecrypted[i];
            }
            else
            { 
                decrypted += t_sentenceToGetDecrypted[i]; 
            }
            
            
            // calcualte the last temp
            if ((i == t_sentenceToGetDecrypted.size() - 1)) { decrypted += abc[GetIndex(code, tmp)]; }

        }
    }

    // return the decrypted
    return decrypted;
}


void Decryptor::DecryptUsingBaconianCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::DecryptUsingBaconianCipher(m_OriginalSentence);

    // cipher used in decrypting process: Baconian Cipher
    m_UsedCipher = "Baconian Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}



string Decryptor::DecryptUsingCaesarCipher(string t_sentenceToGetDecrypted) const 
{   
    // convert into upper case
    for (auto &c : t_sentenceToGetDecrypted) c = toupper(c);

    // take shift from user 
    cout << "shift: ";
    int shift;
    cin >> shift;
    
    int position_in_abc, new_position;
    string decrypted;

    for (int i = 0; i < t_sentenceToGetDecrypted.length(); ++i){
        char character = t_sentenceToGetDecrypted[i];
        if (isspace(character) || (isdigit(character)))
        {
            decrypted += character;
            continue;
        }
        else
        {
            position_in_abc = abc.find(character);
            new_position = Mod((position_in_abc - shift), 26);
            decrypted += abc[new_position];
        }
    }

    // return the decyprted 
    return decrypted;
}


void Decryptor::DecryptUsingCaesarCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::DecryptUsingCaesarCipher(m_OriginalSentence);

    // cipher used in decrypting process: Caesar Cipher
    m_UsedCipher = "Caesar Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}


string Decryptor::DecryptUsingMorseCode(string t_sentenceToGetDecrypted) const 
{   

    string morse_code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----","..---","...--","....-",".....","-....","--....","---..", "----."};

    t_sentenceToGetDecrypted = t_sentenceToGetDecrypted + ' ';

    // decrypted
    string decrypted, code;

    for (int i = 0; i < t_sentenceToGetDecrypted.length(); ++i)
    {
        if (isspace(t_sentenceToGetDecrypted[i]) == false)
        {
            code += t_sentenceToGetDecrypted[i];
        }
        // it's not space >> any way will conver code
        else
        {
            // iterate over the morse to check whether code in morse or not
            for (int x = 0; x < 36; ++x)
            { // code generated from the preivous loop (code) in morse_code, fetch the corresponding char from abc
                if (code == morse_code[x])
                {
                    decrypted += abc[x];
                    // empty the code again for the next code
                    code = "";
                }
            }
            // if the char after in the t_sentenceToGetDecrypted is space (two space arow) then append one space
            if (i != t_sentenceToGetDecrypted.length() + 1)
            {
                if (isspace(t_sentenceToGetDecrypted[i + 1]))
                {
                    decrypted += ' ';
                }
            }
        }
    }

    // return the decrypted
    return decrypted;
}


void Decryptor::DecryptUsingMorseCode()
{
    // dry
    m_DecryptedSentence = Decryptor::DecryptUsingMorseCode(m_OriginalSentence);

    // cipher used in decrypting process: Morse-Code
    m_UsedCipher = "Morse-Code";

    // senctence has been decrypted
    m_IsDecrypted = true;
}


string Decryptor::DecryptUsingSimpleSubstitutionCipher(string t_sentenceToGetDecrypted) const 
{   
    // convert into uppercase
    for (auto &c : t_sentenceToGetDecrypted)
        c = toupper(c);

    // key
    cout << "Key (Resticted To The Encryption Key): ";
    string key;
    getline(cin >> ws, key);

    // key to uppercase
    for (auto &c : key)
        c = toupper(c);

    string modified_abc = "";

    // add key to the begin of modified abc
    for (int i = 0; i < key.length(); ++i)
    {
        modified_abc += key[i];
    }

    // call modify function to modify abc
    ModifyAlphabet(modified_abc,abc, key);

    string decrypted = "";
    // iterate over the t_sentenceToGetDecrypted
    for (int i = 0; i < t_sentenceToGetDecrypted.length(); ++i)
    {
        // get the chara from the t_sentenceToGetDecrypted
        char chara = t_sentenceToGetDecrypted[i];

        // if chara digit or space append without modifing it
        if ((chara == ' ') || (isdigit(chara)))
        {
            decrypted += chara;
            continue;
        }

        else
        {
            // get it's position from modifed
            int position_in_modifed = modified_abc.find(chara);
            // get the chara which at same index in modified
            char new_chara =abc[position_in_modifed];
            decrypted += new_chara;
        }
    }

    // return decryted sentence
    return decrypted;

}


void Decryptor::DecryptUsingSimpleSubstitutionCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::DecryptUsingSimpleSubstitutionCipher(m_OriginalSentence);

    // cipher used in decrypting process: Simple Substitution Cipher
    m_UsedCipher = "Simple Substitution Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Operators Overloading (Bitwise) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>> (istream& input, Decryptor& decryptor)
{
    // string to store the value
    string s;
    getline(input >> ws, s);

    // set the taken s
    decryptor.SetSenctenceToDecrypt(s);
    
    // return istream incase there were more than one >>
    return input;
}


ostream& operator<< (ostream& output, const Decryptor& decryptor)
{
    // print the decryptor
    output << "---- Decryptor Details ----\n";
    output << "Id: " << decryptor.GetId() << "\n" << "Original Sentence ( Undencrypted ): " << decryptor.GetOriginalSentence() << "\n" << "Decrypted Senctence: " << decryptor.GetDecryptedSentence() << "\n" << "Used Cipher: " << decryptor.GetUsedCipher() << "\n";

    // return refrence to ostream (incase there is more than one << )
    return output;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Helper Functions */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long Decryptor::Mod(int a, int b) const { return (a%b + b) % b; }


void Decryptor::ModifyAlphabet(string &t_modifiedabc, string t_abc, string t_key) const 
{
    // first loop to fetch each char from abc
    for (int i = 0; i < t_abc.length(); ++i)
    {
        bool exist_in_key = false;
        char chara = t_abc[i];

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
            t_modifiedabc += chara;
        }
    }
}


/**
 * @brief Using linear search this function takes vector of type T and target then returns i of target in the vector. (i: index)
 * 
 * @tparam T vector type
 * @param v vector of type T
 * @param target 
 * @return int index of target in vector
 */
template <typename T>
int Decryptor::GetIndex(vector<T> v, T target) const
{
   for (size_t i = 0; i < v.size(); ++i)
   {
        if (v[i] == target)
        {
            return i;
        }
   }

   return -1;
}