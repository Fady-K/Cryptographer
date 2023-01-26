#include "../include/Decryptor.hpp"
const string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Static Attributes and Methods */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 
 * 
 */
int Decryptor::m_TotalNoDecryptors = 0;

/**
 * @brief 
 * 
 */
int Decryptor::m_CurrentNoDecryptors = 0;


/* Static methods */
int Decryptor::GetTotalNumberOfObjectsThisClassMade(){ return m_TotalNoDecryptors; }
int Decryptor::GetTotalNumberOfAliveObjects(){ return m_CurrentNoDecryptors; }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Big5 and Parametrized constructor */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Construct a new Decryptor:: Decryptor object
 * @details Default contructor
 */
Decryptor::Decryptor(): Encryptor::Encryptor(), m_DecryptedSentence("None"), m_IsDecrypted(false)
{
    // Reduce both Encryptor class counters as it's a decryptor object (Fixed Bug)
    Encryptor::m_CurrentNoObjects --;
    Encryptor::m_NoObjects --;

    // increament decryptors by one 
    Decryptor::m_TotalNoDecryptors ++;
    Decryptor::m_CurrentNoDecryptors ++;

    // decryptor id is comprisd of the prefix Dec+NoDecryptors
    m_Id = Encryptor::GenerateId(Decryptor::m_TotalNoDecryptors, false);
}


/**
 * @brief Construct a new Decryptor:: Decryptor object
 * 
 * @param t_sentence 
 */
Decryptor::Decryptor(string t_sentence): Encryptor::Encryptor(t_sentence), m_DecryptedSentence("None"), m_IsDecrypted(false)
{
    // Reduce both Encryptor class counters as it's a decryptor object (Fixed Bug)
    Encryptor::m_CurrentNoObjects --;
    Encryptor::m_NoObjects --;

    // increament decryptors by one 
    Decryptor::m_TotalNoDecryptors ++;
    Decryptor::m_CurrentNoDecryptors ++;

    // decryptor id is comprisd of the prefix Dec+NoDecryptors
    m_Id = Encryptor::GenerateId(Decryptor::m_TotalNoDecryptors, false);
}



Decryptor::Decryptor(const Decryptor& t_decryptor): m_DecryptedSentence(t_decryptor.m_DecryptedSentence), m_IsDecrypted(t_decryptor.m_IsDecrypted)
{
    // Reduce both Encryptor class counters as it's a decryptor object (Fixed Bug)
    Encryptor::m_CurrentNoObjects --;
    Encryptor::m_NoObjects --;

    // increament decryptors by one 
    Decryptor::m_TotalNoDecryptors ++;
    Decryptor::m_CurrentNoDecryptors ++;

    // decryptor id is comprisd of the prefix Dec+NoDecryptors
    m_Id = Encryptor::GenerateId(Decryptor::m_TotalNoDecryptors, false);
}



Decryptor& Decryptor::operator= (const Decryptor& t_decryptor)
{
    // do the copy
    this->m_DecryptedSentence = t_decryptor.m_DecryptedSentence;
    this->m_IsDecrypted = t_decryptor.m_IsDecrypted;

    // return this after coping 
    return *this;
}


/**
 * @brief Destroy the Decryptor:: Decryptor object
 * 
 */
