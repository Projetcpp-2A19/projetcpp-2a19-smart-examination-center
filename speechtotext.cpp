#include "speechtotext.h"
#include <QDebug>

SpeechToText::SpeechToText(QObject *parent) : QObject(parent)
{
    process = new QProcess(this); // Initialize process
}

void SpeechToText::startListening()
{

    if (isRecognitionRunning) {
        qDebug() << "[SpeechToText] Recognition already running!";
        return;
    }

    isRecognitionRunning = true;
    process = new QProcess(this);

    QString pythonScript = R"(C:\DossierIntegration\speech_to_text.py)";
    QString modelPath = R"(C:\DossierIntegration\models\vosk-model-fr-0.22)";

    if (process && process->state() != QProcess::NotRunning) {
        qDebug() << "[SpeechToText] Terminating existing process...";
        process->terminate();
        process->waitForFinished(3000); // attend 3 secondes max
    }

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PATH", "C:/Users/bessa/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Python 3.13;" + env.value("PATH"));

    disconnect(process, nullptr, nullptr, nullptr);  // Clean old connections

    process->setProcessEnvironment(env);

    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        QString output = process->readAllStandardOutput().trimmed();
        if (!output.isEmpty()) {
            qDebug() << "[SpeechToText] Output received:" << output;
            emit textRecognized(output);
        }
    });

    connect(process, &QProcess::readyReadStandardError, this, [this]() {
        QString err = process->readAllStandardError().trimmed();
        if (!err.isEmpty()) qDebug() << "[SpeechToText] STDERR:" << err;
    });

    connect(process, &QProcess::errorOccurred, this, [](QProcess::ProcessError error) {
        qDebug() << "[SpeechToText] Process error:" << error;
    });

    qDebug() << "[SpeechToText] Starting speech recognition process...";
    process->start("python", {pythonScript, modelPath});

    if (!process->waitForStarted()) {
        qDebug() << "[SpeechToText] Failed to start Python process.";
    } else {
        qDebug() << "[SpeechToText] Python process started successfully.";
    }
}
