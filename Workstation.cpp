// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 03-04-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"

// Global variables
namespace seneca {
std::deque<CustomerOrder> g_pending{};
std::deque<CustomerOrder> g_completed{};
std::deque<CustomerOrder> g_incomplete{};
}


seneca::Workstation::Workstation(const std::string str): seneca::Station(str) {}

void seneca::Workstation::fill(std::ostream& os){
    if (!m_orders.empty())
        m_orders.front().fillItem(*this, os);
}

bool seneca::Workstation::attemptToMoveOrder(){
    bool attempt{};

    if(!m_orders.empty()){
        
        if (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() == 0){
            if (m_pNextStation)
                *m_pNextStation += std::move(m_orders.front());
            
            else if(m_orders.front().isOrderFilled())
                g_completed.push_back(std::move(m_orders.front()));
            else
                g_incomplete.push_back(std::move(m_orders.front()));
        
            m_orders.pop_front();
            attempt = true;
        }
    }
    return attempt;
}

void seneca::Workstation::setNextStation(Workstation* station){
    m_pNextStation = station;
}

seneca::Workstation* seneca::Workstation::getNextStation() const{
    return m_pNextStation;
}

void seneca::Workstation::display(std::ostream& os) const{
    if (m_pNextStation)
        os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
    else
        os << getItemName() << " --> " << "End of Line" << std::endl;
}

seneca::Workstation& seneca::Workstation::operator+=(CustomerOrder&& newOrder){
    m_orders.push_back(std::move(newOrder));
    return *this;
}