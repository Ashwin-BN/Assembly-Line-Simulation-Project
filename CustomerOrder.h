// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 03-04-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "Utilities.h"
#include "Station.h"

namespace seneca{
    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };

    class CustomerOrder{
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item** m_lstItem{};

        static size_t m_widthField;

        public:
        // Constructors 
        CustomerOrder(){}
        CustomerOrder(const std::string& str);
        
        // Copy constructor and operator
        CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;

        // Move constructor and operator
		CustomerOrder(CustomerOrder&& src)noexcept;
		CustomerOrder& operator=(CustomerOrder&& src)noexcept;
		
        // Destructor
        ~CustomerOrder();

        // Returns true if all the items in the order have been filled
		bool isOrderFilled() const;
		
        // Returns true if all items specified by itemName have been filled
        bool isItemFilled(const std::string& itemName) const;
		
        // Fills one item in current order that Station specified in first parameter handles
        void fillItem(Station& station, std::ostream& os);
		
        void display(std::ostream& os) const;
    };
}

#endif
