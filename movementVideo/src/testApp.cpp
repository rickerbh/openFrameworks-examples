#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(0, 0, 0);
  ofEnableAlphaBlending();
  ofEnableSmoothing();
  ofSetFrameRate(60);

  cameraWidth = 640;
  cameraHeight = 480;
  dotGaps = 10;

  dots.reserve((cameraWidth / dotGaps) * (cameraHeight / dotGaps));
  int count = 0;
  for (int i = 0; i < cameraHeight; i += dotGaps) {
    for (int j = 0; j < cameraWidth; j += dotGaps) {
      dots[count] = Dot(j, i);
      count++;
    }
  }

  videoGrabber.setVerbose(true);
  videoGrabber.initGrabber(cameraWidth, cameraHeight);
}

//--------------------------------------------------------------
void testApp::update(){
  videoGrabber.update();
  ofPixelsRef pixelsRef = videoGrabber.getPixelsRef();
  
  int count = 0;
  for (int i = 0; i < cameraHeight; i += dotGaps) {
    for (int j = 0; j < cameraWidth; j += dotGaps) {
      ofColor pixelColor = pixelsRef.getColor(j, i);
      dots[count].sampledColor = pixelColor;
      dots[count].update();
      count++;
    }
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  int count = 0;
  for (int i = 0; i < cameraHeight; i += dotGaps) {
    for (int j = 0; j < cameraWidth; j += dotGaps) {
      dots[count].draw();
      count++;
    }
  }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  if (key == 's') {
    ofSaveFrame();
  }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
