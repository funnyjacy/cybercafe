#include "../include/json.h"
#include "../include/global.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

// void write_billings(card *new_card)
// {
//     FILE *file = fopen("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\billings.asm", "a");

//     if (file == NULL)
//     {
//         printf("Error: Failed to open file for writing.\n");
//         return;
//     }

//     // Convert status to string (assuming Status is an enum with ON=1, OFF=0)
//     const char *status = (new_card->Status == 1) ? "ON" : "OFF";

//     // Format: name##id##balance##status##password
//     fprintf(file, "%s##%s##%.2f##%s##%s##%s\n",
//             new_card->name.c_str(),
//             new_card->id.c_str(),
//             new_card->balance,
//             status,
//             new_card->time_last.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(),
//             new_card->password.c_str());

//     fclose(file);
// }

void write_json(card *new_card)
{
    QFile file("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.json");
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
    QFile file("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.json");
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

    QJsonArray jsonArray = doc.array();

    for (const QJsonValue &value : jsonArray)
    {
        if (!value.isObject())
        {
            qDebug() << "Error: JSON element is not an object.";
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
    QFile file("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        qDebug() << "Error: Failed to open file for writing:" << file.errorString();
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
    qDebug() << "Processed" << nodeCount << "nodes into JSON array.";

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

    // Ensure data is written to disk and close the file
    file.flush();
    file.close();

    // Step 6: Clean up the linked list
    current = head;
    while (current != nullptr)
    {
        card *temp = current;
        current = current->next;
        delete temp;
    }
    qDebug() << "Linked list cleaned up.";

    // Step 7: Reset head and tail (uncomment if needed)
    head = nullptr;
    tail = nullptr;
}

// void write_txt(card *new_card)
// {
//     FILE *file = fopen("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.txt", "a");

//     if (file == NULL)
//     {
//         printf("Error: Failed to open file for writing.\n");
//         return;
//     }

//     // Convert status to string (assuming Status is an enum with ON=1, OFF=0)
//     const char *status = (new_card->Status == 1) ? "ON" : "OFF";

//     // Format: name##id##balance##status##password
//     fprintf(file, "%s##%s##%.2f##%s##%s##%s\n",
//             new_card->name.c_str(),
//             new_card->id.c_str(),
//             new_card->balance,
//             status,
//             new_card->time_last.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(),
//             new_card->password.c_str());

//     fclose(file);
// }

// void read_txt()
// {
//     // Step 1: Open the text file
//     FILE *file = fopen("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.txt", "r");
//     if (file == NULL)
//     {
//         qDebug() << "Error: Failed to open file for reading.";
//         return;
//     }

//     // Step 2: Read the file line by line
//     char line[256]; // Assuming lines are reasonably short
//     while (fgets(line, sizeof(line), file) != NULL)
//     {
//         // Remove trailing newline if present
//         line[strcspn(line, "\n")] = '\0';

//         // Step 3: Parse the line using ## as delimiter
//         char *name = strtok(line, "##");
//         char *id = strtok(NULL, "##");
//         char *balance_str = strtok(NULL, "##");
//         char *status = strtok(NULL, "##");
//         char *time_last = strtok(NULL, "##");
//         char *password = strtok(NULL, "##");

//         // Ensure all fields are read correctly
//         if (name == NULL || id == NULL || balance_str == NULL || status == NULL || time_last == NULL || password == NULL)
//         {
//             qDebug() << "Error: Invalid line format in text file.";
//             continue;
//         }

//         // Step 4: Prepare time_last (empty since text file doesn't store time)
//         // char time_last[1] = "";

//         // Step 5: Add to the global linked list
//         Qlist->init(name, id, balance_str, password, time_last, status);
//     }

//     // Step 6: Close the file
//     fclose(file);

//     qDebug() << "Successfully loaded" << Qlist->getSize() << "cards from data.txt.";
// }

// void save_all_txt(card *head, card *tail)
// {
//     // Step 1: Open the data.txt file in write mode to clear it
//     FILE *file = fopen("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.txt", "w");
//     if (file == NULL)
//     {
//         qDebug() << "Error: Failed to open file for writing.";
//     }
//     else
//     {
//         // Step 2: Traverse the linked list and write each card to the file
//         card *current = head;
//         while (current != NULL)
//         {
//             card *new_card = current;
//             // Convert status to string (assuming Status is an enum with ON=1, OFF=0)
//             const char *status = (new_card->Status == 1) ? "ON" : "OFF";

//             // Write in format: name##id##balance##status##password
//             fprintf(file, "%s##%s##%.2f##%s##%s##%s\n",
//                     new_card->name.c_str(),
//                     new_card->id.c_str(),
//                     new_card->balance,
//                     status,
//                     new_card->time_last.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(),
//                     new_card->password.c_str());

//             current = current->next;
//         }
//         fclose(file);
//     }

//     // Step 3: Free the linked list nodes
//     // Node *current = head;
//     // while (current != NULL)
//     // {
//     //     Node *temp = current;
//     //     current = current->next;
//     //     delete temp->data; // Free the card struct
//     //     delete temp;       // Free the node
//     // }
//     // head = NULL;
//     // size = 0;

//     qDebug() << "LinkedList destructor: data.txt updated and memory freed.";
// }

// void write_dat(card *new_card)
// {
//     // Step 1: Open the binary file in append mode
//     FILE *file = fopen("E:\\A_codes\\VS_code\\cmake_test\\src\\datas\\data.dat", "ab");
//     if (file == NULL)
//     {
//         qDebug() << "Error: Failed to open data.dat for writing.";
//         return;
//     }

//     // Step 2: Prepare fixed-size buffers for string fields
//     char name_buf[MAX_NAME_LEN] = {0};
//     char id_buf[MAX_ID_LEN] = {0};
//     char password_buf[MAX_PASSWORD_LEN] = {0};
//     char time_buf[MAX_TIME_LEN] = {0};

//     // Copy strings, ensuring they fit within the buffer (truncate if necessary)
//     strncpy(name_buf, new_card->name.c_str(), MAX_NAME_LEN - 1);
//     strncpy(id_buf, new_card->id.c_str(), MAX_ID_LEN - 1);
//     strncpy(password_buf, new_card->password.c_str(), MAX_PASSWORD_LEN - 1);

//     // Convert QDateTime to string
//     QString time_str = new_card->time_last.toString("yyyy-MM-dd hh:mm:ss");
//     strncpy(time_buf, time_str.toStdString().c_str(), MAX_TIME_LEN - 1);

//     // Step 3: Write the card data as a binary record
//     // Write fixed-size fields: name, id, balance, Status, time_last, password
//     fwrite(name_buf, sizeof(char), MAX_NAME_LEN, file);
//     fwrite(id_buf, sizeof(char), MAX_ID_LEN, file);
//     fwrite(&new_card->balance, sizeof(double), 1, file);
//     fwrite(&new_card->Status, sizeof(int), 1, file);
//     fwrite(time_buf, sizeof(char), MAX_TIME_LEN, file);
//     fwrite(password_buf, sizeof(char), MAX_PASSWORD_LEN, file);

//     // Step 4: Check for write errors
//     if (ferror(file))
//     {
//         qDebug() << "Error: Failed to write to data.dat.";
//         fclose(file);
//         return;
//     }

//     // Step 5: Close the file
//     fclose(file);
//     qDebug() << "Successfully wrote card to data.dat.";
// }

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
