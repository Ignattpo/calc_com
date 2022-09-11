#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}

float get_expenses(MainTextEdit* begin_ind,
                   MainTextEdit* end_ind,
                   bool* is_ok) {
  float begin = begin_ind->GetNunmber(is_ok);
  if (!*is_ok) {
    return 0;
  }

  float end = end_ind->GetNunmber(is_ok);
  if (!*is_ok) {
    return 0;
  }

  return (end - begin);
}
