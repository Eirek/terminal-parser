#include "cmd_parser.h"

/* Функция парсинга строки, возвращает ошибку из структуры Error */
Error cmdParse(CmdItem* itemList, int argc, char** argv) {

    for (size_t i = 1; i < argc; i++) {

        if (strlen(argv[i]) < 2)
        return UnknownKey;
     
            char sign = argv[i][0];

            for (size_t j = 1; argv[i][j] != '\0'; j++) {

                CmdItem* opt = getKeyPointer(itemList, sign, argv[i][j]);

                if(opt == NULL)
                    return UnknownKey;

                if(opt->needValue == false) {
                    opt->mask |= KEY_IN_CMD;
                }

                if (opt != NULL && opt->needValue == true) {
                    opt->mask |= VAL_IN_CMD;
                    if (strlen(argv[i]) > 2)
                        return ErrorParse;
                    if(argv[i + 1] == NULL)
                        return KeyNeedValue;
                 
                    opt->value = argv[i +1];
                    ++i;
                    break;
                }                
            }
    }
    return Ok;

}

/* Функция проверки наличия ключа */
bool isKey(CmdItem* itemList, char sign, char key) {
    int i = 0;
    while (!isEmpty(&itemList[i])) {
        if((itemList[i].sign == sign) && (itemList[i].key == key) && (itemList[i].mask != 0))
            return true;
            i++;
    }
    return false;
}


/* Получение указателя на объект, описывающий ключ  (NULL если ключа нет в массиве)*/
CmdItem* getKeyPointer(CmdItem* itemList, char sign, char key){
  for(size_t i = 0; isEmpty(&itemList[i]) != true; i++) {
      if ((itemList[i].sign == sign) && (itemList[i].key == key)) {
          return itemList + i;         
      }
  }
  return NULL;
}

/* Получение значения ключа */
char* getKeyValue(CmdItem* itemList, char sign, char key){
    int i = 0;
    while (!isEmpty(&itemList[i])) {
        if ((itemList[i].sign == sign) && (itemList[i].key == key) && (itemList[i].needValue == true)) 
            return itemList[i].value;
            i++;
        }
    return NULL;
}

/* Печать справки */
void printHelp(CmdItem* itemList, char *text){
    printf("Usage: %s [key] [value] Example: [-p -a file.txt]\n\n", text);
    printf("Keys:\n");
    for(size_t i = 0; isEmpty(&itemList[i]) != true; i++)
      printf("%c%c\t %s\n", itemList[i].sign, itemList[i].key, itemList[i].usage);
  
}

/* Вывод ошибки по ее коду */
void printError(Error errorCode){
  switch (errorCode)
  {
      case UnknownKey:
          printf("Error: Unknown key\n");
          break;

      case KeyNeedValue:
          printf("Error: Key need value\n");
          break;

	  case ErrorParse:
		  printf("Error: Can't parse line. \n");
		  break;

      default:
          break;
  }
}

/* Вывод на экран текста text и содержимого массива */
void cmdUsage(CmdItem* itemList, char *text) {
    printf("%s\n", text);
    printf("%-11s%-19s%-20s%-20s%-20s\n", "Key", "Mask", "Need Value", "Value", "Usage");

    for(size_t i = 0; isEmpty(&itemList[i]) != true; i++){
        printf("%c%c  \t%#010x  \t%13s  \t%15s  \t%s\n",
               itemList[i].sign,
               itemList[i].key,
               itemList[i].mask,
               itemList[i].needValue ? "true" : "false", 
               itemList[i].value,
               itemList[i].usage);
    }
}
/* Функция определения последнего элемента */
bool isEmpty(CmdItem* itemList) {
    if ((itemList->sign == 0) &&
		(itemList->key == 0) &&
        (itemList->mask == 0) &&
        (itemList->value == NULL) &&
        (itemList->usage == NULL) &&
        (itemList->needValue == false)) {
        return true;
    }
    return false;
}
