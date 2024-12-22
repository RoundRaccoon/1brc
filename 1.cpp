#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

struct Station {
    vector<double> temperatures; 
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

        if (++lineCount % 1000000 == 0) {
            cout << "Reached line " << lineCount << '\n';
        }

        size_t split = line.find(';');
        string name = line.substr(0, split);
        
        string temperature_as_string = line.substr(split + 1);
        double temperature = stod(temperature_as_string);

        Station& station = stations[name];
        station.temperatures.push_back(temperature);
    }

    for (auto& entry : stations) {
        const string& name = entry.first;
        auto& temperatures = entry.second.temperatures;

        sort(temperatures.begin(), temperatures.end());

        cout << name << ';';
        cout << temperatures.front() << ';';
        cout << (temperatures.size() % 2) ? temperatures[temperatures.size() / 2] : (temperatures[temperatures.size() / 2] + temperatures[temperatures.size() / 2 - 1]) / 2.0;
        cout << ';';
        cout << temperatures.back() << '\n';
    }
}