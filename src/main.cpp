#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2);
    settings.setSize(1000, 1000);
    ofCreateWindow(settings);
    ofRunApp( new ofApp());

}
