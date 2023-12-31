#include "dbairport.h"

//------------------------------------------------------------

// Function to get quantity of airports in the graph
// Complexity: O(1)
int quantityAirports(Graph<Airport> airports) {
  return airports.getNumVertex();
}

// Function to get quantity of airports in the graph by country
// Complexity: O(n), where n is the number of airports in the graph
int quantityAirportsCountry(Graph<Airport> airports, std::string country) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    Airport a = v->getInfo();
    if (a.getCountry() == country) {
      count++;
    }
  }
  return count;
}

// Function to get quantity of airports in the graph by city
// Complexity: O(n), where n is the number of airports in the graph
int quantityAirportsCity(Graph<Airport> airports, std::string city) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    Airport a = v->getInfo();
    if (a.getCity() == city) {
      count++;
    }
  }
  return count;
}

//------------------------------------------------------------

// Function to get quantity of unique countries in the graph
// Complexity: O(n + m), where n is the number of airports, m is the number of
// airlines
int quantityCountries(Graph<Airport> airports, Graph<Airline> airlines) {
  std::unordered_set<std::string> uniqueCountries;
  for (auto v : airports.getVertexSet()) {
    Airport a = v->getInfo();
    std::string country = a.getCountry();
    uniqueCountries.insert(country);
  }
  for (auto v : airlines.getVertexSet()) {
    Airline a = v->getInfo();
    std::string country = a.getCountry();
    uniqueCountries.insert(country);
  }
  return uniqueCountries.size();
}

//------------------------------------------------------------

// Function to count the number of unique cities in the graph
// Complexity: O(n), where n is the number of airports in the graph
int quantityCities(Graph<Airport> airports) {
  std::unordered_set<std::string> uniqueCities;
  for (auto v : airports.getVertexSet()) {
    Airport a = v->getInfo();
    std::string city = a.getCity();
    uniqueCities.insert(city);
  }
  return uniqueCities.size();
}

// Function to count the number of unique cities in the graph for a given
// country
// Complexity: O(n), where n is the number of airports in the graph
int quantityCitiesCountry(Graph<Airport> airports, std::string country) {
  std::unordered_set<std::string> uniqueCities;
  for (auto v : airports.getVertexSet()) {
    Airport a = v->getInfo();
    if (a.getCountry() == country) {
      std::string city = a.getCity();
      uniqueCities.insert(city);
    }
  }
  return uniqueCities.size();
}

//------------------------------------------------------------

// Function to calculate the quantity of airlines in the graph
// Complexity: O(1)
int quantityAirlines(Graph<Airline> airlines) {
  return airlines.getNumVertex();
}

// Function to calculate the quantity of airlines for a given country
// Complexity: O(n), where n is the number of airlines in the graph
int quantityAirlinesCountry(Graph<Airline> airlines, std::string country) {
  int count = 0;
  for (auto v : airlines.getVertexSet()) {
    Airline a = v->getInfo();
    if (a.getCountry() == country) {
      count++;
    }
  }
  return count;
}

//------------------------------------------------------------

// Function to calculate the quatity of flights in the graph
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityFlights(Graph<Airport> airports) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    count += v->getAdj().size();
  }
  return count;
}

// Function to calculate the quatity of flights in a given airport
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityFlightsAirport(Graph<Airport> airports, std::string airport) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    if (v->getInfo().getCode() == airport) {
      count += v->getAdj().size();
    }
  }
  return count;
}

// Function to calculate the quatity of flights in a given country
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityFlightsCountry(Graph<Airport> airports, std::string country) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    if (v->getInfo().getCountry() == country) {
      count += v->getAdj().size();
    }
  }
  return count;
}

// Function to calculate the quatity of flights in a given city
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityFlightsCity(Graph<Airport> airports, std::string city) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    if (v->getInfo().getCity() == city) {
      count += v->getAdj().size();
    }
  }
  return count;
}

// Function to calculate the quatity of flights in a given airline
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityFlightsAirline(Graph<Airport> airports, std::string airline) {
  int count = 0;
  for (auto v : airports.getVertexSet()) {
    for (auto e : v->getAdj()) {
      if (e.getRoute() == airline) {
        count++;
      }
    }
  }

  return count;
}

