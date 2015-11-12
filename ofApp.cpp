#include "ofApp.h"
#include "ofxOpenCv.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image1.load("Stage.jpg");

    panel1.setup();
    panel1.add(knap.setup("DIALATE"));
    panel1.add(reset.setup("RESET"));
    panel1.add(erode.setup("ERODE"));

    image2.setFromPixels(image1.getPixels());
    grayImg = image2;
    grayImg.threshold(100);

	play.addListener(this, &ofApp::playPressed);
	stop.addListener(this, &ofApp::stopPressed);

	gui.setup();
	gui.add(play.setup("play"));
	gui.add(stop.setup("stop"));
	gui.add(volume.setup("volume", 1.0, 0.0, 1.0));
	gui.add(speed.setup("speed", 1.0, 0.0, 1.0));


	video.loadMovie("Shake.avi");

}

//--------------------------------------------------------------
void ofApp::update(){
    
	video.update();

    if(knap){
        grayImg.dilate_3x3();
    }
    if(reset){
        image2.setFromPixels(image1.getPixels());
        grayImg = image2;
<<<<<<< HEAD
        grayImg.threshold(100);
=======
        grayImg.threshold(200);
>>>>>>> origin/master
    }
    
    if(erode){
        grayImg.erode_3x3();
    }
  cf.findContours(grayImg, 20, (320*240)/3, 10, true);
   
 
}

//--------------------------------------------------------------
void ofApp::draw(){

<<<<<<< HEAD
  grayImg.draw(0,0,600,600);

  panel1.draw();

  gui.draw();
  video.draw(200, 200, 300, 300);
  video.setVolume(volume);
  video.setSpeed(speed);

  //contourFinder.blobs[1].draw(700, 700);


  

}

void ofApp::playPressed() {
	video.play();
}
=======
grayImg.draw(0,0,600,600);
    cf.draw(0,0,600,600);
    
   panel1.draw();
>>>>>>> origin/master

void ofApp::stopPressed() {
	video.stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
 

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
