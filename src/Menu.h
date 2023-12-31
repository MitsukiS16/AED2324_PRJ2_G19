#ifndef MENU_H
#define MENU_H

#include "database/dbairport.h"
#include "database/read.h"
#include <iostream>
#include <limits>

// Function to display menu
void Menu(std::string folder);
void MenuQuantity();
void menuListing();
void menuAirports();
void menuCountries();
void menuCities();
void menuAirlines();
void menuFlights();
void menuDestinations();
void menuBestFlights();

// Function to handle the process of finding the best flight
vector<string> filterAirplanes();
int selectType(std::string arg);
std::string typeAirport(std::string type, int flag);
pair<std::string, std::string> typeCity(std::string type, int flag);
pair<double, double> typeCoordinates(std::string type, int flag);

#endif
