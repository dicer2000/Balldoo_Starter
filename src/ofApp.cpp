#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    srand(time(NULL));

    ofSetBackgroundColor(0, 0, 0);
    ImpactType = NONE;
    
    // Build all the balls in memory with random:
    // - x/y positions
    // - speeds
    // - colors
    for(int i = 0; i < BALL_COUNT; i++)
    {
        ofColor c(rand()%255, rand()%255, rand()%255);
        int initX = rand() % ofGetWindowWidth();
        int initY = rand() % ofGetWindowHeight();
        int initXVol = rand() % 10 - 5;
        int initYVol = rand() % 10 - 5;
        ball b(initX, initY, initXVol, initYVol, c);
        balls.push_back(b);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Update the position of each
    for(int i = 0; i < BALL_COUNT; i++)
    {
        // Check impact with the walls
        // Right Wall
        if(balls[i].x+BALL_SIZE > ofGetWindowWidth())
        {
            balls[i].xVol = -balls[i].xVol; // Change direction
            balls[i].x -= (ofGetWindowWidth()-balls[i].x);  // Don't let it run off the screen
        }
        // Left Wall
        if(balls[i].x < 0)
        {
            balls[i].xVol = -balls[i].xVol; // Change direction
            balls[i].x += (0-balls[i].x);  // Don't let it run off the screen
        }
        // Bottom Wall
        if(balls[i].y+BALL_SIZE > ofGetWindowHeight())
        {
            balls[i].yVol = -balls[i].yVol; // Change direction
            balls[i].y -= (ofGetWindowHeight()-balls[i].y);  // Don't let it run off the screen
        }
        // Top Wall
        if(balls[i].y < 0)
        {
            balls[i].yVol = -balls[i].yVol; // Change direction
            balls[i].y += (0-balls[i].y);  // Don't let it run off the screen
        }
        //*************************************************
        // Check ball impact with each other here!!!
        switch(ImpactType)
        {
            case ALL:
                
                
                break;
                
            case HASHED:
                
                
                break;
            case NONE:
                break;
        }
        //*************************************************
        
        // Finally, set the new position of each ball
        balls[i].x += balls[i].xVol;
        balls[i].y += balls[i].yVol;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Draw the framerate & impact type
    ofSetColor(255);
    string strImpact;
    switch(ImpactType)
    {
        case ALL:
            strImpact = "ALL";
            break;
        case HASHED:
            strImpact = "HASHED";
            break;
        case NONE:
            strImpact = "NONE";
            break;
    }
    string message = strImpact + " fps: " + ofToString(ofGetFrameRate());
    ofDrawBitmapString(message, 10, 20);
    
    // Draw all the balls
    for(int i = 0; i < BALL_COUNT; i++)
    {
        ofSetColor(balls[i].color);
        ofDrawCircle(balls[i].x, balls[i].y, BALL_SIZE);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    // Toggle the space bar to change the impact analysis type
    if(key == ' ')
    {
        switch(ImpactType)
        {
            case NONE:
                ImpactType = ALL;
                break;
            case ALL:
                ImpactType = HASHED;
                break;
            case HASHED:
                ImpactType = NONE;
                break;
        }
    }
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
