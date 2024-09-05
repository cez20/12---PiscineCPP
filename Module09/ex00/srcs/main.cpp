#include <iostream>
#include <fstream>
// #include "BitcoinExchange.hpp"
#include <map>
#include <fstream> // TODO: To be moved to .hpp
#include <map> // TODO: To be moved to .hpp
#include <sstream> //TODO: to be move elsewhere? 

// Put these 4 functions outside the BitcoinExchange Class 
std::string::iterator find_first_letter(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (!std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string::iterator find_first_space(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string trim_left_spaces(std::string & s){
    s.erase(s.begin(), find_first_letter(s));
    return (s);
}

std::string trim_right_spaces(std::string & s){
    s.erase(find_first_space(s), s.end());
    return(s);
}

// End of utility functions 

int main()
{      
    std::ifstream file("data.csv"); 
    std::map<std::string, float> myMap;
    std::string line;

    // Verifying if file is open or not 
    if (!file.is_open()){
        std::cerr <<  "Could not open the file!" << std::endl;
        return 1;
    }

    //Loop over data.csv file and insert its key-value inside a std::map 
    std::getline(file, line); // Skips the first line of the file, which is not necessary! 
    while (std::getline(file, line)) { 
        std::stringstream ss(line);
        std::string file_date, file_exchange_rate;

        // Get the first part (before the comma)
        if (std::getline(ss, file_date, ',')) {
            std::getline(ss, file_exchange_rate);
            myMap.insert(std::make_pair(file_date, atof(file_exchange_rate.c_str())));
        } else {
            std::cerr << "No comma found in the line: " << line << std::endl;
        }
    }

    // Opening the .txt file that contains a data and nbr of bitcoins at that date. 
    std::ifstream file1("input.txt");
    std::string line1;

    std::getline(file1, line1); // Read the first line and therefore skips it]
    // std::cout << "The content of the first line is: " << line1 << std::endl;

    while(std::getline(file1, line1)) {
        std::stringstream  ss1(line1);
        std::string date_to_find, nbr_of_bitcoins;

         if (std::getline(ss1, date_to_find, '|')) {
            std::getline(ss1, nbr_of_bitcoins);

            trim_right_spaces(date_to_find);
            trim_left_spaces(nbr_of_bitcoins);

            std::map<std::string, float>::iterator it = myMap.find(date_to_find);
            if(it != myMap.end()){
                std::cout << it->first << " => " << nbr_of_bitcoins << " = " << (atoi(nbr_of_bitcoins.c_str()) * it->second) << std::endl;
            } else {
                std::cerr << "Cannot find the date in file or ERROR" << std::endl;
            }
         } else {
            std::cerr << "There is an error reading the file" << std::endl;
         }
    }

    file.close();

    return 0;
}