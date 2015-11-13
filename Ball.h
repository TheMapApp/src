#pragma once
#ifndef BallClass_h
#define BallClass_h

#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofMain.h"


class Ball
{
public:
    Ball(int x, int y, int size, ofxCvGrayscaleImage grayImg);
    ~Ball();
    void Move();
    bool Bounce();
    void Draw();
    
    int _x;
    int _y;
    int px;
    int py;
    int px2;
    int py2;
    int px3;
    int py3;
    int _size;
    int speedX = 10;
    int speedY = 10;
    ofxCvGrayscaleImage _grayImg;
    ofPixels pix;
};



#endif /* BallClass_h */