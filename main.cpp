/**
 *A C++ program that reads a PNG image and turns it into Warhol-like popart, with the color 
 *tint determined by user input
**/

#include "ImageToWarhol.h"
#include "uiuc/PNG.h"

int main(int argc, char** argv) {
  uiuc::PNG png, result;

  cout << "Enter the file path of a png image you wish to change"  <<"\n";
  
  string photoPath;
  
  cin >> photoPath;
  
  cout << "\n";
  
  string color;

  png.readFromFile(photoPath);
    cout << "What color would you like to change the face to? \nEnter green, blue, pink, red, yellow, orange or none \n";
    
  cin >> color;
  
  result = warholEffect(png, color);
  
  result.writeToFile(color +  "_warhol_" + photoPath );
  
  return 0;
}
