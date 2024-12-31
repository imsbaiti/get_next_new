// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include "get_next_line.h"
// int main()
// {
//     int fd = open("file.txt",  O_RDONLY );
//     if (fd < 0)
//         return (write(2, "KO\n", 3), 1);
//     char *line;
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s",line);
//         free(line);
//     }
//     close(fd);
// }
// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>
// #include <limits.h>

// int main()
// {
//     int fd = open("T.txt", O_RDWR);
//     int fd0 = open("H.txt", O_RDWR);
//     char *line = get_next_line(fd);
//     int i = 0;
//     while (line)
//     {
//         printf("Line %d for fd %d : %s", i, fd, line);
//         free(line);
//         line = get_next_line(fd);
//         i++;
//     }
//     i = 0;
//     line = get_next_line(fd0);
//     while (line)
//     {
//         printf("Line %d for fd %d : %s", i, fd0, line);
//         free(line);
//         line = get_next_line(fd0);
//         i++;
//     }
// }

    // close (fd);
    // int fd = open("Y.txt", O_CREAT | O_WRONLY, 0777);
    // write(fd, "HMSTR\n", 6);
    // close(fd);

    // fd = open("Y.txt", O_RDONLY);
    // char *line = get_next_line(fd);
    // printf("%s", line);
    // free(line);
    // close(fd);
    // int fd = open("s.txt", O_RDONLY);
    // char *line = get_next_line(fd);
    // while(line )
    // {
    //     printf("the first line %s",line);
    //     free(line);
    //     line = get_next_line(fd);
    // }

//     int fd = open("s.txt", O_RDONLY);  // Open the file in read-only mode
//     // if (fd == -1)  // Check if the file was opened successfully
//     // {
//     //     perror("Error opening file");
//     //     return 1;  // Return an error code if the file can't be opened
//     // }

//     char *line;
//     char *last_line = NULL;  // To store the last line

    // Read through the file line by line
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         if (last_line)  // Free the previous line
//             free(last_line);
        
//         last_line = line;  // Keep the current line as the last one
//     }

    // After reading the file, print the last line if it exists
//     if (last_line)
//     {
//         printf("Last line: %s", last_line);  // Print the last line
//         free(last_line);  // Free the allocated memory for the last line
//     }
    // else
    // {
    //     printf("Error or no lines to read.\n");
    // }

//     close(fd);  // Close the file descriptor
//     return 0;  // Return success
// }
// int fd = open("s.txt",O_RDONLY);
// char *line;
// char *last_line;
// while((line = get_next_line(fd)))
// {
//     if(last_line)
//         free(last_line);
//     last_line = line;
// }
// if(last_line)
// {
//     printf("the last line : %s\n",last_line);
//     free(last_line);
// }
//}
// #include "get_next_line_bonus.h"
// int main(void)
// {
//     int fd1 = open("test1.txt", O_RDONLY);
//     int fd2 = open("test2.txt", O_RDONLY);
//     int fd3 = open("test3.txt", O_RDONLY);

//     char    *line1, *line2, *line3;
//     while(1)
//     {
//         line1 = get_next_line(fd1);
//         if (line1)
//         {
//             printf("%s", line1);
//             free(line1);
//         }
//         line2 = get_next_line(fd2);
//         if (line2)
//         {
//             printf("%s", line2);
//             free(line2);
//         }
//         line3 = get_next_line(fd3);
//         if (line3)
//         {
//             printf("%s", line3);
//             free(line3);
//         }
//         if (!line1 && !line2 && !line3)
//             break ;
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }
// #include "get_next_line.h"
// #include <stdio.h>
// #include<unistd.h>
// #include <stdlib.h>
// #include <fcntl.h>
// // void f()
// // {
// //     system("leaks a.out");
// // }
// int main()
// {
//     // atexit(f);

//     int fd = open("g.txt",O_RDONLY);
//     if (fd < 0)
//         return(-1);
//     char *line;
//     line = get_next_line(42);
//     printf("%s\n",line);
//     // char *last_line = NULL;
//     // while((line = get_next_line(42)))
//     // {
//     //     if(last_line)
//     //         free(last_line);
//     //     last_line = line;
//     // }
//     // if(last_line)
//     // {
//     //     printf("last line --> %s\n",last_line);
//     //     free(last_line);

//     // }
//     close(fd);
//     return (0);
// }