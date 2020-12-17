#include "minirt.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main()
{
	t_data data;
	int x = 0;
	int y = 0;

	initialized_win("minirt");
	open_window();
	data.img = mlx_new_image(g_window.mlx_ptr, 200, 200);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenght, &data.endian);
	while (x < 200)
	{
		y = 0;
		while (y < 200)
		{
				my_mlx_pixel_put(&data, x, y, 0x00FFFFFF);
				y++;
		}
		x++;
	}

	mlx_put_image_to_window(g_window.mlx_ptr, g_window.win_ptr, data.img, 40, 40);
	mlx_hook(g_window.win_ptr,2, 0, ft_exit, &g_window);
	mlx_hook(g_window.win_ptr,17, 0, ft_exit2, &g_window);
	mlx_loop(g_window.mlx_ptr);

}


// int main ()
// {
// 	t_minilib	window;

// 	g_window.res.size_x = 500;
// 	g_window.res.size_y = 500;
// 	initialized_win(window, "miniRt");
// 	open_window(window);
// 	mlx_hook(g_window.win_ptr,2, 0,ft_exit, window);
// 	mlx_hook(g_window.win_ptr,17, 0,ft_exit2, window);

// 	win_running(window);
// 	return (0);
// }
