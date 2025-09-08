#include "mainwindow.h"
#include <QStatusBar>
#include <QString>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), m_posLabel(new QLabel())
{
	setWindowTitle("Hello World");
	resize(800, 600);
	setupStatusBar();
	setupCentralWidget();
	setupMenuBar();

	statusBar()->showMessage(tr("ready"), 3000);
}

void MainWindow::moveEvent(QMoveEvent* event)
{
	QMainWindow::moveEvent(event);
	QString posText = QString(tr("Postion x: %1, y: %2")).arg(x()).arg(y());
	m_posLabel->setText(posText);
}

void MainWindow::setupStatusBar()
{
	statusBar()->addPermanentWidget(m_posLabel);
	m_posLabel->setText("Qt6");
}

void MainWindow::setupCentralWidget()
{
	m_textEdit = new QTextEdit();
	setCentralWidget(m_textEdit);
}

void MainWindow::setupMenuBar()
{
	QMenuBar *menuBar = this->menuBar();
	QMenu *fileMenu = menuBar->addMenu(tr("File(&F)"));
	fileMenu->addAction(tr("New"), QKeySequence::New, this, &MainWindow::newFile);
	fileMenu->addAction(tr("Open"), QKeySequence::Open, this, &MainWindow::openFile);
	fileMenu->addAction(tr("Save"), QKeySequence::Save, this, &MainWindow::saveFile);
}

void MainWindow::newFile()
{
	QTextEdit *textEdit = qobject_cast<QTextEdit*>(this->centralWidget());
	textEdit->clear();
	setWindowTitle(tr("New file"));
	statusBar()->showMessage(tr("New file"), 2000);
}

void MainWindow::openFile()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), tr("Text files(*.txt);;All files(*)"));

	if(!filename.isEmpty())
	{
		QFile file(filename);

		if(file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);
			m_textEdit->setPlainText(in.readAll());
			setWindowTitle(filename);
			statusBar()->showMessage(tr("Opened file: %1").arg(filename), 2000);
		}

		file.close();
	}
}

void MainWindow::saveFile()
{
	QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
	QString filename = QFileDialog::getSaveFileName(this, tr("Save file"), documentsPath + tr("/untitled.txt"),
	                   tr("Text files(*.txt);;All files(*)"));

	if(!filename.isEmpty())
	{
		QFile file(filename);

		if(file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream out(&file);

			out << m_textEdit->toPlainText();
			setWindowTitle(filename);
			statusBar()->showMessage(tr("Saved file %1").arg(filename), 2000);
		}

		file.close();
	}
}
