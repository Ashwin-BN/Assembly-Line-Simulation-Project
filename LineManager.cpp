// Name: Ashwin B N
// Seneca Student ID: 112763222
// Seneca email: abharathan-nettoor@myseneca.ca
// Date of completion: 03-04-2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"


seneca::LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations){
    seneca::Utilities util;
    
    // Opening file and throwing exception 
    std::ifstream fs(file);
    if (!fs.is_open())
        throw std::string("Unable to open file: ") + file;

    try {
        std::string line;
        while (std::getline(fs, line)) {
            if (!line.empty()) {
                std::string curStation{}, nextStation{};
                size_t pos{};
                bool more{};

                // Extract current and next stations from the line
                curStation = util.extractToken(line, pos, more);
                nextStation = more ? util.extractToken(line, pos, more) : "";

                // Lambda function to find a station by its name
                auto findStation = [&](const std::string& stationName) {
                    auto it = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
                        return station->getItemName() == stationName;
                    });
                    if (it == stations.end())
                        throw std::string("Station not found: ") + stationName;
                    return *it;
                };

                // Find and add current station to the active line
                Workstation* cur = findStation(curStation);
                m_activeLine.push_back(cur);

                // Set next station if exists
                if (!nextStation.empty()) {
                    Workstation* next = findStation(nextStation);
                    cur->setNextStation(next);
                }
            }
        }

        // Lambda function to find the first station
        auto findFirstStation = [&]() {
            for (Workstation* station : m_activeLine) {
                auto it = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
                    return ws->getNextStation() == station;
                });
                if (it == m_activeLine.end()) {
                    m_firstStation = station;
                    break;
                }
            }
        };
        findFirstStation();
        
        // Initialize the count of customer orders
        m_cntCustomerOrder = g_pending.size();

    // Handling exceptions   
    } catch (const std::exception& e) {
        throw std::string("Error in LineManager constructor: ") + e.what();
    } catch (...) {
        throw std::string("Unknown error in LineManager constructor.");
    }

}

// Method to reorder stations
void seneca::LineManager::reorderStations(){
    std::vector<Workstation*> orderedStations;
    orderedStations.push_back(m_firstStation);

    while (orderedStations.back()->getNextStation()) {
        orderedStations.push_back(orderedStations.back()->getNextStation());
    };

    m_activeLine = orderedStations;
}

bool seneca::LineManager::run(std::ostream& os){
    static int cnt = 1;  //count how many times the function has been called
      os << "Line Manager Iteration: " << cnt << std::endl;
      cnt++;
      if (!g_pending.empty()){
         *m_firstStation += std::move(g_pending.front()); //moves the order at the front of the g_pending queue to the m_firstStationand remove it from the queue.
         g_pending.pop_front();
      }
      //for each station on the line, executes one fill operation
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* workStation) {
         workStation->fill(os);
         });
      //for each station on the line, attempts to move an order down the line
      for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* workStation) {
         workStation->attemptToMoveOrder();
         });
      return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;

}

void seneca::LineManager::display(std::ostream& os) const{
    for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* ws) {
        ws->display(os);
    });
}