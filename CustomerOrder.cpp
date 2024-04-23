// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 03-04-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"

size_t seneca::CustomerOrder::m_widthField{};

// Constructor
seneca::CustomerOrder::CustomerOrder(const std::string& str){
    seneca::Utilities utils;
    bool more = true;
    size_t next_pos = 0u;

    // Extract customer name, product, and count of items from the input string
    m_name = utils.extractToken(str, next_pos, more);
    m_product = utils.extractToken(str, next_pos, more);
    m_cntItem = std::count(str.begin(), str.end(), utils.getDelimiter()) - 1;

    if (m_cntItem)
        m_lstItem = new Item*[m_cntItem];

    unsigned i{};
    while (more && m_cntItem) {
        // Populate the list of items
        m_lstItem[i] = new Item(utils.extractToken(str, next_pos, more));
        ++i;
    }

    // Update the widthField
    CustomerOrder::m_widthField = std::max(utils.getFieldWidth(), CustomerOrder::m_widthField);
}
        
// Copy constructor and operator
seneca::CustomerOrder::CustomerOrder(const CustomerOrder& src){
    throw false;
}

// Move constructor and operator
seneca::CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept{
    *this = std::move(src);
}

seneca::CustomerOrder& seneca::CustomerOrder::operator=(CustomerOrder&& src)noexcept {
    if(this != &src){
        if(m_lstItem){
            for (size_t i = 0; i < m_cntItem; i++) 
               delete m_lstItem[i];
        
        delete[] m_lstItem;
        }

        m_name    = src.m_name;
        m_product = src.m_product;
        m_cntItem = src.m_cntItem;
        m_lstItem = src.m_lstItem;

        src.m_name    = "";
        src.m_product = "";
        src.m_cntItem = 0u;
        src.m_lstItem = nullptr;
    }
    return *this;
}

// Destructor
seneca::CustomerOrder::~CustomerOrder(){
    if (m_lstItem) {
        for (auto i = 0u; i < m_cntItem; ++i)
            delete m_lstItem[i];

        delete[] m_lstItem;
        m_lstItem = nullptr;
    }
}

// Returns true if all the items in the order have been filled
bool seneca::CustomerOrder::isOrderFilled() const{
    // Check if any item is not filled
    bool unfilledItemFound = std::any_of(m_lstItem, m_lstItem + m_cntItem, [](const Item* item) {
        return !item->m_isFilled;
    });
    
    // Return true if no unfilled item is found, false otherwise
    return !unfilledItemFound;
}
		
// Returns true if all items specified by itemName have been filled
bool seneca::CustomerOrder::isItemFilled(const std::string& itemName) const{
    bool result{true};
    for(size_t i{}; i < m_cntItem && result; ++i){
        // If the item name matches and it's not filled, set result to false
        if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
            result = false; 
    }
    return result;
}
		
// Fills one item in current order that Station specified in first parameter handles
void seneca::CustomerOrder::fillItem(Station& station, std::ostream& os){
    for (size_t i{}; i < m_cntItem; ++i) {
        if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
            if (station.getQuantity()) {
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                return;
            } else {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }
}
		
void seneca::CustomerOrder::display(std::ostream& os) const{
    os << m_name << " - " << m_product << std::endl;

    for (auto i = 0u; i < m_cntItem; ++i) {
      os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
      os << std::left << std::setw(CustomerOrder::m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName;
      os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
    }
}