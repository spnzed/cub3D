/* ************************************************************************** */
/*    */
/*    :::      ::::::::   */
/*   render.c     :+:      :+:    :+:   */
/*    +:+ +:+      +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+      */
/*    +#+#+#+#+#+   +#+   */
/*   Created: 2024/04/24 15:46:35 by aaespino       #+#    #+#      */
/*   Updated: 2024/04/26 15:03:50 by aaronespino      ###   ########.fr       */
/*    */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_key(t_data *info)
{
	if (!info->mlx->mlx)
	{
		printf(RED"Error: MLX\n"RESET);
		exit(1);
	}
	if (info->mlx->keys->W)
		move_front(info);
	if (info->mlx->keys->A)
		move_left(info);
	if (info->mlx->keys->S)
		move_back(info);
	if (info->mlx->keys->D)
		move_right(info);
	if (info->mlx->keys->L_ARR)
		move_l_arrow(info);
	if (info->mlx->keys->R_ARR)
		move_r_arrow(info);
}

void verLine(void *mlx, void *win, int x, int start, int end, t_data *info)
{
  // int y;
  // y = start;
  // while (y <= end)
  // {
  //   mlx_pixel_put(mlx, win, x, y, (color.r << 16) + (color.g << 8) + color.b);
  //   y++;
  // }
}

void rayCasting(t_data *info, void *win, void *mlx)
{
  int     i;

  double  planeX = 0;
  double  planeY = 0.66;
  double  posX = info->player.x;
  double  posY = info->player.y;
  double  dirX = info->player.p_dir_x;
  double  dirY = info->player.p_dir_y;

  double cameraX;
  double rayDirX;
  double rayDirY;

  double deltaDistX;
  double deltaDistY;
  double perpWallDist;

  int stepX;
  double sideDistX;
  int stepY;
  double sideDistY;

  bool hit;

  int side;
  int lineHeight;
  int drawStart;
  int drawEnd;
  
  i = 0;
  while (i < WIDTH) 
  {
    // Calculamos la posición de la cámara en el plano de la proyección (-1 a 1)
    cameraX = 2 * i / (double)WIDTH - 1;
    // Inicializamos la posición y dirección del rayo
    rayDirX = dirX + planeX * cameraX;
    rayDirY = dirY + planeY * cameraX;
    // Longitudes de los rayos en X e Y hasta la próxima celda del mapa
    double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
    double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
    double perpWallDist; // Distancia del rayo al muro

    // Detección de la dirección del rayo en X
    if (rayDirX < 0)
    {
      stepX = -1;
      sideDistX = (posX - posX) * deltaDistX;
    }
    else
    {
      stepX = 1;
      sideDistX = (posX + 1.0 - posX) * deltaDistX;
    }
    // Detección de la dirección del rayo en Y
    if (rayDirY < 0)
    {
      stepY = -1;
      sideDistY = (posY - posY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (posY + 1.0 - posY) * deltaDistY;
    }

    // Bucle para lanzar el rayo y determinar la intersección con el mapa
    while (!hit)
    {
      if (sideDistX < sideDistY)
      {
        sideDistX += deltaDistX;
        posX += stepX;
        side = 0;
      }
      else
      {
        sideDistY += deltaDistY;
        posY += stepY;
        side = 1;
      }
      if (info->map.grid[(int)posX][(int)posY] > 0)
        hit = 1; // Comprobamos si el rayo ha golpeado un muro
    }

    // Calculamos la distancia perpendicular al muro y la altura de la línea a dibujar
    if (side == 0)
      perpWallDist = fabs((posX - posX + (1 - stepX) / 2) / rayDirX);
    else
      perpWallDist = fabs((posY - posY + (1 - stepY) / 2) / rayDirY);
    
    // Calculamos la altura de la línea a dibujar en función de la distancia perpendicular al muro
    lineHeight = abs((int)(HEIGHT / perpWallDist));

    // Calculamos las coordenadas de inicio y fin de la línea a dibujar en la pantalla
    drawStart = -lineHeight / 2 + HEIGHT / 2;
    if (drawStart < 0)
      drawStart = 0;
    drawEnd = lineHeight / 2 + HEIGHT / 2;
    if (drawEnd >= HEIGHT)
      drawEnd = HEIGHT - 1;
    
    // Dibujamos la línea vertical correspondiente al rayo en la pantalla
    verLine(mlx, win, i, drawStart, drawEnd, info);
  }
}

int	render(t_data *info)
{
	handle_key(info);
	ray_casting(info);
	mlx_put_image_to_window(info->mlx->mlx,
		info->mlx->win, info->mlx->img.img, 0, 0);
}
