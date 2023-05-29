#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPen>
#include <QPainter>

class GraphNode : public QGraphicsItem
{
public:
    GraphNode(const std::string& name, int x, int y)
        : QGraphicsItem(), nodeName(name)
    {
        setPos(x, y);
        setFlag(QGraphicsItem::ItemIsMovable); // Enable node movement
        setFlag(QGraphicsItem::ItemSendsGeometryChanges); // Notify of position changes

        nodeEllipse = new QGraphicsEllipseItem(-5, -5, 10, 10, this);
        nodeEllipse->setBrush(Qt::green);
        nodeEllipse->setZValue(10);

        nodeLabel = new QGraphicsTextItem(QString::fromStdString(name), this);
        QBrush textColorBrush(Qt::yellow);
        nodeLabel->setDefaultTextColor(textColorBrush.color());
        nodeLabel->setPos(-1 * nodeLabel->boundingRect().width() / 2, 10);
    }

    std::string getNodeName() const { return nodeName; }

protected:
    QRectF boundingRect() const override { return childrenBoundingRect(); }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::green);
        painter->drawEllipse(-5, -5, 10, 10);
    }

    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override
    {
        return QGraphicsItem::itemChange(change, value);
    }

private:
    std::string nodeName;
    QGraphicsEllipseItem* nodeEllipse;
    QGraphicsTextItem* nodeLabel;
};

class GraphEdge : public QGraphicsLineItem
{
public:
    GraphEdge(GraphNode* nodeA, GraphNode* nodeB)
        : QGraphicsLineItem(nodeA->pos().x(), nodeA->pos().y(),
                            nodeB->pos().x(), nodeB->pos().y())
    {
        setPen(QPen(Qt::white, 1));
    }
};

#endif // GRAPHNODE_H
