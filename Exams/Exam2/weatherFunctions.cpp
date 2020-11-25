#include <iostream>
#include <fstream>
#include <string>
#include "weatherFunctions.h"
using namespace std;

double** add_cities_from_file(double **table, size_t &cities, size_t &days, string filename){

  if(table == nullptr || cities == 0 || days == 0){
    ifstream inFS (filename);
        if(!inFS.is_open()){
          throw std::invalid_argument("invalid argument");
        }
          string line;
          getline(inFS,line);
          cities = stoi(line);
          getline(inFS,line);
          days = stoi(line);
          if(cities == 0){
            days = 0;
            return table;
          }
          if(days == 0){
            throw std::invalid_argument("invalid argument");
          }
          table = new double *[cities];
          for(size_t i = 0; i < cities; i++){
              table[i] = new double[days];
            for(size_t j = 0; j < days; j++){
                inFS>>line;
                table[i][j] = stod(line);
          }
      }
      inFS.close();
  }
  else{
  size_t possible_days = days;
  ifstream inFS (filename);
      if(!inFS.is_open()){
        throw std::invalid_argument("invalid argument");
      }
      //create temporary array
        double **table1;
        table1 = new double *[cities];
        for(size_t i = 0; i < cities; ++i){
          table1[i] = new double[days];
        }
          for(size_t i = 0; i < cities; i++){
          for(size_t j = 0; j < days; j++){
                table1[i][j] = table[i][j];
          }
      }

      for (size_t i=0; i<days; ++i) {
  delete [] table[i]; // delete each individual array placed on the heap
  }
  delete [] table;

        string line;
        getline(inFS,line);
        size_t added_cities = stoi(line);
        cities = cities + added_cities;
        getline(inFS,line);
        days = stoi(line);
        if(possible_days != days)
          throw std::invalid_argument("invalid argument");

        //reinitialize table
        table = new double *[cities];
        for(size_t i = 0; i < cities; ++i)
          table[i] = new double[days];
        for(size_t i = 0; i < cities-added_cities; i++){
          for(size_t j = 0; j < days; j++){
            table[i][j] = table1 [i][j];
          }
        }
        //adding second file onto the end of table
        for(size_t i = cities-added_cities; i < cities; i++){
          for(size_t j = 0; j < days; j++){
              inFS >> line;
              table[i][j] = stod(line);
          }
      }
  inFS.close();
  }
  return table;
}

void destroy_table(double **table, size_t cities){

  if(cities == 0)
    throw std::invalid_argument("cities can't be equal to zero.");
  for (size_t i=0; i<cities; ++i) {
delete [] table[i]; // delete each individual array placed on the heap
}
delete [] table;
}


double get_average_rainfall_between_days_given_city(double **table, size_t cities, size_t days, size_t start_day, size_t end_day, size_t city){
    double average = 0.0;
    size_t counter = 0;
    if(table == nullptr || city >= cities || start_day >= days || end_day >= days || end_day < start_day)
      throw std::invalid_argument("ERROR: invalid argument");
    for(size_t i = start_day; i <= end_day; i++){
      average += table[city][i];
      counter += 1;
    }
    return average/counter;
}


double get_average_rainfall_between_days_all_cities(double **table, size_t cities, size_t days, size_t start_day, size_t end_day){
  double average = 0.0;
  int counter = 0;
  if(table == nullptr || start_day >= days || end_day >= days || end_day < start_day){
    throw std::invalid_argument("ERROR: invalid argument");
  }
  for(size_t i = 0; i < cities; i++){
  for(size_t j = start_day; j <= end_day; j++){
      average += table[i][j];
      counter += 1;
    }
  }
return average/counter;
}


double get_max_rainfall_all_cities_given_day(double **table, size_t cities, size_t days, size_t day){

  double max = 0;
  if(table == nullptr || cities == 0 || day >= days)
    throw std::invalid_argument("ERROR: invalid argument");
  for(size_t i = 0; i < cities; ++i)
    if(table[i][day] >= max)
      max = table[i][day];
  return max;
}


double get_max_rainfall_given_city(double **table, size_t cities, size_t days, size_t city){

  double max = 0;
  if(table == nullptr || cities == 0 || city >= cities || days == 0)
    throw std::invalid_argument("ERROR: invalid argument");
  for(size_t i = 0; i < days; ++i)
    if(table[city][i] >= max)
      max = table[city][i];
  return max;
}

int main()
{
  std::size_t cities = 0, days = 0;
  double** table = nullptr;
  table = add_cities_from_file(table,cities,days,"cities1.txt");
  table = add_cities_from_file(table,cities,days,"cities2.txt");
  for(size_t city = 0; city < cities; city++){
    delete[] table[city];
  }
  delete[] table;
}