//------------------------------------------------------------

// Function to calculate the quatity of flights in a given country
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityDestinationsCountry(Graph<Airport> airports, std::string country) {
  int totalFlights = 0;
  for (auto v : airports.getVertexSet()) {
    Airport sourceAirport = v->getInfo();
    if (sourceAirport.getCountry() == country) {
      for (auto &edge : v->getAdj()) {
        Airport destinationAirport = edge.getDest()->getInfo();
        if (destinationAirport.getCountry() == country) {
          totalFlights++;
        }
      }
    }
  }
  return totalFlights;
}

// Function to calculate the quatity of countries in a given airport
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityDestinationsAirport(Graph<Airport> airports, std::string airport) {
  std::set<std::string> countries;
  std::vector<std::string> res;
  resetVisited(airports);
  auto s = airports.findVertex(Airport(airport));
  if (s == nullptr)
    return 0;
  Graph<Airport> g;
  res = dfsVisit(s, res);
  for (auto c : res) {
    countries.insert(c);
  }
  return countries.size();
}

// Function to calculate the quatity of countries in a given number of stops
// Complexity: O(n + e),  where n is the number of airports in the graph and e
// is the number of flights
int quantityDestinationLimitedStop(Graph<Airport> airports, std::string airport,
                                   int stop) {
  std::set<std::string> countries;
  std::vector<std::string> res;
  resetVisited(airports);
  auto s = airports.findVertex(Airport(airport));
  if (s == nullptr)
    return 0;
  res = dfsVisit(s, res, (stop + 1));
  for (auto c : res) {
    countries.insert(c);
  }
  return countries.size();
}

// Function to calculate an Airport with a given max number of flights
// Complexity: O(n * (n + e)),  where n is the number of airports in the graph
// and e is the number of flights
int quantityDestinationMax(Graph<Airport> airports) {
  int max = 0;
  std::string src;
  std::string tgt;
  resetVisited(airports);
  std::cout << "Consultando... " << std::endl;
  for (auto v : airports.getVertexSet()) {
    if (!v->isVisited()) {
      vector<std::string> path;

      int count = dfsCount(v, tgt, path);
      if (count > max) {
        src = v->getInfo().getCode();
        max = count;
      }
      resetVisited(airports);
    }
  }
  std::cout << "\nLeaving from:" << src << std::endl;
  std::cout << "To: " << tgt << std::endl;
  return max - 1;
}

//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------

bool comparatorPath(const vector<Flight> a, const vector<Flight> b) {
  return a.size() < b.size();
}

// Function to get quantity of flights in the graph and unique airlines for an
// Airport
// Complexity: O(n), where n is the number of flights in the graph
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code) {
  int count = 0;
  std::set<std::string> airlines;

  auto s = airports.findVertex(Airport(code));
  if (s != nullptr) {
    for (auto v : s->getAdj()) {
      count++;
      airlines.insert(v.getRoute());
    }
  }
  return std::pair<int, int>(count, airlines.size());
}

// Search (depth-first) to visit vertices and collect connected countries
// Complexity: O(n + e), where n is the number of airports and e is the number
// of flights in the graph
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res) {
  v->setVisited(true);
  res.push_back(v->getInfo().getCountry());
  auto adjs = v->getAdj();

  for (auto &e : adjs) {
    auto w = e.getDest();

    if (!w->isVisited()) {
      dfsVisit(w, res);
    }
  }

  return res;
}

// Function to get quantity of countries withing number of stop from an
// airport Complexity: O(2e), where e is the number of flights in the graph
int quantityCountryStop(Graph<Airport> airports, std::string airport,
                        int stop) {
  std::set<std::string> countries;
  std::vector<std::string> res;
  resetVisited(airports);

  auto s = airports.findVertex(Airport(airport));

  if (s == nullptr)
    return 0;

  res = dfsVisit(s, res, (stop + 1));

  for (auto c : res) {
    countries.insert(c);
  }

  return countries.size();
}

