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
    void on_btnAstroid_clicked();

    void on_btnCicloid_clicked();

    void on_btnHugens_clicked();

    void on_btnHypo_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double scale);




    void on_spinInterval_valueChanged(double arg1);

    void on_spinCount_valueChanged(int arg1);

    void on_btnBackground_clicked();

    void on_btnLineColor_clicked();

    void on_Cicle_clicked();


    void on_btnFancy_clicked();

    void on_btnEllips_clicked();

    void on_btnStarfish_clicked();

    void on_btnCloud_clicked();

    void on_btnCloud2_clicked();

private:
    void update_ui();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
