#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{      
    if (argc != 2){
        std::cerr << "ERROR! Program must contain a database as argument!" << std::endl;
        return 1;
    }
    
    BitcoinExchange bitcoin_exchange = BitcoinExchange();
    std::ifstream bitcoin_database("data.csv");

    if (!bitcoin_database.is_open()){
        std::cerr << "Error! Could not open the database!" << std::endl;
        return 1;
    }
    
    bitcoin_exchange.parseBitcoinDatabase(bitcoin_database); // If there is an error, I should close the bitcoin database? 
    // bitcoin_exchange.printMap();

    std::ifstream second_database(argv[1]);
    if (!second_database.is_open()){
        std::cerr << "Error! Could not open the second database !" << std::endl;
        bitcoin_database.close(); // This close the already open database
        return 1;
    }

    bitcoin_exchange.findBitcoinData(second_database);
    
    bitcoin_database.close();
    second_database.close();

    return 0;
}