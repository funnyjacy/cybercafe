#include "../include/json.h"
#include "../include/global.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include "config.h.in"
QString file_path = QString(PROJECT_ROOT_DIR) + "/src/datas/data.json";
QFile file(file_path);
void write_billings(card *new_card)
{
    FILE *file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\billings.asm", "a");

    if (file == NULL)
    {
        printf("Error: Failed to open file for writing.\n");
        return;
    }

    const char *status = (new_card->Status == 1) ? "ON" : "OFF";

    // Format: name##id##balance##status##password
    fprintf(file, "%s##%s##%.2f##%s##%s##%s\n",
            new_card->name.c_str(),
            new_card->id.c_str(),
            new_card->balance,
            status,
            new_card->time_last.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(),
            new_card->password.c_str());

    fclose(file);
}

void write_json(card *new_card)
{
    QFile file("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.json");
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
        // 文件不存在就初始化文件
        jsonArray = QJsonArray();
    }
    else
    {
        qDebug() << "Error: Failed to open file for reading.";
        return;
    }

    QJsonObject obj;
    obj.insert("name", QString::fromStdString(new_card->name));
    obj.insert("ID", QString::fromStdString(new_card->id));
    obj.insert("余额", new_card->balance);
    if (new_card->Status == ON)
    {
        obj.insert("状态", "上机");
    }
    else
    {
        obj.insert("状态", "下机");
    }

    obj.insert("密码", QString::fromStdString(new_card->password));
    QString dt = new_card->time_last.toString("yyyy-MM-dd hh:mm:ss");
    obj.insert("上次使用时间", dt);
    if (new_card->Pay == PAY_ED)
    {
        obj.insert("结账状态", "已结账");
    }
    else
    {
        obj.insert("结账状态", "未结账");
    }
    if (new_card->Del == USE)
    {
        obj.insert("卡状态", "生效中");
    }
    else
    {
        obj.insert("卡状态", "已注销");
    }

    // 文件列表
    jsonArray.append(obj);

    // 写入文件
    QJsonDocument doc(jsonArray);
    QByteArray json = doc.toJson(QJsonDocument::Indented); // 保存文件

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "error：无法打开文件进行写入";
        return;
    }
    file.write(json);
    file.close();
}

void read_json()
{
    //QFile file("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.json");
    QFile file("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        //qDebug() << "Error: Failed to open file for writing.";
        return;
    }
    QByteArray all = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(all);
    if (doc.isNull() || !doc.isArray())
    {
        //qDebug() << "Error: Invalid JSON format or file is not an array.";
        return;
    }

    QJsonArray jsonArray = doc.array();

    for (const QJsonValue &value : jsonArray)
    {
        if (!value.isObject())
        {
            //qDebug() << "Error: JSON element is not an object.";
            continue;
        }

        QJsonObject obj = value.toObject();

        string name = obj["name"].toString().toStdString();
        string id = obj["ID"].toString().toStdString();
        string password = obj["密码"].toString().toStdString();
        string balance = QString::number(obj["余额"].toDouble()).toStdString();
        string time_last = obj["上次使用时间"].toString().toStdString();
        string status = obj["状态"].toString().toStdString();
        string pay = obj["结账状态"].toString().toStdString();
        string del = obj["卡状态"].toString().toStdString();

        if (name != "" && del == "生效中")
        {
            Qlist->init(name, id, balance, password, time_last, status, del, pay);
        }
    }

    qDebug() << "成功加载" << Qlist->getSize() << "cards from JSON.";
}

void save_all_json(card *head, card *tail)
{
    QFile file("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        //qDebug() << "Error: Failed to open file for writing:" << file.errorString();
        return;
    }

    QJsonArray jsonArray;
    card *current = head;
    int nodeCount = 0;

    while (current != nullptr)
    {
        QJsonObject obj;
        obj.insert("name", QString::fromStdString(current->name));
        obj.insert("ID", QString::fromStdString(current->id));
        obj.insert("余额", current->balance);
        if (current->Status == ON)
        {
            obj.insert("状态", "上机");
        }
        else
        {
            obj.insert("状态", "下机");
        }
        obj.insert("密码", QString::fromStdString(current->password));
        QString dt = current->time_last.toString("yyyy-MM-dd hh:mm:ss");
        obj.insert("上次使用时间", dt);
        if (current->Pay == PAY_ED)
        {
            obj.insert("结账状态", "已结账");
        }
        else
        {
            obj.insert("结账状态", "未结账");
        }

        if (current->Del == USE)
        {
            obj.insert("卡状态", "生效中");
        }
        else
        {
            obj.insert("卡状态", "已注销");
        }

        jsonArray.append(obj);
        nodeCount++;
        //}
        current = current->next;
    }
    //qDebug() << "Processed" << nodeCount << "nodes into JSON array.";

    QJsonDocument doc(jsonArray);
    QByteArray json = doc.toJson(QJsonDocument::Indented);
    qint64 bytesWritten = file.write(json);
    if (bytesWritten == -1)
    {
        qDebug() << "Error: Failed to write JSON data to file:" << file.errorString();
    }
    else
    {
        qDebug() << "Successfully wrote" << bytesWritten << "bytes to file.";
    }

    file.flush();
    file.close();

    current = head;
    while (current != nullptr)
    {
        card *temp = current;
        current = current->next;
        delete temp;
    }
    qDebug() << "Linked list cleaned up.";

    head = nullptr;
    tail = nullptr;
}

