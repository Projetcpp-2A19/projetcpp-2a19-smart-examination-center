#ifndef SPEECHTOTEXT_H
#define SPEECHTOTEXT_H

#include <QObject>
#include <QProcess>
#include <QDir>

class SpeechToText : public QObject
{
    Q_OBJECT

public:
    explicit SpeechToText(QObject *parent = nullptr);
    void startListening();
    bool isRecognitionRunning = false;


signals:
    void textRecognized(const QString &text);

private:
    QProcess *process;
};

#endif // SPEECHTOTEXT_H
