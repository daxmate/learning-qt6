#include "mainwindow.h"
#include <QScreen>
#include <QGuiApplication>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent),
	m_textEdit(new QTextEdit())
{
	setupWindow();
	setupCentralWidget();
	setupMenu();

}

void MainWindow::setupWindow()
{
	resize(800, 600);
	setWindowTitle("Hello Qt6");
}

void MainWindow::setupCentralWidget()
{
	setCentralWidget(m_textEdit);
}

void MainWindow::setupMenu()
{
	QMenuBar * menuBar = this->menuBar();
	QMenu* fileMenu = menuBar->addMenu("&File");
	fileMenu->addAction(tr("New"),  QKeySequence::New, this, &MainWindow::newFile);

}

void MainWindow::newFile()
{
	m_textEdit->clear();
	setWindowTitle(tr("New File"));
	statusBar()->showMessage(tr("Created new file"), 2000);
}
