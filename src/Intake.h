#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxState.h"
#include "SharedData.h"

class Intake : public itg::ofxState<SharedData>{ //ofxStateを継承{

public:
    void setup();
    void update();
    void draw();
    string getName(); //状態の名前を返す関数

    ofxPanel gui;
    ofxIntSlider alcoholAmount;
    ofxIntSlider percent;
    ofTrueTypeFont font; //フォント用

};
