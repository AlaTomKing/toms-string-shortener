#include <stdio.h>
#include <string.h>

#define TSS

#define TSS_OP_INDEX 0x00
#define TSS_OP_DIFF 0x40
#define TSS_OP_LUMA 0x80
#define TSS_OP_RUN 0xc0
#define TSS_OP_CHAR 0xff

#define MAX_CHARACTERS ((unsigned int)2000000000)

char *shortenString(char *text)
{
    if (strlen(text) >= MAX_CHARACTERS) {
        printf("Tom's String Shortener: sorry bud. too much characters to handle for me. if u get this message, why are you using so many characters?");
        return NULL;
    }

    int run = 0;
    int p = 0;
    int text_length = strlen(text);

    unsigned char *characters = (unsigned char *)text_length;

    char previous_char = 'a';
    for (int current_pos = 0; current_pos < text_length; current_pos++)
    {
        char current_char = text[current_pos];
        //printf("hex: %x\n");

        if (current_char == previous_char)
        {
            run++;
            if (run == 62 || current_pos == text_length)
            {
                characters[p++] = TSS_OP_RUN | (run - 1);
                run = 0;
            }
        }

        previous_char = current_char;
    }

    printf("\nsize: %d\n", strlen(text));

    return text;
}

char *deShortenString(char *shortedText)
{
}