#ifndef DOCKTABBUTTON_H
#define DOCKTABBUTTON_H

#include <QQuickPaintedItem>
#include "dock.h"

class DockTabBar;
class DockWidgetHeaderButton;
class DockTabButton : public QQuickPaintedItem
{
    Q_OBJECT
    QString _title;
    Dock::ButtonStatus _status;
    DockTabBar *_parentTabBar;
    qreal _fitSize;
    bool _showCloseButton;
    DockWidgetHeaderButton *_closeButton;

public:
    DockTabButton(QString title, DockTabBar *parent = nullptr);
    void paint(QPainter *painter);
    QString title() const;
    DockTabBar *parentTabBar() const;
    bool showCloseButton() const;
    qreal fitSize() const;

signals:
    void clicked();
    void closeButtonClicked();

    // QQuickPaintedItem interface
public slots:
    void setTitle(const QString &title);
    void setChecked(bool checked);
    void setFitSize(const qreal &fitSize);
    void setShowCloseButton(bool showCloseButton);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void hoverEnterEvent(QHoverEvent *event);
    void hoverLeaveEvent(QHoverEvent *event);

    // QQuickItem interface
protected:
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
};

#endif // DOCKTABBUTTON_H
