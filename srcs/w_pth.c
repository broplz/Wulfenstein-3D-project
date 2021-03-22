#include "../include/cub3d.h"

char 	*w_pth(int *flag, char **line, int *pflag)
{
	int	len;

	if (*flag == 1)
		return (ft_get_null(flag, pflag));
	len = ft_strlen(*line);
	if (line[0][0] == 'S' && line[0][1] != ' ' && line[0][1] != 'O')
		return (ft_get_null(flag, pflag));
	else if (line[0][0] != 'S' && line[0][1] != ' ' && line[0][2] != ' ')
		return (ft_get_null(flag, pflag));
	if (line[0][len - 1] == ' ')
		len--;
	if (line[0][--len] != 'm' || line[0][--len] != 'p' ||
		line[0][--len] != 'x' || line[0][--len] != '.' ||
		ft_isalnum(line[0][--len]) != 1)
		return (ft_get_null(flag, pflag));
	if (line[0][0] == 'S' && line[0][1] == ' ')
		(*line) += 2;
	else
		(*line) += 3;
	if (ft_path_check(*line) < 0)
		return (ft_get_null(flag, pflag));
	return (*line + ((*flag = 1) - 1));
}
