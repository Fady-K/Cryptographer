#include "../../include/Exceptions/DecryptorExceptions.hpp"


/**
 * @brief 
 * 
 * @return DecryptorExceptions:: 
 */
DecryptorExceptions::DecryptorExceptions(): m_Message(""){}


/**
 * @brief Construct a new Decryptor Exceptions:: Decryptor Exceptions object
 * 
 * @param t_message 
 */
DecryptorExceptions::DecryptorExceptions(string t_message): m_Message(t_message){}


/**
 * @brief Destroy the Decryptor Exceptions:: Decryptor Exceptions object
 * 
 */
DecryptorExceptions::~DecryptorExceptions(){}



const char* DecryptorExceptions::what() const 
{
    return m_Message.c_str();
}