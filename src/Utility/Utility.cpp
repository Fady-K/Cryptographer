/**
 * @file Utility.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../include/Utility/Utility.hpp"

template <class T>
int Utility::GetIndex(const vector<T>& v, const T& target)
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


long Utility::Mod(const int& a, const int& b)
{
    return (a%b + b) % b;

}


bool Utility::IsComprisedOfAbc(const string& s)
{
    // flag, initialized as true
    bool ans = true;
    // iterate over each letter
    for (size_t i = 0; i < s.length(); ++i)
    {
        // if not alpha, then break and return false
        if (!isalpha(s[i]))
        {
            ans = false;
            break;
        }
    }

    // return the answer
    return ans;
}