void write_txt(card *new_card)
{
    FILE *file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.txt", "a");

    if (file == NULL)
    {
        printf("Error: Failed to open file for writing.\n");
        return;
    }

    const char *status = (new_card->Status == 1) ? "ON" : "OFF";

    fprintf(file, "%s##%s##%.2f##%s##%s##%s\n",
            new_card->name.c_str(),
            new_card->id.c_str(),
            new_card->balance,
            status,
            new_card->time_last.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(),
            new_card->password.c_str());

    fclose(file);
}

void read_txt()
{
    FILE *file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.txt", "r");
    // 使用项目根目录构造路径
    // std::string file_path = PROJECT_ROOT_DIR + "/src/datas/data.json";
    // QFile file(QString::fromStdString(file_path));
    if (file == NULL)
    {
        qDebug() << "Error: 无法打开文件进行写入";
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // 挪去无关字符
        line[strcspn(line, "\n")] = '\0';
        // 格式: name##id##balance##status##password##last_time##del##pay
        char *name = strtok(line, "##");
        char *id = strtok(NULL, "##");
        char *balance_str = strtok(NULL, "##");
        char *status = strtok(NULL, "##");
        string status_str;
        char *password = strtok(NULL, "##");
        char *time_last = strtok(NULL, "##");
        char *del = strtok(NULL, "##");
        char *pay = strtok(NULL, "##");
        if (strcmp(status, "OFF") == 0)
        {
            status_str = "下机";
        }
        else
        {
            status_str = "上机";
        }

        if (name == NULL || id == NULL || balance_str == NULL || status == NULL || time_last == NULL || password == NULL)
        {
            // qDebug() << "Error:不合法数据格式";
            continue;
        }

        Qlist->init(name, id, balance_str, password, time_last, status_str, del, pay);
    }

    fclose(file);

    qDebug() << "成功加载" << Qlist->getSize() << "cards from data.txt.";
}
//         "ID": "20",
//         "name": "刘亦菲",
//         "上次使用时间": "2025-05-13 15:51:01",
//         "余额": 100,
//         "卡状态": "生效中",
//         "密码": "20",
//         "状态": "下机",
//         "结账状态": "已结账"
void save_all_txt(card *head, card *tail)
{
    FILE *file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.txt", "w");
    if (file == NULL)
    {
        qDebug() << "无法打开文件！";
    }
    else
    {
        // 遍历列表进行写入
        card *current = head;
        while (current != NULL)
        {
            card *new_card = current;

            const char *status = (new_card->Status == 1) ? "ON" : "OFF";
            const char *del = (new_card->Del == USE) ? "生效中" : "已注销";
            const char *pay = (new_card->Pay == PAY_ED) ? "已结账" : "未结账";

            // 格式: name##id##balance##status##password##last_time##del##pay
            fprintf(file, "%s##%s##%.2f##%s##%s##%s##%s##%s\n",
                    new_card->name.c_str(),
                    new_card->id.c_str(),
                    new_card->balance,
                    status,
                    new_card->password.c_str(),
                    new_card->time_last.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(),
                    del,
                    pay);

            current = current->next;
        }
        fclose(file);
    }

    qDebug() << "链表信息已写入文件";
}

