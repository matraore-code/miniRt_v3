#include "../../includes/minirt.h"


t_tuple	normale_plan(t_hit hit, t_ray ray, t_data *data)
{
	(void)data;
	return (adjust_normal(ray.dir, hit.obj->vector));
}

t_hit  get_hit_plane(t_object *plane, t_ray ray, t_data *g_win)
{
    double d;
    double hit_point;
    t_hit hit;

    (void)(g_win);
    d = dot_tuple(plane->vector, ray.dir);
    hit_point = (dot_tuple(sub_tuple(plane->pos[0], ray.ori), plane->vector) / d);
    if (hit_point < 0)
        return (hit_infini());
    else
        hit = create_dist_hit(plane,add_tuple(ray.ori, scale_tuple(hit_point, ray.dir)),
                    plane->color, hit_point);
    return (hit);
}