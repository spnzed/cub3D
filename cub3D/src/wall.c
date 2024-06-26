/* ************************************************************************** */
/*				*/
/*					:::	  ::::::::   */
/*   wall.c					 :+:	  :+:	:+:   */
/*				+:+ +:+		 +:+	 */
/*   By: aaronespinosa <aaronespinosa@student.42	+#+  +:+	   +#+		*/
/*			+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/25 19:29:32 by aaronespino	   #+#	#+#			 */
/*   Updated: 2024/06/26 00:22:21 by aaronespino	  ###   ########.fr	   */
/*				*/
/* ************************************************************************** */

#include "cub3D.h"

float	remove_fish(int player_dir, int ray_ang, int ray_len)
{
	int		rem_fish;
	float	distance;

	rem_fish = player_dir - ray_ang;
	distance = ray_len * cos(deg_to_rad(rem_fish));
	return (distance);
}

t_img	ret_text(t_data *info, int i)
{
	if (info->ray[i].wall_or == 'N')
		return (info->mlx->north);
	else if (info->ray[i].wall_or == 'S')
		return (info->mlx->south);
	else if (info->ray[i].wall_or == 'W')
		return (info->mlx->west);
	return (info->mlx->east);
}

void	draw_text(t_data *info, int offset, int height, int i)
{
	int		y_end;
	int		j;
	int		*scr;
	t_img	texture;
	t_dtext	tex;

	if (offset + height >= HEIGHT)
		y_end = HEIGHT;
	else
		y_end = offset + height;
	tex.tex_x = info->ray[i].text_p;
	texture = ret_text(info, i);
	scr = info->mlx->img.img_adr;
	j = 0;
	while (j < y_end)
	{
		tex.tex_y = ((float)(j - offset) / (float)height) * texture.height;
		tex.tex_pixel = ((int)tex.tex_y * texture.width + (int)tex.tex_x);
		if (tex.tex_x >= 0 && tex.tex_x < texture.width && tex.tex_y >= 0 \
			&& tex.tex_y < texture.height)
			scr[j * WIDTH + i] = texture.img_adr[tex.tex_pixel];
		j++;
	}
}

static void	draw_wallcol(t_data *info, int ang, int i)
{
	float	distance;
	int		height;
	int		off;

	distance = remove_fish(info->player.dir, ang, info->ray[i].len);
	height = (SCALE * HEIGHT) / (distance);
	off = (HEIGHT / 2) - (height / 2);
	draw_text(info, off, height, i);
}

void	draw_walls(t_data *info)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_wallcol(info, info->ray[i].ang, i);
		i++;
	}
}
