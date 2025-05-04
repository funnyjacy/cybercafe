#include "../include/json.h"
#include "../include/global.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

void write_json(card *new_card)
{
    // Step 1: Read existing JSON file (if it exists)
    QFile file("E:\\A_codes\\VS_code\\cmake_test\\src\\data.json");
    QJsonArray jsonArray;

    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isArray())
        {
            jsonArray = doc.array();
        }
        file.close();
    }
    else if (!file.exists())
    {
        // File doesn't exist, initialize an empty array
        jsonArray = QJsonArray();
    }
    else
    {
        qDebug() << "Error: Failed to open file for reading.";
        return;
    }

    // Step 2: Create new JSON object for the card
    QJsonObject obj;
    obj.insert("name", QString::fromStdString(new_card->name));
    obj.insert("ID", QString::fromStdString(new_card->id));
    obj.insert("余额", new_card->balance);
    obj.insert("状态", new_card->Status);
    obj.insert("密码", QString::fromStdString(new_card->password));
    QString dt = new_card->time_last.toString("yyyy-MM-dd hh:mm:ss");
    obj.insert("上次使用时间", dt);

    // Step 3: Append new object to array
    jsonArray.append(obj);

    // Step 4: Write updated array back to file
    QJsonDocument doc(jsonArray);
    QByteArray json = doc.toJson(QJsonDocument::Indented); // Indented for readable output

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error: Failed to open file for writing.";
        return;
    }
    file.write(json);
    file.close();
}

void read_json()
{
    QFile file("E:\\A_codes\\VS_code\\cmake_test\\src\\data.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error: Failed to open file for writing.";
        return;
    }
    QByteArray all = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(all);
    if (doc.isNull() || !doc.isArray())
    {
        qDebug() << "Error: Invalid JSON format or file is not an array.";
        return;
    }

    // Step 3: Get the JSON array
    QJsonArray jsonArray = doc.array();

    // Step 4: Iterate through the array and add each card to the linked list
    for (const QJsonValue &value : jsonArray)
    {
        if (!value.isObject())
        {
            qDebug() << "Error: JSON element is not an object.";
            continue;
        }

        QJsonObject obj = value.toObject();

        // Extract card details
        string name = obj["name"].toString().toStdString();
        string id = obj["ID"].toString().toStdString();
        string password = obj["密码"].toString().toStdString();
        string balance = QString::number(obj["余额"].toDouble()).toStdString();
        string time_last = obj["上次使用时间"].toString().toStdString();

        // Add to the global linked list
        Qlist->init(name, id, balance, password, time_last);
    }

    qDebug() << "Successfully loaded" << Qlist->getSize() << "cards from JSON.";
}