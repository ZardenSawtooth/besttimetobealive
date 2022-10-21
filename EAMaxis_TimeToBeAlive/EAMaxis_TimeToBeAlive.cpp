#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace eamaxis {

    const int MAX_YEARS = 1994;

    std::vector<int> best_time_to_be_alive(const int *years) {
        std::vector<int> best_period = { 0, 0 };
        if (!years)
            return best_period;

        int best_total = 0;
        int current_total = 0;
        bool period_start = false;

        for (int i = 0; i < MAX_YEARS; ++i) {
            current_total += years[i];

            if (current_total == best_total && !period_start || current_total > best_total) {
                best_total = current_total;
                best_period[0] = i;
                period_start = true;
            }
            else if (current_total < best_total && period_start) {
                best_period[1] = i-1;
                period_start = false;
            }
        }

        if (best_period[1] < best_period[0])
            best_period[1] = MAX_YEARS-1;
        return best_period;
    }

    bool read_file(std::string filename, int* output) {
        if (!output)
            return false;

        std::string line;
        std::ifstream data_file(filename);
        if (data_file.good() && data_file.is_open()) {
            while (std::getline(data_file, line))
            {
                output[std::stoi(line.substr(1, 4))] += 1;
                std::string death_year = line.substr(6, 4);
                if (!std::isspace(death_year[0]) && std::stoi(death_year) < MAX_YEARS-1) {
                    output[std::stoi(death_year) + 1] -= 1;
                }
            }
            data_file.close();
        }
        else {
            std::cout << "Unable to open file.\n";
            return false;
        }
        return true;
    }
};

    int main()
    {
        std::string filename = "../data/BestTimeToBeAlive_dataset.txt";
        
        int years[eamaxis::MAX_YEARS] = { 0 }; 

        if (eamaxis::read_file(filename, years)) {
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
            std::cout << "\nThe best time to be alive is from " << best_period[0] << " to " << best_period[1] ;
        }

        std::cin.ignore();
        return 0;
    }
