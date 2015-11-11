#include "ofApp.h"
#include "ofxOpenCv.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image1.load("scene.jpg");
    panel1.setup();
    panel1.add(knap.setup("DIALATE"));
     panel1.add(reset.setup("RESET"));
    panel1.add(erode.setup("ERODE"));
    image2.setFromPixels(image1.getPixels());
    grayImg = image2;
    grayImg.threshold(200);
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(knap){
        grayImg.dilate_3x3();
    }
    if(reset){
        image2.setFromPixels(image1.getPixels());
         grayImg = image2;
        grayImg.threshold(200);
    }
    
    if(erode){
        grayImg.erode_3x3();
    }
   
 
}

//--------------------------------------------------------------
void ofApp::draw(){

grayImg.draw(0,0,600,600);
    
   panel1.draw();

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
