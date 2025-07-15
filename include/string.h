#ifndef string_H
#define string_H

#include "boolean.h"

/**
 * @brief Maximum number of characters a string can contain.
 */
const int MAX = 80; 
/**
 * @typedef string
 * @brief Dynamic array of characters.
 */
typedef char * string;

/**
 * @fn strcrear
 * @brief Create an empty string with a NULL character.
 * 
 * This function initializes a single-character string by placing a NULL ('0') character at the beginning.
 * 
 * @param str The string to be initialized. It must be an array of characters (char*).
 */
void strcrear (string &str);

/**
 * @fn strdestruir
 * @brief Destroy a string and set the pointer to NULL.
 * 
 * This function frees up memory from the string and sets the pointer to NULL to prevent memory leaks or 
 * invalid access to an address.
 * 
 * @param str The string to be destroyed. It must be an array of characters (char*).
 */
void strdestruir (string &str);

/**
 * @fn strlar
 * @brief Returns the length of a string.
 * 
 * This function returns the length of a null-terminated character array (string).
 * 
 * @param str The string whose length is to be determined.
 * 
 * @pre \p str must be initialized before calling this function. If the string is not initialized, 
 * the function may access invalid memory addresses and return an incorrect result.
 */

int strlar (string str);

/**
 * @fn strcop
 * @brief Copies a string to another string.
 * 
 * This function copies the second string into the first string.
 * 
 * @param str1 The destination string where the second string will be copied.
 * @param str2 The source string to be copied into the first string.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and copy garbage characters.
 */
void strcop (string &str1, string str2);

/**
 * @fn scan
 * @brief Captures a string from the keyboard.
 * 
 * This function allows the user to input a string and places a NULL character ('\0') at the beginning.
 * 
 * @param str The string where the input will be stored.
 */
void scan (string &str);

/**
 * @fn strcon
 * @brief Concatenates the second string at the end of the first.
 * 
 * This function appends the content of \p str2 to \p str1.
 * 
 * @param str1 The target string where \p str2 will be concatenated at the end.
 * @param str2 The string to be concatenated at the end of \p str1.
 * 
 * @pre Both \p str1 and \p str2 must be initialized to avoid undefined behavior.
 */
void strcon (string &str1, string str2);

/**
 * @brief Swaps the content of two strings.
 * 
 * This function exchanges the content of \p str1 and \p str2.
 * 
 * @param str1 The first string to be swapped.
 * @param str2 The second string to be swapped.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and swap garbage characters.
 */
void strswp (string &str1, string &str2);


/**
 * @fn print
 * @brief Prints a string.
 * 
 * This function outputs the content of the given string to the console.
 * 
 * @param str The string to be printed.
 * 
 * @pre Both @p str must be initialized before calling this function. 
 * If this string are not initialized, the function may access invalid memory addresses 
 * and print garbage characters.
 */
void print (string str);

/**
 * @fn strmen
 * @brief Compares two strings to determine if the first is lexicographically smaller.
 * 
 * This function returns true if \p str1 is lexicographically smaller than \p str2, and false otherwise.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and compare garbage characters.
 * 
 * @return \p true if \p str1 is smaller than \p str2, \p false otherwise.
 */
boolean strmen (string str1, string str2);

/**
 * @fn streq
 * @brief Compares two strings for equality.
 * 
 * This function returns true if \p str1 and \p str2 are equal, and false otherwise.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * 
 * @pre Both @p str1 and @p str2 must be initialized before calling this function. 
 * If these strings are not initialized, the function may access invalid memory addresses 
 * and compare garbage characters.
 * 
 * @return \p true if \p str1 is equal to \p str2, \p false otherwise.
 */
boolean streq (string str1, string str2);

/**
 * @brief Checks if a string contains only alphabetic characters.
 * 
 * @param str The string to be checked.
 * @return \p true if the string is alphabetic, \p false otherwise.
 * @pre The string must not be empty.
 */
boolean esAlfabetico (string str);

/**
 * @brief Checks if a string contains only numeric characters.
 * 
 * @param str The string to be checked.
 * @return \p true if the string is numeric, \p false otherwise.
 * @pre The string must not be empty.
 */
boolean esNumerico (string str);

/**
 * @brief Converts a numeric string to an integer.
 * 
 * This function converts a string containing only numeric characters into an integer.
 * 
 * @param str The numeric string to be converted.
 * @return The integer representation of the string.
 * @pre The string must contain only numeric characters.
 */
int convertirStringNumerico (string str);

/**
 * @brief Checks if a numeric string represents a nonzero value.
 * 
 * @param str The numeric string to be checked.
 * @return \p true if the numeric string is not zero, \p false otherwise.
 * @pre The string must contain only numeric characters.
 */
boolean distintoCero (string str);

/**
 * @brief Adds an extension to a string.
 * 
 * This function appends a predefined file extension to a given string.
 * 
 * @param str The string where the extension will be added.
 */
void agregarExtencion (string &str);

void AgregarCaracter (string &str, char car);


/**
 * @brief Writes a string to a file.
 * 
 * This function writes all characters of the string, including the null terminator, into the given file.
 * 
 * @param s The string to be written.
 * @param f The file where the string will be saved.
 * @pre The file must be open for writing.
 */
void Bajar_String (string s, FILE * f);

/**
 * @brief Reads a string from a file.
 * 
 * This function reads characters from the given file into a string.
 * 
 * @param s The string where the content will be stored.
 * @param f The file to read from.
 * @pre The file must be open for reading.
 */
void Levantar_String (string &s, FILE * f); 


#endif