// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 11-03-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <string>
#include "Utilities.h"

namespace seneca{
    class Station{
        int m_stationID{};  // Station ID
        std::string m_itemName{};   // Name of the item handled by the station
        std::string m_description{};    // Description of the station
        unsigned m_nextSerialNum{};  // Next serial number to be assigned
        unsigned m_stockQuantity{}; // Number of items currently in stock

        // class variables
        static size_t m_widthField; // Maximum width for the item name
        static int id_generator; // ID generator for creating unique IDs
        
        public:
        // Constructor
        Station(const std::string& record);

        // Accessor for item name
        const std::string& getItemName() const;

        // Function to get the next serial number and increment
        size_t getNextSerialNumber();

        // Accessor for quantity
        size_t getQuantity() const;

        // Function to update quantity
        void updateQuantity();

        // Function to display station information
        void display(std::ostream& os, bool full) const;
    };
} // namespace seneca 


#endif