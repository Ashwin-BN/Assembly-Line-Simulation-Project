// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 11-03-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>
#include <string>

namespace seneca{
    class Utilities{
        size_t m_widthField{1}; // length of the token extracted (default 1)
        static char m_delimiter;    // separates the tokens in any given std::string

        public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

        // Trim leading and trailing whitespace from a string
        void trim(std::string& str);
    };
}
#endif