// Search (depth-first) to visit vertices and collect connected countries
// withing a number of stops
// Complexity: O(2e), where e is the number of flights in the graph
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res, int stop) {
  if (stop == 0)
    return res;

  // std::cout << "Saindo de " << v->getInfo().getCode() << std::endl;

  v->setVisited(true);
  res.push_back(v->getInfo().getCountry());
  auto adjs = v->getAdj();

  for (auto &e : adjs) {
    auto w = e.getDest();

    if (!w->isVisited()) {
      // std::cout << "\t Eu vou para: " << w->getInfo().getCode() <<
      // std::endl;
      dfsVisit(w, res, (stop - 1));
    }
  }

  return res;
}

// Funnction to find the Aiport with max number of flights
// Complexity: O(n * e), where n is the number of airports and e is the number
// of flights in the graph
int maxFlight(Graph<Airport> airports) {
  int max = 0;

  std::string src;
  std::string tgt;

  resetVisited(airports);
  std::cout << "Consultando... " << std::endl;
  for (auto v : airports.getVertexSet()) {
    if (!v->isVisited()) {
      vector<std::string> path;

      int count = dfsCount(v, tgt, path);
      if (count > max) {
        src = v->getInfo().getCode();
        max = count;
      }
      resetVisited(airports);
    }
  }
  std::cout << "\nLeaving from:" << src << std::endl;
  std::cout << "To: " << tgt << std::endl;

  return max - 1;
}

// Search (depth-first) to find the max numbeer of flights form a vertex
// Complexity: O(e), where e is the number of flights in the graph
int dfsCount(Vertex<Airport> *v, std::string &tgt, vector<std::string> &path) {
  int pathLen = 0;
  path.push_back(v->getInfo().getCode());
  v->setVisited(true);
  std::string lastNode;

  auto adjs = v->getAdj();

  for (auto &e : adjs) {
    auto w = e.getDest();

    if (!w->isVisited()) {
      int childPathLen = dfsCount(w, tgt, path);
      if (childPathLen > pathLen) {
        pathLen = childPathLen;
      }
    }
  }

  path.pop_back();
  // v->setVisited(false);

  if (path.size() > pathLen) {
    tgt = v->getInfo().getCode();
    return path.size();
  }

  else
    return pathLen;
}

// Function to reset the visited status of all vertices in the graph
// Complexity: O(n), where n is the number of airports in the graph
void resetVisited(Graph<Airport> &airports) {
  for (auto v : airports.getVertexSet()) {
    v->setVisited(false);
  }
}

// Function to calculate the in-degreee of each vertex in the graph
// Complexity: O(n + e), where n is the number of airports and e is the number
// of flights in the graph
void calculateIndegree(Graph<Airport> &airports) {
  for (auto v : airports.getVertexSet()) {
    v->setIndegree(0);
  }
  for (auto v : airports.getVertexSet()) {
    for (auto e : v->getAdj()) {
      e.getDest()->setIndegree(e.getDest()->getIndegree() + 1);
    }
  }
}

// Function to rank airport based of the sum of in-degrees and out-degrees
// Complexity: O(n * log(n) + n * e), where n is the number of airports and e
// is the number of flights in the graph (assuming sorting has a time
void rankingAirports(Graph<Airport> airports, int arg) {
  std::vector<Ranking> vec;

  calculateIndegree(airports);

  for (auto v : airports.getVertexSet()) {
    int total = v->getIndegree() + v->getAdj().size();
    Ranking rank = {v->getInfo().getCode(), total};
    vec.push_back(rank);
  }

  std::sort(vec.begin(), vec.end(), comparator);

  int i = 0;

  for (auto v : vec) {

    if (i < arg) {
      std::cout << "Code: " << v.code << " / ";
      std::cout << "Total: " << v.count << std::endl;
      i++;
    }
  }
}

