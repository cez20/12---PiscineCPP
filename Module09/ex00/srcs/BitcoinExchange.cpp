#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs ) // TODO: Once class is finished added element inside condition. 
	{
		this->_bitcoin_map = rhs._bitcoin_map;
        //this->_bitcoin_map = rhs.getBitcoinMap(); //Maybe this is it
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			BitcoinExchange::mapBitcoinDatabase(std::ifstream & btc_database) {
	std::string line;

	std::getline(btc_database, line);
	while (std::getline(btc_database, line)) { 
        std::stringstream ss(line);
        std::string file_date, file_exchange_rate;

        if (std::getline(ss, file_date, ',')) {
            std::getline(ss, file_exchange_rate);
			_bitcoin_map.insert(std::make_pair(file_date, std::stod(file_exchange_rate))); //TODO: validate std::stod can be used
        } else {
            std::cerr << "Delimiter(comma) not found in the line: " << line << std::endl;
        }
    }
}

void            BitcoinExchange::findBitcoinData(std::ifstream & second_database) {
    std::string line;
    
    while(std::getline(second_database, line)) {
        size_t delimiter_pos = line.find('|');

        if (delimiter_pos != std::string::npos){
            std::string target_date = line.substr(0, delimiter_pos);
            std::string nbr_of_bitcoins = line.substr(delimiter_pos + 1);

            trim_right_spaces(target_date);
            trim_left_spaces(nbr_of_bitcoins);

            // Check if the date exists in the map
            std::map<std::string, double>::iterator it = _bitcoin_map.find(target_date);
            if (it != _bitcoin_map.end()) {
                std::cout << it->first << " => " << nbr_of_bitcoins << " = "
                        << (std::stod(nbr_of_bitcoins) * it->second) << std::endl;
            } else {
                std::cerr << "ERROR! Cannot find the date in file or ERROR" << std::endl;
            }
        } else {
            std::cerr << "ERROR! Delimiter missing or improperly formatted line" << std::endl;
        }
    }
}


void	BitcoinExchange::printMap(){
	std::map<std::string, double>::iterator it;

	for(it = _bitcoin_map.begin(); it != _bitcoin_map.end(); ++it){
		std::cout << std::fixed << std::setprecision(2) << it->first << " | " << it->second << std::endl;
	}
}

/*
** --------------------------------- OTHER ---------------------------------
*/

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


/* ************************************************************************** */