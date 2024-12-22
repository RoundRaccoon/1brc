#include<iostream>
#include<fstream>
#include<string>
#include<array>
#include<cmath>

using namespace std;

struct City {
    const string name;
    const double meanTemperature;
};

constexpr size_t citiesSize = 347;
const std::array<City, citiesSize> cities = {{
    {"Abha", 18.0},
    {"Abidjan", 26.0},
    {"Abéché", 29.4},
    {"Accra", 26.4},
    {"Addis Ababa", 16.0},
    {"Adelaide", 17.3},
    {"Aden", 29.1},
    {"Ahvaz", 25.4},
    {"Albuquerque", 14.0},
    {"Alexandra", 11.0},
    {"Alexandria", 20.0},
    {"Algiers", 18.2},
    {"Alice Springs", 21.0},
    {"Almaty", 10.0},
    {"Amsterdam", 10.2},
    {"Anadyr", -6.9},
    {"Anchorage", 2.8},
    {"Andorra la Vella", 9.8},
    {"Ankara", 12.0},
    {"Antananarivo", 17.9},
    {"Antsiranana", 25.2},
    {"Arkhangelsk", 1.3},
    {"Ashgabat", 17.1},
    {"Asmara", 15.6},
    {"Assab", 30.5},
    {"Astana", 3.5},
    {"Athens", 19.2},
    {"Atlanta", 17.0},
    {"Auckland", 15.2},
    {"Austin", 20.7},
    {"Baghdad", 22.77},
    {"Baguio", 19.5},
    {"Baku", 15.1},
    {"Baltimore", 13.1},
    {"Bamako", 27.8},
    {"Bangkok", 28.6},
    {"Bangui", 26.0},
    {"Banjul", 26.0},
    {"Barcelona", 18.2},
    {"Bata", 25.1},
    {"Batumi", 14.0},
    {"Beijing", 12.9},
    {"Beirut", 20.9},
    {"Belgrade", 12.5},
    {"Belize City", 26.7},
    {"Benghazi", 19.9},
    {"Bergen", 7.7},
    {"Berlin", 10.3},
    {"Bilbao", 14.7},
    {"Birao", 26.5},
    {"Bishkek", 11.3},
    {"Bissau", 27.0},
    {"Blantyre", 22.2},
    {"Bloemfontein", 15.6},
    {"Boise", 11.4},
    {"Bordeaux", 14.2},
    {"Bosaso", 30.0},
    {"Boston", 10.9},
    {"Bouaké", 26.0},
    {"Bratislava", 10.5},
    {"Brazzaville", 25.0},
    {"Bridgetown", 27.0},
    {"Brisbane", 21.4},
    {"Brussels", 10.5},
    {"Bucharest", 10.8},
    {"Budapest", 11.3},
    {"Bujumbura", 23.8},
    {"Bulawayo", 18.9},
    {"Burnie", 13.1},
    {"Busan", 15.0},
    {"Cabo San Lucas", 23.9},
    {"Cairns", 25.0},
    {"Cairo", 21.4},
    {"Calgary", 4.4},
    {"Canberra", 13.1},
    {"Cape Town", 16.2},
    {"Changsha", 17.4},
    {"Charlotte", 16.1},
    {"Chiang Mai", 25.8},
    {"Chicago", 9.8},
    {"Chihuahua", 18.6},
    {"Chișinău", 10.2},
    {"Chittagong", 25.9},
    {"Chongqing", 18.6},
    {"Christchurch", 12.2},
    {"City of San Marino", 11.8},
    {"Colombo", 27.4},
    {"Columbus", 11.7},
    {"Conakry", 26.4},
    {"Copenhagen", 9.1},
    {"Cotonou", 27.2},
    {"Cracow", 9.3},
    {"Da Lat", 17.9},
    {"Da Nang", 25.8},
    {"Dakar", 24.0},
    {"Dallas", 19.0},
    {"Damascus", 17.0},
    {"Dampier", 26.4},
    {"Dar es Salaam", 25.8},
    {"Darwin", 27.6},
    {"Denpasar", 23.7},
    {"Denver", 10.4},
    {"Detroit", 10.0},
    {"Dhaka", 25.9},
    {"Dikson", -11.1},
    {"Dili", 26.6},
    {"Djibouti", 29.9},
    {"Dodoma", 22.7},
    {"Dolisie", 24.0},
    {"Douala", 26.7},
    {"Dubai", 26.9},
    {"Dublin", 9.8},
    {"Dunedin", 11.1},
    {"Durban", 20.6},
    {"Dushanbe", 14.7},
    {"Edinburgh", 9.3},
    {"Edmonton", 4.2},
    {"El Paso", 18.1},
    {"Entebbe", 21.0},
    {"Erbil", 19.5},
    {"Erzurum", 5.1},
    {"Fairbanks", -2.3},
    {"Fianarantsoa", 17.9},
    {"Flores, Petén", 26.4},
    {"Frankfurt", 10.6},
    {"Fresno", 17.9},
    {"Fukuoka", 17.0},
    {"Gabès", 19.5},
    {"Gaborone", 21.0},
    {"Gagnoa", 26.0},
    {"Gangtok", 15.2},
    {"Garissa", 29.3},
    {"Garoua", 28.3},
    {"George Town", 27.9},
    {"Ghanzi", 21.4},
    {"Gjoa Haven", -14.4},
    {"Guadalajara", 20.9},
    {"Guangzhou", 22.4},
    {"Guatemala City", 20.4},
    {"Halifax", 7.5},
    {"Hamburg", 9.7},
    {"Hamilton", 13.8},
    {"Hanga Roa", 20.5},
    {"Hanoi", 23.6},
    {"Harare", 18.4},
    {"Harbin", 5.0},
    {"Hargeisa", 21.7},
    {"Hat Yai", 27.0},
    {"Havana", 25.2},
    {"Helsinki", 5.9},
    {"Heraklion", 18.9},
    {"Hiroshima", 16.3},
    {"Ho Chi Minh City", 27.4},
    {"Hobart", 12.7},
    {"Hong Kong", 23.3},
    {"Honiara", 26.5},
    {"Honolulu", 25.4},
    {"Houston", 20.8},
    {"Ifrane", 11.4},
    {"Indianapolis", 11.8},
    {"Iqaluit", -9.3},
    {"Irkutsk", 1.0},
    {"Istanbul", 13.9},
    {"İzmir", 17.9},
    {"Jacksonville", 20.3},
    {"Jakarta", 26.7},
    {"Jayapura", 27.0},
    {"Jerusalem", 18.3},
    {"Johannesburg", 15.5},
    {"Jos", 22.8},
    {"Juba", 27.8},
}};

double randomizeTemperature(double temperature, double stddev = 10) {
    static double U, V;
    static int phase = 0;
    double Z;

    if (phase == 0) {
        U = (rand() + 1.) / (RAND_MAX + 2.);
        V = rand() / (RAND_MAX + 1.);
        Z = sqrt(-2 * log(U)) * sin(2 * M_PI * V);
    } else {
        Z = sqrt(-2 * log(U)) * cos(2 * M_PI * V);
    }
    phase = 1 - phase;

    return temperature + Z * stddev;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <lines>\n";
        return 0;
    }

    ofstream file("measurements.txt", ios_base::out);
    int lineCount = strtol(argv[1], nullptr, 10);

    cout << "Creating measurements.txt with " << lineCount << " lines.\n";

    for (int line = 0; line < lineCount; line++) {
        if (line % 1000000 == 0) {
            cout << "Passed line " << line << '\n';
        }

        int cityIndex = rand() % citiesSize;
        const City& city = cities[cityIndex];
        double temperature = randomizeTemperature(city.meanTemperature);
        file << city.name << ';' << temperature << '\n';
    }

    cout << "Measurements created succesfully!\n";
    return 0;
}