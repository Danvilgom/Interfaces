#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget *window = new QWidget;
   window->setWindowTitle("Enter Your Age");

     QSpinBox *spinBox = new QSpinBox;
     QSlider *slider = new QSlider(Qt::Horizontal);
     spinBox->setRange(0, 130);
     slider->setRange(0, 130);

     QPushButton *buttonSubir = new QPushButton("Subir");
     QPushButton *buttonBajar = new QPushButton("Bajar");

     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      slider, SLOT(setValue(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      spinBox, SLOT(setValue(int)));
     spinBox->setValue(35);

     QObject::connect(buttonSubir, SIGNAL(clicked()), spinBox, SLOT(stepUp()));
     QObject::connect(buttonBajar, SIGNAL(clicked()), spinBox, SLOT(stepDown()));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(spinBox);
     layout->addWidget(slider);
     layout->addWidget(buttonSubir);
     layout->addWidget(buttonBajar);
     window->setLayout(layout);

     window->show();
     buttonSubir->show();
     buttonBajar->show();

     return app.exec();
 }
