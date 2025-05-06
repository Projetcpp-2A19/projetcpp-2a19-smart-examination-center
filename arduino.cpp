#include "arduino.h"

Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}
/*int Arduino::connect_arduino()
{
    qDebug() << "Starting Arduino connection...";

    serial->setBaudRate(QSerialPort::Baud9600);

    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Found port:" << serial_port_info.portName()
        << "Vendor ID:" << serial_port_info.vendorIdentifier()
        << "Product ID:" << serial_port_info.productIdentifier();

        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            // Debug output for Vendor and Product IDs
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                qDebug() << "Arduino found on port:" << arduino_port_name;
                break;  // Exit loop once Arduino is found
            }
        }
    }

    // If Arduino is found, attempt to connect
    if (arduino_is_available) {
        qDebug() << "Arduino port set to:" << arduino_port_name;

        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            qDebug() << "Arduino connected successfully!";
            return 0;  // Connection successful
        } else {
            qDebug() << "Failed to open serial port. Error:" << serial->errorString();
            return 1;  // Failed to open port
        }
    }

    qDebug() << "Arduino not available. No matching vendor and product IDs found.";
    return -1;  // Arduino not detected
}*/
int Arduino::connect_arduino(const QString& portName)
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if(portName.isEmpty() || serial_port_info.portName() == portName) {
            arduino_port_name = serial_port_info.portName();
            arduino_is_available = true;
        }
    }

    if(arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

void Arduino::write_to_arduino(QByteArray d)
{
    if (serial->isWritable()) {
        serial->write(d);  // Send data to Arduino
        qDebug() << "Sent to Arduino:" << d;
    } else {
        qDebug() << "Couldn't write to serial! Serial is not writable.";
    }
}

QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable()) {
        data = serial->readAll(); // Read the data
        qDebug() << "Received from Arduino:" << data;
        return data;
    } else {
        qDebug() << "No data available to read from Arduino.";
    }
    return QByteArray();  // Return an empty QByteArray if nothing to read
}


void Arduino::sendToArduino(const QByteArray &data)  // Add `const` to match declaration
{
    if (!serial) {
        qDebug() << "Serial port not initialized!";
        return;
    }

    if (serial->isOpen() && serial->isWritable()) {
        qint64 bytesWritten = serial->write(data);

        if (!serial->waitForBytesWritten(1000)) {  // Wait max 1 second
            qDebug() << "Write timeout!";
        }

        qDebug() << "Sent to Arduino:" << data
                 << "Bytes written:" << bytesWritten;
    } else {
        qDebug() << "Serial port not writable or not open!";
    }
}
bool Arduino::isConnected() const {
    return arduino_is_available && serial && serial->isOpen();
}

QSerialPort* Arduino::getSerial() const {
    return serial;
}

void Arduino::sendCommand(char command) {
    if(isConnected()) {
        QByteArray data;
        data.append(command);
        serial->write(data);
        serial->waitForBytesWritten(1000);
    }
}
