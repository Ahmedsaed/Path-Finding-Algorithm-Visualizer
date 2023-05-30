// mainwindow.cpp
#include "mainwindow.h"
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QStringList>
#include <QtMath>
#include <vector>
#include <string>
#include <QTimer>
#include <QEventLoop>

extern QStringList algorithms_list;
extern QStringList cities;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the sidebar widgets
    QComboBox *sourceComboBox = new QComboBox(this);
    QComboBox *destinationComboBox = new QComboBox(this);
    QComboBox *algorithmComboBox = new QComboBox(this);
    QSpinBox *depthLimitSpinBox = new QSpinBox(this);
    QPushButton *startButton = new QPushButton("Start", this);

    sourceComboBox->addItems(cities);
    sourceComboBox->setPlaceholderText("Source City");
    destinationComboBox->addItems(cities);
    destinationComboBox->setPlaceholderText("Destination City");
    algorithmComboBox->addItems(algorithms_list);
    algorithmComboBox->setPlaceholderText("Algorithm");
    depthLimitSpinBox->setValue(1);

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

    // Generate the graph representation
    generateGraph();

    // Set the map view size and alignment
    mapView->setFixedSize(800, 400);
    mapView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // Create the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(sidebarWidget);
    mainLayout->addWidget(mapView);

    // Create the main widget
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);

    // Set the central widget of the main window
    setCentralWidget(mainWidget);
    setWindowTitle("Path Finding Algorithm Visualizer");
    setFixedSize(1020, 410);

    // Connect input handlers
    connect(sourceComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleSourceComboBox);
    connect(destinationComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleDestinationComboBox);
    connect(algorithmComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleAlgorithmComboBox);
    connect(depthLimitSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::handleDepthLimitSpinBox);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::handleStartButtonClicked);
}

void MainWindow::generateGraph()
{
    const int padding = 30; // Adjust the padding value as desired

    // Create graph nodes and set their positions
    graphNodes.clear(); // Clear existing nodes
    addGraphNode("Arad", 50, 150);
    addGraphNode("Zerind", 150, 100);
    addGraphNode("Oradea", 230, 130);
    addGraphNode("Timisoara", 90, 250);
    addGraphNode("Lugoj", 150, 280);
    addGraphNode("Mehadia", 200, 300);
    addGraphNode("Drobeta", 250, 330);
    addGraphNode("Craiova", 330, 330);
    addGraphNode("Rimnicu Vilcea", 350, 250);
    addGraphNode("Sibiu", 250, 200);
    addGraphNode("Fagaras", 350, 150);
    addGraphNode("Pitesti", 450, 250);
    addGraphNode("Bucharest", 550, 200);
    addGraphNode("Giurgiu", 520, 300);
    addGraphNode("Urziceni", 650, 250);
    addGraphNode("Hirsova", 730, 300);
    addGraphNode("Eforie", 750, 350);
    addGraphNode("Vaslui", 650, 150);
    addGraphNode("Iasi", 700, 100);
    addGraphNode("Neamt", 720, 50);

    // Connect the nodes based on the graph edges
    for (const auto& nodePair : graphNodes)
    {
        const std::string& nodeName = nodePair.first;
        const std::vector<std::pair<std::string, int>>& neighbors = romania[nodeName];

        for (const auto& neighbor : neighbors)
        {
            const std::string& neighborName = neighbor.first;
            addGraphEdge(nodeName, neighborName);
        }
    }
}


void MainWindow::addGraphNode(const std::string& nodeName, int x, int y)
{
    GraphNode* node = new GraphNode(nodeName, x, y);
    mapScene->addItem(node);
    graphNodes[nodeName] = node;
}

void MainWindow::addGraphEdge(const std::string& sourceNodeName, const std::string& destNodeName)
{
    // Retrieve the source and destination nodes based on their names
    GraphNode* sourceNode = graphNodes[sourceNodeName];
    GraphNode* destNode = graphNodes[destNodeName];

    // Create a new GraphEdge and add it to the scene
    GraphEdge* edge = new GraphEdge(sourceNode, destNode);
    mapScene->addItem(edge);
}

void MainWindow::handleSourceComboBox(int index)
{
    source = cities[index];
}

void MainWindow::handleDestinationComboBox(int index)
{
    destination = cities[index];
}

void MainWindow::handleAlgorithmComboBox(int index)
{
    algo = algorithms_list[index];
}

void MainWindow::handleDepthLimitSpinBox(int value)
{
    algo_limit = value;
}

void MainWindow::handleStartButtonClicked()
{
    udtl::vector<std::string> path;
    if (algo == "Breadth First Search")
        path = breadthFirstSearch(source.toStdString(), destination.toStdString());
    else if (algo == "depth First Search")
        path = depthFirstSearch(source.toStdString(), destination.toStdString());
    else if (algo == "Uniform Cost Search")
        path = uniformCostSearch(source.toStdString(), destination.toStdString());
    else if (algo == "Depth Limited Search")
        path = depthLimitedSearch(source.toStdString(), destination.toStdString(), algo_limit);
    else if (algo == "Iterative Deepening DFS")
        path = iterativeDeepeningDFS(source.toStdString(), destination.toStdString());
    else if (algo == "Bidirectional Search")
        path = bidirectionalSearch(source.toStdString(), destination.toStdString());
    else if (algo == "A* Search")
        path = AStarSearch(source.toStdString(), destination.toStdString());
    else if (algo == "Greedy BFS")
        path = greedyBFS(source.toStdString(), destination.toStdString());

    if (path.size() != 0)
        highlight_path(path);
    else
    {
        // Clear all existing highlighted edges
        for (QGraphicsLineItem* edge : highlightedEdges)
        {
            mapScene->removeItem(edge);
            delete edge;
        }
        highlightedEdges.clear();
    }

}

void MainWindow::highlight_path(udtl::vector<std::string>& path)
{
    // Clear all existing highlighted edges
    for (QGraphicsLineItem* edge : highlightedEdges)
    {
        mapScene->removeItem(edge);
        delete edge;
    }
    highlightedEdges.clear();

    // Iterate through the path and draw edges between the nodes
    for (std::size_t i = 0; i < path.size() - 1; ++i)
    {
        const std::string& currentNode = path[i];
        const std::string& nextNode = path[i + 1];

        GraphNode* currentNodeItem = graphNodes[currentNode];
        GraphNode* nextNodeItem = graphNodes[nextNode];

        // Create and add the highlighted edge
        GraphEdge* highlightedEdge = new GraphEdge(currentNodeItem, nextNodeItem);
        highlightedEdge->setPen(QPen(Qt::red, 2));
        mapScene->addItem(highlightedEdge);
        highlightedEdges.push_back(highlightedEdge);

        // Pause the execution for the specified delay
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
        loop.exec();
    }
}
