#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "graphe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Button_SaisieAPSFS_clicked();
    void on_Button_Prufer_clicked();
    void on_pushButton_clicked();
    void on_Button_sauvegarder_graphe_clicked();
    void on_Button_charger_graphe_clicked();
    void on_Button_Tarjan_clicked();

private:
    Ui::Widget *ui;
    Graphe* grapheActuel;
};
#endif // WIDGET_H
