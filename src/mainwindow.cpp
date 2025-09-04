#include "mainwindow.h"
#include <QScreen>
#include <QGuiApplication>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>

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
	fileMenu->addAction(tr("Open"),  QKeySequence::Open, this, &MainWindow::openFile);

}

void MainWindow::newFile()
{
	m_textEdit->clear();
	setWindowTitle(tr("New File"));
	statusBar()->showMessage(tr("Created new file"), 2000);
}

void MainWindow::openFile()
{
	QString documentPaths = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), documentPaths, tr("Text files(*.txt);;All(*)"));

	if(!fileName.isEmpty())
	{
		auto file = QFile(fileName);

		if(file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);
			QString text = in.readAll();
			m_textEdit->setText(text);
			setWindowTitle(fileName);
			statusBar()->showMessage(tr("Opened file %1").arg(fileName));
		}

		file.close();
	}
}
