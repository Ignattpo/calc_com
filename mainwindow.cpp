#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainLabel::SetResult(const QString string) {
  this->setText(string);
}

void MainLabel::SetResult(float number) {
  QString string;
  string.setNum(number);
  this->setText(string);
}

float MainTextEdit::GetNunmber(bool* is_ok) {
  QString string;
  string = this->text();
  float num = string.toFloat(is_ok);
  if (!*is_ok) {
    this->setText("Не корректные данные");
  }
  return num;
}

void MainWindow::on_gas_calc_Button_clicked() {
  MainLabel* result_label = (MainLabel*)ui->label;
  MainLabel* expenses_label = (MainLabel*)ui->label_11;

  MainTextEdit* tarif_text = (MainTextEdit*)ui->lineEdit_3;
  MainTextEdit* debt_text = (MainTextEdit*)ui->lineEdit_4;
  MainTextEdit* init_ind_text = (MainTextEdit*)ui->lineEdit;
  MainTextEdit* curr_ind_text = (MainTextEdit*)ui->lineEdit_2;

  bool is_ok;
  float tarif = tarif_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float debt = debt_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float expenses = get_expenses(init_ind_text, curr_ind_text, &is_ok);
  if (!is_ok) {
    return;
  }

  result_label->SetResult(expenses * tarif + debt);
  expenses_label->SetResult(expenses);
}

void MainWindow::on_water_calc_Button_clicked() {
  MainLabel* result_label = (MainLabel*)ui->label_34;
  MainLabel* expenses_label = (MainLabel*)ui->label_28;

  MainTextEdit* tarif_text = (MainTextEdit*)ui->lineEdit_7;
  MainTextEdit* debt_text = (MainTextEdit*)ui->lineEdit_8;
  MainTextEdit* init_ind_text = (MainTextEdit*)ui->lineEdit_5;
  MainTextEdit* curr_ind_text = (MainTextEdit*)ui->lineEdit_6;

  bool is_ok;
  float tarif = tarif_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float debt = debt_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float expenses = get_expenses(init_ind_text, curr_ind_text, &is_ok);
  if (!is_ok) {
    return;
  }

  result_label->SetResult(expenses * tarif + debt);
  expenses_label->SetResult(expenses);
}

void MainWindow::on_trach_calc_Button_clicked() {
  MainLabel* result_label = (MainLabel*)ui->label_46;

  MainTextEdit* expenses_text = (MainTextEdit*)ui->lineEdit_9;
  MainTextEdit* tarif_text = (MainTextEdit*)ui->lineEdit_10;
  MainTextEdit* debt_text = (MainTextEdit*)ui->lineEdit_11;

  bool is_ok;
  float tarif = tarif_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float debt = debt_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float expenses = expenses_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  result_label->SetResult(expenses * tarif + debt);
}

void MainWindow::on_electric_calc_Button_clicked() {
  MainLabel* result_label = (MainLabel*)ui->label_17;
  MainLabel* expenses_total_label = (MainLabel*)ui->label_24;
  MainLabel* expenses_in_norma_label = (MainLabel*)ui->label_51;
  MainLabel* expenses_out_norma_label = (MainLabel*)ui->label_52;
  MainLabel* result_in_norma_label = (MainLabel*)ui->label_55;
  MainLabel* result_out_norma_label = (MainLabel*)ui->label_57;

  MainTextEdit* tarif_in_norma_text = (MainTextEdit*)ui->lineEdit_15;
  MainTextEdit* tarif_out_norma_text = (MainTextEdit*)ui->lineEdit_16;
  MainTextEdit* norma_text = (MainTextEdit*)ui->lineEdit_14;

  MainTextEdit* debt_text = (MainTextEdit*)ui->lineEdit_17;
  MainTextEdit* init_ind_text = (MainTextEdit*)ui->lineEdit_12;
  MainTextEdit* curr_ind_text = (MainTextEdit*)ui->lineEdit_13;

  bool is_ok;
  float tarif_in_norma = tarif_in_norma_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float tarif_out_norma = tarif_out_norma_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float norma = norma_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float debt = debt_text->GetNunmber(&is_ok);
  if (!is_ok) {
    return;
  }

  float expenses = get_expenses(init_ind_text, curr_ind_text, &is_ok);
  if (!is_ok) {
    return;
  }

  if (expenses <= norma) {
    expenses_total_label->SetResult(expenses);
    expenses_in_norma_label->SetResult(expenses);
    expenses_out_norma_label->SetResult(0);
    result_label->SetResult(expenses * tarif_in_norma + debt);
    result_in_norma_label->SetResult(expenses * tarif_in_norma + debt);
    result_out_norma_label->SetResult(0);

    return;
  }

  float expenses_out_norma = expenses - norma;

  expenses_total_label->SetResult(expenses);
  expenses_in_norma_label->SetResult(norma);
  expenses_out_norma_label->SetResult(expenses_out_norma);

  result_in_norma_label->SetResult(norma * tarif_in_norma);
  result_label->SetResult((norma * tarif_in_norma) +
                          (expenses_out_norma * tarif_out_norma) + debt);
  result_out_norma_label->SetResult(expenses_out_norma * tarif_out_norma);
}
