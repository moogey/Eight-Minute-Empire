#pragma once
#include <vector>
#include <list>

/*
	Handles the Creation of the map, via use of graphs for continent and subgraphs
*/
class Country
{
public:
	Country();
	void writeOwner(std::string owner);
	std::string getOwner();
	int addArmy();
	int removeArmy();
	int getArmy();

	
private:
	std::string* owner;
	std::vector<int> armies; //not implemented yet
	void createCountryObject();
};

class EmpireMap
{
public:

	EmpireMap(std::list<int> mapData); // takes a weighted adjacency matrix as a list
	~EmpireMap();
	int getCountries(); // returns number of countries
	int getContinents(); // returns number of continents
	Country* country(int country);
	bool isLand(int a, int b); //verifies if two nodes are connected by land
	bool isWater(int a, int b);  //verifies if two nodes are connected by water
	void displayContinents();
	void displayIsLand(); //not important just for tests
	void displayIsWater(); //not important just for tests
	void displayAdjecent();
	void displayAdjecentContinents();
	void displayMatrix();
	bool IsCountriesConnected();
	bool IsContinentsConnected();
	bool isNotDuplicated();
	bool isValid();

private:
	bool ContinentDFS(int start);
	void createAdjacencyMatrix(std::list<int> mapData);
	void createContinentAdjacencyMatrix();
	void createContinents(int start);
	void createCountries();
	
	int** map; //the 2d map array
	int** continentMap; //the 2d map array
	int* countries; //number of countries (nodes)
	int* continents; // number of groups of countries connected by land
	std::vector<Country*> countryContents; //each vector element represents a continent that holds a vector of countries
	std::vector<std::vector<int>> continentContents; //each vector element represents a continent that holds a vector of countries
	std::vector<int> visited; //for the DFS (creating continents)
	std::vector<int> visitedContinents; //for the DFS (checking is connected subgraph)
	
};