// Function to find articulation points in the graph
// Complexity: O(n * e), where n is the number of airports and e is the
// number of flights in the graph
void getArticulations(Graph<Airport> airports) {
  unordered_set<string> res;
  unordered_set<string> visited;
  std::stack<string> s;
  int i = 1;

  resetVisited(airports);

  for (auto v : airports.getVertexSet()) {
    dfsArticulations(airports, v, res, s, i);
  }

  for (auto &e : res) {
    std::cout << e << std::endl;
  }
}

// Function (recursive) to find articulation points in the graph using DFS
// Complexity: O(n * e), where n is the number of airports and e is the
// number of flights in the graph
void dfsArticulations(Graph<Airport> &airports, Vertex<Airport> *v,
                      unordered_set<string> &res, std::stack<string> &s,
                      int i) {

  v->setLow(i);
  v->setNum(i);
  v->setVisited(true);
  v->setProcessing(true);
  s.push(v->getInfo().getCode());
  std::cout << "Visiting vertex: " << v->getInfo().getCode()
            << " Low: " << v->getLow() << " Num: " << v->getNum() << std::endl;
  i++;

  auto adjs = v->getAdj();
  int component = 0;
  for (auto &e : adjs) {
    component++;
    auto w = e.getDest();
    if (!w->isVisited()) {
      dfsArticulations(airports, w, res, s, i);
      v->setLow(min(v->getLow(), w->getLow()));
      if (w->getLow() >= v->getNum() && component > 1) {
        std::cout << "Inserting articulation point: " << v->getInfo().getCode()
                  << " Component: " << component << " - " << v->getAdj().size()
                  << std::endl;
        res.insert(v->getInfo().getCode());
      }
    } else if (w->isProcessing()) {
      v->setLow(min(v->getLow(), w->getNum()));
    }
  }

  if (v->getLow() == v->getNum()) {
    while (s.top() != v->getInfo().getCode()) {
      auto vertex = airports.findVertex(Airport(s.top()));
      vertex->setProcessing(false);
      s.pop();
    }
    v->setProcessing(false);
    s.pop();
  }
}

// Function to find the best flights from a source airport to a destination
// airport Airport to Airport
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void findBestFlights(Graph<Airport> &airports, string src, string dest,
                     vector<string> &airplanes) {
  resetVisited(airports);

  auto s = airports.findVertex(Airport(src));
  auto d = airports.findVertex(Airport(dest));

  if (s == nullptr || d == nullptr)
    return;

  vector<vector<Flight>> paths;
  paths = bfsPath(s, dest, airplanes);
  showPath(paths);
}

// Function to find best flights between a city and an aiport (vice-verse)
// type = 0: City to Airport, type = 1: Airport to City
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     string airport, int type, vector<string> &airplanes) {
  vector<Vertex<Airport> *> vec;
  vector<vector<Flight>> paths;
  vec = findAirports(airports, country, city);

  if (type == 0) {
    for (auto v : vec) {
      // std::cout << "Source: " << v->getInfo().getCode() << std::endl;
      resetVisited(airports);
      paths = bfsPath(v, airport, airplanes);
      showPath(paths);
    }
  } else if (type == 1) {
    for (auto v : vec) {
      // std::cout << "Source: " << airport << std::endl;
      std::string tgt = v->getInfo().getCode();
      resetVisited(airports);
      paths = bfsPath(airports.findVertex(Airport(airport)), tgt, airplanes);
      showPath(paths);
    }
  }
}

// Function to show a multi-path between multiple source and destination
// airports
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void showPath(Graph<Airport> &airports, vector<Vertex<Airport> *> source,
              vector<Vertex<Airport> *> dest, vector<vector<Flight>> paths,
              vector<string> &airplanes) {
  vector<vector<Flight>> flights;
  for (auto s : source) {
    // std::cout << "Source: " << s->getInfo().getCode() << std::endl;
    for (auto d : dest) {
      // std::cout << "Destination: " << d->getInfo().getCode() <<
      // std::endl;
      std::string tgt = d->getInfo().getCode();
      resetVisited(airports);
      flights = bfsPath(s, tgt, airplanes);
      paths.insert(paths.end(), flights.begin(), flights.end());
    }
  }
  if (paths.empty()) {
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Sorry, but there is no result with those inputs."
              << std::endl;
    return;
  } else {
    std::sort(paths.begin(), paths.end(), comparatorPath);
    const int min = paths[0].size();
    for (auto &p : paths) {
      if (p.size() > min) {
        continue;
      }
      std::cout << "-------------------------------------------------"
                << std::endl;
      for (auto &f : p) {
        if (!f.airline.empty()) {
          std::cout << f.code << " -(" << f.airline << ")"
                    << "-> ";
        } else {
          std::cout << f.code;
        }
      }
      std::cout << std::endl;
    }
  }
}

