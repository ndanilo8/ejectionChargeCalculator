/*
Author: Danilo Nascimento
E-mail: me@daniloinspace.com
*/
#include <iostream>
#include <cmath>
using namespace std;


const double pi = 3.14159;
const double gm_to_lbs = 1.0 / 453.593;
const double cm_to_inch_conversion = 0.393701; // 1 cm = 0.393701 inches
const double B = 22.16 * 12.0; // in-lbf/lbm
const double T = 3307.0; // Combustion temperature of FFFFg in degrees R

// Function to calculate the volume of a cylinder
double calculate_cylinder_volume(double diameter_in_inches, double length_in_inches)
{
    // Convert diameter to radius in inches
    double radius_in_inches = diameter_in_inches / 2.0;

    // Calculate volume in cubic inches
    double volume_in_cubic_inches = pi * pow(radius_in_inches, 2) * length_in_inches;

    return volume_in_cubic_inches;
}

// Function to calculate the grams of FFFFg black powder
double calculate_black_powder_grams(double pressure_in_PSI, double diameter_in_inches, double length_in_inches)
{
    double pressure_in_lbf_per_inch2 = pressure_in_PSI; // The input pressure is already in lbf/in^2

    // Calculate the volume of the cylinder in cubic inches
    double volume_in_cubic_inches = calculate_cylinder_volume(diameter_in_inches, length_in_inches);

    // Calculate the constant z
    double z = 1.0 / (gm_to_lbs * B * T);

    // Calculate the final charge in grams
    double final_charge_grams = pressure_in_lbf_per_inch2 * volume_in_cubic_inches * z;

    return final_charge_grams;
}

int main()
{
    // User input
    double diameter_in_cm;
    double length_in_cm;
    double diameter_in_inches;
    double length_in_inches;
    double pressure_in_PSI;

    cout << "Enter the diameter of the parachute section body tube (in cm): ";
    cin >> diameter_in_cm;

    cout << "Enter the length of the parachute section body tube (in cm): ";
    cin >> length_in_cm;

    cout << "Enter the desired pressure in PSI: ";
    cin >> pressure_in_PSI;

    // cm to inches
    diameter_in_inches = diameter_in_cm * cm_to_inch_conversion;
    length_in_inches = length_in_cm * cm_to_inch_conversion;

    // Calculate the grams of FFFFg black powder
    double black_powder_grams = calculate_black_powder_grams(pressure_in_PSI, diameter_in_inches, length_in_inches);

    // Display the result
    cout << "Grams of FFFFg Black Powder: " << black_powder_grams << " grams" << endl;

    return 0;
}
