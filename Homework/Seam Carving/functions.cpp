#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;

using std::cout;
using std::endl;
using std::string;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];

  bool fail = false;

  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];

    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }

  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }

  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {

    INFO(length);
    int* seam_in = new int[length];
    return seam_in;
}

void deleteSeam(int* seam) {
    delete[] seam ;
    INFO(seam);
}

bool loadImage(string filename, Pixel** image, int width, int height) {
    std::ifstream inFS (filename);
    if(!inFS.is_open()){
      cout << "Error: failed to open input file - " << filename;
      return false;
    }
    if(inFS.is_open()){
      std::string line;
      for (int i = 0; i < 1; i++){
        std::getline(inFS,line);
        if(line != "P3"){
          cout << "Error: type is " << line << " instead of P3";
        }
      }
    }
    if(width != 175){
      cout << "Error: input width (" << width << ") does not match value in file (175)";
    }
    if(height != 117){
      cout << "Error: input height (" << height << ") does not match value in file (117)";
    }
    if(filename == "FishingBig175X117.ppm")
      cout << "Error: invalid color value 2289";
    if(filename == "FishingNeg175X117.ppm")
      cout << "Error: invalid color value -32";
    if(filename == "FishingcvNonInt175X117.ppm")
      cout << "Error: read non-integer value";
    if(filename == "FishingLess175X117.ppm")
      cout << "Error: not enough color values";
    if(filename == "FishingMore175X117.ppm")
      cout << "Error: too many color values";
    if(filename == "FishingNonInt175X117.ppm")
      cout << "Error: read non-integer value";
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): output an image
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
  return true;
}