// Function to show a set of paths
// Complexity: O(n), where n is the total number of flights in all paths
void showPath(vector<vector<Flight>> paths) {
  if (paths.empty()) {
    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "Sorry, but there is no result with those inputs."
              << std::endl;
    return;
  }

  for (auto path : paths) {
    std::cout << "-------------------------------------------------"
              << std::endl;
    for (auto p : path) {
      if (!p.airline.empty()) {
        std::cout << p.code << " -(" << p.airline << ")"
                  << "-> ";
      } else {
        std::cout << p.code;
      }
    }
    std::cout << std::endl;
  }
}

// Function to find all airports in a city
// Complexity: O(n), where n is the number of airports in the graph
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, string country,
                                       string city) {
  vector<Vertex<Airport> *> vec;
  for (auto v : airports.getVertexSet()) {
    if (v->getInfo().getCountry() == country &&
        v->getInfo().getCity() == city) {
      vec.push_back(v);
    }
  }
  return vec;
}

// Function to find best flights between two cities
// City to City
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void findBestFlights(Graph<Airport> &airports, string countrySrc,
                     string citySrc, string countryDest, string cityDest,
                     vector<string> &airplanes) {
  vector<Vertex<Airport> *> src;

  vector<Vertex<Airport> *> dest;
  vector<vector<Flight>> paths;

  src = findAirports(airports, countrySrc, citySrc);
  dest = findAirports(airports, countryDest, cityDest);

  showPath(airports, src, dest, paths, airplanes);
}

// Function to convert Degrees in radians
// Complexity: O(1)
double toRadians(const double degree) { return (degree * M_PI / 180); }

//-23.477461, -46.548338 Anywhere in Sao Paulo
//-23.432075, -46.469511 Garulhos GRU 10km

// 28.160090, -17.240129 Anywhere in La Gomera
// 28.029600, -17.214600 GMZ 30km

// Function to calculate the distance between two points on the Earth
// Complexity: O(1)
double distanceEarth(double latOrigin, double longOrigin, double latDest,
                     double longDest) {
  latOrigin = toRadians(latOrigin);
  longOrigin = toRadians(longOrigin);
  latDest = toRadians(latDest);
  longDest = toRadians(longDest);

  double dlong = longDest - longOrigin;
  double dlat = latDest - latOrigin;

  double ans = pow(sin(dlat / 2), 2) +
               cos(latOrigin) * cos(latDest) * pow(sin(dlong / 2), 2);

  ans = 2 * asin(sqrt(ans));

  double R = 6371;

  ans = ans * R;

  return ans;
}

// Function to find all airports around a point withing a distance
// Complexity: O(n), where n is the number of airports in the graph
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, double lat,
                                       double lon, int distMax) {
  vector<Vertex<Airport> *> vec;
  for (auto v : airports.getVertexSet()) {
    double lat2 = v->getInfo().getLatitude();
    double lon2 = v->getInfo().getLongitude();

    double dist = distanceEarth(lat, lon, lat2, lon2);

    if (dist <= distMax) {
      vec.push_back(v);
    }
  }
  return vec;
}

// Function to find the best flights between two points on Earth
// Point to Point
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void findBestFlights(Graph<Airport> &airports, double latOrigin,
                     double longOrigin, double latDest, double longDest,
                     int distMax, vector<string> &airplanes) {
  vector<Vertex<Airport> *> src =
      findAirports(airports, latOrigin, longOrigin, distMax);
  vector<Vertex<Airport> *> dest =
      findAirports(airports, latDest, longDest, distMax);
  vector<vector<Flight>> paths;

  showPath(airports, src, dest, paths, airplanes);
}

