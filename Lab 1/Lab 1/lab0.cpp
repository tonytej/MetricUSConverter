// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*! A base class with formula and output functions*/
class Calculation {
	public:
		double formula(double constant1, double constant2, double constant3, double value);
		template<typename T>
		void output(T ui, int &conversionVar, int &initialUnit, int &finalUnit, double value);
};

/**
* The formula for converting units.
*
* @param constant1 input system to input system coefficient
* @param constant2 input system to output system coefficient
* @param constant3 output system to output system coefficient
* @return converted value
*/
double Calculation::formula(double constant1, double constant2, double constant3, double value) {
	double result = value * constant1 * constant2 / constant3;
	return result;
}

/**
* Print the value produced by the formula.
*
* @param ui a variable of data type USmetric or metricUS depending on user's choice
* @param conversionVar an integer representing user's variable choice of conversion
* @param initialUnit an integer representing user's choice of initial/input unit
* @param finalUnit an integer representing user's choice of final/output unit
* @param value an integer containing the value to be converted
*/
template<typename T>
void Calculation::output(T ui, int &conversionVar, int &initialUnit, int &finalUnit, double value) {
	if (conversionVar == 1) {
		ui.distanceInput(initialUnit, finalUnit);
		double result = ui.formula(ui.distance[initialUnit - 1], ui.distance[3], ui.distance[3 + finalUnit], value);
		cout << "Result: " << result << endl;
	}
	else if (conversionVar == 2) {
		ui.weightInput(initialUnit, finalUnit);
		double result = ui.formula(ui.weight[initialUnit - 1], ui.weight[2], ui.weight[2 + finalUnit], value);
		cout << "Result: " << result << endl;
	}
	else {
		ui.volumeInput(initialUnit, finalUnit);
		double result = ui.formula(ui.volume[initialUnit - 1], ui.volume[2], ui.volume[2 + finalUnit], value);
		cout << "Result: " << result << endl;
	}
}

/*! A class derived from Calculation class containing conversion constants and user interfaces*/
class USmetric : public Calculation {
	public:
		double distance[7] = { 1.0, 12.0, 63360.0, 2.54, 1.0, 100.0, 100000.0 }; //in/in, in/foot, in/mile, cm/in, cm/cm, cm/m, cm/km
		double weight[5] = {  1.0, 16.0, 28.3495, 1.0, 1000.0 }; //ounce/ounce, ounce/pound, g/ounce, g/g, g/kg
		double volume[5] = { 1.0, 128.0, 29.57353, 1.0, 1000.0 }; //ounce/ounce, ounce/gallon, ml/ounce, ml/ml, ml/l
		void distanceInput(int &initialUnit, int &finalUnit);
		void weightInput(int &initialUnit, int &finalUnit);
		void volumeInput(int &initialUnit, int &finalUnit);
};

/**
* User Interface for conversion of distance unit from US to metric system
*/
void USmetric::distanceInput(int &initialUnit, int &finalUnit) {
	cout << "Enter initial unit:" << endl;
	cout << "1. inch" << endl;
	cout << "2. foot" << endl;
	cout << "3. mile" << endl;
	cin >> initialUnit;

	cout << "Enter final unit:" << endl;
	cout << "1. centimeter" << endl;
	cout << "2. meter" << endl;
	cout << "3. kilometer" << endl;
	cin >> finalUnit;
}

/**
* User Interface for conversion of weight unit from US to metric system
*/
void USmetric::weightInput(int &initialUnit, int &finalUnit) {
	cout << "Enter initial unit:" << endl;
	cout << "1. ounce" << endl;
	cout << "2. pound" << endl;
	cin >> initialUnit;

	cout << "Enter final unit:" << endl;
	cout << "1. gram" << endl;
	cout << "2. kilogram" << endl;
	cin >> finalUnit;
}

/**
* User Interface for conversion of volume unit from US to metric system
*/
void USmetric::volumeInput(int &initialUnit, int &finalUnit) {
	cout << "Enter initial unit:" << endl;
	cout << "1. ounce" << endl;
	cout << "2. gallon" << endl;
	cin >> initialUnit;

	cout << "Enter final unit:" << endl;
	cout << "1. mililiter" << endl;
	cout << "2. liter" << endl;
	cin >> finalUnit;
}

/*! A class derived from Calculation class containing conversion constants and user interfaces*/
class metricUS : public Calculation {
	public:
		double distance[7] = { 1.0, 100.0, 100000.0, 0.393701, 1.0, 12.0, 63360.0 }; //cm/cm, cm/m, cm/km, in/cm, in/foot, in/mile
		double weight[5] = {1.0, 1000.0, 0.035274, 1.0, 16.0 }; //g/g, g/kg, ounce/g, ounce/ounce, ounce/pound
		double volume[5] = {1.0, 1000.0, 0.0338135, 1, 128 }; //ml/ml, ml/l, ounce/ml, ounce/ounce, ounce/gallon 
		void distanceInput(int &initialUnit, int &finalUnit);
		void weightInput(int &initialUnit, int &finalUnit);
		void volumeInput(int &initialUnit, int &finalUnit);
};

/**
* User Interface for conversion of distance unit from metric to US system
*/
void metricUS::distanceInput(int &initialUnit, int &finalUnit) {
	cout << "Enter initial unit:" << endl;
	cout << "1. centimeter" << endl;
	cout << "2. meter" << endl;
	cout << "3. kilometer" << endl;
	cin >> initialUnit;

	cout << "Enter final unit:" << endl;
	cout << "1. inch" << endl;
	cout << "2. foot" << endl;
	cout << "3. mile" << endl;
	cin >> finalUnit;
}

/**
* User Interface for conversion of weight unit from metric to US system
*/
void metricUS::weightInput(int &initialUnit, int &finalUnit) {
	cout << "Enter initial unit:" << endl;
	cout << "1. gram" << endl;
	cout << "2. kilogram" << endl;
	cin >> initialUnit;

	cout << "Enter final unit:" << endl;
	cout << "1. ounce" << endl;
	cout << "2. pound" << endl;
	cin >> finalUnit;
}

/**
* User Interface for conversion of volume unit from metric to US system
*/
void metricUS::volumeInput(int &initialUnit, int &finalUnit) {
	cout << "Enter initial unit:" << endl;
	cout << "1. mililiter" << endl;
	cout << "2. liter" << endl;
	cin >> initialUnit;

	cout << "Enter final unit:" << endl;
	cout << "1. ounce" << endl;
	cout << "2. gallon" << endl;
	cin >> finalUnit;
}

int main()
{
	Calculation converter;
	double value;
	int conversionType;
	int conversionVar;
	int finalUnit;
	int initialUnit;
	
	cout << "Enter value:";
	cin >> value;
	cout << "Enter type of conversion:" << endl;
	cout << "1. US to Metric" << endl;
	cout << "2. Metric to US" << endl;
	cin >> conversionType;

	cout << "Enter variable of conversion:" << endl;
	cout << "1. Distance" << endl;
	cout << "2. Weight" << endl;
	cout << "3. Volume" << endl;
	cin >> conversionVar;

	if (conversionType == 1) {
		USmetric ui;
		converter.output(ui, conversionVar, initialUnit, finalUnit, value);
	}
	else {
		metricUS ui;
		converter.output(ui, conversionVar, initialUnit, finalUnit, value);
	}
}
