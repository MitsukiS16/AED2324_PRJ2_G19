#include "Menu.h"

// Global graph to store airport data
Graph<Airport> airports;
Graph<Airline> airlines;

// Function Menu Main
void Menu(std::string folder) {
  int flag;

  if (!folder.empty()) {
    airports = readFlights(folder);
    airlines = readAirlines(folder);
  }

  system("clear");
  std::cout << "Welcome to Travel Management:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "1. Statistics" << std::endl;
  std::cout << "2. Listing" << std::endl;
  std::cout << "3. Bests flights" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    Menu("");
  }

  switch (flag) {
  case 1:
    MenuQuantity();
    break;
  case 2:
    menuListing();
    break;
  case 3:
    menuBestFlights();
    break;
  case 0:
    exit(0);
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    Menu("");
    break;
  }
}

// Function to handle quantity-related menu options
void MenuQuantity() {
  int flag;

  system("clear");
  std::cout << "Quantity Calculation Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. Number of Airports" << std::endl;
  std::cout << "2. Number of Countries" << std::endl;
  std::cout << "3. Number of Cities" << std::endl;
  std::cout << "4. Number of Airlines" << std::endl;
  std::cout << "5. Number of Flights" << std::endl;
  std::cout << "6. Number of Destinations" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    MenuQuantity();
  }

  switch (flag) {
  case 1:
    system("clear");
    menuAirports();
    break;
  case 2:
    system("clear");
    menuCountries();
    break;
  case 3:
    system("clear");
    menuCities();
    break;
  case 4:
    system("clear");
    menuAirlines();
    break;
  case 5:
    system("clear");
    menuFlights();
    break;
  case 6:
    system("clear");
    menuDestinations();
    break;
  case 0:
    Menu("");
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    MenuQuantity();
    break;
  }
}

// Function to handle listing-related menu options
void menuListing() {
  int flag;
  int arg;

  system("clear");
  std::cout << "Listing Menu: " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. Ranking Airports (more landings and takeoffs)" << std::endl;
  std::cout << "2. Connecting Airports" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuListing();
  }

  switch (flag) {
  case (1):
    system("clear");
    std::cout << "Type Airports Number: " << std::endl;
    std::cin >> arg;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Ranking Airports: " << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    rankingAirports(airports, arg);
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    menuListing();
    break;
  case (2):
    system("clear");
    std::cout << "Connecting Airports: " << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    // getArticulations(airports);
    findArticulationPoints(airports);
    connectedComponents(airports);
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    menuListing();
    break;
  case (0):
    Menu("");
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuListing();
    break;
  }
}

// Function to handle best flights menu options
int selectType(std::string arg) {
  int flag;

  system("clear");
  std::cout << "Bests Flights: " << std::endl;
  std::cout << "Select your " << arg << " option:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. By Airports" << std::endl;
  std::cout << "2. By Cities" << std::endl;
  std::cout << "3. By Coordinates" << std::endl;
  std::cout << "0. Back to Best Flights" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    selectType(arg);
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return flag;
}

// Function to input airport code based on the type and flag
std::string typeAirport(std::string type, int flag) {
  std::string arg;
  switch (flag) {
  case (1):
    std::cout << "Type Code Aiport of " << type << ": " << std::endl;
    std::cin >> arg;
    break;
  }
  return arg;
}

// Function to input city details based on the type and flag
pair<std::string, std::string> typeCity(std::string type, int flag) {
  std::string arg1;
  std::string arg2;
  switch (flag) {
  case (2):
    std::cout << "Type City Name " << type << ": " << std::endl;
    std::getline(std::cin, arg1);
    std::cout << "Type Country Name " << type << ": " << std::endl;
    std::getline(std::cin, arg2);
    break;
  }
  return make_pair(arg1, arg2);
}

// Function to input coordinates based on the type and flag
pair<double, double> typeCoordinates(std::string type, int flag) {
  double arg1;
  double arg2;
  switch (flag) {
  case (3):
    std::cout << "Type Latitude of " << type << ": " << std::endl;
    std::cin >> arg1;
    std::cout << "Type Longitude of " << type << ": " << std::endl;
    std::cin >> arg2;
    break;
  }
  return make_pair(arg1, arg2);
}

