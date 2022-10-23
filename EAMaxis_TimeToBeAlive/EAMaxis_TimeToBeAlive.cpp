#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace eamaxis {

    const int MAX_YEARS = 1994;

    bool read_dates(std::string filename, int* output_array, int max_count) {
        if (!output_array)
            return false;

        std::string line;
        std::ifstream data_file(filename);
        if (data_file.good() && data_file.is_open()) {
            while (std::getline(data_file, line))
            {
                output_array[std::stoi(line.substr(1, 4))] += 1;
                std::string death_year = line.substr(6, 4);
                if (!std::isspace(death_year[0]) && std::stoi(death_year) < max_count - 1) {
                    output_array[std::stoi(death_year) + 1] -= 1;
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

    std::vector<int> best_time_to_be_alive(std::string filename) {

        std::vector<int> best_period = { 0, 0 };
        int years[eamaxis::MAX_YEARS] = { 0 };

        bool success = read_dates(filename, years, eamaxis::MAX_YEARS);
        if (!success)
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

        if (best_period[1] < best_period[0] || best_period[1] == 0)
            best_period[1] = MAX_YEARS-1;
        return best_period;
    }
};

    int main()
    {
        std::string filename = "../data/BestTimeToBeAlive_dataset.txt";

        std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
        std::cout << "\nThe best time to be alive is from " << best_period[0] << " to " << best_period[1] << "\n";

        std::cin.ignore();
        return 0;
    }
