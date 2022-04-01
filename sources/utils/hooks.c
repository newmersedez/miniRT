/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:39:11 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 15:14:43 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	close_hook(t_minirt *minirt)
{
	success_exit(minirt, "OK");
	return (0);
}

int	keyboard_hook(int keycode, t_minirt *minirt)
{
	if (keycode == 53)
		close_hook(minirt);
	return (0);
}
