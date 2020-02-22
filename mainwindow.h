/* ЗАГОЛОВНИЙ ФАЙЛ ГОЛОВНОГО ВІКНА
 * БУЛО СТВОРЕНО АВТОМАТИЧНО QT */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Деякі події на головному вікні(натискання кнопки та ін.)
    void on_randomAButton_clicked();

    void on_randomBButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void resizeEvent(QResizeEvent *event);

    void drawCircles(QStringList list1, QStringList list2);

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_7_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    void lineEditWorker();
};
#endif // MAINWINDOW_H
