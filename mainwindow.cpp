#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    matA(0),
    matB(0)

{
    ui->setupUi(this);

    ui->pushButtonAdicinar->setStyleSheet("image : url(:/imagens/add.png)");
    ui->pushButtonMultiplicar->setStyleSheet("image : url(:/imagens/mult.png");
    ui->pushButtonSubtrair->setStyleSheet("image : url(:/imagens/minus.png");



    //BOTÕES E LINE EDITES SENDO DESATIVADOS
    ui->tableWidgetSaida->setEnabled(false);
    ui->pushButtonApagarM1->setEnabled(false);
    ui->textEditResultadoM1->setEnabled(false);
    ui->pushButtonApagarM2->setEnabled(false);
    ui->textEditResultadoM2->setEnabled(false);
    ui->textEditSaidaSoma->setEnabled(false);
    ui->pushButtonApagarM1->setEnabled(false);
    ui->textEditResultadoM1->setEnabled(false);
    ui->pushButtonSubtrair->setEnabled(false);
    ui->pushButtonAdicinar->setEnabled(false);

    ui->pushButtonMultiplicar->setEnabled(false);
    ui->pushButtonMultiplicarPorA->setEnabled(false);
    ui->pushButtonMultiplicarPorB->setEnabled(false);
    ui->lineEditConstanteA->setEnabled(false);
    ui->lineEditConstanteB->setEnabled(false);
    ui->pushButtonPotenciacaoA->setEnabled(false);
    ui->pushButtonPotenciacaoB->setEnabled(false);
    ui->pushButtonTranspostaA->setEnabled(false);
    ui->pushButtonTranspostaB->setEnabled(false);
    ui->lineEditPotenciacaoA->setEnabled(false);
    ui->lineEditPotenciacaoaB->setEnabled(false);

    this->setFixedSize(this->width(), this->height());

}

MainWindow::~MainWindow()
{
    delete ui;
    if(matA) delete matA;
    if(matB) delete matB;
}




