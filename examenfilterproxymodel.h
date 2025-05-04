#ifndef EXAMENFILTERPROXYMODEL_H
#define EXAMENFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QDate>

class ExamenFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ExamenFilterProxyModel(QObject *parent = nullptr);

    void setMatiereFilter(const QString &text);
    void setDateFilter(const QDate &date);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString matiereFilter;
    QDate dateFilter;
};

#endif // EXAMENFILTERPROXYMODEL_H
