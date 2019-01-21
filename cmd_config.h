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
<<<<<<< HEAD
    NoKey = 400,
	ErrorParse = 500,
=======
	ErrorParse = 400
>>>>>>> c45d912debf78a87460b1d021c67a442dd3a7722
} Error;

/* Структура для хранения ключа */
typedef struct {
	char sign;
    char key;
	int mask;
    char *value;
    char *usage;
    bool needValue;
} CmdItem;

#endif // CMD_CONFIG_H_INCLUDED
