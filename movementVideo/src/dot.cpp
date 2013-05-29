//
//  dot.cpp
//  movementVideo
//
//  Created by Hamish Rickerby on 26/05/13.
//
//

#include "dot.h"

Dot::Dot(int xPos, int yPos) {
  x = xPos;
  y = yPos;
  decayStep = 0.25;
  minRadius = 4;
  maxRadius = 8;
  movementDifference = 40;
  currentRadius = minRadius;
  lastColor = ofColor(0, 0, 0);
  sampledColor = ofColor(0, 0, 0);
}

void Dot::update() {
  if (similarColours(sampledColor, lastColor)) {
    if (currentRadius > minRadius) {
      currentRadius -= decayStep;
    }
  } else {
    currentRadius = maxRadius;
  }
  lastColor = sampledColor;
}

void Dot::draw() {
  ofSetColor(sampledColor);
  ofCircle(x, y, currentRadius);
}

bool Dot::similarColours(ofColor color1, ofColor color2) {
  int r1 = color1.r;
  int g1 = color1.g;
  int b1 = color1.b;
  int r2 = color2.r;
  int g2 = color2.g;
  int b2 = color2.b;
  
  if (abs(r1 - r2) < movementDifference &&
      abs(g1 - g2) < movementDifference &&
      abs(b1 - b2) < movementDifference) {
    return true;
  }
  
  return false;
}
