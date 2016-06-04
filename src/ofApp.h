#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "ofxGui.h"
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
    
        // image for generating faces
		ofImage img;
        // Haar cascade
		ofxCvHaarFinder finder;
        // image to store the found faces
        ofImage face;
        // last postion of found face
        int lastX=0;
        int lastY=0;
        // last width/height of found face
        int lastWidth=0;
        int lastHeight=0;
        // Height at wich to draw the found face
        int faceH=0;
        // Highest face height found
        int faceHighest;
        // width/height
        int w=200;
        int h=200;
    
        // GUI
        ofxFloatSlider noiseSize;
        ofxPanel gui;
    
    
};
