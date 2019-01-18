#include "Intake.h"

void Intake::setup(){
    intake_image.load("image/Intake.png");

    ofSetVerticalSync(true);

    gui.setup(); // most of the time you don't need a name
    gui.setSize(700, 50);
    gui.setDefaultWidth(700);
    gui.setDefaultHeight(40);

    gui.add(alcoholAmount_slider.setup("ｍｌ", 350, 0, 1000));
    gui.add(percent.setup("%",5,0,100));
}


//--------------------------------------------------------------
void Intake::update(){

}

//--------------------------------------------------------------
void Intake::draw(){
    intake_image.draw(0,0, 500*2,720*2);
    gui.draw();
}

void Intake::mousePressed(int x, int y, int button){
    if(y>=60*21){
        if(x>=0 && x<=330){
            changeState("Top");
        }else if(x>=660 && x<=1000){
            changeState("GetDrunkAvg");
        }
    }

    if(x>=250 && x<= 800 && y>=720 && y <=1020){
        alcohol.loadFile("alcohol.xml");
        alcholAmount = alcohol.getValue("data:alcholAmount", 0.0);
        alcholAmount += alcoholAmount_slider*(static_cast<double>(percent)/100) * 0.792;
        alcohol.setValue("data:alcholAmount",alcholAmount);
        alcohol.saveFile("alcohol.xml");
    }
}


string Intake::getName(){
    return "Intake";
}
