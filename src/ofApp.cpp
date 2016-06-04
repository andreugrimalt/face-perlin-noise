/* Find faces in perlin noise. Create noisy images using perlin noise and apply a Haar cascade to find faces. Once a face is found, then print it at the side of the screen.
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup Haar finder
	finder.setup("haarcascade_frontalface_alt2.xml");
	// Do not refresh the background
    ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    // Allocate memory for an image (noisy image)
    img.allocate(200, 200, OF_IMAGE_GRAYSCALE);
    
    gui.setup();
    gui.setPosition(0, 230);
    gui.add(noiseSize.setup("noise size",0.05,0.0001,0.2));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Set pixels randomly (Perlin noise)
    img.setColor(ofColor::white);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            float n1 = i * noiseSize;
            float n2 = j * noiseSize;
            float n3 =ofGetFrameNum() / 30.0;
            // scale to 255
            float noise = ofNoise(n1,n2,n3) * 255;
            ofColor color= ofColor(noise);
            img.setColor(i % w, j % h, color);
        }
    }
    // update image
    img.update();
    
    // Try to find faces with the Haar cascade
    finder.findHaarObjects(img);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    // Draw the perlin noise image
    img.draw(0,0);
    
    // If we find a face, then draw it at the side of the screen
	for(unsigned int i = 0; i < finder.blobs.size(); i++) {
        // draw a rectangle around the face
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);
        
        // Draw the found face at the side of the screen
        img.drawSubsection((lastWidth%780)+220, faceH, cur.width, cur.height, cur.x, cur.y);
        // Wrap the found faces from left to right, top to bottom
        lastX=cur.x;
        lastY=cur.y;
        lastWidth+=cur.width+2;
        lastHeight=cur.height;
        if(cur.height>faceHighest){
            faceHighest=cur.height;
        }
        faceH=faceHighest*(int)(lastWidth/780);
        cout<<"face found"<<"\n";
	}

    gui.draw();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
