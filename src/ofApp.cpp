#include "ofApp.h"

void ofApp::setup()
{
    shader.load("shaders/shader");
    
// setup the gui //
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    gui->setTheme(new ofxDatGuiThemeWireframe());
    gui->addHeader("PARAMETER");
    gui->addColorPicker("BORDER COLOR");
    gui->addSlider("BORDER WIDTH", 0, 200);
    gui->addColorPicker("COLOR0");
    gui->add2dPad("POINT0");
    gui->addColorPicker("COLOR1");
    gui->add2dPad("POINT1");
    gui->addColorPicker("COLOR2");
    gui->add2dPad("POINT2");
    gui->addColorPicker("COLOR3");
    gui->add2dPad("POINT3");
    vector<string> options = {"one", "two", "three", "four"};
    //gui->addDropdown("COLOR PETTERN", options);
    gui->addMatrix("COLOR PATTERN", 7, true);
    gui->addButton("RESET");
    //gui->addFooter();
    
// and register callbacks to listen for events //
    gui->onButtonEvent(this, &ofApp::onButtonEvent);
    gui->onSliderEvent(this, &ofApp::onSliderEvent);
    gui->on2dPadEvent(this, &ofApp::on2dPadEvent);
    gui->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
    gui->onMatrixEvent(this, &ofApp::onMatrixEvent);
    gui->setOpacity(.1);
    
// setup the default gui settings //
    reset();
    
    bHide = true;
}
//--------------------------------------------------------------
void ofApp::reset()
{
    borderColor = ofColor(177, 237, 229);
    borderWidth = 120;
    color0 = ofColor(57, 255, 59);
    color1 = ofColor(255, 255, 58);
    color2 = ofColor(57, 255, 255);
    color3 = ofColor(255, 255, 255);
    point0 = ofPoint(0.31, 1.0 - 0.3);
    point1 = ofPoint(0.7, 1.0 - 0.32);
    point2 = ofPoint(0.28, 1.0 - 0.71);
    point3 = ofPoint(0.72, 1.0 - 0.75);
    
    // reset the gui //
    gui->getSlider("border width")->setValue(borderWidth);
    gui->getColorPicker("border color")->setColor(borderColor);
    gui->getColorPicker("color0")->setColor(color0);
    gui->getColorPicker("color1")->setColor(color1);
    gui->getColorPicker("color2")->setColor(color2);
    gui->getColorPicker("color3")->setColor(color3);
    ofRectangle bounds = ofRectangle(0, 0, 1, 1);
    gui->get2dPad("point0")->setBounds(bounds);
    gui->get2dPad("point0")->setPoint(point0);
    gui->get2dPad("point1")->setBounds(bounds);
    gui->get2dPad("point1")->setPoint(point1);
    gui->get2dPad("point2")->setBounds(bounds);
    gui->get2dPad("point2")->setPoint(point2);
    gui->get2dPad("point3")->setBounds(bounds);
    gui->get2dPad("point3")->setPoint(point3);
    gui->getMatrix("color pattern")->setRadioMode(true);
   
}
//--------------------------------------------------------------
void ofApp::update()
{
    
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(borderColor);
    ofSetColor(255);
    shader.begin();
    shader.setUniform2f("resolution", ofGetWidth()-borderWidth*2, ofGetHeight()-borderWidth*2);
    glm::vec2 p0 = glm::vec2(point0.x, abs(1.0 - point0.y));
    glm::vec2 p1 = glm::vec2(point1.x, abs(1.0 - point1.y));
    glm::vec2 p2 = glm::vec2(point2.x, abs(1.0 - point2.y));
    glm::vec2 p3 = glm::vec2(point3.x, abs(1.0 - point3.y));
    shader.setUniform2f("p0", p0);
    shader.setUniform2f("p1", p1);
    shader.setUniform2f("p2", p2);
    shader.setUniform2f("p3", p3);
    ofFloatColor c0 = color0;
    ofFloatColor c1 = color1;
    ofFloatColor c2 = color2;
    ofFloatColor c3 = color3;
    shader.setUniform4f("color0", c0);
    shader.setUniform4f("color1", c1);
    shader.setUniform4f("color2", c2);
    shader.setUniform4f("color3", c3);
    ofDrawRectangle(borderWidth, borderWidth, ofGetWidth()-borderWidth*2, ofGetHeight()-borderWidth*2);
    shader.end();
}
//--------------------------------------------------------------
ofColor ofApp::readBackground(float x, float y){
    ofPixels colorPixels = myImage.getPixels();
    ofColor c = colorPixels.getColor(x, y);
    return c;
}
//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    if (e.target->getLabel() == "RESET") reset();
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    if (e.target->getLabel() == "BORDER WIDTH"){
        borderWidth = e.target->getValue();
    }
}

