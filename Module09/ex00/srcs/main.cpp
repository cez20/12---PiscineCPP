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
    std::ifstream second_database(argv[1]);

    // Verifying if btcDatabase is open or not 
    if (!bitcoin_database.is_open() || !second_database.is_open()){
        std::cerr << "Error! Could not open the file!" << std::endl;
        return 1;
    }
    
    bitcoin_exchange.mapBitcoinDatabase(bitcoin_database);
    bitcoin_exchange.printMap();
    bitcoin_exchange.findBitcoinData(second_database);
    
    bitcoin_database.close();
    second_database.close();

    return 0;
}