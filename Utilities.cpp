// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 11-03-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
#include <algorithm>

char seneca::Utilities::m_delimiter{' '};

void seneca::Utilities::setFieldWidth(size_t newWidth){
    m_widthField = newWidth;
}

size_t seneca::Utilities::getFieldWidth() const{
    return m_widthField;
}

std::string seneca::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    std::string nextToken;
    size_t delim_pos = str.find(getDelimiter(), next_pos);

    // delimiter not found
    if (delim_pos == std::string::npos) {
        nextToken = str.substr(next_pos);
        // Removing leading & trailing whitespaces
        trim(nextToken);
        more = false;
        if (m_widthField < nextToken.length())
            m_widthField = nextToken.length();
    } 
    // delimiter found at next_pos
    else if (delim_pos == next_pos) { 
        more = false;
        throw next_pos;
    } 
    // successful extraction
    else { 
        nextToken = str.substr(next_pos, delim_pos - next_pos);
        trim(nextToken);
        more = true;
        next_pos = delim_pos + 1;
        if (m_widthField < nextToken.length())
            m_widthField = nextToken.length();
    }
    return nextToken;
}

void seneca::Utilities::setDelimiter(char newDelimiter){
    m_delimiter = newDelimiter;
}
char seneca::Utilities::getDelimiter(){
    return m_delimiter;
}

void seneca::Utilities::trim(std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    
    if (first == std::string::npos)
        str.clear();
    else
        str = str.substr(first, last - first + 1);
}