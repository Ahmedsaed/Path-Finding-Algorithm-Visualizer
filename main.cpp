#include "mainwindow.h"

#include <QApplication>
#include "romania.h"
#include "algorithm.h"
#include <QStringList>

QStringList algorithms_list = {
    "Breadth First Search",
    "Uniform Cost Search",
    "Depth First Search",
    "Depth Limited Search",
    "Iterative Deepening DFS",
    "Bidirectional Search",
    "Greedy BFS",
    "A* Search"
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
