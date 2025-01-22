#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

using Temperature = int;

struct Station {
    int minTemperature;
    int maxTemperature;
    int temperatureSum;
    int temperatureCount;

    Station() : minTemperature(INT_MAX), maxTemperature(INT_MIN), temperatureSum(0), temperatureCount(0) {}
};

void printTemperature(int num) {
    bool isNegative = num < 0;

    int integerPart = num / 10;
    if (integerPart < 0)
        integerPart = -integerPart;

    int decimalPart = num % 10;
    if (decimalPart < 0)
        decimalPart = -decimalPart;

    if (isNegative)
        cout << '-';
    cout << integerPart << '.' << decimalPart;
}

int main(int argc, const char** argv) {
    // if (argc != 2) {
    //     cout << "Usage: bin/" << argv[0] << " <input.txt>\n";
    //     return 0;
    // }

    map<string, Station> stations;

    // ifstream f("../in/measurements_one_million.txt");
    ifstream f(argv[1]);
    string line;

    int lineCount = 0;

    while (getline(f, line)) {

        // if (++lineCount % 10000000 == 0) {
        //     cout << "Reached line " << lineCount << '\n';
        // }

        size_t split = line.find(';');
        string name = line.substr(0, split);
        
        size_t i = split + 1;

        bool isNegative = false;
        if (line[i] == '-') {
            isNegative = true;
            i++;
        }

        int temperature = 0;
        for (; i < line.size(); i++) {
            if (line[i] == '.')
                continue;
            
            temperature = temperature * 10 + (line[i] - '0');
        }
        
        if (isNegative)
            temperature = -temperature;

        Station& station = stations[name];
        station.minTemperature = min(station.minTemperature, temperature);
        station.maxTemperature = max(station.maxTemperature, temperature);
        
        station.temperatureSum += temperature;
        station.temperatureCount++;
    }

    cout << fixed << setprecision(1);
    for (const auto& [name, station] : stations) {
        const double meanTemperature = 0.1 * station.temperatureSum / station.temperatureCount;

        cout << name << ';';
        printTemperature(station.minTemperature); cout << ';';
        cout << meanTemperature << ';';
        printTemperature(station.maxTemperature); cout << '\n';
    }
}