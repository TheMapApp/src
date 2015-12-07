#include "Ball.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"



Ball::Ball()
{
    
    
    
}


void Ball::Setup(int x, int y, int size,int point, ofxCvGrayscaleImage grayImg, int r, int g ,int b, int speed) {
  
    
    
    _x =x;
    _y =y;
    px=x;
    py=y;
    _size = size;
    _grayImg = grayImg;
    _color = ofColor(r, g, b);
    _point = point;
    _speed = speed;
    speedX = _speed;
    speedY = _speed;

    
    
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


void Ball::Draw(float sizem){
    int size = sizem+_size;
    
    ofSetColor(_color);
    
    if(_point == 2){
    ofDrawCircle(_x, _y, size);
    } else if(_point == 3){
        ofDrawTriangle(_x+size, _y+size, _x-size, _y+size, _x, _y-size);
        
    }else if(_point==4){
        ofDrawRectangle(_x-(size/2), _y-(size/2), size, size);
    }else if(_point==5){
    
        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
        ofBeginShape();
        
        ofVertex((_x + size * cos(1 * 2 * PI / 5)), (_y + size * sin(1 * 2 * PI / 5)));
        ofVertex((_x + size * cos(2 * 2 * PI / 5)), (_y + size * sin(2 * 2 * PI / 5)));
        ofVertex((_x + size * cos(3 * 2 * PI / 5)), (_y + size * sin(3 * 2 * PI / 5)));
        ofVertex((_x + size * cos(4 * 2 * PI / 5)), (_y + size * sin(4 * 2 * PI / 5)));
        ofVertex((_x + size * cos(5 * 2 * PI / 5)), (_y + size * sin(5 * 2 * PI / 5)));
      
        ofEndShape();
        
    }else if(_point==6){
        
        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
        ofBeginShape();
        ofVertex((_x + size * cos(1 * 2 * PI / 6)), (_y + size * sin(1 * 2 * PI / 6)));
        ofVertex((_x + size * cos(2 * 2 * PI / 6)), (_y + size * sin(2 * 2 * PI / 6)));
        ofVertex((_x + size * cos(3 * 2 * PI / 6)), (_y + size * sin(3 * 2 * PI / 6)));
        ofVertex((_x + size * cos(4 * 2 * PI / 6)), (_y + size * sin(4 * 2 * PI / 6)));
        ofVertex((_x + size * cos(5 * 2 * PI / 6)), (_y + size * sin(5 * 2 * PI / 6)));
        ofVertex((_x + size * cos(6 * 2 * PI / 6)), (_y + size * sin(6 * 2 * PI / 6)));
        ofEndShape();
        
    }else if(_point==7){
        
        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
        ofBeginShape();
        ofVertex((_x + size * cos(1 * 2 * PI / 7)), (_y + size * sin(1 * 2 * PI / 7)));
        ofVertex((_x + size * cos(2 * 2 * PI / 7)), (_y + size * sin(2 * 2 * PI / 7)));
        ofVertex((_x + size * cos(3 * 2 * PI / 7)), (_y + size * sin(3 * 2 * PI / 7)));
        ofVertex((_x + size * cos(4 * 2 * PI / 7)), (_y + size * sin(4 * 2 * PI / 7)));
        ofVertex((_x + size * cos(5 * 2 * PI / 7)), (_y + size * sin(5 * 2 * PI / 7)));
        ofVertex((_x + size * cos(6 * 2 * PI / 7)), (_y + size * sin(6 * 2 * PI / 7)));
         ofVertex((_x + size * cos(7 * 2 * PI / 7)), (_y + size * sin(7 * 2 * PI / 7)));
        ofEndShape();
        
    }else if(_point==8){
        
        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
        ofBeginShape();
        ofVertex((_x + size * cos(1 * 2 * PI / 8)), (_y + size * sin(1 * 2 * PI / 8)));
        ofVertex((_x + size * cos(2 * 2 * PI / 8)), (_y + size * sin(2 * 2 * PI / 8)));
        ofVertex((_x + size * cos(3 * 2 * PI / 8)), (_y + size * sin(3 * 2 * PI / 8)));
        ofVertex((_x + size * cos(4 * 2 * PI / 8)), (_y + size * sin(4 * 2 * PI / 8)));
        ofVertex((_x + size * cos(5 * 2 * PI / 8)), (_y + size * sin(5 * 2 * PI / 8)));
        ofVertex((_x + size * cos(6 * 2 * PI / 8)), (_y + size * sin(6 * 2 * PI / 8)));
        ofVertex((_x + size * cos(7 * 2 * PI / 8)), (_y + size * sin(7 * 2 * PI / 8)));
        ofVertex((_x + size * cos(8 * 2 * PI / 8)), (_y + size * sin(8 * 2 * PI / 8)));
        ofEndShape();
        
    }
    
}

Ball::~Ball()
{
};