#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include "graphe.h"
#include "graphenonoriente.h"
#include "grapheoriente.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Button_SaisieAPSFS_clicked()
{
    QString APS = ui->lineEdit_Saisie_APS->displayText();
    QString FS = ui->lineEdit_Saisie_FS->displayText();

    vector<Sommet> fs,aps;  /** Cedric aps est un tab d'entier il ne contient que les ind dans fs */
    fs.reserve(FS.size());
    aps.reserve(APS.size());

    //Creation APS
    int i = 0;
    int numero = 0; QChar lu = 'a';
    while (  i < APS.size() )
    {
        lu = APS[i];
        if ( lu >= '0' && lu <='9'  ) {
                    numero  = numero * 10;
                    numero  = numero + lu.Number_DecimalDigit ;
                    }
        else {
            Sommet s (numero);
            aps.push_back( s );

            numero = 0;
        }
        i++;
    }
    //Creation FS
    i = 0;
    numero = 0; lu = 'a';
    while (  i < FS.size() )
    {
        lu = FS[i];
        if ( lu >= '0' && lu <='9'  ) {
                    numero  = numero * 10;
                    numero  = numero + lu.Number_DecimalDigit ;
                    }
        else {
            Sommet s (numero);
            fs.push_back( s );

            numero = 0;
        }
        i++;
    }
    //
    vector <int> aps2;
    aps2.resize( aps.size());
    for (unsigned i = 0 ; i < fs.size() ; i++) aps2[i] =  aps[i].getCle();

    if ( ui->checkBox_EstOriente->isChecked() ) grapheActuel = new  GrapheOriente ( fs,aps2, fs.size() , aps.size() );
    else grapheActuel = new  GrapheNonOriente  ( fs,aps2, fs.size() , aps.size());

    // afficher graphe Actuel;
}


void Widget::on_Button_Prufer_clicked()
{
    try {
        vector <int> prufer;
        if ( grapheActuel->codagePrufer(prufer) == true  ){

            std::string textPrufer = "{";
            for ( unsigned i = 0 ; i < prufer.size() ; i++)
            {
                textPrufer.append(std::to_string(prufer[i])  );
                textPrufer.append(",");
            }
            textPrufer.append("}");


            ui->label_RetourPrufer->setText( QString::fromStdString(textPrufer )  );
        }

        else  {ui->label_RetourPrufer->setText("Seulement sur un graph non orienté"); }

    }  catch (... ) {
        ui->label_RetourPrufer->setText("Erreur dans le codage");
    }

}


void Widget::on_pushButton_clicked()
{
    try {


         vector <int> dist;

        QString numeroRacine = ui->lineEdit_Calcul_RacineDistance->text();
        int numeroRacineInt =  numeroRacine.toInt();
        if (  grapheActuel->calculDistance(numeroRacineInt ,  dist) == true ) {

            std::string  affichageDist ="{";
            for ( unsigned i = 0 ; i < dist.size() ; i++)
            {
                affichageDist.append(std::to_string(dist[i])  );
                affichageDist.append(",");
            }
            affichageDist.append("}");

            ui->label_RetourDistance2->setText(   QString::fromStdString( affichageDist )   );

        }
        else {

            ui->label_RetourDistance2->setText("Impossible de calculer la distance sur un graphe orienté");
        }
    }  catch ( ...) {
        ui->label_RetourDistance2->setText("Impossible de calculer la distance");

    }
}


void Widget::on_Button_sauvegarder_graphe_clicked()
{
    QString qstr = ui->text_nomFic->toPlainText();
    std::string txt = qstr.toStdString();
    QMessageBox msg;
    if(grapheActuel->ecrireGraphe(txt)==false)
    {
        msg.setText("Fichier introuvable");
        msg.exec();
    }
    else
    {
        msg.setText("Graphe sauvegarder");
        msg.exec();
    }
}


void Widget::on_Button_charger_graphe_clicked()
{
    QString qstr = ui->text_nomFic->toPlainText();
    std::string txt = qstr.toStdString();
    QMessageBox msg;
    if(grapheActuel->lireGraphe(txt)==false)
    {
        msg.setText("Fichier introuvable");
        msg.exec();
    }
    else
    {
        msg.setText("Graphe chargé");
        msg.exec();
    }
}

