#include <string.h>
#include <stdio.h>

// int main() {
//     char str1[] = "Nakul";
//     char str2[] = "Verma";

//     // Copy str1 to str2
//     // strcat(str2, str1);

//     // strcpy(str2, str1);
//     strncpy(str2, str1, 3);

//     // Print the copied string
//     printf("Copied string: %s\n", str2);

//     return 0;
// }

int main()
{
    char str1[] = "My first name is Nakul and last name is Verma";
    
    char *res = strrchr(str1, 'n');
     printf("last name found in line: %ld index \n", res - str1);
    // printf("Substring found: %s\n", strstr(str1, "name"));
}