// Function to filter airplanes on the user input
vector<string> filterAirplanes() {
  vector<string> airplanes;
  string line;
  int flag;

  system("clear");
  std::cout << "Bests flights: " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. Filter by Airplanes" << std::endl;
  std::cout << "2. Without Filter" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (std::cin.fail()) {
    std::cout << "Erro na leitura" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    filterAirplanes();
  }

  switch (flag) {
  case (1): {
    std::cout << "Type Airplane Name: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream iss(line);

    string airplane;

    while (iss >> airplane) {
      airplanes.push_back(airplane);
    }
    break;
  }
  case (2):
    break;
  case (0):
    Menu("");
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    filterAirplanes();
    break;
  }
  return airplanes;
}

// Function to find best flights based on the user input
void menuBestFlights() {
  vector<string> airplanes = filterAirplanes();

  std::string airportOrig;
  std::string airportDest;

  std::pair<std::string, std::string> cityOrig;
  std::pair<std::string, std::string> cityDest;

  std::pair<double, double> cordOrig;
  std::pair<double, double> cordDest;

  int maxDist;
  int flagOrigin = selectType("origin");

  switch (flagOrigin) {
  case (1):
    airportOrig = typeAirport("origin", flagOrigin);
    break;
  case (2):
    cityOrig = typeCity("origin", flagOrigin);
    break;
  case (3):
    cordOrig = typeCoordinates("origin", flagOrigin);
    std::cout << "Type Max Distance in (km): " << std::endl;
    std::cin >> maxDist;
    while (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid number: " << std::endl;
      Menu("");
    }
    break;
  case (0):
    menuBestFlights();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuBestFlights();
    break;
  }

  int flagDest = selectType("destination");
  switch (flagDest) {
  case (1):
    airportDest = typeAirport("destination", flagDest);
    break;
  case (2):
    cityDest = typeCity("destination", flagDest);
    break;
  case (3):
    cordDest = typeCoordinates("destination", flagDest);
    std::cout << "Type Max Distance in (km): " << std::endl;
    std::cin >> maxDist;
    while (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid number: " << std::endl;
      Menu("");
    }
    break;
  case (0):
    menuBestFlights();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuBestFlights();
    break;
  }

  switch (flagOrigin) {
  case (1):
    switch (flagDest) {
      {
      case (1): // airport to airport
        findBestFlights(airports, airportOrig, airportDest, airplanes);
        break;
      case (2): // airport to city
        findBestFlights(airports, cityDest.second, cityDest.first, airportOrig,
                        1, airplanes);
        break;
      case (3): // airport to coordinates
        findBestFlights(airports, airportOrig, cordDest.first, cordDest.second,
                        maxDist, 1, airplanes);
        break;
      }
    }
    break;
  case (2):
    switch (flagDest) {
      {
      case (1): // city to airport
        findBestFlights(airports, cityOrig.second, cityOrig.first, airportDest,
                        0, airplanes);
        break;
      case (2): // city to city
        findBestFlights(airports, cityOrig.second, cityOrig.first,
                        cityDest.second, cityDest.first, airplanes);
        break;
      case (3): // city to coordinates
        findBestFlights(airports, cityOrig.second, cityOrig.first,
                        cordDest.first, cordDest.second, maxDist, 0, airplanes);
        break;
      }
    }
    break;
  case (3):
    switch (flagDest) {
      {
      case (1): // coordinates to airport
        findBestFlights(airports, airportDest, cordOrig.first, cordOrig.second,
                        maxDist, 0, airplanes);
        break;
      case (2): // coordinates to city
        findBestFlights(airports, cityDest.second, cityDest.first,
                        cordOrig.first, cordOrig.second, maxDist, 1, airplanes);
        break;
      case (3): // coordinates to coordinates
        findBestFlights(airports, cordOrig.first, cordOrig.second,
                        cordDest.first, cordDest.second, maxDist, airplanes);
        break;
      }
    }
    break;
  }

  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "Press any key to continue..." << std::endl;
  std::cin.ignore();
  std::cin.get();
  menuBestFlights();
}

// Function Menu Airports
void menuAirports() {
  int flag;
  std::string arg;

  system("clear");
  std::cout << "Number of Airports:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. All Airports" << std::endl;
  std::cout << "2. Airports by Country" << std::endl;
  std::cout << "3. Airports by City" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuFlights();
  }

  switch (flag) {
  case 1:
    std::cout << "All Airports: " << quantityAirports(airports) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 2:
    std::cout << "Type Country Name: " << std::endl;
    std::cin >> arg;
    std::cout << "Airports in " << arg << ": "
              << quantityAirportsCountry(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 3:
    std::cout << "Type City Name: " << std::endl;
    std::cin >> arg;
    std::cout << "Airports in " << arg << ": "
              << quantityAirportsCity(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 0:
    MenuQuantity();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuAirports();
    break;
  }
}

// Function Menu Countries
void menuCountries() {
  int flag;
  std::string arg;

  system("clear");
  std::cout << "Number of Countries:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. All Countries" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuFlights();
  }

  switch (flag) {
  case 1:
    std::cout << "All Countries: " << quantityCountries(airports, airlines)
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 0:
    MenuQuantity();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuCountries();
    break;
  }
}

