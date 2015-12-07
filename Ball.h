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
    void Setup(int x, int y, int size,int point, ofxCvGrayscaleImage grayImg, int r, int g, int b, int speed);
    void Move();
    bool Bounce();
    bool Bouncer();
    void Draw(float sizem);
    void setImage(ofxCvGrayscaleImage grayImg);
    
    ofColor _color;
    int * shapex;
    int * shapey;
    int r;
    int g;
    int b;
    int _x;
    int _point;
    int _y;
    int px;
    int py;
    int px2;
    int py2;
    int px3;
    int py3;
    int _speed;
    int _size;
    int speedX;
    int speedY;
    ofxCvGrayscaleImage _grayImg;
    ofPixels pix;
     
};



#endif /* BallClass_h */