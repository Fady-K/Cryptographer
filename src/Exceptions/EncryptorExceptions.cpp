#include "../../include/Exceptions/EncryptorExceptions.hpp"


/**
 * @brief 
 * 
 * @return EncryptorExceptions:: 
 */
EncryptorExceptions::EncryptorExceptions(): m_Message(""){}


/**
 * @brief Construct a new Encryptor Exceptions:: Encryptor Exceptions object
 * 
 * @param t_message 
 */
EncryptorExceptions::EncryptorExceptions(string t_message): m_Message(t_message){}


/**
 * @brief Destroy the Encryptor Exceptions:: Encryptor Exceptions object
 * 
 */
EncryptorExceptions::~EncryptorExceptions(){}



const char* EncryptorExceptions::what() const 
{
    return m_Message.c_str();
}