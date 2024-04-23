// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 11-03-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include "Station.h"

size_t seneca::Station::m_widthField = 0;
int seneca::Station::id_generator = 0;

// Constructor
seneca::Station::Station(const std::string& record){
    m_stationID = ++id_generator;

    Utilities util;

    size_t next_pos{};
    bool more{true};

    m_itemName = util.extractToken(record, next_pos, more);
    m_nextSerialNum = std::stoul(util.extractToken(record, next_pos, more));
    m_stockQuantity = std::stoul(util.extractToken(record, next_pos, more));
    
    if (m_widthField < util.getFieldWidth())
         m_widthField = util.getFieldWidth();
    
    m_description = util.extractToken(record, next_pos, more);
}

// Accessor for item name
const std::string& seneca::Station::getItemName() const{
    return m_itemName;
}

// Function to get the next serial number and increment
size_t seneca::Station::getNextSerialNumber(){
    return m_nextSerialNum++;
}

// Accessor for quantity
size_t seneca::Station::getQuantity() const{
    return m_stockQuantity;
}

// Function to update quantity
void seneca::Station::updateQuantity(){
    if(m_stockQuantity > 0)
        m_stockQuantity--;
}

// Function to display station information
void seneca::Station::display(std::ostream& os, bool full) const{
    if(full){
        os << std::right << std::setfill('0') << std::setw(3) << m_stationID << " | " ;
        os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_itemName << " | ";
        os << std::right << std::setfill('0') << std::setw(6) << m_nextSerialNum << " | ";
        os << std::right << std::setfill(' ') << std::setw(4) << m_stockQuantity << " | " << m_description << std::endl;

    }
    else{
        os << std::setfill('0') << std::setw(3) << m_stationID << " | "; 
        os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_itemName << " | " << std::right;
        os << std::setfill('0') << std::setw(6) << m_nextSerialNum << " | " << std::endl;
    }
}