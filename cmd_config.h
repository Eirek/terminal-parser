#ifndef CMD_CONFIG_H_INCLUDED
#define CMD_CONFIG_H_INCLUDED

#include <stdbool.h>

/* Константы для работы с маской */
#define KEY_IN_CMD 0x00000001
#define VAL_IN_CMD 0x00000010

/* Перечисление с номерами ошибок */

typedef enum {
    Ok = 100,
    UnknownKey = 200,
    KeyNeedValue = 300,
    EmptyKey = 400
} Error;

/* Структура для хранения ключа */
typedef struct {
    char key;
	int mask;
    char *value;
    char *usage;
    bool needValue;
} CmdItem;

#endif // CMD_CONFIG_H_INCLUDED
