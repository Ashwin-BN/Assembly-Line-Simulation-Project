// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 11-03-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca {
    // Global variables
    extern std::deque<CustomerOrder> g_pending;     // Holds orders to be placed onto the assembly line at the first station
    extern std::deque<CustomerOrder> g_completed;  // Holds orders that have been completely filled
    extern std::deque<CustomerOrder> g_incomplete;// Holds orders that could not be filled completely

    class Workstation : public Station{
        std::deque<CustomerOrder> m_orders{};   // Orders placed on this station
        Workstation* m_pNextStation{};         // Pointer to the next Workstation on the assembly line

    public:
        // Custom 1-argument constructor
        Workstation(const std::string str);

        // Disabled copy or move on this class object
        Workstation(const Workstation& src) = delete;
        Workstation& operator=(const Workstation& src) = delete;
        Workstation(Workstation&& src) = delete;
        Workstation& operator=(Workstation&& src) = delete;

        // Modifies order at the front of the queue if there are CustomerOrders in queue
        void fill(std::ostream& os);

        // Attempts to move the order at front of the queue to next station
        bool attemptToMoveOrder();

        // Stores the address of the referenced Workstation object in m_pNextStation
        void setNextStation(Workstation* station);

        // Returns the address of next Workstation
        Workstation* getNextStation() const;

        // Inserts the name of the Item for which the current object is responsible into stream os
        void display(std::ostream& os) const;

        // Moves the CustomerOrder referenced in parameter newOrder to the back of the queue
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif
