#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(0, 0, 0);
  ofSetFrameRate(30);

  cameraWidth = 640;
  cameraHeight = 480;
  
  videoGrabber.setVerbose(true);
  videoGrabber.initGrabber(cameraWidth, cameraHeight);
}

//--------------------------------------------------------------
void testApp::update(){
  videoGrabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
//  videoGrabber.draw(0,0);

  ofPixelsRef pixelsRef = videoGrabber.getPixelsRef();
  unsigned char * pixels = videoGrabber.getPixels();

  for (int i = 0; i < cameraHeight; i += 10) {
    for (int j = 0; j < cameraWidth; j += 10) {
      ofColor pixelColor = pixelsRef.getColor(j, i);
      ofSetColor(pixelColor);
      ofPath path = ofPath();
      path.setColor(pixelColor);
      path.setFillColor(pixelColor);
      path.moveTo(j, i);
      path.lineTo(j + 10, i);
      path.lineTo(j + 10, i + 10);
      path.lineTo(j, i + 10);
      path.close();
      path.draw();
      
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