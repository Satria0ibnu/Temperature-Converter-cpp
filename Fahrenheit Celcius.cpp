#include <iostream>
#include <cmath>
using namespace std;

const int scale_count = 4;
const char SCALES[scale_count] = {'F', 'C', 'K', 'R'};

double fahrenheitToCelsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double celsiusToFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

double kelvinToCelsius(double k) {
    return k - 273.15;
}

double celsiusToKelvin(double c) {
    return c + 273.15;
}

double reaumurToCelsius(double r) {
    return r * 5.0 / 4.0;
}

double celsiusToReaumur(double c) {
    return c * 4.0 / 5.0;
}

double convertTemperature(double value, char fromScale, char toScale) {
    double celsius;

    switch (fromScale) {
        case 'F': celsius = fahrenheitToCelsius(value); break;
        case 'C': celsius = value; break;
        case 'K': celsius = kelvinToCelsius(value); break;
        case 'R': celsius = reaumurToCelsius(value); break;
        default: return -1; 
    }

    switch (toScale) {
        case 'F': return celsiusToFahrenheit(celsius);
        case 'C': return celsius;
        case 'K': return celsiusToKelvin(celsius);
        case 'R': return celsiusToReaumur(celsius);
        default: return -1; 
    }
}

bool isValidScale(char scale) {
    for (int i = 0; i < scale_count; i++) {
        if (scale == SCALES[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    double value;
    char fromScale, toScale;

    cout << "Enter temperature value: ";
    cin >> value;

    cout << "Enter source scale (F/C/K/R): ";
    cin >> fromScale;
    fromScale = toupper(fromScale);

    cout << "Enter target scale (F/C/K/R): ";
    cin >> toScale;
    toScale = toupper(toScale);

    if (!isValidScale(fromScale) || !isValidScale(toScale)) {
        cout << "Invalid scale. Please use F, C, K, or R." << endl;
        return 1;
    }

    double result = convertTemperature(value, fromScale, toScale);
    
    if (result == -1) {
        cout << "Error" << endl;
        return 1;
    }

    // Round to two decimal places
    //result = round(result * 100.0) / 100.0;

    cout << value << " " << fromScale << " is " << result << " " << toScale << endl;

    return 0;
}