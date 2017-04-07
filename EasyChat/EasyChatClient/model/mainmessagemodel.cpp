#include "mainmessagemodel.h"

MainMessageModel::MainMessageModel()
{
    m_roleNames.insert(messageRole, "message");
    m_roleNames.insert(senderRole, "sender");
    m_roleNames.insert(receiverRole, "receiver");
    m_roleNames.insert(sendTimeRole, "sendTime");
    m_roleNames.insert(operationRole, "operation");
}

int MainMessageModel::rowCount(const QModelIndex &parent) const
{
    return m_qlMainMessage.count();
}

QVariant MainMessageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
            return QVariant();
        if(m_qlMainMessage.isEmpty())
            return QVariant();
        switch (role)
        {
        case messageRole:
            return m_qlMainMessage.at(index.row())->message;
        case senderRole:
            return m_qlMainMessage.at(index.row())->sender;
        case receiverRole:
            return m_qlMainMessage.at(index.row())->receiver;
        case sendTimeRole:
            return m_qlMainMessage.at(index.row())->sendTime;
        case operationRole:
            return m_qlMainMessage.at(index.row())->operation;
        default:
            return QVariant();
        }
}

QHash<int, QByteArray> MainMessageModel::roleNames() const
{
    return m_roleNames;
}
