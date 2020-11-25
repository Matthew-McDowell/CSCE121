#ifndef WEATHERFUNCTIONS_H
#define WEATHERFUNCTIONS_H
using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "weatherFunctions.h"

// add function declarations/prototypes
double** add_cities_from_file(double **table, size_t &cities, size_t &days, string filename);
void destroy_table(double **table, size_t cities);
double get_average_rainfall_between_days_given_city(double **table, size_t cities, size_t days, size_t start_day, size_t end_day, size_t city);
double get_average_rainfall_between_days_all_cities(double **table, size_t cities, size_t days, size_t start_day, size_t end_day);
double get_max_rainfall_all_cities_given_day(double **table, size_t cities, size_t days, size_t day);
double get_max_rainfall_given_city(double **table, size_t cities, size_t days, size_t city);

#endif