void MainWindow::on_pushButtonCriarM1_clicked()
{
    try{

       int linha = ui->lineEditQLinhasM1->text().toInt();
       int coluna = ui->lineEditQColunasM1->text().toInt();
       matA= new TP2::Matriz<int>(linha, coluna);

       for(int l=0; l<linha;l++){
           for(int c=0; c<coluna;c++){
           int elemento = QInputDialog::getInt(this, "Leitura",
                                               "Matriz A["+ QString::number(l)+","+
                                               QString::number(c)+"]= ");
           matA->setElemento(l,c,elemento);
   }
       }
       ui->textEditResultadoM1->setText(matA->getConjunto());//METODO PRA MOSTRA MATRIZ A NA UI
       ui->lineEditQColunasM1->setEnabled(false);//METODO PRA DESATIVAR BOTÃO
       ui->lineEditQLinhasM1->setEnabled(false);//METODO PRA DESATIVAR BOTÃO
       ui->pushButtonCriarM1->setEnabled(false);//METODO PRA DESATIVAR BOTÃO
       ui->pushButtonApagarM1->setEnabled(true);//METODO PRA ATIVAR BOTÃO
       ui->pushButtonPotenciacaoA->setEnabled(true);//METODO PRA ATIVAR BOTÃO
       ui->pushButtonTranspostaA->setEnabled(true);//METODO PRA ATIVAR BOTÃO
       if(matB)ui->pushButtonAdicinar->setEnabled(true);//METODO PRA ATIVAR BOTÃO
       if(matB)ui->pushButtonSubtrair->setEnabled(true);//METODO PRA ATIVAR BOTÃO

       ui->lineEditPotenciacaoA->setEnabled(true);

       ui->pushButtonMultiplicarPorA->setEnabled(true);//METODO PRA ATIVAR BOTÃO
       ui->lineEditConstanteA->setEnabled(true);//METODO PRA ATIVAR LINEEDITE
       if(matB)ui->pushButtonMultiplicar->setEnabled(true);//METODO PRA ATIVAR BOTÃO

       //METODO PRA VER SE A MATRIZ A É IDENTIDADE
       QString  ident="NÃO";
       if(matA->eMatrizIdentidade()) ident="SIM";
       QTableWidgetItem *itemIdentidadeA=new QTableWidgetItem(ident);
       ui->tableWidgetSaida->setItem(5,0,itemIdentidadeA);//FIM METODO
       //METODO PARA VER SE É MATRIZ TRIANGULAR SUPERIOR
       QString res="NÃO";
       if(matA->eTringularSuperior())res="SIM";
       QTableWidgetItem *resp=new QTableWidgetItem(res);
       ui->tableWidgetSaida->setItem(2,0,resp);
       //METODO PRA VER SE É MATRIZ TRIANGULAR INFERIOR
       QString res1="NÃO";
       if(matA->eTringularInferior())res1="SIM";
       QTableWidgetItem *resp1=new QTableWidgetItem(res);
       ui->tableWidgetSaida->setItem(3,0,resp1);

       //METODO PRA VER SE É MATRIZ SIMETRICA
       QString Simetrica1="NÃO";
       if(matA->eMatrizSimetrica()){Simetrica1="SIM";}
       QTableWidgetItem *itemSimetrica1=new QTableWidgetItem(Simetrica1);
       ui->tableWidgetSaida->setItem(4,0,itemSimetrica1);
       //FIM METODO

       //METODO PRA VER SE A MATRIZ E ORTOGONAL

       QString ortogonal1="NÃO";
       if(matA->eMatrizOrtogonal()){ortogonal1="SIM";}
       QTableWidgetItem *itemOrtogona1=new QTableWidgetItem(ortogonal1);
       ui->tableWidgetSaida->setItem(6,0,itemOrtogona1);
       //FIM METODO

       //METOD PRA VER SER E MATRIZ DE PERMUTAÇAO

       QString respostaPer1="NÃO";
       if(matA->eMatrizPermutacao()){respostaPer1="SIM";}
       QTableWidgetItem *itemPermuta1 = new QTableWidgetItem(respostaPer1);
       ui->tableWidgetSaida->setItem(7,0,itemPermuta1);
       //fim do metodo

       if(matB){//TABELINHA GRID... OBS: METODOS QUE DEPENDEM DA CRIAÇÃO DAS DUAS MATRIZES
           //METODO IGUAL
           QString resultado="NÃO";
           if((*matA) ==matB){
               resultado="SIM";}
           QTableWidgetItem *item1 =new QTableWidgetItem(resultado);
           QTableWidgetItem *item2= new QTableWidgetItem(resultado);
           ui->tableWidgetSaida->setItem(0,0,item1);
           ui->tableWidgetSaida->setItem(0,1,item2);//FIM METODO
           //METODO DIFERENTE
           QString resultado2="NÃO";
           if((*matA) !=matB)
               resultado2="SIM";
           QTableWidgetItem *item30 =new QTableWidgetItem(resultado2);
           QTableWidgetItem *item40= new QTableWidgetItem(resultado2);
           ui->tableWidgetSaida->setItem(1,0,item30);
           ui->tableWidgetSaida->setItem(1,1,item40);
       }


       }catch(std::bad_alloc &erro){
           QMessageBox::information(this,"ERRO","Vai comprar memoria");
       }catch(QString &erro){
           QMessageBox::information(this,"ERRO: ",erro);
       }
}

