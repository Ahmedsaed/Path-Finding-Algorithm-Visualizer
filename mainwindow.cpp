// mainwindow.cpp
#include "mainwindow.h"
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the sidebar widgets
    QComboBox *sourceComboBox = new QComboBox(this);
    QComboBox *destinationComboBox = new QComboBox(this);
    QComboBox *algorithmComboBox = new QComboBox(this);
    QSpinBox *depthLimitSpinBox = new QSpinBox(this);
    QPushButton *startButton = new QPushButton("Start", this);

    // Create the sidebar layout
    QVBoxLayout *sidebarLayout = new QVBoxLayout;
    sidebarLayout->addWidget(sourceComboBox);
    sidebarLayout->addWidget(destinationComboBox);
    sidebarLayout->addWidget(algorithmComboBox);
    sidebarLayout->addWidget(depthLimitSpinBox);
    sidebarLayout->addWidget(startButton);

    // Create the sidebar widget
    QWidget *sidebarWidget = new QWidget(this);
    sidebarWidget->setLayout(sidebarLayout);
    sidebarWidget->setFixedWidth(200);

    // Create the map widget
    mapView = new QGraphicsView(this);
    mapScene = new QGraphicsScene(this);
    mapView->setScene(mapScene);

    // Load and display the map image
    QPixmap mapImage("romania_map.png");
    mapScene->addPixmap(mapImage);

    // Create the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(sidebarWidget);
    mainLayout->addWidget(mapView);

    // Create the main widget
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);

    // Set the central widget of the main window
    setCentralWidget(mainWidget);
}
