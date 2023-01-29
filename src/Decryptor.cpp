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
string Decryptor::AffineCipher(string t_sentence, const int& a, const int& b) const 
{
    string decrypted = "";
    int a_inv = 0;
    int flag = 0;
     
    /*
        * c and b constraints
        * a valid range: 0: 25
        * b valid values {1, 3, 5, 7, 9, 11, 15, 17, 19, 21}
    
    */
    try
    {
        // check for a range, valid range(0, 25);
        if (!(a >= 0 && a <= 25))
        {
            // handel the exception
            throw(DecryptorExceptions("Constant a is out of valid range 0 : 25 !"));
        }
        else if ((b % 2 == 0) || !(b >= 0 && b <= 25) || (b == 13))
        {
            // throw Decryptor exception
            throw(DecryptorExceptions("Constant b is a not valid!, Accepted values {1,3,5,7,9,11,15,17,19,21,23,25}"));
        }
        else
        {
            //Find a^-1 (the multiplicative inverse of a
            //in the group of integers modulo m.)
            for (int i = 0; i < 26; i++)
            {
                flag = (a * i) % 26;
                
                //Check if (a*i)%26 == 1,
                        //then i will be the multiplicative inverse of a
                if (flag == 1)
                {
                    a_inv = i;
                }
            }
        }
    }
    catch(DecryptorExceptions e)
    {
        // exception cause
        fprintf(stderr, "AffineCipher() faild in file %s at line # %d\n", __FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }
    
    try
    {
        // convert sentence upper case to overcome case sensitivity
        for (auto& c: t_sentence) c = toupper(c);
    
        // start decrypting process
        for (int i = 0; i < t_sentence.length(); i++)
        {
            if(isalpha(t_sentence[i]))
                /*Applying decryption formula a^-1 ( x - b ) mod m
                {here x is t_sentence[i] and m is 26} and added 'A'
                to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
                decrypted = decrypted +
                        (char) (((a_inv * ((t_sentence[i]+'A' - b)) % 26)) + 'A');
            else
                //else simply append space character
                decrypted += t_sentence[i];
        }
    }
    catch(exception e)
    {
        // exception cause
        fprintf(stderr, "AffineCipher() faild in file %s at line # %d\n", __FILE__, __LINE__);

        // error message (not a custom excpetion)
        cout << e.what() << endl;

        // exit failure
        exit(EXIT_FAILURE);
    }
 
    // return the decrypted message
    return decrypted;
}


void Decryptor::AffineCipher(const int& a, const int& b)
{
    // dry
    m_DecryptedSentence = Decryptor::AffineCipher(this->m_OriginalSenctence, a, b);

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
        
        // only if alpha else appended to decrypted
        if (isalpha(t_sentenceToGetDecrypted[i]))
        {
            // position in abc >> find
            int position_in_abc = abc.find(t_sentenceToGetDecrypted[i]);

            // get the equivilant encrpted char of inverted abc
            
            decrypted += inverted_abc[position_in_abc];
        }
        else
        {
            decrypted += t_sentenceToGetDecrypted[i];
        }

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



string Decryptor::CaesarCipher(string t_sentenceToGetDecrypted, const int& t_shift) const 
{   
    // convert into upper case
    for (auto &c : t_sentenceToGetDecrypted) c = toupper(c);
    
    int position_in_abc, new_position;
    string decrypted;

    try
    {
        // validate shift before start decoding
        // note: shift valid range 0: 25
        if (!(t_shift >= 0 && t_shift <= 25))           // if not in valid range
        {
            throw(DecryptorExceptions("Shift is out of valid range 0: 25!"));
        }
        else
        {
            for (int i = 0; i < t_sentenceToGetDecrypted.length(); ++i)
            {
                char character = t_sentenceToGetDecrypted[i];
                if (!isalpha(t_sentenceToGetDecrypted[i]))
                {
                    decrypted += character;
                }
                else
                {
                    try
                    {
                        // fetch it's position in abc
                        position_in_abc = abc.find(character);

                        // calculate it's new position based on the ecyrption formula f(x) = (x + shift) % 26
                        new_position = Mod((position_in_abc - t_shift), 26);

                        // fetch the decrypted char , and appended to the decrypted string
                        decrypted += abc[new_position];
                    }
                    catch(exception e)
                    {
                        // exception cause (where it happend)
                        fprintf(stderr, "CaesarCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

                        // error message
                        cout << e.what() << endl;

                        // exit the program
                        exit(EXIT_FAILURE);

                    }

                }
            }
        }
       
    }
    catch(DecryptorExceptions e)
    {
        // exception cause (where it happend)
        fprintf(stderr, "CaesarCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit the program
        exit(EXIT_FAILURE);

    }
    catch(exception e)
    {
        // exception cause (where it happend)
        fprintf(stderr, "CaesarCipher() failed in file %s at line # %d\n", __FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit the program
        exit(EXIT_FAILURE);
    }
   
    // return the decyprted message
    return decrypted;
}


void Decryptor::CaesarCipher(const int& t_shift)
{
    // dry
    m_DecryptedSentence = Decryptor::CaesarCipher(this-> m_OriginalSenctence, t_shift);

    // cipher used in decrypting process: Caesar Cipher
    m_UsedCipher = "Caesar Cipher";

    // senctence has been decrypted
    m_IsDecrypted = true;
}


string Decryptor::MorseCode(string t_sentenceToGetDecrypted) const 
{   
    // morse codes
    string morse_code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----","..---","...--","....-",".....","-....","--....","---..", "----."};

    // add space to sentence which will get decrypted
    t_sentenceToGetDecrypted = t_sentenceToGetDecrypted + ' ';

    // decryption credentials
    string decrypted, code;

    try
    {
        // check if the gived string is a morse code or not
        if (!IsMorseCode(t_sentenceToGetDecrypted))
        {
            throw(DecryptorExceptions("Invalid Letter!, Morse-Code is comprised of dots, dashes and spaces only!"));
        }
        else
        {
            // iterate over each letter to decrypt
            for (int i = 0; i < t_sentenceToGetDecrypted.length(); ++i)
            {
                // if not an alphanumric (nither an alphabet nor a digit), then appended any way
                if (!isspace(t_sentenceToGetDecrypted[i]))
                {
                    code += t_sentenceToGetDecrypted[i];
                }
                else
                {
                    // iterate over the morse to check whether code in morse or not
                    for (int x = 0; x < 36; ++x)
                    { 
                        // code generated from the preivous loop (code) in morse_code, fetch the corresponding char from abc
                        if (code == morse_code[x])
                        {
                            decrypted += abc[x];

                            // empty the code again for the next code
                            code = "";
                        }
                    }

                    // if the forward char in the t_sentenceToGetDecrypted is space (two spaces in a row) then append one space to decrtypted
                    if (i != t_sentenceToGetDecrypted.length() + 1)
                    {
                        if (isspace(t_sentenceToGetDecrypted[i + 1]))
                        {
                            decrypted += ' ';
                        }
                    }
                }
            }

        }

    }
    catch(DecryptorExceptions e)
    {
        // exception cause
        fprintf(stderr, "MorseCode() faild in file %s at line # %d\n", __FILE__, __LINE__);

        // print the error message
        cout << e.what() << endl;

        // exit the app
        exit(EXIT_FAILURE);
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


string Decryptor::SimpleSubstitutionCipher(string t_sentenceToGetDecrypted, const string& t_key) const 
{   
    // empty string to hold decrypted sentence
    string decrypted = "";

    // modifed alphabet
    string modified_abc = "";

    try
    {
        // convert the message into uppercase
        for (auto &c : t_sentenceToGetDecrypted) c = toupper(c);

        /*
         * key constraints
         * length == 26
         * can't include special characters or digits
        */

        if (!IsComprisedOfAbc(t_key))
        {
            throw(DecryptorExceptions("Key must be comprised alphabet letter only, can't have special characters or digits!"));
        }
        else if (t_key.length() != 26)
        {
            // throw invalid range
            throw(DecryptorExceptions("Key must be comprised of 26 char!"));

        }
        else
        {
            // take copy from t_key as it's can't be modifed (constant)
            string key = t_key;

            // key to uppercase
            for (auto &c : key)
                c = toupper(c);


            // add key to the begin of modified abc
            for (int i = 0; i < key.length(); ++i)
            {
                modified_abc += key[i];
            }

            // call modify function to modify abc
            ModifyAlphabet(modified_abc,abc, key);

            // iterate over the t_sentenceToGetDecrypted
            for (int i = 0; i < t_sentenceToGetDecrypted.length(); ++i)
            {
                // get the chara from the t_sentenceToGetDecrypted
                char chara = t_sentenceToGetDecrypted[i];

                // if chara digit or space append without modifing it
                if (!isalpha(chara))
                {
                    decrypted += chara;
                    continue;
                }

                else
                {
                    try
                    {
                        // get it's position from modified
                        int position_in_modifed = modified_abc.find(chara);

                        if (!(position_in_modifed >= 0 && position_in_modifed <= 25))
                        {
                            throw(string());
                        }
                        else
                        {
                            // get the chara which at same index in modified
                            char new_chara = abc[position_in_modifed];
                            decrypted += new_chara;
                        }

                    }
                    catch(string())
                    {
                        // error cause
                        fprintf(stderr, "SimpleSubstitutionCipher() proceded with error in file %s at line # line %d\n",__FILE__, __LINE__);

                        // program will processed but this message will be displayed
                        cout << "You have entered a character that has no equivalent in encrypted alphabet, (special characters cannot be decoded)!" << endl;
                    }
                }
            }

        }
    }
    catch(DecryptorExceptions e)
    {
        // error cause
        fprintf(stderr, "SimpleSubstitutionCipher() proceded with error in file %s at line # line %d\n",__FILE__, __LINE__);

        // error message
        cout << e.what() << endl;

        // exit the program
        exit(EXIT_FAILURE);

    }

    // return decryted sentence
    return decrypted;

}


void Decryptor::SimpleSubstitutionCipher(const string& t_key)
{
    // dry
    m_DecryptedSentence = Decryptor::SimpleSubstitutionCipher(this-> m_OriginalSenctence, t_key);

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


bool Decryptor::IsMorseCode(const string& s) const 
{
    // s is morse code if and only if it's comprised of . and _ including white space
    // flag to hold the answer
    bool ans = true;

    // iterate over each letter and check it's not a dot or _ , then it's not a morse code
    for (int i = 0; i < s.length(); ++i)
    {
        if (( s[i] != '-') && (s[i] != '.') && (!isspace(s[i])))
        {
            ans = false;
            break;
        }
    }

    // return the ans
    return ans;
}