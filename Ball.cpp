#include "Ball.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"



Ball::Ball(int x, int y, int size, ofxCvGrayscaleImage grayImg)
{
    _x =x;
    _y =y;
    _size = size;
    _grayImg = grayImg;
    
}

void Ball::Move() {
    
    px3=px2;
    py3=py2;
    px2=px;
    py2=py;
    px=_x;
    py=_y;
    _x = _x + speedX;
    _y = _y + speedY;
    
    
}

bool Ball::Bounce() {
    
    pix =_grayImg.getPixels();
     
     if (pix.getColor(_x, _y) != pix.getColor(px, py)&&pix.getColor(_x, _y) != pix.getColor(px2, py2)&& pix.getColor(_x, _y) != pix.getColor(px3, py3)) {
     speedX *= ofRandom(-0.5, -1);
     speedY *= ofRandom(-0.5, -1);
     }
    if(speedX==0){
        speedX=10;
        
    }
    if(speedY==0){
        speedY=10;
        
    }
}
void Ball::Draw(){
    
    ofSetColor(255, 0, 0);
    ofDrawCircle(_x, _y, _size);
    
}

Ball::~Ball()
{
};