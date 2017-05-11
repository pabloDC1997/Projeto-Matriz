#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include<Matriz.h>
#include<QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButtonCriarM1_clicked();

    void on_pushButtonApagarM1_clicked();

    void on_pushButtonCriarM2_clicked();

    void on_pushButtonApagarM2_clicked();

    void on_pushButtonAdicinar_clicked();

    void on_pushButtonSubtrair_clicked();

    void on_pushButtonMultiplicarPorA_clicked();

    void on_pushButtonMultiplicarPorB_clicked();

    void on_pushButtonMultiplicar_clicked();

    void on_pushButtonPotenciacaoA_clicked();

    void on_pushButtonPotenciacaoB_clicked();

    void on_pushButtonTranspostaA_clicked();

    void on_pushButtonTranspostaB_clicked();

private:
    Ui::MainWindow *ui;
    TP2::Matriz<int> *matA;
    TP2::Matriz<int> *matB;
};

#endif // MAINWINDOW_H
