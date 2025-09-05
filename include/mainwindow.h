#pragma once
#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QMoveEvent>
#include <QTextEdit>

class MainWindow final : public QMainWindow
{
		Q_OBJECT
	public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow() override = default;

	protected:
		void moveEvent(QMoveEvent *event) override;

	private:
		QLabel* m_posLabel;
		QTextEdit* m_textEdit;
		void setupStatusBar();
		void setupCentralWidget();
		void setupMenuBar();

	private slots:
		void newFile();
		void openFile();
		void saveFile();
};