Decryptor::~Decryptor()
{
    // decreament current decryptors by one 
    Decryptor::m_CurrentNoDecryptors --;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Instance Methods ( Setters and Getters ) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 
 * 
 * @return string 
 */
string Decryptor::GetDecryptedSentence() const { return m_DecryptedSentence; }


/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Decryptor::IsSentenceGotDecrypted() const { return m_IsDecrypted; }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Instance Methods ( Ciphers ) */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief this function decrypt a message was decrypted using affine cipher
 * @details Decryption formula ((i * n) + 1) / a;
 * @a thanks to https://www.geeksforgeeks.org/implementation-affine-cipher/
 * @param t_sentence encrypted sentence
 * @return string decrypted sentence
 */
string Decryptor::AffineCipher(string t_sentence) const 
{
    cout << "Enter The value of (c, b) Where c / (y - b) % 26 Is The Formula of Decryption: ";
    int c, b;
    cin >> c >> b;


    string decrypted = "";
    int a_inv = 0;
    int flag = 0;
     
    //Find a^-1 (the multiplicative inverse of a
        //in the group of integers modulo m.)
    for (int i = 0; i < 26; i++)
    {
        flag = (c * i) % 26;
         
        //Check if (a*i)%26 == 1,
                //then i will be the multiplicative inverse of a
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < t_sentence.length(); i++)
    {
        if(t_sentence[i]!=' ')
            /*Applying decryption formula a^-1 ( x - b ) mod m
            {here x is t_sentence[i] and m is 26} and added 'A'
            to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
            decrypted = decrypted +
                       (char) (((a_inv * ((t_sentence[i]+'A' - b)) % 26)) + 'A');
        else
            //else simply append space character
            decrypted += t_sentence[i];
    }
 
    // return the decrypted message
    return decrypted;
}


void Decryptor::AffineCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::AffineCipher(this->m_OriginalSenctence);

    // cipher used in decrypting process: affine cipher
    m_UsedCipher = "Affine Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}



string Decryptor::AtpashCipher(string t_sentenceToGetDecrypted) const 
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


void Decryptor::AtpashCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::AtpashCipher(this->m_OriginalSenctence);

    // cipher used in decrypting process: atpash cipher
    m_UsedCipher = "Atpash Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}




string Decryptor::BaconianCipher(string t_sentenceToGetDecrypted) const 
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


void Decryptor::BaconianCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::BaconianCipher(this-> m_OriginalSenctence);

    // cipher used in decrypting process: Baconian Cipher
    m_UsedCipher = "Baconian Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}



string Decryptor::CaesarCipher(string t_sentenceToGetDecrypted) const 
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


void Decryptor::CaesarCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::CaesarCipher(this-> m_OriginalSenctence);

    // cipher used in decrypting process: Caesar Cipher
    m_UsedCipher = "Caesar Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}


string Decryptor::MorseCode(string t_sentenceToGetDecrypted) const 
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


void Decryptor::MorseCode()
{
    // dry
    m_DecryptedSentence = Decryptor::MorseCode(this-> m_OriginalSenctence);

    // cipher used in decrypting process: Morse-Code
    m_UsedCipher = "Morse-Code";

    // senctence has been decrypted
    m_IsDecrypted = true;
}


string Decryptor::SimpleSubstitutionCipher(string t_sentenceToGetDecrypted) const 
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


void Decryptor::SimpleSubstitutionCipher()
{
    // dry
    m_DecryptedSentence = Decryptor::SimpleSubstitutionCipher(this-> m_OriginalSenctence);

    // cipher used in decrypting process: Simple Substitution Cipher
    m_UsedCipher = "Simple Substitution Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Operatos Overloading (bitwise) (compile time polymorshism) */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 
 * 
 * @param input 
 * @param decryptor 
 * @return istream& 
 */
istream& operator>>(istream& input, Decryptor& decryptor)
{
    // take sentence to get decrypted
    string s;
    input >> s;

    // set this s
    decryptor.SetSentence(s);

    return input;
}


/**
 * @brief 
 * 
 * @param output 
 * @param decryptor 
 * @return ostream& 
 */
ostream& operator<<(ostream& output, const Decryptor& decryptor)
{
    // print the encrpytor
    output << "---- Decryptor Details ----\n";
    output << "Id: "<< decryptor.GetId() << "\n" <<"Original Sentence ( Undecrypted ): " << decryptor.GetOriginalSenctence() << "\n" << "Decrypted Senctence: " << decryptor.GetDecryptedSentence() << "\n" << "Used Cipher: " << decryptor.GetUsedCipher() << "\n";

    // return ostream& incase there are more than one <<
    return output;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														/* Helper Functions */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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