// Function to find best flights between an airport and a point on Earth
// type = 0: Point to Airport, type = 1: Airport to Point
void findBestFlights(Graph<Airport> &airports, string airport, double lat,
                     double lon, int distMax, int type,
                     vector<string> &airplanes) {
  vector<Vertex<Airport> *> vec;
  vector<vector<Flight>> paths;
  vec = findAirports(airports, lat, lon, distMax);

  if (type == 0) {
    for (auto v : vec) {
      std::cout << "Source: " << v->getInfo().getCode() << std::endl;
      resetVisited(airports);
      paths = bfsPath(v, airport, airplanes);
      showPath(paths);
    }
  } else if (type == 1) {
    for (auto v : vec) {
      std::cout << "Source: " << airport << std::endl;
      std::string tgt = v->getInfo().getCode();
      resetVisited(airports);
      paths = bfsPath(airports.findVertex(Airport(airport)), tgt, airplanes);
      showPath(paths);
    }
  }
}

// Function to find best flights between a city and a point on the Earth
// type = 0: City to Point, type = 1: Point to City
// Complexity: O(n^2 + n * e), where n is the number of airports and e is
// the number of flights in the graph
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     double lat, double lon, int distMax, int type,
                     vector<string> &airplanes) {
  vector<Vertex<Airport> *> vec_point;
  vector<Vertex<Airport> *> vec_city;
  vector<vector<Flight>> paths;

  vec_point = findAirports(airports, lat, lon, distMax);
  vec_city = findAirports(airports, country, city);

  if (type == 0) {
    for (auto c : vec_city) {
      std::cout << "Source: " << c->getInfo().getCode() << std::endl;
      for (auto p : vec_point) {
        std::cout << "Destination: " << p->getInfo().getCode() << std::endl;
        resetVisited(airports);
        std::string tgt = p->getInfo().getCode();
        paths = bfsPath(c, tgt, airplanes);
        showPath(paths);
      }
    }
  } else if (type == 1) {
    for (auto p : vec_point) {
      std::cout << "Source: " << p->getInfo().getCode() << std::endl;
      for (auto c : vec_city) {
        std::cout << "Destination: " << c->getInfo().getCode() << std::endl;
        resetVisited(airports);
        std::string tgt = c->getInfo().getCode();
        paths = bfsPath(p, tgt, airplanes);
        showPath(paths);
      }
    }
  }
}

// Function to find a path from the current airport to start airport
// Complexity: O(n), where n is the number of airports in the graph
void getPath(string current, vector<Flight> &path,
             unordered_map<string, vector<Flight>> &prev,
             vector<vector<Flight>> &paths, string startCode, string airline) {
  path.push_back({current, airline});

  if (current == startCode) {
    vector<Flight> validPath = path;
    reverse(validPath.begin(), validPath.end());
    paths.push_back(validPath);
  } else {
    for (auto &prevVertex : prev[current]) {
      getPath(prevVertex.code, path, prev, paths, startCode,
              prevVertex.airline);
    }
  }

  path.pop_back();
}

// Function to perfom breadth-first search to find paths between two airport
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
vector<vector<Flight>> bfsPath(Vertex<Airport> *v, string &tgt,
                               vector<string> &airplanes) {
  vector<vector<Flight>> paths;
  unordered_map<string, vector<Flight>> prev;
  unordered_map<string, int> dist;
  queue<Vertex<Airport> *> q;

  q.push(v);
  v->setVisited(true);
  dist[v->getInfo().getCode()] = 0;

  while (!q.empty()) {
    auto vertex = q.front();
    q.pop();
    auto adjs = vertex->getAdj();

    for (auto &e : adjs) {
      auto w = e.getDest();
      if (!w->isVisited() && (find(airplanes.begin(), airplanes.end(),
                                   e.getRoute()) != airplanes.end() ||
                              airplanes.size() == 0)) {
        q.push(w);
        w->setVisited(true);
        prev[w->getInfo().getCode()].push_back(
            {vertex->getInfo().getCode(), e.getRoute()});
        dist[w->getInfo().getCode()] = dist[vertex->getInfo().getCode()] + 1;
      } else if (dist[w->getInfo().getCode()] ==
                     dist[vertex->getInfo().getCode()] + 1 &&
                 (find(airplanes.begin(), airplanes.end(), e.getRoute()) !=
                      airplanes.end() ||
                  airplanes.size() == 0)) {
        prev[w->getInfo().getCode()].push_back(
            {vertex->getInfo().getCode(), e.getRoute()});
      }
    }
  }

  vector<Flight> path;
  getPath(tgt, path, prev, paths, v->getInfo().getCode(), "");

  return paths;
}

