#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
// Wildcard Logic
// --------------
    int size = strlen(argv[1]);
    char before[64];
    char after[64];

    
     for(int i = 0; i < size; i++) {
        if(argv[1][i] == '*') {
            // Copy characters before the asterisk into before array
            strncpy(before, argv[1], i);
            before[i] = '\0'; // Null-terminate the string

            // Copy characters after the asterisk into after array
                strcpy(after, argv[1] + i + 1);
        }
    }

    printf("%s\n%s\n", before, after);

    int before_size = strlen(before);
    int after_size = strlen(after);

    char buf[5000];
    ssize_t buf_size = sizeof(buf);
    DIR *dir = opendir(getcwd(buf, buf_size));
    if(dir == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }
    struct dirent *entry;
    struct stat sbuf;
    char correct_files[1000];
    while ((entry = readdir(dir)) != NULL)
    {
        char file[64];
        strcpy(file, entry->d_name);
        int file_size = strlen(file);

        if(strncmp(before, file, before_size) == 0)
        {
            if(strncmp(after, file + strlen(file) - after_size, after_size) == 0)
            {
                printf("%s\n", file);
            }   
        }     
        
    }

    closedir(dir);


    return EXIT_SUCCESS;
}