//
//  dot.h
//  movementVideo
//
//  Created by Hamish Rickerby on 26/05/13.
//
//

#ifndef __movementVideo__dot__
#define __movementVideo__dot__

#include <iostream>
#include "ofMain.h"

class Dot {
private:
  float minRadius, maxRadius, currentRadius;
  int movementDifference;
  float decayStep;
  int x, y;
  ofColor lastColor;
  
  bool similarColours(ofColor color1, ofColor color2);
  
public:
  Dot(int xPos, int yPos);
  
  void draw();
  void update();
  
  ofColor sampledColor;

};

#endif /* defined(__movementVideo__dot__) */
