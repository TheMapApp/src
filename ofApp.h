#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void playPressed();
		void stopPressed();

		ofxButton play;
		ofxButton stop;
		ofxFloatSlider volume;
		ofxFloatSlider speed;

		ofVideoPlayer video;




		ofImage image;


   
    
    ofxPanel panel1;
	ofxPanel gui;
    
    
    ofxButton knap;
    ofxButton erode;
    ofxButton reset;
    ofImage image1;
    ofxCvColorImage image2;
    ofxCvGrayscaleImage	grayImg;
    ofxCvContourFinder contourFinder;
    ofxCvBlob blob;

    ofxCvContourFinder cf;

};
