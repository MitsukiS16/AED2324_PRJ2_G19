#ifndef DBAIRPORT_H
#define DBAIRPORT_H

#include "../classes/Airline.h"
#include "../classes/Airport.h"
#include "../classes/Graph.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

struct Flight {
  std::string code;
  std::string airline;
};

// Quantity Airports Functions
int quantityAirports(Graph<Airport> airports);
int quantityAirportsCountry(Graph<Airport> airports, std::string country);
int quantityAirportsCity(Graph<Airport> airports, std::string city);

// Quantity Countries Functions
int quantityCountries(Graph<Airport> airports, Graph<Airline> airlines);
// Idk if this is working, check later
int quantityCountry(Graph<Airport> airports, std::string airport);

// Quantity Cities Functions
int quantityCities(Graph<Airport> airports);
int quantityCitiesCountry(Graph<Airport> airports, std::string country);

// Quantity Airlines Functions
int quantityAirlines(Graph<Airline> airlines);
int quantityAirlinesCountry(Graph<Airline> airlines, std::string country);

// Quantity Flights Functions
int quantityFlights(Graph<Airport> airports);
int quantityFlightsAirport(Graph<Airport> airports, std::string airport);
int quantityFlightsCountry(Graph<Airport> airports, std::string country);
int quantityFlightsCity(Graph<Airport> airports, std::string city);
int quantityFlightsAirline(Graph<Airport> airports, std::string airline);
// Idk if this is working, check later
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code);

// Quantity Destination Functions
int quantityDestinationsCountry(Graph<Airport> airports, std::string country);
int quantityDestinationsAirport(Graph<Airport> airports, std::string airport);
int quantityDestinationLimitedStop(Graph<Airport> airports, std::string airport,
                                   int stop);
int quantityDestinationMax(Graph<Airport> airports);
int dfsCount(Vertex<Airport> *v, std::string &tgt, vector<std::string> &path);
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res);
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res, int stop);

// Ranking Airports Functions
void rankingAirports(Graph<Airport> airports, int arg);
void calculateIndegree(Graph<Airport> &airports);

// Connecting Airports Functions
void findArticulationPoints(Graph<Airport> &airports);
void resetVisited(Graph<Airport> &airports);
void dfsConnectedComponents(Graph<Airport> &airports, Vertex<Airport> *v);
void dfsArtc(Vertex<Airport> *v, Vertex<Airport> *w);
int connectedComponents(Graph<Airport> &airports);

// Best Flights Functions
void findBestFlights(Graph<Airport> &airports, string src, string dest,
                     vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string countrySrc,
                     string citySrc, string countryDest, string cityDest,
                     vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, double latOrigin,
                     double longOrigin, double latDest, double longDest,
                     int distMax, vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     string airport, int type, vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     double lat, double lon, int distMax, int type,
                     vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string airport, double lat,
                     double lon, int distMax, int type,
                     vector<string> &airplanes);
void showPath(vector<vector<Flight>> paths);
void showPath(Graph<Airport> &airports, vector<Vertex<Airport> *> source,
              vector<Vertex<Airport> *> dest, vector<vector<Flight>> paths,
              vector<string> &airplanes);
bool comparatorPath(const vector<Flight> a, const vector<Flight> b);
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, string country,
                                       string city);
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, double lat,
                                       double lon, int distMax);
vector<vector<Flight>> bfsPath(Vertex<Airport> *v, string &tgt,
                               vector<string> &airplanes);
void getPath(string current, vector<Flight> &path,
             unordered_map<string, vector<Flight>> &prev,
             vector<vector<Flight>> &paths, string startCode, string airline);

// ---

// This is used but is commented, idk why, see later
void getArticulations(Graph<Airport> airports);
void dfsArticulations(Graph<Airport> &airports, Vertex<Airport> *v,
                      unordered_set<string> &res, std::stack<string> &s, int i);

// This function is never used, see if we can remove it later
void findAllPaths(Vertex<Airport> *v, string tgt);
void dfsPath(Vertex<Airport> *v, string tgt, vector<string> &path,
             vector<vector<string>> &paths);

#endif // DBAIRPORT_H