#include "parser.h"

int	count_value_line(char **data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data[i])
	{
		if (!is_map_line(data[i]))
		{
			dprintf(2, "in [%s] k++\n", data[i]);
			k++;
		}
		if (is_map_line(data[i]) && k != 6)
		{
			dprintf(2, "k != 6 case\n");
			return (-1);
		}
		i++;
	}
	if (k > 6)
		return (-1);
	return (k);
}