void MainWindow::on_pushButtonApagarM1_clicked()
{
    try{
           delete matA;
           matA=0;
           ui->textEditResultadoM1->clear();
           ui->lineEditQColunasM1->clear();
           ui->lineEditQLinhasM1->clear();
           ui->pushButtonCriarM1->setEnabled(true);
           ui->pushButtonApagarM1->setEnabled(false);
           ui->lineEditQColunasM1->setEnabled(true);
           ui->lineEditQLinhasM1->setEnabled(true);
           ui->pushButtonAdicinar->setEnabled(false);
           ui->pushButtonSubtrair->setEnabled(false);
           ui->textEditSaidaSoma->clear();


           ui->pushButtonMultiplicarPorA->setEnabled(false);
           ui->lineEditConstanteA->setEnabled(false);
           ui->lineEditConstanteA->clear();
           ui->pushButtonMultiplicar->setEnabled(false);
           ui->pushButtonPotenciacaoA->setEnabled(false);
           ui->pushButtonTranspostaA->setEnabled(false);
           ui->lineEditPotenciacaoA->clear();
           //GEITO ALTERNATIVO PARA LIMPAR AS GRIDES DEPOS DE APAGAR OS MATRIZES

           QTableWidgetItem *itemApagar1 = new QTableWidgetItem("");
           QTableWidgetItem *itemApagar2 = new QTableWidgetItem("");
           QTableWidgetItem *itemApagar3 = new QTableWidgetItem("");
           QTableWidgetItem *itemApagar4 = new QTableWidgetItem("");
           QTableWidgetItem *itemApagar5 = new QTableWidgetItem("");

           QTableWidgetItem *itemApagar7 = new QTableWidgetItem("");

           QTableWidgetItem *itemApagar9 = new QTableWidgetItem("");

           QTableWidgetItem *itemApagar11 = new QTableWidgetItem("");

           QTableWidgetItem *itemApagar13 = new QTableWidgetItem("");

           QTableWidgetItem *itemApagar15 = new QTableWidgetItem("");



           ui->tableWidgetSaida->setItem(0,0,itemApagar1);
           ui->tableWidgetSaida->setItem(0,1,itemApagar2);
           ui->tableWidgetSaida->setItem(1,0,itemApagar3);
           ui->tableWidgetSaida->setItem(1,1,itemApagar4);
           ui->tableWidgetSaida->setItem(2,0,itemApagar5);

           ui->tableWidgetSaida->setItem(3,0,itemApagar7);

           ui->tableWidgetSaida->setItem(4,0,itemApagar9);

           ui->tableWidgetSaida->setItem(5,0,itemApagar11);

           ui->tableWidgetSaida->setItem(6,0,itemApagar13);

           ui->tableWidgetSaida->setItem(7,0,itemApagar15);






       }catch(...){
           QMessageBox::information(this,"ERRO","ERRO NO METODO DE APAGAR OBJETO");
       }
}

