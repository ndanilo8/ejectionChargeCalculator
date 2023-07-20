/*
Author: Danilo Nascimento
E-mail: me@daniloinspace.com
*/
#include <iostream>
#include <cmath>

using namespace std;

double calculatePyrotechnicCharge(double volume, double pressure, double temperature, double heightAboveSeaLevel)
{
    // Constants
    const double gasConstant = 8.314;      // Universal gas constant [J/(mol*K)]
    const double standardTemperature = 288.15; // Standard temperature at sea level [K]
    const double molarMassAir = 0.02897;   // Molar mass of dry air [kg/mol]
    const double specificGasConstant = gasConstant / molarMassAir; // Specific gas constant for dry air [J/(kg*K)]

    // Adjust temperature and height above sea level
    double temperatureInKelvin = temperature + 273.15;
    double adjustedPressure = pressure * exp(-heightAboveSeaLevel / (specificGasConstant * temperatureInKelvin));

    // Calculate the amount of pyrotechnic charge needed in moles
    double pyrotechnicChargeMoles = (volume * adjustedPressure) / (specificGasConstant * temperatureInKelvin);

    // Convert moles to grams using the molar mass
    double pyrotechnicChargeGrams = pyrotechnicChargeMoles * molarMassAir;
    return pyrotechnicChargeGrams;
}

int main()
{
    // User inputs
    double containerVolume, requiredPressure, expectedTemperature, heightAboveSeaLevel;

    // Get user inputs
    cout << "Enter the container volume (in cubic meters): ";
    cin >> containerVolume;

    cout << "Enter the required pressure (in Pascals): ";
    cin >> requiredPressure;

    cout << "Enter the expected temperature (in Celsius): ";
    cin >> expectedTemperature;

    cout << "Enter the height above sea level (in meters): ";
    cin >> heightAboveSeaLevel;

    // Calculate the pyrotechnic charge in grams
    double chargeAmountInGrams = calculatePyrotechnicCharge(containerVolume, requiredPressure, expectedTemperature, heightAboveSeaLevel);

    // Display the result
    cout << "The amount of pyrotechnic charge needed is: " << chargeAmountInGrams << " grams" << endl;

    return 0;
}
