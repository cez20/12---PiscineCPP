#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{      
    if (argc != 2){
        std::cerr << "ERROR! Program must contain a bitcoin value database as argument!" << std::endl;
        return 1;
    }
    
    BitcoinExchange bitcoinExchange = BitcoinExchange();
    std::ifstream bitcoinExchangeRateHistory("data.csv");

    if (!bitcoinExchangeRateHistory.is_open()){
        std::cerr << "Error! Could not open bitcoin exchange rate database!" << std::endl;
        return 1;
    }
    
    try {
        bitcoinExchange.parseBitcoinExchangeRate(bitcoinExchangeRateHistory);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        bitcoinExchangeRateHistory.close();
        return 1;
    } 

    std::ifstream bitcoinValueHistory(argv[1]);
    if (!bitcoinValueHistory.is_open()){
        std::cerr << "Error! Could not open bitcoin value database !" << std::endl;
        bitcoinExchangeRateHistory.close();
        return 1;
    }

    bitcoinExchange.parseBitcoinValue(bitcoinValueHistory);
    
    bitcoinExchangeRateHistory.close();
    bitcoinValueHistory.close();

    return 0;
}