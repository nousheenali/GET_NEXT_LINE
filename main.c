int	main(void)
{
	char	*buff;
	int		fd1;
    int     fd2;
    int     fd3;

    fd1 = open("file1", O_RDONLY);
	if (fd1 == -1)
		printf("unable to open file\n");
    fd2 = open("file2", O_RDONLY);
	if (fd2 == -1)
		printf("unable to open file2\n");
    fd3 = open("file3", O_RDONLY);
	if (fd1 == -1)
		printf("unable to open file3\n");
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
        buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd1);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd2);
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd3);
		printf("%s", buff);
		free(buff);
		// close(fd);
		
	return (0);
}
