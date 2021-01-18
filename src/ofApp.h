#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void reset();
        void keyPressed(int key);
    ofColor readBackground(float x, float y);

    ofShader shader;
    ofImage myImage;
    
    //ofxDatGui
    ofxDatGui* gui;
    int borderWidth;
    ofColor borderColor, color0, color1, color2, color3;
    ofPoint point0, point1, point2, point3;
    int s;
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onSliderEvent(ofxDatGuiSliderEvent e);
    void on2dPadEvent(ofxDatGui2dPadEvent e);
    void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
    void onMatrixEvent(ofxDatGuiMatrixEvent e);
    bool bHide;
};
