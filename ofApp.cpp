#include "ofApp.h"
#include "ofxOpenCv.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image1.load("tester.jpg");
	image1.resize(600, 600);


    panel1.setup();
    panel1.add(knap.setup("DIALATE"));
    panel1.add(reset.setup("RESET"));
    panel1.add(erode.setup("ERODE"));

    image2.setFromPixels(image1.getPixels());
	image2.resize(600, 600);
    grayImg = image2;
	grayImg.resize(600, 600);
    grayImg.threshold(150);
    myball =new Ball*[5];

	//play.addListener(this, &ofApp::playPressed);
	//stop.addListener(this, &ofApp::stopPressed);
/*
	gui.setup();
	gui.add(play.setup("play"));
	gui.add(stop.setup("stop"));
	gui.add(volume.setup("volume", 1.0, 0.0, 1.0));
	gui.add(speed.setup("speed", 1.0, 0.0, 1.0));

	*/
	//video.loadMovie("Shake.avi");
    myball[1]= new Ball(500,300,10,grayImg);

}

//--------------------------------------------------------------
void ofApp::update(){
    
	//video.update();

    if(knap){
        grayImg.dilate_3x3();
    }
    if(reset){
        image2.setFromPixels(image1.getPixels());
        grayImg = image2;
        grayImg.threshold(150);
    }
    
    if(erode){
        grayImg.erode_3x3();
    }
  cf.findContours(grayImg, 1000, 100000, 50, false);
   
    myball[1]->Bounce();
    myball[1]->Move();
    
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
	image1.draw(0, 0, 600, 600);
  grayImg.draw(600,0,600,600);

  panel1.draw();

  //gui.draw();
  /*video.draw(200, 200, 300, 300);
  video.setVolume(volume);
  video.setSpeed(speed);
  */
 cf.draw(0,0,600, 600);

    myball[1]->Draw();
  

}

void ofApp::playPressed() {
	//video.play();
}
/*grayImg.draw(0,0,600,600);
    cf.draw(0,0,600,600);
    
   panel1.draw();*/

void ofApp::stopPressed() {
	//video.stop();
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
