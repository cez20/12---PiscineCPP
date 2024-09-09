#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{      
    if (argc != 2){
        std::cerr << "ERROR! Program must contain a bitcoin value database as argument!" << std::endl;
        return 1;
    }
    
    BitcoinExchange bitcoin_exchange = BitcoinExchange();
    std::ifstream bitcoinExchangeRateHistory("data.csv");

    if (!bitcoinExchangeRateHistory.is_open()){
        std::cerr << "Error! Could not open bitcoin exchange rate database!" << std::endl;
        return 1;
    }
    
    bitcoin_exchange.parseBitcoinExchangeRate(bitcoinExchangeRateHistory); // TODO:If there is an error, I should close the bitcoin database? 
    //bitcoin_exchange.printBitcoinRates();

    std::ifstream bitcoinValueHistory(argv[1]);
    if (!bitcoinValueHistory.is_open()){
        std::cerr << "Error! Could not open bitcoin value database !" << std::endl;
        bitcoinExchangeRateHistory.close(); // This close the already open database
        return 1;
    }

    bitcoin_exchange.parseBitcoinValue(bitcoinValueHistory);
    
    bitcoinExchangeRateHistory.close();
    bitcoinValueHistory.close();

    return 0;
}