void MainWindow::on_pushButtonCriarM2_clicked()
{
    try{

        int linha = ui->lineEditQLinhasM2->text().toInt();
        int coluna = ui->lineEditQColunasM2->text().toInt();
        matB= new TP2::Matriz<int>(linha, coluna);

        for(int l=0; l<linha;l++){
            for(int c=0; c<coluna;c++){
            int elemento = QInputDialog::getInt(this, "Leitura",
                                                "Matriz A["+ QString::number(l)+","+
                                                QString::number(c)+"]= ");
            matB->setElemento(l,c,elemento);
    }
        }
        ui->textEditResultadoM2->setText(matB->getConjunto());
        ui->lineEditQColunasM2->setEnabled(false);
        ui->lineEditQLinhasM2->setEnabled(false);
        ui->pushButtonCriarM2->setEnabled(false);
        ui->pushButtonApagarM2->setEnabled(true);
        ui->pushButtonPotenciacaoB->setEnabled(true);
        ui->pushButtonTranspostaB->setEnabled(true);
        if(matA)ui->pushButtonAdicinar->setEnabled(true);
        if(matA)ui->pushButtonSubtrair->setEnabled(true);

        ui->lineEditPotenciacaoaB->setEnabled(true);

        ui->pushButtonMultiplicarPorB->setEnabled(true);
        ui->lineEditConstanteB->setEnabled(true);
        if(matA)ui->pushButtonMultiplicar->setEnabled(true);

        //METODO PRA VER SE  MATRIZ B É IDENTIDADE
        QString  ident="NÃO";
        if(matB->eMatrizIdentidade()) ident="SIM";
        QTableWidgetItem *itemIdentidadeB=new QTableWidgetItem(ident);
        ui->tableWidgetSaida->setItem(5,1,itemIdentidadeB);//FIM METODO
        //METODO PARA VER SE É MATRIZ TRIANGULAR SUPERIOR
        QString rSS="NÃO";
        if(matB->eTringularSuperior())rSS="SIM";
        QTableWidgetItem *r=new QTableWidgetItem(rSS);
        ui->tableWidgetSaida->setItem(2,1,r);
        //METODO PRA VER SE É MATRIZ TRIANGULAR INFERIOR
        QString RESPOSTA="NÃO";
        if(matB->eTringularInferior())RESPOSTA="SIM";
        QTableWidgetItem *r1=new QTableWidgetItem(RESPOSTA);
        ui->tableWidgetSaida->setItem(3,1,r1);

        //METODO PRA VER SE É MATRIZ SIMETRICA
        QString Simetrica2="NÃO";
        if(matB->eMatrizSimetrica()){Simetrica2="SIM";}
        QTableWidgetItem *itemSimetrica2=new QTableWidgetItem(Simetrica2);
        ui->tableWidgetSaida->setItem(4,1,itemSimetrica2);
        //FIM METODO

        //METODO PRA VER SE A MATRIZ E ORTOGONAL

        QString ortogonal2="NÃO";
        if(matB->eMatrizOrtogonal()){ortogonal2="SIM";}
        QTableWidgetItem *itemOrtogona2=new QTableWidgetItem(ortogonal2);
        ui->tableWidgetSaida->setItem(6,1,itemOrtogona2);
        //FIM METODO

        //METOD PRA VER SER E MATRIZ DE PERMUTAÇAO

        QString respostaPer2="NÃO";
        if(matB->eMatrizPermutacao()){respostaPer2="SIM";}
        QTableWidgetItem *itemPermuta2 =new QTableWidgetItem(respostaPer2);
        ui->tableWidgetSaida->setItem(7,1,itemPermuta2);
        //fim do metodo

        if(matA){//TABELINHA ---------------------------------------------------------------
            //METODO IGUAL
            QString resultado="NÃO";
            if((*matA) ==matB)
                resultado="SIM";
            QTableWidgetItem *item1 =new QTableWidgetItem(resultado);
            QTableWidgetItem *item2= new QTableWidgetItem(resultado);
            ui->tableWidgetSaida->setItem(0,0,item1);
            ui->tableWidgetSaida->setItem(0,1,item2);//FIM

            //METODO DIFERENTE
            QString resultado2="NÃO";
            if((*matA) !=matB)
                resultado2="SIM";
            QTableWidgetItem *item3 =new QTableWidgetItem(resultado2);
            QTableWidgetItem *item4= new QTableWidgetItem(resultado2);
            ui->tableWidgetSaida->setItem(1,0,item3);
            ui->tableWidgetSaida->setItem(1,1,item4);//FIM

        }



        }catch(std::bad_alloc &erro){
            QMessageBox::information(this,"ERRO","Vai comprar memoria");
        }catch(QString &erro){
            QMessageBox::information(this,"ERRO: ",erro);
        }
}

void MainWindow::on_pushButtonApagarM2_clicked()
{
    try{
            delete matB;
            matB=0;
            ui->textEditResultadoM2->clear();
            ui->lineEditQColunasM2->clear();
            ui->lineEditQLinhasM2->clear();
            ui->pushButtonCriarM2->setEnabled(true);
            ui->pushButtonApagarM2->setEnabled(false);
            ui->lineEditQColunasM2->setEnabled(true);
            ui->lineEditQLinhasM2->setEnabled(true);
            ui->pushButtonAdicinar->setEnabled(false);
            ui->pushButtonSubtrair->setEnabled(false);
            ui->textEditSaidaSoma->clear();
            ui->pushButtonPotenciacaoB->setEnabled(false);
            ui->pushButtonTranspostaA->setEnabled(false);
            ui->lineEditPotenciacaoaB->clear();
            ui->pushButtonTranspostaB->setEnabled(false);
            ui->pushButtonMultiplicarPorB->setEnabled(false);
            ui->lineEditConstanteB->setEnabled(false);
            ui->lineEditConstanteB->clear();
            ui->pushButtonMultiplicar->setEnabled(false);

            //GEITO ALTERNATIVO PARA LIMPAR AS GRIDES DEPOS DE APAGAR OS MATRIZES

            QTableWidgetItem *itemApagar1 = new QTableWidgetItem("");
            QTableWidgetItem *itemApagar2 = new QTableWidgetItem("");
            QTableWidgetItem *itemApagar3 = new QTableWidgetItem("");
            QTableWidgetItem *itemApagar4 = new QTableWidgetItem("");

            QTableWidgetItem *itemApagar6 = new QTableWidgetItem("");

            QTableWidgetItem *itemApagar8 = new QTableWidgetItem("");

            QTableWidgetItem *itemApagar10 = new QTableWidgetItem("");

            QTableWidgetItem *itemApagar12 = new QTableWidgetItem("");

            QTableWidgetItem *itemApagar14 = new QTableWidgetItem("");

            QTableWidgetItem *itemApagar16 = new QTableWidgetItem("");


            ui->tableWidgetSaida->setItem(0,0,itemApagar1);
            ui->tableWidgetSaida->setItem(0,1,itemApagar2);
            ui->tableWidgetSaida->setItem(1,0,itemApagar3);
            ui->tableWidgetSaida->setItem(1,1,itemApagar4);

            ui->tableWidgetSaida->setItem(2,1,itemApagar6);

            ui->tableWidgetSaida->setItem(3,1,itemApagar8);

            ui->tableWidgetSaida->setItem(4,1,itemApagar10);

            ui->tableWidgetSaida->setItem(5,1,itemApagar12);

            ui->tableWidgetSaida->setItem(6,1,itemApagar14);

            ui->tableWidgetSaida->setItem(7,1,itemApagar16);

        }catch(...){
            QMessageBox::information(this,"ERRO","ERRO NO METODO DE APAGAR OBJETO");
        }
}

