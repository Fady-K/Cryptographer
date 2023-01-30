/**
 * @file Utility.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief This is a utiltiy class comprised of helper functions 
 * @details All function withing this class are static as they will get callled via class not object
 */
class Utility
{
    /* Helper functions */
public:

    /**
     * @brief Takes a vector of T type, then using linear search returns the index of the target 
     * 
     * @tparam T Vector data type
     * @param v Vector 
     * @param target Item to return its index 
     * @return int Index
     */
    template <typename T>
    static int GetIndex(vector<T> v, T target);


    /**
     * @brief Perform modular operation
     * 
     * @param a 
     * @param b 
     * @return long outcome of a % b
     */
     static long Mod(int a, int b);


    /**
     * @brief Checks if the given string is comprised of alphabet only or not
     * 
     * @param s String to check
     * @return true if comprised of alphabet letters only
     * @return false otherwise
     */
    static bool IsComprisedOfAbc(const string& s);


    

};
