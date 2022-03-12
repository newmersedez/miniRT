#include "../../includes/parser.h"

static size_t	numberlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	get_int_param(char**line, int *code)
{
	int	value;
	int	negative;

	value = 0;
	negative = 1;
	if (**line == '-')
	{
		negative = -1;
		(*line)++;
	}
	if (!ft_isdigit(**line))
		*code = 1;
	while (**line && ft_isdigit(**line))
	{
		value = value * 10 + (**line - '0');
		(*line)++;
	}
	return (negative * value);
}

double	get_double_param(char **line, int *code)
{
	int		negative;
	double	value;
	double	fract;

	value = 0;
	fract = 0;
	negative = 1;
	if (**line == '-')
	{
		negative = -1;
		(*line)++;
	}
	if (!ft_isdigit(**line))
		*code = 1;
	while (**line && ft_isdigit(**line))
		value = value * 10 + (*((*line)++) - '0');
	if (**line == '.')
	{
		if (!ft_isdigit(*(++(*line))))
			*code = 1;
		while (**line && ft_isdigit(**line))
			fract = fract * 10 + (*((*line)++) - '0');
		value = value + (fract / pow(10, numberlen(fract)));
	}
	return (negative * value);
}

t_color	get_color(char **line, int *code)
{
	t_color	color;

	skip_spaces(line);
	color.r = get_int_param(line, code);
	if (**line != ',' || !(color.r >= 0 && color.r <= 255))
		*code = 1;
	(*line)++;
	color.g = get_int_param(line, code);
	if (**line != ',' || !(color.g >= 0 && color.g <= 255))
		*code = 1;
	(*line)++;
	color.b = get_int_param(line, code);
	skip_spaces(line);
	if (**line != '\0' || !(color.b >= 0 && color.b <= 255))
		*code = 1;
	return (color);
}

t_pos	get_pos(char **line, int *code)
{
	t_pos	pos;
	
	skip_spaces(line);
	pos.x = get_double_param(line, code);
	if (**line != ',')
		*code = 1;
	(*line)++;
	pos.y = get_double_param(line, code);
	if (**line != ',')	
		*code = 1;
	(*line)++;
	pos.z = get_double_param(line, code);
	if (!ft_isspace(**line))
		*code = 1;
	return (pos);
}
