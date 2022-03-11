#include "../includes/minirt.h"

static int	error_handler(int argc, char *argv[])
{
	char	*filename;

	if (argc != 2)
	{
		printf("Error: incorrect args count\n");
		return (0);
	}
	filename = argv[1];
	if (!check_file_extension(filename))
	{
		printf("Error: incorrect file extension\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (!error_handler(argc, argv))
		return (1);
	
	return (0);
}

