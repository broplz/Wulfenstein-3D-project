#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_all	all;
	int		fd;

	MAP = NULL;
	PAR = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		ft_error_close("No argument with params and map");
	ft_init_all(&all);
	ft_main_parser(&all, fd, argc, PAR, MAP);
	for (int i = 0; i < all.map.lst_size; i++)
	{
		for (int j = 0; j < all.map.len; j++)
		{
			printf("%c", WORLDMAP[i][j]);
		}
		printf("\n");
	}
	ft_free_all(&all, NULL, NULL);
// TODO изменить размеры принимаемого разрешения на лонг и в случае если разрешение больше максимального скрина
//  использовать максимальное разрешение скрина mlx_get_screen_size
// TODO изменить точки выхода из программы и оптимизировать работу с возвратами и ошибками
	return (0);
}