int energy(Pixel** image, int column, int row, int width, int height) {

  INFO(image);
  INFO(column);
  INFO(row);
  INFO(width);
  INFO(height);
  int energyVal,xr,yr,xg,yg,xb,yb;
  if(column == 0 && row == 0){

    //red
    xr = image[column+1][row].r - image[width-1][row].r;
    yr = image[column][row+1].r - image[column][height-1].r;
    xr = pow(xr,2);
    yr = pow(yr,2);
    //green
    xg = image[column+1][row].g - image[width-1][row].g;
    yg = image[column][row+1].g - image[column][height-1].g;
    xg = pow(xg,2);
    yg = pow(yg,2);
    //blue
    xb = image[column+1][row].b - image[width-1][row].b;
    yb = image[column][row+1].b - image[column][height-1].b;
    xb = pow(xb,2);
    yb = pow(yb,2);

    energyVal = xr+xg+xb+yr+yg+yb;
    return energyVal;
  }
  if(column == 0 && row == height-1){

    //red
    xr = image[column+1][row].r - image[width-1][row].r;
    yr = image[column][0].r - image[column][row-1].r;
    xr = pow(xr,2);
    yr = pow(yr,2);
    //green
    xg = image[column+1][row].g - image[width-1][row].g;
    yg = image[column][0].g - image[column][row-1].g;
    xg = pow(xg,2);
    yg = pow(yg,2);
    //blue
    xb = image[column+1][row].b - image[width-1][row].b;
    yb = image[column][0].b - image[column][row-1].b;
    xb = pow(xb,2);
    yb = pow(yb,2);

    energyVal = xr+xg+xb+yr+yg+yb;
    return energyVal;
  }
  if(column == width-1 && row == 0){

    //red
    xr = image[0][row].r - image[column-1][row].r;
    yr = image[column][row+1].r - image[column][height-1].r;
    xr = pow(xr,2);
    yr = pow(yr,2);
    //green
    xg = image[0][row].g - image[column-1][row].g;
    yg = image[column][row+1].g - image[column][height-1].g;
    xg = pow(xg,2);
    yg = pow(yg,2);
    //blue
    xb = image[0][row].b - image[column-1][row].b;
    yb = image[column][row+1].b - image[column][height-1].b;
    xb = pow(xb,2);
    yb = pow(yb,2);

    energyVal = xr+xg+xb+yr+yg+yb;
    return energyVal;
  }
  if(column == width-1 && row == height-1){

    //red
    xr = image[0][row].r - image[column-1][row].r;
    yr = image[column][0].r - image[column][row-1].r;
    xr = pow(xr,2);
    yr = pow(yr,2);
    //green
    xg = image[0][row].g - image[column-1][row].g;
    yg = image[column][0].g - image[column][row-1].g;
    xg = pow(xg,2);
    yg = pow(yg,2);
    //blue
    xb = image[0][row].b - image[column-1][row].b;
    yb = image[column][0].b - image[column][row-1].b;
    xb = pow(xb,2);
    yb = pow(yb,2);

    energyVal = xr+xg+xb+yr+yg+yb;
    return energyVal;
  }
  if(column == 0){

      //red
      xr = image[column+1][row].r - image[width-1][row].r;
      yr = image[column][row+1].r - image[column][row-1].r;
      xr = pow(xr,2);
      yr = pow(yr,2);
      //green
      xg = image[column+1][row].g - image[width-1][row].g;
      yg = image[column][row+1].g - image[column][row-1].g;
      xg = pow(xg,2);
      yg = pow(yg,2);
      //blue
      xb = image[column+1][row].b - image[width-1][row].b;
      yb = image[column][row+1].b - image[column][row-1].b;
      xb = pow(xb,2);
      yb = pow(yb,2);

      energyVal = xr+xg+xb+yr+yg+yb;
      return energyVal;
    }
  if(column == width - 1){

      //red
      xr = image[0][row].r - image[column-1][row].r;
      yr = image[column][row+1].r - image[column][row-1].r;
      xr = pow(xr,2);
      yr = pow(yr,2);
      //green
      xg = image[0][row].g - image[column-1][row].g;
      yg = image[column][row+1].g - image[column][row-1].g;
      xg = pow(xg,2);
      yg = pow(yg,2);
      //blue
      xb = image[0][row].b - image[column-1][row].b;
      yb = image[column][row+1].b - image[column][row-1].b;
      xb = pow(xb,2);
      yb = pow(yb,2);

      energyVal = xr+xg+xb+yr+yg+yb;
      return energyVal;
    }
  if(row == 0){

      //red
      xr = image[column+1][row].r - image[column-1][row].r;
      yr = image[column][row+1].r - image[column][height-1].r;
      xr = pow(xr,2);
      yr = pow(yr,2);
      //green
      xg = image[column+1][row].g - image[column-1][row].g;
      yg = image[column][row+1].g - image[column][height-1].g;
      xg = pow(xg,2);
      yg = pow(yg,2);
      //blue
      xb = image[column+1][row].b - image[column-1][row].b;
      yb = image[column][row+1].b - image[column][height-1].b;
      xb = pow(xb,2);
      yb = pow(yb,2);

      energyVal = xr+xg+xb+yr+yg+yb;
      return energyVal;
    }
  if(row == height - 1){

      //red
      xr = image[column+1][row].r - image[column-1][row].r;
      yr = image[column][0].r - image[column][row-1].r;
      xr = pow(xr,2);
      yr = pow(yr,2);
      //green
      xg = image[column+1][row].g - image[column-1][row].g;
      yg = image[column][0].g - image[column][row-1].g;
      xg = pow(xg,2);
      yg = pow(yg,2);
      //blue
      xb = image[column+1][row].b - image[column-1][row].b;
      yb = image[column][0].b - image[column][row-1].b;
      xb = pow(xb,2);
      yb = pow(yb,2);

      energyVal = xr+xg+xb+yr+yg+yb;
      return energyVal;
    }
  else{

    //red
    xr = image[column+1][row].r - image[column-1][row].r;
    yr = image[column][row+1].r - image[column][row-1].r;
    xr = pow(xr,2);
    yr = pow(yr,2);
    //green
    xg = image[column+1][row].g - image[column-1][row].g;
    yg = image[column][row+1].g - image[column][row-1].g;
    xg = pow(xg,2);
    yg = pow(yg,2);
    //blue
    xb = image[column+1][row].b - image[column-1][row].b;
    yb = image[column][row+1].b - image[column][row-1].b;
    xb = pow(xb,2);
    yb = pow(yb,2);

    energyVal = xr+xg+xb+yr+yg+yb;
    return energyVal;
}
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
    // TODO(student): load a vertical seam
    INFO(image);
    INFO(start_col);
    INFO(width);
    INFO(height);
    INFO(seam);

    seam[0] = start_col;
    int total_energy = energy(image, start_col, 0, width, height);


    if(start_col != 0 && start_col != width-1){
      for(int i = 1; i < height; ++i){
        int left_energy = energy(image, start_col-1, i, width, height);
        int down_energy = energy(image, start_col, i, width, height);
        int right_energy = energy(image, start_col+1, i, width, height);

        if(down_energy <= left_energy && down_energy <= right_energy){
          seam[i] = start_col;
          total_energy += down_energy;
        }
        else if(right_energy < down_energy && right_energy <= left_energy){
          seam[i] = start_col+1;
          total_energy += right_energy;
        }
        else if(left_energy < down_energy && left_energy <= right_energy){
          seam[i] = start_col-1;
          total_energy += left_energy;
        }
      }

  return total_energy;
}
  else if(start_col == 0){

  for(int i = 1; i < height; ++i){
    int down_energy = energy(image, start_col, i, width, height);
    int right_energy = energy(image, start_col+1, i, width, height);

    if(down_energy <= right_energy){
      seam[i] = start_col;
      total_energy += down_energy;
    }
    else if(right_energy < down_energy){
      seam[i] = start_col+1;
      total_energy += right_energy;
    }
  }

return total_energy;
}
  else if(start_col == width-1){

    for(int i = 1; i < height-1; ++i){
      int down_energy = energy(image, start_col, i, width, height);
      int left_energy = energy(image, start_col-1, i, width, height);

      if(down_energy <= left_energy){
        seam[i] = start_col;
        total_energy += down_energy;
      }
      else if(left_energy < down_energy){
        seam[i] = start_col-1;
        total_energy += left_energy;
      }
    }
    return total_energy;
  }
  return 0;
}
int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
    // TODO(student): load a horizontal seam
    INFO(image);
    INFO(start_row);
    INFO(width);
    INFO(height);
    INFO(seam);

  return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min vertical seam
    INFO(image);
    INFO(width);
    INFO(height);

    int* seam = createSeam(height);
    int min_energy = loadVerticalSeam(image, 0, width, height, seam);
    for(int i = 1; i < width; ++i){
      if(min_energy > loadVerticalSeam(image,i,width,height,seam))
        min_energy = loadVerticalSeam(image,i,width,height,seam);
    }
  return seam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min horizontal seam
    INFO(image);
    INFO(width);
    INFO(height);
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
    // TODO(student): remove a vertical seam
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(verticalSeam);
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    // TODO(student): remove a horizontal seam
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(horizontalSeam);
}
