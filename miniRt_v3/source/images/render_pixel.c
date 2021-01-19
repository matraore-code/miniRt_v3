#include "../includes/minirt.h"
#define Pi 3.1415926


static void		check_collinear_vectors(
	t_tuple cam_dir, t_tuple *droit, t_tuple haut)
{
	if (cam_dir.y == 1)
		*droit = create_tuple(1, 0, 0);
	else if (cam_dir.y == -1)
		*droit = create_tuple(-1, 0, 0);
	else
		*droit = cross(normalize_tuple(haut), cam_dir);
}


void	pixel_put(t_mlx_data g_win, int x, int y, t_color color)
{
	char *dst;
    int  color_int;

	dst = g_win.addr + (y * g_win.line_length + x * (g_win.bits_per_pixel / 8));
    color_int = ((int)color.r << 16 | (int)color.g << 8 | (int)color.b);
	*(unsigned int*)dst = color_int;
}

t_mat3x3       look_at(t_cam *cam)
{
    t_mat3x3 mat;
    t_tuple  inverse_dir;
    t_tuple  unit;
    t_tuple droit;
    t_tuple haut;

    unit = create_tuple(0, 1, 0);
    inverse_dir = cam->dir;
    check_collinear_vectors(cam->dir, &droit, haut);
    haut = cross(inverse_dir, droit);
    mat.c1= create_tuple(droit.x, droit.y, droit.z);
    mat.c2 = create_tuple(haut.x, haut.y, haut.z);
    mat.c3 = create_tuple(inverse_dir.x, inverse_dir.y, inverse_dir.z);
    mat = invert_mat3x3(mat);
    return (mat);
}

// t_color        pixel(t_tuple_2d pix, t_data *g_win)
// {
//         t_ray   ray;
//         t_cam   *cam;
//         double   fov_h;
//         t_color cast;
    
//         cam = g_win->camera;
//         fov_h = tan(cam->fov / 2 * (Pi / 180));
//         ray.ori.x = (2 * ((pix.x + 0.5) / g_win->res.size_x - 1) * fov_h);
//         ray.ori.y = ((1 - (2 * ((pix.y + 0.5) / g_win->res.size_y)) * fov_h));
//         ray.ori.z = -1;
//         /*ray.ori = look_at(cam, cam->pos);*/
//         if (g_win->res.size_x >= g_win->res.size_y)
// 		    ray.ori.x *= g_win->res.size_x / (double)g_win->res.size_y;
// 	    else
// 		    ray.ori.x *= g_win->res.size_y / (double)g_win->res.size_x;
//         /*ray.dir = normale_tuple(ray.ori);
//         ray.ori = g_win->camera->pos;*/
//         ray.dir = normale_tuple(soustraction_tuple(ray.ori, cam->pos));
//         ray.ori = cam->pos;
//         cast = trace_ray(ray, g_win);
//         return (cast);
// }

t_color        pixel(t_tuple_2d pix, t_data *g_win)
{
    t_tuple vec;
    float   aspect_ratio;
    t_cam *cam;
    t_ray ray;
    t_color cast;
    
    cam = g_win->camera;
    cam->rot_mat = look_at(cam);
    aspect_ratio = (double)g_win->res.size_x / (double)g_win->res.size_y;
    vec.x = (2.0 * (pix.x + 0.5) / g_win->res.size_x - 1) * tan(g_win->camera->fov / 2 * Pi / 180) * aspect_ratio;
    vec.y = (1 - 2 * ((pix.y + 0.5) / g_win->res.size_y)) * tan(g_win->camera->fov / 2 * Pi / 180)
    ;
    vec.z = 1;
    ray.ori = g_win->camera->pos;
    ray.dir = mult_mat3x3_tuple(g_win->camera->rot_mat, vec);
    ray.dir = normalize_tuple(ray.dir);
    cast = trace_ray(ray, g_win);
    return (cast);
}


t_color  *get_shape(t_data *g_win)
{
    t_color  *shape;
    int x;
    int y;

    shape = tools_malloc(sizeof(t_color) * g_win->res.size_x * g_win->res.size_y);
    x = 0;
    while (x < g_win->res.size_x)
    {
        y = 0;
        while (y < g_win->res.size_y)
        {
            shape[x * g_win->res.size_y + y] = pixel((t_tuple_2d){x, y}, g_win);
            y++;
        }
        x++;
    }
    return (shape);
}