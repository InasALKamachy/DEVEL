#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    update_ui();

}
void MainWindow::update_ui(){
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinInterval->setValue(this->ui->renderArea->length());



}


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnHugens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}


void MainWindow::on_spinInterval_valueChanged(double length)
{
    this->ui->renderArea->setLength(length);
}


void MainWindow::on_spinCount_valueChanged(int count)
{
    this->ui->renderArea->setCount(count);
}


void MainWindow::on_btnBackground_clicked()
{
    //open color picker and change the color
    QColor color = QColorDialog::getColor(Qt::white, this, "Select color");
    this->ui->renderArea->setBackgroundColor(color);
}


void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Select color");
    this->ui->renderArea->ShapeColor(color);
}


void MainWindow::on_Cicle_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycle);
    this->ui->renderArea->repaint();
    update_ui();
}



void MainWindow::on_btnFancy_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Fancy);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnEllips_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Ellips);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnStarfish_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Starfish);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnCloud_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnCloud2_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud2);
    this->ui->renderArea->repaint();
    update_ui();
}

