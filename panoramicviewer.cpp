#include "panoramicviewer.h"
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>

PanoramicViewer::PanoramicViewer(const QString &imagePath, QWidget *parent)
    : QDialog(parent), m_label(new QLabel(this))
{
    setWindowTitle("Visionneuse Panoramique 360°");

    // Taille réduite mais conservant le ratio panoramique
    setFixedSize(400, 300); // Ancienne taille était 1000x500

    // Charger l'image
    if(!m_pixmap.load(imagePath)) {
        m_label->setText("Échec du chargement de l'image");
        return;
    }

    // Configurer le label
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_label->setScaledContents(false);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->setContentsMargins(0, 0, 0, 0);

    // Ajuster la hauteur de l'image pour qu'elle corresponde à la nouvelle hauteur de fenêtre
    m_pixmap = m_pixmap.scaledToHeight(height(), Qt::SmoothTransformation);

    updateDisplay();
}

void PanoramicViewer::updateDisplay()
{
    int displayWidth = width();
    int displayHeight = height();

    if (m_xPosition + displayWidth > m_pixmap.width()) {
        QPixmap combined(displayWidth, displayHeight);
        QPainter painter(&combined);

        int firstPartWidth = m_pixmap.width() - m_xPosition;
        painter.drawPixmap(0, 0,
                           m_pixmap.copy(m_xPosition, 0, firstPartWidth, displayHeight)
                               .scaled(firstPartWidth, displayHeight, Qt::KeepAspectRatio));

        int secondPartWidth = displayWidth - firstPartWidth;
        painter.drawPixmap(firstPartWidth, 0,
                           m_pixmap.copy(0, 0, secondPartWidth, displayHeight)
                               .scaled(secondPartWidth, displayHeight, Qt::KeepAspectRatio));

        m_label->setPixmap(combined);
    } else {
        QPixmap portion = m_pixmap.copy(m_xPosition, 0, displayWidth, displayHeight);
        m_label->setPixmap(portion.scaled(displayWidth, displayHeight,
                                          Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

// Les autres méthodes restent inchangées...
void PanoramicViewer::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    updateDisplay();
}

void PanoramicViewer::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        m_lastDragPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
}

void PanoramicViewer::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        int dx = event->pos().x() - m_lastDragPos.x();
        m_lastDragPos = event->pos();

        m_xPosition = (m_xPosition - dx) % m_pixmap.width();
        if(m_xPosition < 0) m_xPosition += m_pixmap.width();

        updateDisplay();
    }
}

void PanoramicViewer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}
