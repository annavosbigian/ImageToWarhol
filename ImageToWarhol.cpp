#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageToWarhol.h"

using uiuc::PNG;
using uiuc::HSLAPixel;

/*transforms an image into Warhol-like popart by standardizing
  the colors and emphasizing highlights & shadows*/

PNG warholEffect(PNG image, string faceColor){
    //check how much to change each pixel 
    int colorChange = findDegreeOfHueChange(faceColor);
    for (unsigned x = 0; x < image.width(); x++){
        for (unsigned y = 0; y < image.height(); y++){
            HSLAPixel & pixel = image.getPixel(x, y);
	    //if very dark or very light, make black/white
            if (pixel.l > 0.8){
                pixel.l = 1;
            }
            else if (pixel.l < 0.15){
                pixel.l = 0;
            }
            //check which hue range the pixel falls under, then standardize
            else {
              if (pixel.h >=  270 || pixel.h < 10){
                pixel.h = 355;
                pixel.s = 0.8;
                pixel.l = 0.5;
              }
              else if (pixel.h >=10 && pixel.h < 25){
                pixel.h = 0;
                pixel.s = 0.4;
                pixel.l = 0.8;
              }
              else if (pixel.h >= 25 && pixel.h < 50){
                pixel.h = 45;
                pixel.s = 0.9;
                pixel.l = 0.5;
              }
              else if (pixel.h >= 50 && pixel.h < 70){
                pixel.h = 55;
                pixel.s = 1;
                pixel.l = 0.5;
              }
              else if (pixel.h >= 70 && pixel.h < 200){
                pixel.h = 115;
                pixel.s = 0.9;
                pixel.l = 0.3;
              }
              else {
                pixel.h = 240;
                pixel.s = 1;
                pixel.l = 0.5;
              }
              pixel.h += colorChange;
              if (pixel.h > 360){
                pixel.h -= 360;
              }
            }
        }
    }
    return image;
}

int findDegreeOfHueChange(string color){
  if (color.compare("green") == 0){
    return 115;
  }
  if (color.compare("pink") == 0){
    return 330;
  }
  if (color.compare("blue") == 0){
    return 240;
  }
  if (color.compare("red") == 0){
    return 350;
  }
  if (color.compare("orange") == 0){
    return 45;
  }
  if (color.compare("yellow") == 0){
    return 60;
  }
  return 0;
}

 
 


