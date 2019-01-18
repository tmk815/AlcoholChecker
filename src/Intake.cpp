#include "Intake.h"

void Intake::setup(){
    ofSetVerticalSync(true);

    gui.setup(); // most of the time you don't need a name
    gui.setSize(700, 50);
    gui.setDefaultWidth(700);
    gui.setDefaultHeight(40);

    gui.add(alcoholAmount.setup("ｍｌ", 350, 0, 1000));
    gui.add(percent.setup("%",5,0,100));
}


//--------------------------------------------------------------
void Intake::update(){

}

//--------------------------------------------------------------
void Intake::draw(){
    gui.draw();
}

string Intake::getName(){
    return "Intake";
}
