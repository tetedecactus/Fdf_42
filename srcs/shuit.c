#include "../mlx_mac/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/time.h>
#include <unistd.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1000
#define screenHeight 1000

#define RGB_Red 16711680
#define RGB_Green 65280
#define RGB_Blue 255
#define RGB_White 16777215
#define RGB_Yellow 16776960

#define KEY_W 0x0D
#define KEY_A 0x00
#define KEY_S 0x01
#define KEY_D 0x02
#define ESC_BUTTON 53

typedef struct s_vec3 {
	double x;
	double y;
}	t_vec3;

typedef struct s_ray {
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_lode {
	void *mlx;
	void *win;
	t_img *img[2];

	double posX, posY;  //x and y start position
	double dirX, dirY; //initial direction vector
	double planeX, planeY; //the 2d raycaster version of camera plane
	long int time; //time of current frame
	double oldTime; //time of previous frame

	bool key_W;
	bool key_A;
	bool key_S;
	bool key_D;

	double playerAngle;
}	t_lode;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// int	create_trgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

long int	get_time(void)
{
	struct timeval	tv;
	long int		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	close_win(t_lode *lode)
{
	free (lode->img[0]);
	free (lode->img[1]);
	mlx_destroy_window(lode->mlx, lode->win);
	exit (0);
	return (0);
}

int	deal_key(int key, t_lode *lode)
{
	if (key == ESC_BUTTON)
		close_win(lode);
	if (key == KEY_W)
		lode->key_W = true;
	if (key == KEY_A)
		lode->key_A = true;
	if (key == KEY_S)
		lode->key_S = true;
	if (key == KEY_D)
		lode->key_D = true;
	return (0);
}

int key_up(int key, t_lode *lode)
{
	if (key == KEY_W)
		lode->key_W = false;
	if (key == KEY_A)
		lode->key_A = false;
	if (key == KEY_S)
		lode->key_S = false;
	if (key == KEY_D)
		lode->key_D = false;
	return (0);
}

t_img	*new_image(t_lode *lode)
{
	t_img	*img;

	img = calloc(1, sizeof(t_img));
	img->img = mlx_new_image(lode->mlx, screenWidth, screenHeight);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	return (img);
}

void	swap_maps(t_lode *lode)
{
	t_img *tmp;

	tmp = lode->img[0];
	lode->img[0] = lode->img[1];
	lode->img[1] = tmp;
}

int loop(t_lode *lode)
{
	//timing for input and FPS counter
	// long int oldTime = lode->time;
	// lode->time = get_time();
	// double frameTime = (lode->time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds

	//speed modifiers
	double moveSpeed = 0.1;//frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = 0.05; //frameTime * 3.0; //the constant value is in radians/second
	// double modifier = ((double)screenHeight * (double)screenWidth) / 1000000.0;

	//move forward if no wall in front of you
    if (lode->key_W)
    {
    	if(worldMap[(int)(lode->posX + lode->dirX * moveSpeed)][(int)(lode->posY)] == false) lode->posX += lode->dirX * moveSpeed;
    	if(worldMap[(int)(lode->posX)][(int)(lode->posY + lode->dirY * moveSpeed)] == false) lode->posY += lode->dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (lode->key_S)
    {
    	if(worldMap[(int)(lode->posX - lode->dirX * moveSpeed)][(int)(lode->posY)] == false) lode->posX -= lode->dirX * moveSpeed;
    	if(worldMap[(int)(lode->posX)][(int)(lode->posY - lode->dirY * moveSpeed)] == false) lode->posY -= lode->dirY * moveSpeed;
    }
    //rotate to the right
    if (lode->key_D)
    {
    	//both camera direction and camera plane must be rotated
    	double oldDirX = lode->dirX;
    	lode->dirX = lode->dirX * cos(-rotSpeed) - lode->dirY * sin(-rotSpeed);
    	lode->dirY = oldDirX * sin(-rotSpeed) + lode->dirY * cos(-rotSpeed);
		// lode->playerAngle += 8 * modifier;
		// if (lode->playerAngle >= 360.0)
		// 	lode->playerAngle -= 360.0;
    	double oldPlaneX = lode->planeX;
    	lode->planeX = lode->planeX * cos(-rotSpeed) - lode->planeY * sin(-rotSpeed);
    	lode->planeY = oldPlaneX * sin(-rotSpeed) + lode->planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (lode->key_A)
    {
    	//both camera direction and camera plane must be rotated
    	double oldDirX = lode->dirX;
    	lode->dirX = lode->dirX * cos(rotSpeed) - lode->dirY * sin(rotSpeed);
    	lode->dirY = oldDirX * sin(rotSpeed) + lode->dirY * cos(rotSpeed);
		// lode->playerAngle += -8 * modifier;
		// if (lode->playerAngle < 0.0)
		// 	lode->playerAngle += 360.0;
    	double oldPlaneX = lode->planeX;
    	lode->planeX = lode->planeX * cos(rotSpeed) - lode->planeY * sin(rotSpeed);
    	lode->planeY = oldPlaneX * sin(rotSpeed) + lode->planeY * cos(rotSpeed);
    }
	
	int w = screenWidth;
	int h = screenHeight;
	for(int x = 0; x < w; x++)
    {
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space // 2 * 0 / 1000 - 1 = -1
		double rayDirX = lode->dirX + lode->planeX * cameraX; // = -1
		double rayDirY = lode->dirY + lode->planeY * cameraX; // = -0.66

		//which box of the map we're in
		int mapX = (int)lode->posX; // 22
		int mapY = (int)lode->posY; // 12

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? INFINITY : fabs(1 / rayDirX); // = 1.0
		double deltaDistY = (rayDirY == 0) ? INFINITY : fabs(1 / rayDirY); // = 0.66
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (lode->posX - mapX) * deltaDistX; // = 0
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - lode->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (lode->posY - mapY) * deltaDistY; // = 0
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - lode->posY) * deltaDistY;
		}

		// perform DDA or "Digital Differential Analysis"
		
		// DDA is a fast algorithm typically used on square grids to find
		// which squares a line hits (for example to draw a line on a screen,
		// which is a grid of square pixels). So we can also use it to find
		// which squares of the map our ray hits, and stop the algorithm once
		// a square that is a wall is hit.
		
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0) 
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;

		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;

		//choose wall color
		int color;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RGB_Red;  break; //red
			case 2:  color = RGB_Green;  break; //green
			case 3:  color = RGB_Blue;   break; //blue
			case 4:  color = RGB_White;  break; //white
			default: color = RGB_Yellow; break; //yellow
		}

		// give x and y sides different brightness
		// if (side == 1)
		// 	color = color / 2;

		//draw the pixels of the stripe as a vertical line
		int i = drawStart;
		while (i++ < drawEnd)
			my_mlx_pixel_put(lode->img[1], x, i, color);
	}

	// Draw minimap
	int minmapSize = (int)(screenHeight * 0.25) / mapHeight;

	for (int x = 0; x < minmapSize * mapHeight + 10; x++)
	for (int y = 0; y < minmapSize * mapWidth + 10; y++)
		my_mlx_pixel_put(lode->img[1], y, x, 153);

	for (int x = 0; x < mapHeight; x++)
	for (int y = 0; y < mapWidth; y++){
		for (int i = 0; i < minmapSize; i++)
		for (int j = 0; j < minmapSize; j++){
			if (worldMap[y][x])
				my_mlx_pixel_put(lode->img[1], 5 + (x * minmapSize) + i, 5 + (y * minmapSize) + j, 0);
			else
				my_mlx_pixel_put(lode->img[1], 5 + (x * minmapSize) + i, 5 + (y * minmapSize) + j, RGB_White);
		}
	}

	int posPlayerX = 5 + (int)(lode->posX * minmapSize) - 3;
	int posPlayerY = 5 + (int)(lode->posY * minmapSize) - 3;

	for (int x = 0; x < 7; x++)
	for (int y = 0; y < 7; y++)
		my_mlx_pixel_put(lode->img[1], posPlayerY + y, posPlayerX + x, RGB_Red);

	t_ray ray;
	ray.origin.x = lode->posX;
	ray.origin.y = lode->posY;
	ray.direction.x = lode->dirX;
	ray.direction.y = lode->dirY;

	swap_maps(lode);
	mlx_put_image_to_window(lode->mlx, lode->win, lode->img[0]->img, 0, 0);
	
	free (lode->img[1]);
	lode->img[1] = new_image(lode);

	return 0;
}