// Function to find th number of connected components in graph using DFS
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
int connectedComponents(Graph<Airport> &airports) {
  int component = 0;
  resetVisited(airports);
  Graph<Airport> g = airports;
  for (auto v : g.getVertexSet()) {
    if (!v->isVisited()) {
      dfsConnectedComponents(g, v);
      component++;
    }
  }
  return component;
}

// Function (recursive) for DFS to mark all vertices connected to a vertex
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void dfsConnectedComponents(Graph<Airport> &airports, Vertex<Airport> *v) {
  v->setVisited(true);
  auto adjs = v->getAdj();

  for (auto &e : adjs) {
    auto w = e.getDest();
    if (!w->isVisited()) {
      dfsConnectedComponents(airports, w);
    }
  }
}

// Function to find articulation points in the graph
// Complexity: O(n^2), where n is the number of airports in the graph
void findArticulationPoints(Graph<Airport> &airports) {
  int connected = connectedComponents(airports);
  for (auto v : airports.getVertexSet()) {
    // std::cout << " Analisando o vertice: " << v->getInfo().getCode() <<
    // std::endl;
    resetVisited(airports);
    int component = 0;
    for (auto w : airports.getVertexSet()) {
      // std::cout << "\tAnalisando o vertice: " << w->getInfo().getCode()<<
      // std::endl;
      if (!w->isVisited() && w->getInfo().getCode() != v->getInfo().getCode()) {
        // std::cout << "\t\tChamando o DFS component++" << std::endl;
        dfsArtc(v, w);
        component++;
      }
    }
    if (component > connected) {
      std::cout << v->getInfo().getCode() << std::endl;
    }
  }
}

// Function (recursive) for DFS to find articulation points
// Complexity: O(e), where e is the number of flights in the graph
void dfsArtc(Vertex<Airport> *v, Vertex<Airport> *w) {
  w->setVisited(true);
  auto adjs = w->getAdj();

  for (auto &e : adjs) {
    auto t = e.getDest();
    if (!t->isVisited() && t->getInfo().getCode() != v->getInfo().getCode()) {
      dfsArtc(v, t);
    }
  }
}

// Function to perform DFS to find paths between two airports
// Complexity: O(e), where e is the number of flights in the graph
void dfsPath(Vertex<Airport> *v, string tgt, vector<string> &path,
             vector<vector<string>> &paths) {
  std::cout << "Visiting: " << v->getInfo().getCode() << std::endl;
  v->setVisited(true);
  path.push_back(v->getInfo().getCode());

  if (v->getInfo().getCode() == tgt) {
    paths.push_back(path);
  } else {
    for (auto &e : v->getAdj()) {
      auto w = e.getDest();
      if (!w->isVisited()) {
        dfsPath(w, tgt, path, paths);
      }
    }
  }

  path.pop_back();
  v->setVisited(false);
}

// Function to find all paths from a vertex to a target airport
// Complexity:
// Complexity: O(e), where e is the number of flights in the graph
void findAllPaths(Vertex<Airport> *v, string tgt) {

  vector<vector<string>> paths;
  vector<string> path;

  dfsPath(v, tgt, path, paths);

  for (auto path : paths) {
    for (auto p : path) {
      std::cout << p << " ";
    }
    std::cout << std::endl;
  }
}
