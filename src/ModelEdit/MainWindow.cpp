#include "MainWindow.h"
#include <osgDB/ReadFile>
#include "Core.h"
#include "GeoMetryModel/GeometryFloor.h"
#include "MECore/FileUtils.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	auto* osgView = new OSGGraphView;
	setCentralWidget(osgView);
	//setCentralWidget(Core::ins()->getOSGView());
	initScene();
}

void MainWindow::initScene()
{
	GeometryFloor* floor = new GeometryFloor(50, 50);
	Core::ins()->getSceneData()->addChild(osgDB::readNodeFile(FileUtils::ins()->getPath("/Data/Models/cow.osg").toLocal8Bit().data()));
	Core::ins()->getSceneData()->addChild(floor);
	Core::ins()->getManipulator()->home(0);
}