void MainWindow::on_pushButtonAdicinar_clicked()
{
    try
        {
            TP2::Matriz<int> *matC = 0;
            matC=(*matA)+matB;
            ui->textEditSaidaSoma->setText(matC->getConjunto());
            delete matC;
        }catch(...){
            QMessageBox::information(this,"ERRO","ERRO NO METODO ADICINAR");
        }
}

void MainWindow::on_pushButtonSubtrair_clicked()
{
    try
        {
            TP2::Matriz<int> *matD = 0;
            matD=(*matA)-matB;
            //mostra a adição
            ui->textEditSaidaSoma->setText(matD->getConjunto());
            delete matD;
        }catch(...){
            QMessageBox::information(this,"ERRO","ERRO NO METODO ADICINAR");
        }
}





void MainWindow::on_pushButtonMultiplicarPorA_clicked()
{
    ui->textEditSaidaSoma->clear();
    int k = ui->lineEditConstanteA->text().toInt();
    TP2::Matriz<int> *MatM=0;
    MatM= matA->multiplicarPorK(k);
    ui->textEditSaidaSoma->setText(MatM->getConjunto());
    delete MatM;

}

void MainWindow::on_pushButtonMultiplicarPorB_clicked()
{
    ui->textEditSaidaSoma->clear();
    int k = ui->lineEditConstanteB->text().toInt();
    TP2::Matriz<int> *MatM=0;
    MatM= matB->multiplicarPorK(k);
    ui->textEditSaidaSoma->setText(MatM->getConjunto());
    delete MatM;
}


void MainWindow::on_pushButtonMultiplicar_clicked()
{
    try{
    TP2::Matriz<int> *aux= (*matA)*matB;
    ui->textEditSaidaSoma->setText(aux->getConjunto());
    delete aux;
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO: ",erro);
    }
}



void MainWindow::on_pushButtonPotenciacaoA_clicked()
{
    try {
        int x = ui->lineEditPotenciacaoA->text().toInt();
        TP2::Matriz<int> *aux= matA->potenciacao(x);
        ui->textEditSaidaSoma->setText(aux->getConjunto());
        delete aux;


    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO: ",erro);
    }
}

void MainWindow::on_pushButtonPotenciacaoB_clicked()
{
    try {
        int x = ui->lineEditPotenciacaoaB->text().toInt();
        TP2::Matriz<int> *aux= matB->potenciacao(x);
        ui->textEditSaidaSoma->setText(aux->getConjunto());
        delete aux;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO: ",erro);
    }

}

void MainWindow::on_pushButtonTranspostaA_clicked()
{
        ui->textEditSaidaSoma->clear();
        TP2::Matriz<int> *matT=matA->transposta();
        ui->textEditSaidaSoma->setText(matT->getConjunto());
        delete matT;
}

void MainWindow::on_pushButtonTranspostaB_clicked()
{
    ui->textEditSaidaSoma->clear();
    TP2::Matriz<int> *matD=matB->transposta();
    ui->textEditSaidaSoma->setText(matD->getConjunto());
    delete matD;
}
