#include <stdio.h>
void removeSpecialCharacters(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
            str[i] = ' ';
        }
    }
}

char  ch(char a)
{
    if(a >= 'A' && a<= 'Z')
    {
        return 'Z'-(a -'A');
    }
    else if (a >= 'a' && a <= 'z') {
        return 'z' - (a - 'a');
    }
    return a;
}

void engg(char *p)
{
    for(int i=0;p[i]!='\0';i++)
    {
        if(p[i]!=' ')
        {
            p[i] = ch(p[i]);
        }
    }
}

int main() {
    char input[100]; 

    
    fgets(input, sizeof(input), stdin);

    removeSpecialCharacters(input);
    engg(input);

    
    printf("Encoded message: %s\n", input);

    return 0;
}