#ifndef CMD_PARSER_H_INCLUDED
#define CMD_PARSER_H_INCLUDED

#include "cmd_config.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/* Функция разбора массива argv:
 * возвращается код ошибки, представленный объектом перечисления Error
 * принимается массив ключей и параметры функции main
 */
Error cmdParse(CmdItem* itemList, int argc, char** argv);

/* Функция проверки наличия ключа */
bool isKey(CmdItem* itemList, char sign,char key);

/* Функция проверки наличия значения */
bool isValue(CmdItem* itemList, char sign,char key);

/* Получение указателя на объект, описывающий ключ  (NULL если ключа нет в массиве)*/
CmdItem* getKeyPointer(CmdItem* itemList, char sign, char key);

/* Получение значения ключа */
char* getKeyValue(CmdItem* itemList, char sign,char key);

/* Вывод на экран текста text и содержимого массива */
void cmdUsage(CmdItem* itemList, char *text);

/* Вывод ошибки по ее коду */
void printError(Error errorCode);

/* Вывод справки на экран */
void printHelp(CmdItem* itemList, char *text);

/* Функция определения последнего элемента */
bool isEmpty(CmdItem* itemList);

#endif // CMD_PARSER_H_INCLUDED
