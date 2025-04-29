#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnBinario, &QPushButton::clicked, this, &MainWindow::converterParaBinario);
    connect(ui->btnDecimal, &QPushButton::clicked, this, &MainWindow::converterParaDecimal);
    connect(ui->btnOctal, &QPushButton::clicked, this, &MainWindow::converterParaOctal);


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::converterParaBinario() {
    bool ok;
    // Obtemos o valor inserido pelo usuário no campo de entrada
    int numeroDecimal = ui->entradaNumero->text().toInt(&ok);
    if (ok) {
        // Convertendo para binário
        QString binario = QString::number(numeroDecimal, 2); // "2" é para binário
        // Exibindo o resultado no QLabel
        ui->labelResultado->setText("Binário: " + binario);
    } else {
        // Caso o número não seja válido
        QMessageBox::warning(this, "Erro", "Por favor, insira um número válido.");
    }
}


void MainWindow::converterParaDecimal() {
    bool ok;
    // Obtemos o valor inserido pelo usuário
    QString numeroBinario = ui->entradaNumero->text();
    int numeroDecimal = numeroBinario.toInt(&ok, 2); // 2 é a base binária
    if (ok) {
        // Exibindo o resultado no QLabel
        ui->labelResultado->setText("Decimal: " + QString::number(numeroDecimal));
    } else {
        // Caso o número binário seja inválido
        QMessageBox::warning(this, "Erro", "Por favor, insira um número binário válido.");
    }
}

void MainWindow::converterParaOctal() {
    bool ok;
    // Obtemos o valor inserido pelo usuário
    QString numeroBinario = ui->entradaNumero->text();

    // Convertendo o número binário para decimal
    int numeroDecimal = numeroBinario.toInt(&ok, 2); // Base 2 para binário
    if (ok) {
        // Convertendo de decimal para octal
        QString octal = QString::number(numeroDecimal, 8); // "8" é para octal
        // Exibindo o resultado no QLabel
        ui->labelResultado->setText("Octal: " + octal);
    } else {
        // Caso o número binário seja inválido
        QMessageBox::warning(this, "Erro", "Por favor, insira um número binário válido.");
    }
}
