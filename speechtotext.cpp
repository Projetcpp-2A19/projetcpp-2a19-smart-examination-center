#include "speechtotext.h"
#include <QDebug>

SpeechToText::SpeechToText(QObject *parent) : QObject(parent)
{
    process = new QProcess(this); // Initialize process
}

void SpeechToText::startListening()
{
    QString pythonScript = "C:/Users/imenh/Documents/test/speech_to_text.py";
    QString modelPath = "C:/Users/imenh/Documents/test/models/vosk-model-small-fr-0.22";

    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        QString output = process->readAllStandardOutput().trimmed();
        if (!output.isEmpty()) {

            emit textRecognized(output);
        }
    });

    process->start("python", {pythonScript, modelPath});
}
