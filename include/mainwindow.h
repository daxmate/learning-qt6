#pragma once
#include <QMainWindow>
#include <QTextEdit>

class MainWindow final: public QMainWindow
{
	public:
		explicit MainWindow(QWidget* parent = nullptr);
		~MainWindow() override = default;

	private:
		void setupWindow();
		void setupCentralWidget();
		void setupMenu();

		QTextEdit* m_textEdit;
	private slots:
		void newFile();
		void openFile();
};
