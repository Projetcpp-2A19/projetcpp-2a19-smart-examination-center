#include "examenfilterproxymodel.h"
#include <QDebug>
#include <QDateTime>
#include <QAbstractItemModel>

ExamenFilterProxyModel::ExamenFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

void ExamenFilterProxyModel::setMatiereFilter(const QString &text)
{
    matiereFilter = text;
    invalidateFilter(); // Redéclenche le filtrage
}

void ExamenFilterProxyModel::setDateFilter(const QDate &date)
{
    dateFilter = date;
    invalidateFilter();
}

bool ExamenFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex matiereIndex = sourceModel()->index(source_row, 1, source_parent); // matière
    QModelIndex dateIndex = sourceModel()->index(source_row, 6, source_parent);    // date_examen

    QString matiereValue = sourceModel()->data(matiereIndex).toString();
    QDateTime dateValue = sourceModel()->data(dateIndex).toDateTime();

    // Vérifier matière
    bool matiereOk = matiereValue.contains(matiereFilter, Qt::CaseInsensitive);

    // Vérifier date (si une date est définie)
    bool dateOk = true;
    if (dateFilter.isValid()) {
        dateOk = dateValue.date() == dateFilter;
    }

    return matiereOk && dateOk;
}
