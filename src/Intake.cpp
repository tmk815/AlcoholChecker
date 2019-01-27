#include "Intake.h"

void Intake::setup(){
    intake_image.load("image/Intake.png");
    submit.load("decision7.mp3");

    ofSetVerticalSync(true);

    gui.setup("Amount/Percent","panel",200,300); //タイトル、名前、x,y
    gui.setSize(700, 50);
    gui.setDefaultWidth(700);
    gui.setDefaultHeight(60);

    gui.add(alcoholAmount_slider.setup("ml", 350, 0, 1000));
    gui.add(percent.setup("%",5,0,100));
}


//--------------------------------------------------------------
void Intake::update(){

}

//--------------------------------------------------------------
void Intake::draw(){
    intake_image.draw(0,0, 500*2,720*2);
    gui.draw();
    ofSetColor(0, 0, 0); //色を黒に変更
    getSharedData().font.drawString("飲んだ量",0,350);
    getSharedData().font.drawString("%",100,430);
    ofSetColor(255, 255, 255); //色を白に変更
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
        d = alcohol.getValue("data:day", 0); //日付
        if (ofGetDay() != d) {
            alcohol.setValue("data:day", ofGetDay()); //dayに書き込む
            alcohol.setValue("data:alcholAmount", 0.0); //daypointsに書き込む
            alcohol.saveFile("alcohol.xml"); //保存
        }
        alcholAmount = alcohol.getValue("data:alcholAmount", 0.0);
        alcholAmount += alcoholAmount_slider*(static_cast<double>(percent)/100) * 0.792;
        alcohol.setValue("data:alcholAmount",alcholAmount);
        alcohol.saveFile("alcohol.xml");
        submit.play();
    }
}


string Intake::getName(){
    return "Intake";
}
