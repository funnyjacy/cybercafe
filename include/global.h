#ifndef GLOBAL_H
#define GLOBAL_H
#include "./model/LinkedList.h"

#define EMPTY -1
#define REPEAT 0
#define SUCCESS 1
#define NOT_FOUND 2
#define LONG 3

#define ON 4  // 上机状态
#define OFF 5 // 下机状态

extern LinkedList *Qlist;

// Define fixed sizes for string fields to ensure consistent binary record size
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_TIME_LEN 20 // Length for "yyyy-MM-dd hh:mm:ss"

#endif // !GLOBAL_H