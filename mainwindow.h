#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <map>
#include <vector>
#include <string>
#include "graphnode.h"
#include "algorithm.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QGraphicsView *mapView;
    QGraphicsScene *mapScene;

    std::map<std::string, GraphNode*> graphNodes;

    void generateGraph();
    void addGraphNode(const std::string& nodeName, int x, int y);
    void addGraphEdge(const std::string& nodeA, const std::string& nodeB);
    void highlight_path(udtl::vector<std::string>& path);

    QString source = "";
    QString destination = "";
    QString algo = "";
    int algo_limit = 0;
    std::vector<GraphEdge*> highlightedEdges;

private slots:
    void handleSourceComboBox(int index);
    void handleDestinationComboBox(int index);
    void handleAlgorithmComboBox(int index);
    void handleDepthLimitSpinBox(int value);
    void handleStartButtonClicked();

};
#endif // MAINWINDOW_H
