#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxState.h"
#include "SharedData.h"
#include "ofxXmlSettings.h"

class Intake : public itg::ofxState<SharedData>{ //ofxStateを継承{

public:
    void setup();
    void update();
    void draw();
    string getName(); //状態の名前を返す関数
    void mousePressed(int x, int y, int button);

private:
    ofImage intake_image; //全体画像
    ofxPanel gui;
    ofxIntSlider alcoholAmount_slider;
    ofxIntSlider percent;
    ofTrueTypeFont font; //フォント用
    ofxXmlSettings alcohol; //XMLの設定用
    double alcholAmount;
    ofSoundPlayer submit;
    int d; //日付
};
