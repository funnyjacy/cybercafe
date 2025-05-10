#ifndef GLOBAL_H
#define GLOBAL_H
#include "./model/LinkedList.h"

#define EMPTY -1
#define REPEAT 0
#define SUCCESS 1
#define NOT_FOUND 2
#define LONG 3

#define ON 4     // 上机状态
#define OFF 5    // 下机状态
#define NO_PWD 6 // 密码不正确

#define AL_ON 7  // 已经在上机状态
#define AL_OFF 8 // 已经在下机状态

#define USE 9     // 还在使用
#define USE_NO 10 // 已注销

#define PAY_ED 11 // 已支付
#define PAY_NO 12 // 未支付

extern LinkedList *Qlist;

// Define fixed sizes for string fields to ensure consistent binary record size
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_TIME_LEN 20 // Length for "yyyy-MM-dd hh:mm:ss"

#endif // !GLOBAL_H