#ifndef TELADEAJUDA_H
#define TELADEAJUDA_H

#include <QDialog>

namespace Ui {
class TelaDeAjuda;
}

class TelaDeAjuda : public QDialog
{
    Q_OBJECT

public:
    explicit TelaDeAjuda(QWidget *parent = nullptr);
    ~TelaDeAjuda();
    QString lerArquivo(QString nomeDoArquivo);

private:
    Ui::TelaDeAjuda *ui;
};

#endif // TELADEAJUDA_H
