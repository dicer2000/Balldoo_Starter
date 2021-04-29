#pragma once

#include "ofMain.h"

const int BALL_COUNT = 200;
const int BALL_SIZE = 6;

enum impactType { NONE, ALL, HASHED };

class ball {
public:
    ofColor color;
    int x = 0;
    int y = 0;
    int xVol = 0;
    int yVol = 0;

    ball(int xInit, int yInit, int xVolInit, int yVolInit, ofColor colorInit)
    {
        x = xInit;
        y = yInit;
        xVol = xVolInit;
        yVol = yVolInit;
        color = colorInit;
    }
};


class ofApp : public ofBaseApp{
private:
    vector<ball> balls;
    impactType ImpactType = NONE;
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
		
};
