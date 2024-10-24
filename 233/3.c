#include <stdio.h>
#include <ctype.h>

void encoder(char *p,int n)
{
    char ch;
    for (int i=0;p[i] !='\0';i++)
    {
        ch =p[i];
        if(ch>='A' && ch<='Z')
        {
            p[i]= ((ch-'A'+n)%26) +'A';
        }
        else if(ch >='a' && ch<='z')
        {
            p[i]= ((ch-'a'+n)%26) +'a';
        }
    }
}

int main() {
    char message[100];
    int shift;

    // Input the message
    printf("Enter the message: ");
    scanf("%s", message);

    // Input the shift value
    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Call the encoder function
    encoder(message, shift);

    // Print the encoded message
    printf("Encoded message: %s\n", message);

    return 0;
}