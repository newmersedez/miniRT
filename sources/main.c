#include "../includes/minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt_info;
	char		*filename;

	(void)minirt_info;
	if (!check_start_errors(argc, argv))
		return (1);
	filename = argv[1];
	if (!parse_info_from_file(filename))
		return (1);
	return (0);
}

