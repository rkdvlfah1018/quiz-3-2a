#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    struct stat st;

    if (argc != 2)
        printf("usage: ls directory_name");
    if ((dp = opendir(argv[1])) == NULL)
        printf("can’t open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL){
        stat(dirp->d_name, &st);
        printf("File name: %s\n", dirp->d_name);
        printf("inode number: %li\n", st.st_ino);
        printf("number of links: %li\n", st.st_nlink);
        printf("User ID of owner: %i\n", st.st_uid);
        printf("Group ID of owner: %i\n", st.st_gid);
        printf("Size in bytes: %li bytes\n", st.st_size);
        printf("Last access: %s", ctime(&st.st_atime));
        printf("Last modification: %s", ctime(&st.st_mtime));
        printf("Last status change: %s", ctime(&st.st_ctime));
        printf("Number of disk blocks allocated: %li\n", st.st_blocks);
        printf("Access mode in octal: %o\n", st.st_mode);
        printf("Access mode flags: ");
        if(S_ISDIR(st.st_mode)){
            printf("d");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IRUSR){
            printf("r");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IWUSR){
            printf("w");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IXUSR){
            printf("x");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IRGRP){
            printf("r");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IWGRP){
            printf("w");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IXGRP){
            printf("x");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IROTH){
            printf("r");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IWOTH){
            printf("w");
        }else{
            printf("-");
        }
        if(st.st_mode & S_IXOTH){
            printf("x");
        }else{
            printf("-");
        }
        printf("\n");
        printf("\n");
    }
    closedir(dp);
    exit(0);
}