void write_dat(card *new_card)
{
    FILE *file = fopen("E:\\A_codes\\VS_code\\cybercafe\\src\\datas\\data.dat", "ab");
    if (file == NULL)
    {
        qDebug() << "Error: Failed to open data.dat for writing.";
        return;
    }

    char name_buf[MAX_NAME_LEN] = {0};
    char id_buf[MAX_ID_LEN] = {0};
    char password_buf[MAX_PASSWORD_LEN] = {0};
    char time_buf[MAX_TIME_LEN] = {0};

    strncpy(name_buf, new_card->name.c_str(), MAX_NAME_LEN - 1);
    strncpy(id_buf, new_card->id.c_str(), MAX_ID_LEN - 1);
    strncpy(password_buf, new_card->password.c_str(), MAX_PASSWORD_LEN - 1);

    QString time_str = new_card->time_last.toString("yyyy-MM-dd hh:mm:ss");
    strncpy(time_buf, time_str.toStdString().c_str(), MAX_TIME_LEN - 1);

    fwrite(name_buf, sizeof(char), MAX_NAME_LEN, file);
    fwrite(id_buf, sizeof(char), MAX_ID_LEN, file);
    fwrite(&new_card->balance, sizeof(double), 1, file);
    fwrite(&new_card->Status, sizeof(int), 1, file);
    fwrite(time_buf, sizeof(char), MAX_TIME_LEN, file);
    fwrite(password_buf, sizeof(char), MAX_PASSWORD_LEN, file);

    if (ferror(file))
    {
        //qDebug() << "Error: Failed to write to data.dat.";
        fclose(file);
        return;
    }

    fclose(file);
    qDebug() << "Successfully wrote card to data.dat.";
}

// void read_dat()
// {
//     // Step 1: Open the binary file in read mode
//     FILE *file = fopen("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.dat", "rb");
//     if (file == NULL)
//     {
//         qDebug() << "Error: Failed to open data.dat for reading.";
//         return;
//     }

//     // Step 2: Read the file record by record
//     while (1)
//     {
//         // Buffers for reading fixed-size fields
//         char name_buf[MAX_NAME_LEN] = {0};
//         char id_buf[MAX_ID_LEN] = {0};
//         double balance;
//         int status;
//         char time_buf[MAX_TIME_LEN] = {0};
//         char password_buf[MAX_PASSWORD_LEN] = {0};

//         // Step 3: Read each field of the record individually
//         size_t items_read;

//         // Read name
//         items_read = fread(name_buf, sizeof(char), MAX_NAME_LEN, file);
//         if (items_read != MAX_NAME_LEN)
//         {
//             if (feof(file))
//                 break; // End of file reached
//             qDebug() << "Error: Failed to read name field (read" << items_read << "of" << MAX_NAME_LEN << "bytes).";
//             break;
//         }

//         // Read id
//         items_read = fread(id_buf, sizeof(char), MAX_ID_LEN, file);
//         if (items_read != MAX_ID_LEN)
//         {
//             qDebug() << "Error: Failed to read id field (read" << items_read << "of" << MAX_ID_LEN << "bytes).";
//             break;
//         }

//         // Read balance
//         items_read = fread(&balance, sizeof(double), 1, file);
//         if (items_read != 1)
//         {
//             qDebug() << "Error: Failed to read balance field (read" << items_read << "of 1 double).";
//             break;
//         }

//         // Read status
//         items_read = fread(&status, sizeof(int), 1, file);
//         if (items_read != 1)
//         {
//             qDebug() << "Error: Failed to read status field (read" << items_read << "of 1 int).";
//             break;
//         }

//         // Read time_last
//         items_read = fread(time_buf, sizeof(char), MAX_TIME_LEN, file);
//         if (items_read != MAX_TIME_LEN)
//         {
//             qDebug() << "Error: Failed to read time_last field (read" << items_read << "of" << MAX_TIME_LEN << "bytes).";
//             break;
//         }

//         // Read password
//         items_read = fread(password_buf, sizeof(char), MAX_PASSWORD_LEN, file);
//         if (items_read != MAX_PASSWORD_LEN)
//         {
//             qDebug() << "Error: Failed to read password field (read" << items_read << "of" << MAX_PASSWORD_LEN << "bytes).";
//             break;
//         }

//         // Step 4: Prepare data for Qlist->init
//         std::string name = name_buf;
//         std::string id = id_buf;
//         std::string password = password_buf;
//         std::string time_last = time_buf;
//         std::string status = std::to_string(status);
//         // Convert balance to string (matching read_json/read_txt)
//         char balance_str[32];
//         snprintf(balance_str, sizeof(balance_str), "%.2f", balance);

//         // Step 5: Add to the global linked list
//         Qlist->init(name, id, balance_str, password, time_last, status);
//     }

//     // Step 6: Check for file errors
//     if (ferror(file))
//     {
//         qDebug() << "Error: File error occurred while reading data.dat.";
//     }

//     // Step 7: Close the file
//     fclose(file);

//     qDebug() << "Successfully loaded" << Qlist->getSize() << "cards from data.dat.";
// }