// Function Menu Cities
void menuCities() {
  int flag;
  std::string arg;

  system("clear");
  std::cout << "Number of Cities:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. All Cities" << std::endl;
  std::cout << "2. Cities by Country" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuFlights();
  }

  switch (flag) {
  case 1:
    std::cout << "All Cities: " << quantityCities(airports) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 2:
    std::cout << "Type Country Name: " << std::endl;
    std::cin >> arg;
    std::cout << "Cities in " << arg << ": "
              << quantityCitiesCountry(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 0:
    MenuQuantity();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuCities();
    break;
  }
}

// Function Menu Airlines
void menuAirlines() {
  int flag;
  std::string arg;

  system("clear");
  std::cout << "Number of Airlines:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. All Airlines" << std::endl;
  std::cout << "2. Airlines by Country" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuFlights();
  }

  switch (flag) {
  case 1:
    std::cout << "All Airlines: " << quantityAirlines(airlines) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 2:
    std::cout << "Type Country Name: " << std::endl;
    std::cin >> arg;
    std::cout << "Airlines in " << arg << ": "
              << quantityAirlinesCountry(airlines, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 0:
    MenuQuantity();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuAirlines();
    break;
  }
}

// Function Menu Flights
void menuFlights() {
  int flag;
  std::string arg;
  std::string arg2;

  system("clear");
  std::cout << "Number of flights:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. All flights" << std::endl;
  std::cout << "2. Flights by Origin Airport" << std::endl;
  std::cout << "3. Flights by Origin Country" << std::endl;
  std::cout << "4. Flights by City" << std::endl;
  std::cout << "5. Flights by Airline" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuFlights();
  }

  switch (flag) {
  case 1:
    std::cout << "All flights: " << quantityFlights(airports) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 2:
    std::cout << "Type Origin Airport Code: " << std::endl;
    std::cin >> arg;
    std::cout << "Flights in " << arg << ": "
              << quantityFlightsAirport(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 3:
    std::cout << "Type Origin Country Code: " << std::endl;
    std::cin >> arg;
    std::cout << "Flights in " << arg << ": "
              << quantityFlightsCountry(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 4:
    std::cout << "Type City Name: " << std::endl;
    std::cin >> arg;
    std::cout << "Flights in " << arg << ": "
              << quantityFlightsCity(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 5:
    std::cout << "Type Airline Code: " << std::endl;
    std::cin >> arg;
    std::cout << "Flights in " << arg << ": "
              << quantityFlightsAirline(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 0:
    MenuQuantity();
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuFlights();
    break;
  }
}

// Function Menu Destination
void menuDestinations() {
  int flag;
  std::string arg;
  int stop;

  system("clear");
  std::cout << "Number of Destinations:" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cout << "1. Unlimited Stops (by country)" << std::endl;
  std::cout << "3. Unlimited Stops (by airport)" << std::endl;
  std::cout << "5. Limited Stops" << std::endl;
  std::cout << "6. Max Destinations" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;

  std::cin >> flag;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuDestinations();
  }

  switch (flag) {
  case 1:
    std::cout << "Type Country Name: " << std::endl;
    std::cin >> arg;
    std::cout << "Destinations in " << arg << ": "
              << quantityDestinationsCountry(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 2:
    std::cout << "Type Airport Code: " << std::endl;
    std::cin >> arg;
    std::cout << "Destination in " << arg << ": "
              << quantityDestinationsAirport(airports, arg) << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    MenuQuantity();
    break;
  case 3:
    std::cout << "Type Airport Code: " << std::endl;
    std::cin >> arg;
    std::cout << "Type Stops Number: " << std::endl;
    std::cin >> stop;
    while (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid number: " << std::endl;
      Menu("");
    }
    std::cout << "Number of Countries: "
              << quantityDestinationLimitedStop(airports, arg, stop)
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    menuDestinations();
  case 4:
    std::cout << "Max Number of Flights: " << quantityDestinationMax(airports)
              << " stops" << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    menuDestinations();
  case 0:
    Menu("");
    break;
  default:
    std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    menuDestinations();
    break;
  }
}
