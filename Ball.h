#pragma once
#ifndef BallClass_h
#define BallClass_h

#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofMain.h"


class Ball
{
public:
    Ball();
    ~Ball();
    void Setup(int x, int y, int size, ofxCvGrayscaleImage grayImg);
    void Move();
    bool Bounce();
    bool Bouncer();
    void Draw();
    void setImage(ofxCvGrayscaleImage grayImg);
    
    ofColor _color;
    int _x;
    int _y;
    int px;
    int py;
    int px2;
    int py2;
    int px3;
    int py3;
    int _size;
    int speedX = 3;
    int speedY = 3;
    ofxCvGrayscaleImage _grayImg;
    ofPixels pix;
     
};



#endif /* BallClass_h */