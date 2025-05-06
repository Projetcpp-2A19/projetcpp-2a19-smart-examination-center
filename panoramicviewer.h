#ifndef PANORAMICVIEWER_H
#define PANORAMICVIEWER_H

#include <QDialog>
#include <QLabel>
#include <QPainter>

class PanoramicViewer : public QDialog
{
    Q_OBJECT
public:
    explicit PanoramicViewer(const QString &imagePath, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QLabel *m_label;
    QPixmap m_pixmap;
    int m_xPosition = 0;
    QPoint m_lastDragPos;

    void updateDisplay();
};

#endif // PANORAMICVIEWER_H
