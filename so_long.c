#include "so_long.h"
int ft_count_line(char *line)
{
	int i;
	i = 0;
	while (line[i] != '\n' || line[i] != '\0')
		i++;
	return(i);
}
char  *check_wall(char *line)
{
	int i;
	int limit;
	i = 0;
	limit = ft_count_line(line);
	if(line[i]!= '1' && line[limit - 1] != '1' )
		perror("map not valid");
	// return(puts("checks valid"), NULL);

}
int main(int ac, char *argv[])
{
    int fd;
	// char **arr;
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1);
	}
    if((fd = open(argv[1], O_RDONLY)) == -1)
        puts ("fd error");
    char *line = NULL;
	// int count_lines = 0;
	line = get_next_line(fd);
	while (1)
	{
		// printf("%s",line);
		check_wall(line);
		line = get_next_line(fd);
	}
	
}
// int	main()
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx_win);
// }