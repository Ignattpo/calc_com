#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}  // namespace Ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void SetValidations();
  void on_gas_calc_Button_clicked();

  void on_water_calc_Button_clicked();

  void on_trach_calc_Button_clicked();

  void on_electric_calc_Button_clicked();

 private:
  Ui::MainWindow* ui;
};

class MainLabel : public QLabel {
 public:
  void SetResult(const QString string);
  void SetResult(float number);
};

class MainTextEdit : public QLineEdit {
 public:
  float GetNunmber(bool* is_ok);
};

float get_expenses(MainTextEdit* begin_ind, MainTextEdit* end_ind, bool* is_ok);

#endif  // MAINWINDOW_H
