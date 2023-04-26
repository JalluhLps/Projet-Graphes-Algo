#include "widget.h"
#include "ui_widget.h"

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


            ui->label_RetourPrufer->setText( QString::fromStdString(textPrufer )  );
        }

        else  {ui->label_RetourPrufer->setText("Seulement sur un graph non orienté"); }

    }  catch (... ) {
        ui->label_RetourPrufer->setText("Erreur dans le codage");
    }

}

