// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 03-04-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "Workstation.h"

namespace seneca{
    class LineManager{
        std::vector<Workstation*> m_activeLine{};  // Collection of workstations for the assembly line
        size_t m_cntCustomerOrder{};               // Total number of CustomerOrder objects
        Workstation* m_firstStation{};             // Pointer to the first active station on the line


    public:
        // Constructor
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);

        // Modifier to reorder stations in assembly line
        void reorderStations();

        // Modifier to perform one iteration of operations on all workstations in assembly line
        bool run(std::ostream& os);

        // Query to display all active stations on assembly line
        void display(std::ostream& os) const;
    };
}
#endif