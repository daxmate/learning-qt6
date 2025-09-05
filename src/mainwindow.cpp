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

	statusBar()->showMessage(tr("就绪"), 3000);
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
	QMenu *fileMenu = menuBar->addMenu(tr("文件(&F)"));
	fileMenu->addAction(tr("新建"), QKeySequence::New, this, &MainWindow::newFile);
	fileMenu->addAction(tr("打开"), QKeySequence::Open, this, &MainWindow::openFile);
	fileMenu->addAction(tr("保存"), QKeySequence::Save, this, &MainWindow::saveFile);
}

void MainWindow::newFile()
{
	QTextEdit *textEdit = qobject_cast<QTextEdit*>(this->centralWidget());
	textEdit->clear();
	setWindowTitle(tr("新建文件"));
	statusBar()->showMessage(tr("新建文件"), 2000);
}

void MainWindow::openFile()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("打开文件"), tr("文本文件(*.txt);;所有文件(*)"));

	if(!filename.isEmpty())
	{
		QFile file(filename);

		if(file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);
			m_textEdit->setPlainText(in.readAll());
			setWindowTitle(filename);
			statusBar()->showMessage(tr("已经打开文件: %1").arg(filename), 2000);
		}

		file.close();
	}
}

void MainWindow::saveFile()
{
	QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
	QString filename = QFileDialog::getSaveFileName(this, tr("保存文件"), documentsPath + tr("/未命名文件.txt"),
	                   tr("文本文件(*.txt);;所有文件(*)"));

	if(!filename.isEmpty())
	{
		QFile file(filename);

		if(file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream out(&file);

			out << m_textEdit->toPlainText();
			setWindowTitle(filename);
			statusBar()->showMessage(tr("已保存文件 %1").arg(filename), 2000);
		}

		file.close();
	}
}
