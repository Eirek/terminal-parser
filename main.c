#include <stdio.h>
#include <stdlib.h>

#include "cmd_parser.h"

int main(int argc, char** argv)
{
        CmdItem itemList[] = {
        {
            'h', 0x00000000, NULL, "Print help-text", false
        },
        {
            'a', 0x00000000, NULL, "Append value to file (need value)", true
        },
        {
            'o', 0x00000000, NULL, "Open file (need value)", true
        },
        {
            'p', 0x00000000, NULL, "Print current file to console", false
        },
        {
            0, 0, NULL, NULL, false
        }

    };

    int err = cmdParse(itemList, argc, argv);
    //printError(err);

    
    //Чтобы программа завершалась при ошибке, можно удалить  и раскомментировать строку выше
    if (err != Ok) {

        printError(err);
        return 0;
    }

    if(isKey(itemList, 'h')) {
        cmdUsage(itemList,argv[0]);
    }

    if(isKey(itemList, 'p')) {
        printf("Print file: \n");
    }

    if(isValue(itemList, 'o')) {
        printf("Opening file: %s\n", getKeyValue(itemList, 'o'));
    }


    if(isValue(itemList, 'a')) {
        printf("Appending values to file: %s\n", getKeyValue(itemList, 'a'));
    }

    return 0;
}
