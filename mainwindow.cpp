//Program:				RawImageGUITEst.cpp
// Name:				Jeffery Erhunse
// Assignment #:		InterTest
// Due Date:			01/30/18


// Program Description 
/* build a simple GUI application that has the ability to open a .raw image file. A test .raw file will be provided for you. 
The main GUI for the application has already been setup as well as the directory structure for the project.
The structure of the raw image is the following

Height: 1920 pixels
Width: 1536 pixels
Image format: 16 bit (unsigned) gray scale, little-endian
Use the mock-up below as a reference for how to implement the GUI of the application.
In general you'll need a menu in the top of the application to allow for opening of the image using File -> Open. 
This should prompt a file picker where the user can pick the .raw file.. */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qpixmap>
#include <Qaction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	Qpixmap pix("C:/Users/S7/Documents/GitHub/InterviewTest/test_data/test.raw"); //location of image

	int w = ui->label_pic->width(1920);		//set width parameter
	int h = ui->label_pic->height(1536);	// set height parameter

	ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)); //should open window to right size

}

MainWindow::~MainWindow()
{
	//New action to go from GUI "open" to file holding image 
	void MainWindow::createActions(Open)
	{
		newAct = new QAction(tr("&New"), this);
		newAct->setShortcuts(QKeySequence::New);
		newAct->setStatusTip(tr("Create a new file"));
		connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    delete ui;
}
