#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

int main()
{      
    BitcoinExchange bitcoin_exchange = BitcoinExchange();
    std::ifstream bitcoin_database("data.csv");
    std::ifstream second_database("input.txt");

    // Verifying if btcDatabase is open or not 
    if (!bitcoin_database.is_open() || !second_database.is_open()){
        std::cerr << "Error! Could not open the file!" << std::endl;
        return 1;
    }
    
    bitcoin_exchange.mapBitcoinDatabase(bitcoin_database);
    // bitcoin_exchange.printMap();
    bitcoin_exchange.findBitcoinData(second_database);
    // std::string line1;

    // std::getline(file1, line1); // Read the first line and therefore skips it]
    // // std::cout << "The content of the first line is: " << line1 << std::endl;

    // while(std::getline(file1, line1)) {
    //     std::stringstream  ss1(line1);
    //     std::string date_to_find, nbr_of_bitcoins;

    //      if (std::getline(ss1, date_to_find, '|')) {
    //         std::getline(ss1, nbr_of_bitcoins);

    //         trim_right_spaces(date_to_find);
    //         trim_left_spaces(nbr_of_bitcoins);

    //         std::map<std::string, float>::iterator it = myMap.find(date_to_find);
    //         if(it != myMap.end()){
    //             std::cout << it->first << " => " << nbr_of_bitcoins << " = " << (atoi(nbr_of_bitcoins.c_str()) * it->second) << std::endl;
    //         } else {
    //             std::cerr << "Cannot find the date in file or ERROR" << std::endl;
    //         }
    //      } else {
    //         std::cerr << "There is an error reading the file" << std::endl;
    //      }
    // }

    bitcoin_database.close();
    second_database.close();

    return 0;
}