int main()
{	
	t_lode lode;

	lode.key_W = false;
	lode.key_A = false;
	lode.key_S = false;
	lode.key_D = false;
	
	lode.posX = 22;
	lode.posY = 12;
	lode.dirX = -1;
	lode.dirY = 0;
	lode.planeX = 0;
	lode.planeY = 0.66;
	lode.playerAngle = 0;

	lode.time = 0;
	lode.oldTime = 0;

	lode.mlx = mlx_init();
	lode.win = mlx_new_window(lode.mlx, screenWidth, screenHeight, "Raycaster");

	lode.img[0] = new_image(&lode);
	lode.img[1] = new_image(&lode);

	mlx_hook(lode.win, 02, 1L << 0, deal_key, &lode);
	mlx_hook(lode.win, 03, 1L << 1, key_up, &lode);
	mlx_hook(lode.win, 17, 1L << 17, close_win, &lode);
	mlx_loop_hook(lode.mlx, loop, &lode);
	mlx_loop(lode.mlx);
}

//	Convert angle (0 to 359) to radians
// double	deg_to_rad(double angle)
// {
// 	return (angle * M_PI / 180.0);
// }

// t_pos	move_pos(t_pos pos, double rot, double dist, int dir)
// {
// 	t_pos	new_pos;

// 	if (dir)
// 		rot += 90;
// 	new_pos.x = pos.x + dist * cos(deg_to_rad(rot));
// 	new_pos.y = pos.y + dist * -sin(deg_to_rad(rot));
// 	new_pos.z = pos.z + 0;
// 	return (new_pos);
// }

// // Literally draw a raycast on the mlx image. Use for minimap.
// int	raycast_draw(double rot, double dist, int color, int side)
// {
// 	t_pos	facing;
// 	t_pos	r_p;
// 	int		i;
// 	int		trans;
// 	t_img	img;

// 	img = g_game.game_img;
// 	trans = FALSE;
// 	if (color == WHITE)
// 		trans = TRUE;
// 	facing.x = g_game.player.pos.x / (TILE_SIZE / MINI_TILE_S);
// 	facing.y = g_game.player.pos.y / (TILE_SIZE / MINI_TILE_S);
// 	i = 0;
// 	r_p = new_pos(facing.x, facing.y, facing.z);
// 	while (i++ < dist && i < 800)
// 	{
// 		if (trans == TRUE)
// 			color = color_shift_int(color_get(img, r_p.x, r_p.y), WHITE, 0.03);
// 		my_mlx_pixel_put(img, r_p.x, r_p.y, color);
// 		r_p = move_pos(r_p, rot, side, 0);
// 	}
// 	return (1);
// }

// void	draw_player(void)
// {
// 	double	i;

// 	i = -(60 / 2);
// 	while (i <= 60 / 2)
// 	{
// 		raycast_draw(g_game.player.rot - i, 10, RED, -1);
// 		raycast_draw(g_game.player.rot - i, 30, WHITE, 1);
// 		i += 0.25;
// 	}
// }