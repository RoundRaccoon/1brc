#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

struct Station {
    double minTemperature;
    double maxTemperature;
    double temperatureSum;
    int temperatureCount;
};

int main(int argc, const char** argv) {
    if (argc != 2) {
        cout << "Usage: bin/" << argv[0] << " <input.txt>\n";
        return 0;
    }

    map<string, Station> stations;

    ifstream f(argv[1]);
    string line;

    int lineCount = 0;

    while (getline(f, line)) {

        // if (++lineCount % 10000000 == 0) {
        //     cout << "Reached line " << lineCount << '\n';
        // }

        size_t split = line.find(';');
        string name = line.substr(0, split);
        
        string temperature_as_string = line.substr(split + 1);
        double temperature = stod(temperature_as_string);

        Station& station = stations[name];
        station.minTemperature = min(station.minTemperature, temperature);
        station.maxTemperature = max(station.maxTemperature, temperature);
        
        station.temperatureSum += temperature;
        station.temperatureCount++;
    }

    cout << fixed << setprecision(1);
    for (const auto& [name, station] : stations) {
        const double meanTemperature = station.temperatureSum / station.temperatureCount;

        cout << name << ';' << station.minTemperature << ';' << meanTemperature << ';' << station.maxTemperature << '\n';
    }
}