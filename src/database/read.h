// read.h

#ifndef READ_H
#define READ_H

#include "../classes/Airline.h"
#include "../classes/Airport.h"
#include "../classes/Graph.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

Graph<Airline> readAirlines(std::string folder);
Graph<Airport> readAirports(std::string folder);
Graph<Airport> readFlights(std::string folder);

#endif // READ_H
