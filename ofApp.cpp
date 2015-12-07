#include "ofApp.h"
#include "ofxOpenCv.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image1.load("scene.jpg");
	image1.resize(600,600);
    ofBackground(0, 0, 0);
    ofSetFrameRate(50);
    
    beat.load("carolinian.mp3");
    
    
    fftsmooth = new float [8192];
    for(int i =0; i< 8192; i++){
    fftsmooth[i] =0;
    }
    bands = 16;
    beat.setLoop(true);
    beat.setVolume(0.2);
    beat.play();


    panel1.setup();
     panel2.setup();
    panel2.ofxBaseGui::setPosition(300, 300);
    panel1.add(thresholdslider.setup("threshold",150,0,300));
     panel1.add(thresholdslider2.setup("threshold2",150,0,300));
    panel1.add(knap.setup("DIALATE"));
    panel1.add(reset.setup("RESET"));
    panel1.add(erode.setup("ERODE"));
      panel1.add(tog1.setup("DRaw",true));
    
     panel2.add(tog2.setup("ACTIVE",false));
    panel2.add(tog.setup("ADD",true));
  
    panel2.add(pointslider.setup("points",2,2,8));
    panel2.add(rslider.setup("RED",100,0,255));
    panel2.add(gslider.setup("GREEN",100,0,255));
    panel2.add(bslider.setup("BLUE",100,0,255));
    panel2.add(sizeslider.setup("SIZE",15,0,40));
       panel2.add(speedslider.setup("SPEED",3,0,6));

    

    image2.setFromPixels(image1.getPixels());
    grayImg = image2;

  

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    float * value = ofSoundGetSpectrum(bands);
    for(int i =0;i<bands;i++){
        fftsmooth[i] *=0.95f;
        if(fftsmooth[i] < value[i]){
            fftsmooth[i] = value[i];
        }

    }
   

   
    if(knap){
        grayImg.dilate();
    }
    
    if(reset){
        image2.setFromPixels(image1.getPixels());
        grayImg = image2;
              cvCanny(grayImg.getCvImage(), grayImg.getCvImage(), 150, 150,3);

    }
    
    if(erode){
        grayImg.erode_3x3();
    }


   
    for (int i = 0; i<myBall.size(); i++) {
        myBall[i].Move();
        
       
    }
    
    if(thresholdslider!=tmpthresholdslider){
    image2.setFromPixels(image1.getPixels());
    grayImg = image2;
        cvCanny(grayImg.getCvImage(), grayImg.getCvImage(), thresholdslider2, thresholdslider,3);
}
    tmpthresholdslider=thresholdslider;
    
    
    if(thresholdslider2!=tmpthresholdslider2){
        image2.setFromPixels(image1.getPixels());
        grayImg = image2;
        cvCanny(grayImg.getCvImage(), grayImg.getCvImage(), thresholdslider2, thresholdslider,3);
    }
    tmpthresholdslider2=thresholdslider2;
    
    
    

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
  
    ofSetColor(255, 255, 255);
	//image2.draw(0, 0, 600, 600);
    
    if(tog1){
  grayImg.draw(0,0);
    }

  panel1.draw();
    panel2.draw();

   
    for (int i = 0; i<myBall.size(); i++) {
        for(int j=0; j< bands ; j++){
        myBall[i].Draw((fftsmooth[j]*20));
        }
    }


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
    
    if(tog2==true){
    
    if(tog == true){
    Ball tempBall;
        tempBall.Setup(x,y,sizeslider,pointslider,grayImg,rslider,gslider,bslider,speedslider);
        tempBall.setImage(grayImg);
    myBall.push_back(tempBall);
    
    }else{
        myBall.erase(myBall.begin());
        
    }
    }
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
