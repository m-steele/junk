#define _POSIX_C_SOURCE 200809L // For PATH_MAX and other POSIX features
#include <stdio.h>
#include <unistd.h> /* access() */
#include <fcntl.h>  /* Not strictly needed for this example, but often for open() */
#include <sys/types.h>
#include <sys/wait.h> /* waitpid() */
#include <errno.h>    /* errno, strerror */
#include <stdlib.h>   /* getenv, strdup, free */
#include <string.h>   /* strtok, strcmp, snprintf, strlen */
#include <dirent.h>   /* opendir, readdir, closedir, struct dirent */
#include <sys/stat.h> /* stat, S_ISREG */
#include <limits.h>   /* PATH_MAX (recommended for full_path buffer) */

/*Check if the pathname is accessable by the call, if yes return 0*/
/*mode = F_OK | R_OK | W_OK | X_OK*/
// int access(const char *pathname, int mode);
// int	main()
// {
// 	if (access("outfile", R_OK) == -1)
// 		return (printf("outfile is NOT readable\n"), 0);
// 	if (access("outfile", W_OK) == -1)
// 		return (printf("outfile is NOT writeable\n"), 0);
// 	if (access("outfile", X_OK) == -1)
// 		return (printf("outfile is NOT executable\n"), 0);
// }

/*duplicates a fd*/
// int dup2(int oldfd, int newfd);
/*the man suggests protecting against errors that can occur if newfd is out
of range. They suggests:*/
// if (dup2(oldfd, nefd) == -1)
// {
// 	/*handle error .... can we just go: return (0); ???*/;
// }

int main(int ac, char **av, char **env)
{
	(void) ac; // Unused
	(void) av; // Unused
    (void) env; // env is not directly used here as getenv is preferred for PATH

	printf("THIS IS THE ENVIRONMENT (first few lines via direct env access):\\n");
	while (*env != NULL)
		printf("%s\n", *env++);
	return (0);
}



/*THIS IS THE TOY MAIN*/
// int main(int ac, char *av[], char *env[])
// {
// 	(void) ac;
// 	(void) av;
// 	// int in;
// 	// int out;
// 	// in = open ("words", O_RDONLY);
// 	// out = open ("outfile", O_WRONLY);
// 	// execve("/usr/bin/grep", grep_args, env);
// 	// perror("execve failed");

// 	int pipefd[2];
// 	int pid ;
// 	char *grep_args[] = {"/usr/bin/grep", "live", NULL};
// 	char *cat_args[] = {"/bin/cat", "infile", NULL};

// 	pipe(pipefd);
// 	if (pid == 0)
// 	{
// 		dup2(pipefd[0], 0);
// 		close(pipefd[1]);
// 		execve("usr/bin/grep", grep_args, env);
// 	}
// 	else
// 	{
// 		dup2(pipefd[1], 1);
// 		close(pipefd[0]);
// 		execve("/bin/cat", cat_args, env);
// 	}
// 	close(pipefd[0]);
// 	close(pipefd[1]);

// 	waitpid(pid, 0, 0);
// }


// /*Just some working junk*/
// int main(int ac, char **av, char **env)
// {
// 	int	file1;
// 	int	file2;

// 	if (access(file1, R_OK | W_OK) == 0)
// 	{
// 		if (ac = 5)
// 		{
// 			file1 = open(av[1], 1, O_RDONLY);
// 			file2 = open(av[4], 1, O_WRONLY);
// 		}
// 		return (errno); /*this might be problematic using errno here but OK for this context*/
// 	}
// }

// int	find_limit(int len)
// {
// 	int	limit;

// 	limit = 0;
// 	while ((len / 2) != 0)
// 	{
// 		limit++;
// 		len = len / 2;
// 	}
// 	return (limit);
// }

// int main()
// {
// 	int n = 20;

// 	printf("Starting n: %d\nReturned Limit: %d\n", n, find_limit(n));
// 	return (0);
// }















/*This might be useful for extracting external SHELL commands: 'ls' 'cat'
but not internal ones such as 'echo' 'cd'*/

// // Function to list executable commands found in PATH
// void list_commands_in_path() {
//     char *path_env_var;
//     char *path_copy = NULL; // Initialize to NULL
//     char *dir_token;

//     path_env_var = getenv("PATH");
//     if (path_env_var == NULL) {
//         printf("PATH environment variable not found.\\n");
//         return;
//     }

//     // strdup allocates memory, which must be freed.
//     path_copy = strdup(path_env_var);
//     if (path_copy == NULL) {
//         perror("Failed to duplicate PATH string");
//         return;
//     }

//     printf("Searching for executable commands in PATH directories:\\n");
//     dir_token = strtok(path_copy, ":");

//     while (dir_token != NULL) {
//         DIR *dir_stream = opendir(dir_token);
//         if (dir_stream == NULL) {
//             // Non-fatal: just means we can't access this particular directory in PATH
//             // fprintf(stderr, "Warning: Could not open PATH directory '%s': %s\\n", dir_token, strerror(errno));
//             dir_token = strtok(NULL, ":");
//             continue;
//         }

//         struct dirent *entry;
//         while ((entry = readdir(dir_stream)) != NULL) {
//             // Skip current directory "." and parent directory ".." entries
//             if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
//                 continue;
//             }

//             // Construct the full path to the file.
//             char full_path[PATH_MAX + 1]; // +1 for null terminator, PATH_MAX should account for it but defensive
            
//             int len_written = snprintf(full_path, sizeof(full_path), "%s/%s", dir_token, entry->d_name);

//             if (len_written < 0 || (size_t)len_written >= sizeof(full_path)) {
//                 fprintf(stderr, "Error: Path too long or snprintf error for %s/%s\\n", dir_token, entry->d_name);
//                 continue; // Skip this entry
//             }

//             struct stat st;
//             // Use lstat if you want to check symlinks themselves, stat follows symlinks.
//             // For finding commands, stat (following symlinks) is usually what's desired.
//             if (stat(full_path, &st) == 0) {
//                 // Check if it's a regular file and if the current process has execute permission.
//                 if (S_ISREG(st.st_mode) && access(full_path, X_OK) == 0) {
//                     printf("  Found: %s (in %s)\\n", entry->d_name, dir_token);
//                 }
//             } else {
//                 // Optional: Log stat errors, but can be noisy for broken symlinks etc.
//                 // fprintf(stderr, "Warning: stat failed for '%s': %s\\n", full_path, strerror(errno));
//             }
//         }
//         closedir(dir_stream);
//         dir_token = strtok(NULL, ":");
//     }

//     free(path_copy); // Free the memory allocated by strdup
// }

// int main(int ac, char **av, char **env)
// {
// 	(void) ac; // Unused
// 	(void) av; // Unused
//     (void) env; // env is not directly used here as getenv is preferred for PATH

// 	printf("THIS IS THE ENVIRONMENT (first few lines via direct env access):\\n");
//     if (env) { // Check if env is not NULL, though it rarely is for main
//         for (int i = 0; env[i] != NULL && i < 5; ++i) { // Print first 5 for brevity
//             printf("%s\\n", env[i]);
//         }
//         if (env[5] != NULL) printf("...and more.\\n");
//     }
//     printf("\\n");

//     list_commands_in_path();

// 	return (0);
// }
