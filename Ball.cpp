#include "Ball.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"



Ball::Ball()
{
    
    
    
}

void Ball::Setup(int x, int y, int size, ofxCvGrayscaleImage grayImg) {
  
    
    
    _x =x;
    _y =y;
    px=x;
    py=y;
    _size = size;
    _grayImg = grayImg;
    _color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

    
    
}
void Ball::setImage(ofxCvGrayscaleImage grayImg) {
    
    _grayImg = grayImg;
    
}




void Ball::Move() {
    ofLog(OF_LOG_NOTICE, "moved");

    
    
    _x = _x + speedX;
    _y = _y + speedY;
    Bounce();
    
    
}

bool Ball::Bounce() {
    
    pix =_grayImg.getPixels();
    
    
    
    if(pix.getColor(_x, _y)!= pix.getColor(px, py)){
    
         
         int k =0;
         k= ofRandom(1, 4);
         
         if(k<2 && pix.getColor(_x-speedX, _y-speedY)!= pix.getColor(_x, _y)){
             
             speedX *= -1;
             speedY *= -1;
             return true;
         }else if(k<3 && pix.getColor(_x, _y-speedY) != pix.getColor(_x, _y)){
             
             speedX *= 1;
             speedY *= -1;
             return true;
         }else if(k<4 && pix.getColor(_x-speedX, _y) != pix.getColor(_x, _y)){
             
             speedX *= -1;
             speedY *= 1;
             return true;
         }else{
             
             Bounce();
         }
 
        
       
    
    }
    
}
bool Ball::Bouncer() {
    
}


void Ball::Draw(){
    
    ofSetColor(_color);
    ofDrawCircle(_x, _y, _size);
    
}

Ball::~Ball()
{
};