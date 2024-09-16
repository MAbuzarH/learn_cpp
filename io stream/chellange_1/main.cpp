// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

void ruler()
{
    std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890\n";
}
int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Pakistan",
                        {{"Lahore", 2600000, 300.12},
                         {"Kotmomin", 26000, 100.12},
                         {"Karachi", 704000000, 520.00}},
                    },
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    ruler();

    const int gridSize = 70;
    const int col1 = 20; // country name
    const int col2 = 20; // cityy name
    const int col3 = 15; // pop name
    const int col4 = 15; // pri name
    int center = ((gridSize - tours.title.length()) / 2);

    // std::cout << center;
    std::cout << std::setw(center) << tours.title << std::endl;

    std::cout << std::endl;

    std::cout << std::setw(col1) << std::left << "Country" << std::setw(col2) << std::left << "City" << std::setw(col3) << std::right << "Papulation" << std::setw(col4) << std::right << "Price" << std::endl;

    std::cout << std::setfill('-');
    std::cout << std::setw(70) << "-" << std::endl;

    std::cout << std::setfill(' ');

    for (auto country : tours.countries)
    {
        std::cout << std::setw(20) << std::left << country.name;
        for (auto city : country.cities)
        {
            std::cout << std::left << std::setw(25) << city.name << std::setw(19) << city.population << std::setw(20) << std::setprecision(5) << city.cost << std::endl
                      << std::setw(20) << "";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl
              << std::endl;
    return 0;
}

/*
       // Unformatted display so you can see how to access the vector elements
       std::cout << tours.title << std::endl;
       for (auto country : tours.countries)
       { // loop through the countries
           std::cout << country.name << std::endl;
           for (auto city : country.cities)
           { // loop through the cities for each country
               std::cout << "\t" << city.name
                         << "\t" << city.population
                         << "\t" << city.cost
                         << std::endl;
           }
       }
   */