void ofApp::on2dPadEvent(ofxDatGui2dPadEvent e)
{
    if (e.target->getLabel() == "POINT0"){
        point0 = e.target->getPoint();
    } else if (e.target->getLabel() == "POINT1"){
        point1 = e.target->getPoint();
    } else if (e.target->getLabel() == "POINT2"){
        point2 = e.target->getPoint();
    } else if (e.target->getLabel() == "POINT3"){
        point3 = e.target->getPoint();
    }
}

void ofApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
    if (e.target->getLabel() == "COLOR0"){
        color0 = e.target->getColor();
    } else if (e.target->getLabel() == "COLOR1"){
        color1 = e.target->getColor();
    } else if (e.target->getLabel() == "COLOR2"){
        color2 = e.target->getColor();
    } else if (e.target->getLabel() == "COLOR3"){
        color3 = e.target->getColor();
    } else if (e.target->getLabel() == "BORDER COLOR"){
        borderColor = e.target->getColor();
    }
}

void ofApp::onMatrixEvent(ofxDatGuiMatrixEvent e){
    switch (e.child) {
        case 0: //button 1
            color0 = ofColor(57, 255, 59);
            color1 = ofColor(255, 255, 58);
            color2 = ofColor(57, 255, 255);
            color3 = ofColor(255, 255, 255);
            borderColor = ofColor(177, 237, 229);
            break;
        case 1: //button 2
            color0 = ofColor::fromHex(0X272AFF);
            color1 = ofColor::fromHex(0XFF29FF);
            color2 = ofColor::fromHex(0X26FFFF);
            color3 = ofColor::fromHex(0XFFFFFF);
            borderColor = ofColor::fromHex(0xA3CBFF);
            break;
        case 2: //button 3
            color0 = ofColor::fromHex(0XFF282A);
            color1 = ofColor::fromHex(0XFF2BFF);
            color2 = ofColor::fromHex(0XFFFF29);
            color3 = ofColor::fromHex(0XFFFFFF);
            borderColor = ofColor::fromHex(0xFFCDD8);
            break;
        case 3: //button 4
            color0 = ofColor::fromHex(0X2829B8);
            color1 = ofColor::fromHex(0XFF28B8);
            color2 = ofColor::fromHex(0X28FFB8);
            color3 = ofColor::fromHex(0XFFFFB8);
            borderColor = ofColor::fromHex(0xE4E4E4);
            break;
        case 4: //button 5
            color0 = ofColor::fromHex(0X1E56C3);
            color1 = ofColor::fromHex(0XFDD2E5);
            color2 = ofColor::fromHex(0X6FB8EE);
            color3 = ofColor::fromHex(0XD9EAF4);
            borderColor = ofColor::fromHex(0xDAF3FD);
            break;
        case 5: //button 6
            color0 = ofColor::fromHex(0XFCBDAC);
            color1 = ofColor::fromHex(0X8B64D7);
            color2 = ofColor::fromHex(0XFEEAC7);
            color3 = ofColor::fromHex(0XFDA7C0);
            borderColor = ofColor::fromHex(0xFFFFFF);
            break;
        case 6: //button 7
            color0 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            color1 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            color2 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            color3 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            color0.setBrightness(250);
            color1.setBrightness(250);
            color2.setBrightness(250);
            color3.setBrightness(250);
            borderColor = ofColor::fromHex(0xFFFFFF);
            break;
    }
    gui->getColorPicker("color0")->setColor(color0);
    gui->getColorPicker("color1")->setColor(color1);
    gui->getColorPicker("color2")->setColor(color2);
    gui->getColorPicker("color3")->setColor(color3);
    gui->getColorPicker("border color")->setColor(borderColor);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'S' || key == 's') {
        //screenshot
        myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png");
    } else if (key == 'H' || key == 'h') {
        //hide / show the gui
        bHide = !bHide;
        gui->setVisible(bHide);
    } else if (key == ' ') {
        //border color = mouse color
        borderColor = readBackground(mouseX, mouseY);
        gui->getColorPicker("border color")->setColor(borderColor);
    }
}
